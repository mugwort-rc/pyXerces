# -*- coding: utf-8 -*-

import pprint
import re

import Xerces
try:
	import XQilla
except:
	pass

class XercesEtreeException(Exception):
	pass

class _XercesNode(object):
	def __init__(self, node):
		"""
			@brief constructor
			@param [in]		node	Xerces.DOMNode
		"""
		self._node = node

	# ==============================
	# Begin utility functions

	def _owner(self):
		return self._node.getOwnerDocument()

	def _remove(self):
		"""
			@brief remove node from owner document
		"""
		if self._node is None:
			raise XercesEtreeException('Node is removed.')
		parent = self._node.getParentNode()
		if parent is not None:
			parent.removeChild(self._node)
			owner = self._owner()
			owner.adoptNode(self._node)
			self._node.release()

	# End utility functions
	# ==============================

class _XercesAttributes:
	def __init__(self, owner):
		"""
			@brief constructor
			@param [in]		owner	attribute owner element
		"""
		self._owner = owner

	# ==============================
	# Begin utility functions

	def __to_map(self):
		"""
			@breif convert to python dict from Xerces.DOMNamedNodeMap
		"""
		items = self._owner.getAttributes()
		buff  = {}
		for i in range(items.getLength()):
			item = items.item(i)
			buff[unicode(item.getNodeName())] = unicode(item.getNodeValue())
		return buff

	def _update(self, attr):
		current = self.__to_map()
		for name,value in attr.items():
			ns, name = _parse_namespace(name)
			if name in current:
				attrib = self._owner.getAttributeNodeNS(ns, name)
				attrib.setValue(value)
				current[_build_namespace(ns, name)] = value
			else:
				doc = self._owner.getOwnerDocument()
				attrib = doc.createAttributeNS(ns, name)
				attrib.setValue(value)
				self._owner.setAttributeNode(attrib)
				current[_build_namespace(ns, name)] = value

	# End utility functions
	# ==============================

	def __repr__(self):
		"""
			@brief represent
			@return represent string
		"""
		return str(self.__to_map())

	def __contains__(self, name):
		"""
			@brief name in self
			@return boolean
		"""
		return name in self.__to_map()

	def __setitem__(self, key, value):
		"""
			@brief set attribute value
			@param [in]		key		key name
			@param [in]		value	value
		"""
		# existing key
		if key in self.__to_map():
			item = self._owner.getAttributes().getNamedItem(key).toDOMAttr()
			item.setValue(unicode(value))
		# new key
		else:
			self._owner.setAttribute(key, unicode(value))

	def items(self):
		"""
			@brief get attribute items
			@return list of (key, value)
		"""
		return self.__to_map().items()

	def keys(self):
		"""
			@brief get attribute keys
			@return list of key
		"""
		return self.__to_map().keys()

	def values(self):
		"""
			@brief get attribute values
			@return list of value
		"""
		return self.__to_map().values()

class _XercesText(_XercesNode):
	def __init__(self, prev, node):
		"""
			@brief constructor
			@param [in]		prev	previous element (tail holder)
			@param [in]		node	text node
		"""
		_XercesNode.__init__(self, node)

		self._prev = prev
		self._node = node

	def __str__(self):
		"""
			@brief convert str
			@return str
		"""
		return str(self._get())

	def __unicode__(self):
		"""
			@brief convert unicode
			@return unicode
		"""
		return unicode(self._get())

	def __repr__(self):
		"""
			@brief represent
			@return represent str
		"""
		pp = pprint.PrettyPrinter()
		return pp.pformat(self._get())

	def __eq__(self, rhs):
		"""
			@brief operator ==
			@param [in]		rhs		rhs string
			@return self == rhs
		"""
		return self._get() == rhs

	def _set(self, value):
		"""
			@brief set value
			@param [in]		value	text value
		"""
		self._node.setNodeValue(value)

	def _get(self):
		"""
			@brief get value
			@return text value
		"""
		return self._node.getNodeValue()

