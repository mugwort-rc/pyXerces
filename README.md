# pyXerces

## Build

	$ python setup.py build

## Usage

### Xerces-C++ style

	import Xerces
	parser = Xerces.XercesDOMParser()
	
	xml = open('sample.xml', 'rb').read()
	input = Xerces.MemBufInputSource(xml, 'PyXercesDOMParser')
	parser.parse(input)
	dom = parser.getDocument()

### like lxml.etree style

	from Xerces import etree

	dom = etree.fromstring('<test><a/><a/><a/></test>')

	print 'tag:', dom.tag
	print 'len:', len(dom)

	result = dom.xpath('//a')

	for elem in result:
		print 'tag:', elem.tag

#### XSLT

	from Xerces import etree
	
	transform = etree.XSLT('''<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	  <xsl:template match="/">
	    <foo><xsl:value-of select="/a/b/text()" /></foo>
	  </xsl:template>
	</xsl:stylesheet>''')
	
	result = transform('<a><b>Test</b></a>')

	print str(result)
	print result.getroot().text

#### XQuery

	from Xerces import etree
	
	query = etree.XQuery('<result>{ //data }</result>')
	
	result = query('<datas><data no="1"/><data no="2"/><data no="3"/></datas>')
	
	print str(result)
	print len(result.getroot())