class _XercesDocument(object):
	def __init__(self, document):
		"""
			@brief constructor
			@param [in]		document	Xerces.DOMDocument
		"""
		object.__setattr__(self, '_elem', document)

	# ==============================
	# Begin utility functions

	def _isOwn(self, elem):
		"""
			@brief is own node
			@param [in]		elem	check element
			@return boolean
		"""
		return self._elem.isSameNode(elem._elem.getOwnerDocument())

	def _adopt(self, elem):
		"""
			@brief adopt document
			@param [in]		elem	adopt element
			@return _XercesElement
		"""
		if self._isOwn(elem):
			if elem.tail is not None:
				self._elem.adoptNode(elem._elem.getNextSibling())
			self._elem.adoptNode(elem._elem)
			return elem
		return None

	def _import(self, elem):
		"""
			@brief import athor document's node
			@param [in,out]		elem	target element
		"""
		result = None
		if not self._isOwn(elem):
			result = _XercesElement(self._elem.importNode(elem._elem, True))
			if elem.getparent() is not None:
				parent = elem.getparent()
				parent.remove(elem)
		return result

	# End utility functions
	# ==============================

	def __getattr__(self, name):
		# docinfo attribute
		if name == 'docinfo':
			pass
		# parser attribute
		elif name == 'parser':
			pass

	def find(self):
		# TODO:
		pass

	def findall(self):
		# TODO:
		pass

	def findtext(self):
		# TODO:
		pass

	def getiterator(self):
		# TODO:
		pass

	def getpath(self):
		# TODO:
		pass

	def getroot(self):
		elem = self._elem.getDocumentElement()
		if elem is not None:
			return _XercesElement(elem)
		return None

	def iter(self):
		# TODO:
		pass

	def iterfind(self):
		# TODO:
		pass

	def parse(self):
		# TODO:
		pass

	def relaxng(self):
		# TODO:
		pass

	def write(self):
		# TODO:
		pass

	def write_c14n(self):
		# TODO:
		pass

	def xinclude(self):
		# TODO:
		pass

	def xmlschema(self):
		# TODO:
		pass

	def xpath(self, xpath, namespaces={}):
		root = self.getroot()
		return root.xpath(xpath, namespaces={})

	def xslt(self):
		# TODO:
		pass

class _XercesElement(object):

	class Iterator:
		def __init__(self, elems):
			"""
				@brief constructor
				@param [in]		nodes	Xerces.DOMNodeList object
			"""
			self._elems = elems
			self._index = 0

		def next(self):
			"""
				@brief iterate next
			"""
			if self._index >= len(self._elems):
				raise StopIteration
			result = self._elems[self._index]
			self._index += 1
			return result

	def __init__(self, elem):
		"""
			@brief constructor
			@param [in]		elem	Xerces.DOMElement
		"""
		if elem.getNodeType() != Xerces.DOMNode.ELEMENT_NODE:
			raise XercesEtreeException('element is not ELEMENT_NODE')

		object.__setattr__(self, '_elem', elem)

		# initialize attributes
		self.__initialize_attributes()

	def __initialize_attributes(self):
		"""
			@brief intialize class attribute
		"""
		# attrib
		self.attrib = _XercesAttributes(self._elem)
		# text
		child = self._elem.getFirstChild()
		if child is not None and child.getNodeType() == Xerces.DOMNode.TEXT_NODE:
			object.__setattr__(self, 'text', _XercesText(self._elem, child))
		else:
			object.__setattr__(self, 'text', None)
		# tail
		sibling = self._elem.getNextSibling()
		if sibling is not None and sibling.getNodeType() == Xerces.DOMNode.TEXT_NODE:
			object.__setattr__(self, 'tail', _XercesText(self._elem, sibling))
		else:
			object.__setattr__(self, 'tail', None)
		# base
		if self._elem.getBaseURI() is not None:
			object.__setattr__(self, 'base', unicode(self._elem.getBaseURI()))
		else:
			object.__setattr__(self, 'base', None)

	# ==============================
	# Begin utility functions

	def __to_list(self):
		"""
			@brief convert to python list from _XercesElement child nodes(ELEMENT_NODE)
			@return list
		"""
		buff  = []
		nodes = self._elem.getChildNodes()
		for i in range(nodes.getLength()):
			node = nodes.item(i)
			if node.getNodeType() == Xerces.DOMNode.ELEMENT_NODE:
				buff.append(_XercesElement(node.toDOMElement()))
		return buff

	# End utility functions
	# ==============================

	def __repr__(self):
		"""
			@brief represent
			@return represent str
		"""
		return '<_XercesElement %s at %x>' % (self.tag, id(self))

	def __eq__(self, rhs):
		"""
			@brief operator ==
			@param [in]		rhs		right parameter
			@return boolean
		"""
		if type(rhs) is _XercesElement and self._elem.isSameNode(rhs._elem):
			return True
		return False

	def __contains__(self, item):
		"""
			@brief item in self
			@return boolean
		"""
		# get child elements
		childs = [x._elem for x in list(self)]
		# check element
		for child in childs:
			if item._elem.isSameNode(child):
				return True
		return False

	def __len__(self):
		"""
			@brief count of _XercesElement child nodes(ELEMENT_NODE)
		"""
		buff = self.__to_list()
		return len(buff)

	def __getitem__(self, index):
		"""
			@brief get child element from index
			@param [in]		index	index
		"""
		buff = self.__to_list()
		return buff[index]

	def __setitem__(self, index, elem):
		"""
			@brief set child element from index
		"""
		self.replace(self[index], elem)

	def __delitem__(self, index):
		"""
			@breif remove child
			@param [in]		index	index of child
		"""
		self.remove(self[index])

	def __getslice__(self, start, stop):
		"""
			@brief get child elements from slice index
			@param [in]		start	start pos
			@param [in]		stop	stop pos
			@return list of child elements
		"""
		buff = self.__to_list()
		return buff[start:stop]

	def __iter__(self):
		"""
			@brief iteratable function
		"""
		return _XercesElement.Iterator(self.__to_list())

	def __setattr__(self, name, value):
		"""
			@brief change the attribute value
			@param [in]		name	attribute name
			@param [in]		value	set value
		"""
		# TODO: nsmap
		# TODO: sourceline
		# tag attribute
		if name == 'tag':
			if value is not None and name != self.tag:
				ns, value = _parse_namespace(value)
				doc = self._elem.getOwnerDocument()
				doc.renameNode(self._elem, ns, value)
		# text attribute
		elif name == 'text':
			child = self._elem.getFirstChild()
			# already exists
			if child is not None and child.getNodeType() == Xerces.DOMNode.TEXT_NODE:
				text = self.text
				if value is None:
					text._remove()
					object.__setattr__(self, 'text', None)
				else:
					text._set(value)
			# create new node
			else:
				if value is not None:
					doc = self._elem.getOwnerDocument()
					node = doc.createTextNode(value)
					if child is None:
						self._elem.appendChild(node)
					else:
						self._elem.insertBefore(node, child)
					text = _XercesText(self._elem, node)
					object.__setattr__(self, 'text', text)
		# tail attribute
		elif name == 'tail':
			parent = self.getparent()
			if parent is None:
				object.__setattr__(self, 'tail', unicode(value))
				return
			next = self._elem.getNextSibling()
			# already exists
			if next is not None and next.getNodeType() == Xerces.DOMNode.TEXT_NODE:
				tail = self.tail
				if value is None:
					tail._remove()
					object.__setattr__(self, 'tail', None)
				else:
					tail._set(value)
			# create new node
			else:
				if value is not None:
					doc = self._elem.getOwnerDocument()
					node = doc.createTextNode(value)
					if next is None:
						parent._elem.appendChild(node)
					else:
						parent._elem.insertBefore(node, next)
					text = _XercesText(self._elem, node)
					object.__setattr__(self, 'tail', text)
		# base attribute
		elif name == 'base':
			object.__setattr__(self, 'base', value)
		# prefix attribute
		elif name == 'prefix':
			if self._elem.getNamespaceURI() is not None:
				self._elem.setPrefix(value)
			else:
				raise XercesEtreeException('Namespace is not set.')

	def __getattr__(self, name):
		"""
			@brief get attribute value
			@param [in]		name	attribute name
			@return attribute value
		"""
		# tag attribute
		if name == 'tag':
			ns    = self._elem.getNamespaceURI()
			value = self._elem.getNodeName()
			return _build_namespace(ns, value)
		# text attribute
		elif name == 'text':
			text = object.__getattr__(self, 'text')
			if text is not None:
				return unicode(text)
			return None
		# tail attribute
		elif name == 'tail':
			if self.getparent() is None:
				tail = object.__getattr__(self, 'tail')
				return tail
			tail = object.__getattr__(self, 'tail')
			if tail is not None:
				return unicode(tail)
			return None
		# attrib attribute
		elif name == 'attrib':
			return _XercesAttributes(self._elem)
		# base attribute
		elif name == 'base':
			base = object.__getattr__(self, 'base')
			if base is not None:
				return base
			else:
				base = self._elem.getBaseURI()
				if base is not None:
					return unicode(base)
				return None
		# prefix attribute
		elif name == 'prefix':
			prefix = self._elem.getPrefix()
			if prefix is not None:
				return unicode(prefix)
			return None

	def clear(self):
		"""
			@brief etree.Element.clear
		"""
		self.text = None
		self.tail = None
		for child in self:
			self.remove(child)

	def remove(self, elem):
		"""
			@brief etree.Element.remove
			@param [in]		elem	child _XercesElement
		"""
		# get child elements
		if elem in self:
			if elem.tail is not None:
				elem.tail = None
			self._elem.removeChild(elem._elem)

	def replace(self, child, new):
		"""
			@brief replace element
			@param [in]		child	target child element
			@param [in]		new		replace element
		"""
		doc = self.getroottree()
		if not doc._isOwn(new):
			new = doc._import(new)
		if child in self:
			self._elem.replaceChild(new._elem, child._elem)

	def addnext(self, elem):
		"""
			@brief add next
			@param [in]		elem	new element
		"""
		next = self.getnext()
		parent = self.getparent()
		if parent is None:
			raise XercesEtreeException('Root node cannot addnext.')
		if next is not None:
			doc = self.getroottree()
			add_elem = elem
			if not doc._isOwn(elem):
				add_elem = doc._import(elem)
			parent._elem.insertBefore(add_elem._elem, next._elem)
		else:
			parent.append(elem)

	def addprevious(self, elem):
		"""
			@brief add previous
			@param [in]		elem	new element
		"""
		parent = self.getparent()
		if parent is None:
			raise XercesEtreeException('Root node cannot addnext.')
		doc = self.getroottree()
		add_elem = elem
		if not doc._isOwn(elem):
			add_elem = doc._import(elem)
		parent._elem.insertBefore(add_elem._elem, self._elem)

	def append(self, elem):
		"""
			@brief append element
			@param [in]		elem	new element
		"""
		root = self.getroottree()
		add_elem = elem
		if not root._isOwn(elem):
			add_elem = root._import(elem)
		self._elem.appendChild(add_elem._elem)

	def extend(self, elems):
		"""
			@brief extend elements
			@param [in]		elems	list of element
		"""
		for elem in elems:
			self.append(elem)

	def find(self, name):
		"""
			@brief find first element by name
			@param [in]		name	search name
			@return XercesElement
		"""
		return self.findall(name)[0]

	def findall(self, name):
		"""
			@brief find element by name
			@param [in]		name	search name
			@return list of XercesElement
		"""
		ns, name = _parse_namespace(name)
		items = self._elem.getElementsByTagNameNS(ns, name)
		result = []
		for i in range(items.getLength()):
			node = items.item(i)
			if node.getNodeType() == Xerces.DOMNode.ELEMENT_NODE:
				result.append(_XercesElement(node.toDOMElement()))
		return result

	def findtext(self, elem):
		# TODO:
		pass

	def getnext(self):
		"""
			@brief etree.Element.getnext
			@return _XercesElement
		"""
		next = self._elem.getNextSibling()
		if next is not None and next.getNodeType() == Xerces.DOMNode.TEXT_NODE:
			next = next.getNextSibling()
		if next is not None and next.getNodeType() == Xerces.DOMNode.ELEMENT_NODE:
			return _XercesElement(next)
		return None

	def getparent(self):
		"""
			@brief etree.Element.getparent
			@return _XercesElement
		"""
		parent = self._elem.getParentNode()
		if parent is not None and parent.getNodeType() == Xerces.DOMNode.ELEMENT_NODE:
			return _XercesElement(parent.toDOMElement())
		return None

	def getprevious(self):
		"""
			@brief etree.Element.getprevious
			@return _XercesElement
		"""
		previous = self._elem.getPreviousNode()
		if previous is not None and previous.getNodeType() == Xerces.DOMNode.TEXT_NODE:
			previous = previous.getPreviousNode()
		if previous is not None and previous.getNodeType() == Xerces.DOMNode.ELEMENT_NODE:
			return _XercesElement(previous.toDOMElement())
		return None

	def getroottree(self):
		"""
			@brief etree.Element.getroottree
			@return _XercesDocument
		"""
		return _XercesDocument(self._elem.getOwnerDocument())

	def index(self, search):
		"""
			@brief get index of search element
			@param [in]		search		XercesElement
			@return index int
		"""
		i = 0
		for elem in self:
			if elem == search:
				return i
			i += 1

	def insert(self, index, elem):
		"""
			@brief insert
		"""
		if len(self) == 0 and index == 0:
			self.append(elem)
		else:
			if len(self) == 0:
				raise IndexError
			self[index].addprevious(elem)

	def makeelement(self, tag, attrib={}):
		"""
			@brief make element
			@param [in]		tag		element name
			@param [in]		attrib	attribute dict
		"""
		return Element(tag, attrib)

	def items(self):
		"""
			@brief etree.Element.items
		"""
		return self.attrib.items()

	def keys(self):
		"""
			@brief etree.Element.keys
		"""
		return self.attrib.keys()

	def values(self):
		"""
			@brief etree.Element.values
		"""
		return self.attrib.values()

	def get(self, key, default=None):
		"""
			@brief get element attribute
		"""
		if key not in self.attrib:
			return default
		return self.attrib[key]

	def set(self, key, value):
		"""
			@brief set element attribute
			@param [in]		key		attribute name
			@param [in]		value	value
		"""
		self.attrib[key] = value

	def xpath(self, exp, namespaces={}):
		"""
			@brief evaluate XPath
			@param [in]		exp			expression
			@param [in]		namespaces	namespace dict
			@return list
		"""
		doc = self._elem.getOwnerDocument()
		ns  = None
		if namespaces:
			ns = doc.createNSResolver(None)
			for name,uri in namespaces.items():
				ns.addNamespaceBinding(name, uri)
		ret = doc.evaluate(exp, self._elem, ns, Xerces.DOMXPathResult.UNORDERED_NODE_SNAPSHOT_TYPE, None)
		result = []
		for i in range(ret.getSnapshotLength()):
			ret.snapshotItem(i)
			node = ret.getNodeValue()
			node_type = node.getNodeType()
			if node_type == Xerces.DOMNode.ELEMENT_NODE:
				result.append(_XercesElement(node.toDOMElement()))
			elif node_type == Xerces.DOMNode.TEXT_NODE or node_type == Xerces.DOMNode.ATTRIBUTE_NODE:
				result.append(unicode(node.getNodeValue()))
			else:
				result.append(node)
		if ns:
			ns.release()
		if ret:
			ret.release()
		return result

def Element(tag, attrib={}, **extra):
	"""
		@brief create new element
		@param [in]		tag		tag name
		@param [in]		attrib	attribute dict
		@return XercesElement
	"""
	impl = _get_impl()

	url, tag = _parse_namespace(tag)
	doc = impl.createDocument(url, tag, None)
	elem = doc.getDocumentElement()

	attr = _XercesAttributes(elem)
	attr._update(attrib)
	attr._update(extra)

	return _XercesElement(elem)

def SubElement(parent, tag, attrib={}, **extra):
	"""
		@brief create sub element
		@param [in]		parent		parent element
		@param [in]		tag			tag name
		@param [in]		attrib		attribute dict
		@return XercesElement
	"""
	doc = parent._elem.getOwnerDocument()

	url, tag = _parse_namespace(tag)
	elem = doc.createElementNS(url, tag)

	attr = _XercesAttributes(elem)
	attr._update(attrib)
	attr._update(extra)

	result = _XercesElement(elem)

	parent.append(result)

	return result

class _XQillaResultTree:
	def __init__(self, result):
		self._result = result

	def __str__(self):
		return self._result

	def __unicode__(self):
		return self._result.decode('utf-8')

	def getroot(self):
		dom = None
		try:
			dom = fromstring(self._result)
		except:
			pass
		return dom

class _XQillaObject:
	def __init__(self, queryType, source):
		"""
			@brief constructor
			@param [in]		queryType	type of query
			@param [in]		source		source xsl (dom (lxml.etree like) or text)
		"""
		if type(source) is _XercesElement or type(source) is _XercesDocument:
			source = tostring(source)

		self._xqilla = XQilla.XQilla()
		self._conf    = XQilla.XercesConfiguration()
		self._context = self._xqilla.createContext(queryType, self._conf)
		self._query = self._xqilla.parse(source, self._context)

	def __call__(self, doc):
		"""
			@brief call
			@param [in]		doc		context (dom (lxml.etree like) or text)
		"""
		if type(doc) is _XercesElement or type(doc) is _XercesDocument:
			doc = tostring(doc)

		inputSource = Xerces.MemBufInputSource(doc, 'memXSLT')

		ctx = self._query.createDynamicContext()
		mm  = ctx.getMemoryManager()
		node = ctx.parseDocument(inputSource)

		ctx.setContextItem(node.toItem())
		ctx.setContextPosition(1)
		ctx.setContextSize(1)

		target = Xerces.MemBufFormatTarget()
		writer = XQilla.EventSerializer('UTF-8', '1.1', target, mm)

		nsfilter = XQilla.NSFixupFilter(writer, mm)

		self._query.execute(nsfilter, ctx)

		return _XQillaResultTree(target.getStringBuffer())

class XSLT(_XQillaObject):
	def __init__(self, source):
		"""
			@brief constructor
			@param [in]		source	source xsl (dom (lxml.etree like) or text)
		"""
		_XQillaObject.__init__(self, XQilla.XQilla.XSLT2, source)

class XQuery(_XQillaObject):
	def __init__(self, source):
		_XQillaObject.__init__(self, XQilla.XQilla.XQUERY3, source)

def _parse_namespace(tag):
	"""
		@brief parse represent of namespace
		@return tuple of str
	"""
	match = re.match(r'(\{(https?://.+)\})?(.+)', unicode(tag))
	if match:
		ns, url, tag = match.groups()
		return url, tag
	return None, None

def _build_namespace(ns, name):
	"""
		@brief represent of namespace
		@return represented namespace str
	"""
	if ns:
		return u'{%s}%s'%(unicode(ns), unicode(name))
	return unicode(name)

def _get_impl():
	"""
		@brief get DOMImplementation
		@return Xerces.DOMImplementation
	"""
	impl = Xerces.DOMImplementationRegistry.getDOMImplementation(XQilla.gXPath2_3_0)
	if impl is not None:
		return impl
	return Xerces.DOMImplementationRegistry.getDOMImplementation('LS')

def parse(source, parser=None):
	"""
		@brief etree parse
		@param [in]		source		source file (path / fileobj / uri)
		@return TODO:
	"""

	if parser is not None:
		raise XercesEtreeException('Unsupported option.')

	# TODO: xmlns attribute from SAXParser
	if type(source) is file:
		source = source.name
	if type(source) is str:
		impl = _get_impl()
		parser = impl.createLSParser(Xerces.DOMImplementationLS.MODE_SYNCHRONOUS, None)
		doc = parser.parseURI(source)
		if doc is not None:
			return _XercesDocument(doc)
	return None

def fromstring(text, parser=None, base_url=None):
	"""
		@brief etree fromstring
		@param [in]		text		source text
		@param [in]		parser		unsupported parameter
		@param [in]		base_url	unsupported parameter
		@return _XercesElement class
	"""

	# check option
	if parser is not None:
		raise XercesEtreeException('Unsupported option.')

	impl = _get_impl()

	mem = Xerces.MemBufInputSource(text, 'mem')
	parser = impl.createLSParser(Xerces.DOMImplementationLS.MODE_SYNCHRONOUS, None)
	input  = impl.createLSInput()
	input.setByteStream(mem)

	# set parameter option
	if base_url is not None:
		input.setBaseURI(base_url)

	document = parser.parse(input)

	if document is not None:
		elem = document.getDocumentElement()
		if elem is not None:
			return _XercesElement(elem)

	return None

def tostring(elem, encoding=None, method='xml', xml_declaration=None, pretty_print=False, with_tail=True, standalone=None, doctype=None, exclusive=False, with_comments=True, inclusive_ns_prefixes=None):
	"""
		@brief etree tostring
		@param [in]		elem					target element
		@param [in]		encoding				unsupported parameter
		@param [in]		method					unsupported parameter
		@param [in]		xml_declaration			boolean (default False)
		@param [in]		pretty_print			boolean (default False)
		@param [in]		with_tail				output with tail (default True)
		@param [in]		standalone				unsupported parameter
		@param [in]		doctype					unsupported parameter
		@param [in]		exclusive				unsupported parameter
		@param [in]		with_comments			unsupported parameter
		@param [in]		inclusive_ns_prefixes	unsupported parameter
		@return xml str
	"""

	dom = elem._elem

	# check option
	if encoding is not None:
		raise XercesEtreeException('Unsupported option.')
	if method != 'xml':
		raise XercesEtreeException('Unsupported method.')
	if standalone is not None:
		raise XercesEtreeException('Unsupported option.')
	if doctype is not None:
		raise XercesEtreeException('Unsupported option.')
	if exclusive != False:
		raise XercesEtreeException('Unsupported option.')
	if with_comments != True:
		raise XercesEtreeException('Unsupported option.')
	if inclusive_ns_prefixes is not None:
		raise XercesEtreeException('Unsupported option.')

	# create memory FormatTarget
	formatTarget = Xerces.MemBufFormatTarget()

	# create impl
	impl = Xerces.DOMImplementationRegistry.getDOMImplementation('LS')

	# create output
	output = impl.toDOMImplementationLS().createLSOutput()
	output.setByteStream(formatTarget)

	# create serializer
	serializer = impl.toDOMImplementationLS().createLSSerializer()

	# set default style(like a lxml.etree.tostring)
	# XML declaration (default = True)
	if serializer.getDomConfig().canSetParameter(Xerces.XMLUni.fgDOMXMLDeclaration.toString(), False):
		serializer.getDomConfig().setParameter(Xerces.XMLUni.fgDOMXMLDeclaration.toString(), False)

	# set option
	# method
	if method == 'c14n':
		# XXX: Xerces not supported this option.
		if serializer.getDomConfig().canSetParameter(Xerces.XMLUni.fgDOMWRTCanonicalForm.toString(), True):
			serializer.getDomConfig().setParameter(Xerces.XMLUni.fgDOMWRTCanonicalForm.toString(), True)
	# XML declaration
	if xml_declaration is not None:
		if serializer.getDomConfig().canSetParameter(Xerces.XMLUni.fgDOMXMLDeclaration.toString(), xml_declaration):
			serializer.getDomConfig().setParameter(Xerces.XMLUni.fgDOMXMLDeclaration.toString(), xml_declaration)
	# pretty print
	if pretty_print:
		if serializer.getDomConfig().canSetParameter(Xerces.XMLUni.fgDOMWRTFormatPrettyPrint.toString(), pretty_print):
			serializer.getDomConfig().setParameter(Xerces.XMLUni.fgDOMWRTFormatPrettyPrint.toString(), pretty_print)

	# dom serialize
	serializer.write(dom, output)
	serializer.release()

	# get data in memory
	result = formatTarget.getStringBuffer()
	output.release()

	if with_tail and type(elem) is _XercesElement and elem.tail is not None:
		result += elem.tail

	return result

