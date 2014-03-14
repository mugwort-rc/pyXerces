"""
Licensed to the Apache Software Foundation (ASF) under one or more
contributor license agreements.  See the NOTICE file distributed with
this work for additional information regarding copyright ownership.
The ASF licenses this file to You under the Apache License, Version 2.0
(the "License"); you may not use this file except in compliance with
the License.  You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import unittest

import Xerces

class DOMBasicTests(unittest.TestCase):
    """DOMBasicTests    Basic DOM Level 1 tests"""
    def test_doc01(self):
        """Test Doc01      Create a new empty document"""
        # First precondition, so that lazily created strings do not appear
        # as memory leaks.
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()
        doc.release()

    def test_doc02(self):
        """Test Doc02      Create one of each kind of node using the
                  document createXXX methods.
                  Watch for memory leaks."""
        # Do all operations in a preconditioning step, to force the
        # creation of implementation objects that are set up on first use.
        # Don't watch for leaks in this block (no  / )
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        el = doc.createElement('Doc02Element')

        frag = doc.createDocumentFragment()

        text = doc.createTextNode('Doc02TextNode')

        comment = doc.createComment('Doc02Comment')

        cdataSec = doc.createCDATASection('Doc02CDataSection')

        docType = doc.createDocumentType('Doc02DocumentType')

        notation = doc.createNotation('Doc02Notation')

        pi = doc.createProcessingInstruction('Doc02PITarget', 'Doc02PIData')

        nodeList = doc.getElementsByTagName('*')

        doc.release()

    def test_doc03(self):
        """Doc03 - Create a small document tree"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('COre').createDocument()

        rootEl = doc.createElement('Doc03RootElement')

        doc.appendChild(rootEl)

        textNode = doc.createTextNode('Doc03 text stuff')

        rootEl.appendChild(textNode)

        nodeList = doc.getElementsByTagName('*')

        doc.release()

    def test_attr01(self):
        """Attr01"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        rootEl = doc.createElement('RootElement')

        doc.appendChild(rootEl)

        attr01 = doc.createAttribute('Attr01')
        rem = rootEl.setAttributeNode(attr01)
        if rem:
            rem.release()

        attr01 = doc.createAttribute('Attr01')
        rem = rootEl.setAttributeNode(attr01)
        if rem:
            rem.release()

        doc.release()

    def test_attr02(self):
        """Attr02"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        rootEl = doc.createElement('RootElement')

        doc.appendChild(rootEl)

        attr01 = doc.createAttribute('Attr02')

        rem = rootEl.setAttributeNode(attr01)
        if rem:
            rem.release()

        attr02 = doc.createAttribute('Attr02')

        rem = rootEl.setAttributeNode(attr02)
        if rem:
            rem.release()

        doc.release()

    def test_attr03(self):
        """Attr03"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        rootEl = doc.createElement('RootElement')

        doc.appendChild(rootEl)

        attr01 = doc.createAttribute('Attr03')

        rem = rootEl.setAttributeNode(attr01)
        if rem:
            rem.release()

        attr01.setValue('Attr03Value1')

        attr01.setValue('Attr03Value2')

        doc.release()

    def test_attr04(self):
        """Attr04"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        rootEl = doc.createElement('RootElement')

        doc.appendChild(rootEl)

        attr01 = doc.createAttribute('Attr04')

        rem = rootEl.setAttributeNode(attr01)
        if rem:
            rem.release()

        attr01.setValue('Attr04Value1')
        value = attr01.getFirstChild()

        doc.release()

    def test_text01(self):
        """Text04"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        rootEl = doc.createElement('RootElement')

        doc.appendChild(rootEl)

        txt1 = doc.createTextNode('Hello Goodbye')
        rootEl.appendChild(txt1)

        txt1.splitText(6)
        rootEl.normalize()

        doc.release()

    def test_notation01(self):
        """Notation01"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        dt = doc.createDocumentType('DocType_for_Notation01')

        doc.appendChild(dt)

        notationMap = dt.getNotations()

        nt1 = doc.createNotation('Notation01')

        rem = notationMap.setNamedItem(nt1)
        if rem:
            rem.release()

        abc1 = notationMap.getNamedItem('Notation01')

        nt2 = abc1.toDOMNotation()
        self.assertTrue(nt1, nt2)

        abc6 = notationMap.getNamedItem('Notation01')

        nt2 = abc6

        doc.release()

    def test_namedNodeMap01(self):
        """NamedNodeMap01 - comparison operators."""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()
        nnm = doc.getAttributes()  # Should be null, because node type is not Element.

        self.assertEqual(nnm, None)

        el = doc.createElement('NamedNodeMap01')

        nnm2 = el.getAttributes()  # Should be an empty, but non-null map.
        self.assertNotEqual(nnm2, None)
        self.assertNotEqual(nnm, nnm2)

        doc.release()

    def test_importNode_quick(self):
        """importNode quick test"""
        doc1 = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()
        doc2 = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        el1 = doc1.createElement('abc')

        doc1.appendChild(el1)
        self.assertNotEqual(el1.getParentNode(), None)
        el2 = doc2.importNode(el1, True)
        self.assertEqual(el2.getParentNode(), None)
        tagName = el2.getNodeName()

        self.assertEqual(tagName, 'abc')

        self.assertEqual(el2.getOwnerDocument(), doc2)
        self.assertNotEqual(doc1, doc2)

        doc1.release()
        doc2.release()

    def test_getLength(self):
        """getLength() tests.  Both Node CharacterData and NodeList implement
                  getLength().  Early versions of the DOM had a clash
                  between the two, originating in the implementation class
                  hirearchy, which has NodeList as a (distant) base class
                  of CharacterData.  This is a regression test to verify
                  that the problem stays fixed."""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        tx = doc.createTextNode('Hello')

        el = doc.createElement('abc')

        el.appendChild(tx)

        textLength = tx.getLength()
        self.assertEqual(textLength, 5)

        nl = tx.getChildNodes()
        nodeListLen = nl.getLength()
        self.assertEqual(nodeListLen, 0)

        nl = el.getChildNodes()
        nodeListLen = nl.getLength()
        self.assertEqual(nodeListLen, 1)

        doc.release()

    def test_nodeList(self):
        """NodeList - comparison operators, basic operation."""
        nl = nl2 = None
        self.assertEqual(nl, None)
        self.assertFalse(nl is not None)
        self.assertEqual(nl, nl2)

        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()
        nl = doc.getChildNodes()  # Should be non-null, but empty

        self.assertNotEqual(nl, None)
        l = nl.getLength()
        self.assertEqual(l, 0)

        el = doc.createElement('NodeList01')

        doc.appendChild(el)
        l = nl.getLength()
        self.assertEqual(l, 1)
        self.assertNotEqual(nl, nl2)
        nl2 = nl
        self.assertEqual(nl, nl2)

        doc.release()

    def test_name_validity_checking(self):
        """Name validity checking."""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()
        with self.assertRaises(Xerces.PyDOMException) as e:
            el = doc.createElement('!@@ bad element name')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.INVALID_CHARACTER_ERR)

        doc.release()

    def test_assignment_opes_return_value(self):
        """Assignment ops return value"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        el = doc.createElement('NodeList01')

        doc.appendChild(el)

        n1 = n2 = n3 = el
        self.assertEqual(n1, n2)
        self.assertEqual(n2, n3)
        self.assertEqual(n1, el)
        self.assertNotEqual(n1, None)
        n1 = n2 = n3 = None
        self.assertEqual(n1, None)

        doc.release()

    def test_cloning_of_a_node_with_attributes(self):
        """Cloning of a node with attributes. Regression test for a ref counting
  bug in attributes of cloned nodes that occured when the "owned" flag
  was not set in the clone."""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        root = doc.createElement('CTestRoot')

        root.setAttribute('CTestAttr', 'CTestAttrValue')

        s = root.getAttribute('CTestAttr')
        self.assertEqual(s, 'CTestAttrValue')

        abc2 = root.cloneNode(True)
        cloned = abc2.toDOMElement()
        a = cloned.getAttributeNode('CTestAttr')
        self.assertNotEqual(a, None)
        s = a.getValue()
        self.assertEqual(s, 'CTestAttrValue')
        a = None

        a = cloned.getAttributeNode('CTestAttr')
        self.assertNotEqual(a, None)
        s = a.getValue()
        self.assertEqual(s, 'CTestAttrValue')

        doc.release()

    def test_splitText(self):
        """splitText()
     Regression test for a bug from Tinny Ng"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        tn = doc.createTextNode('0123456789')
        tn1 = tn.splitText(5)

        self.assertEqual(tn.getNodeValue(), '01234')
        self.assertEqual(tn1.getNodeValue(), '56789')

        tn2 = tn.splitText(5)
        self.assertEqual(tn.getNodeValue(), '01234')
        self.assertEqual(tn2.getNodeValue(), Xerces.XMLUni.fgZeroLenString)

        with self.assertRaises(Xerces.PyDOMException) as e:
            tn.splitText(6)
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.INDEX_SIZE_ERR)

        doc.release()

class DOMNSTests(unittest.TestCase):
    """DOMNSTests    DOM Name Space tests
  DOM Level 2 tests.  These should be split out as a separate test."""
    def test_hasFeature(self):
        """hasFeature.  The set of supported options tested here is for Xerces 1.1
              Note: because the implementation lazily creates some of the comprison
                    strings within the implementation, this test must be pre-flighted
                    outside of the TESPROLOG/ macros to avoid spurious
                    reports of memory leaks.

 Also test the case-insensitive"""
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        self.assertTrue(impl.hasFeature('XmL', '2.0'))

        self.assertTrue(impl.hasFeature('xML', None))
        self.assertTrue(impl.hasFeature('xML', Xerces.XMLUni.fgZeroLenString))

        self.assertTrue(impl.hasFeature('XMl', '1.0'))

        self.assertFalse(impl.hasFeature('xML', '3.0'))

        self.assertTrue(impl.hasFeature('TrAveRsal', None))
        self.assertTrue(impl.hasFeature('TrAveRsal', Xerces.XMLUni.fgZeroLenString))

    def test_hasFeature_2(self):
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        self.assertTrue(impl.hasFeature('XmL', None))
        self.assertTrue(impl.hasFeature('XmL', '1.0'))
        self.assertTrue(impl.hasFeature('XmL', '2.0'))
        self.assertFalse(impl.hasFeature('XmL', '3.0'))

        self.assertTrue(impl.hasFeature('Core', None))

        self.assertTrue(impl.hasFeature('coRe', '1.0'))

        self.assertTrue(impl.hasFeature('core', '2.0'))

        self.assertTrue(impl.hasFeature('cORe', '3.0'))
        self.assertFalse(impl.hasFeature('cORe', '4.0'))

        self.assertTrue(impl.hasFeature('Traversal', Xerces.XMLUni.fgZeroLenString))

        self.assertFalse(impl.hasFeature('traversal', '1.0'))

        self.assertTrue(impl.hasFeature('TraVersal', '2.0'))

        self.assertTrue(impl.hasFeature('Range', None))

        self.assertFalse(impl.hasFeature('raNge', '1.0'))

        self.assertTrue(impl.hasFeature('RaNge', '2.0'))

        self.assertFalse(impl.hasFeature('HTML', None))

        self.assertFalse(impl.hasFeature('Views', Xerces.XMLUni.fgZeroLenString))

        self.assertFalse(impl.hasFeature('StyleSheets', None))

        self.assertFalse(impl.hasFeature('CSS', Xerces.XMLUni.fgZeroLenString))
        self.assertFalse(impl.hasFeature('CSS2', None))
        self.assertFalse(impl.hasFeature('Events', None))

        self.assertFalse(impl.hasFeature('UIEvents', None))
        self.assertFalse(impl.hasFeature('MouseEvents', None))
        self.assertFalse(impl.hasFeature('MutationEvents', None))
        self.assertFalse(impl.hasFeature('HTMLEvents', None))

    def test_isSupported(self):
        """isSupported test (similar to hasFeature)"""
        doc = Xerces.DOMImplementationRegistry.getDOMImplementation('Core').createDocument()

        self.assertTrue(doc.isSupported('XmL', None))
        self.assertTrue(doc.isSupported('XmL', '1.0'))
        self.assertTrue(doc.isSupported('XmL', '2.0'))
        self.assertFalse(doc.isSupported('XmL', '3.0'))

        self.assertTrue(doc.isSupported('Core', None))
        self.assertTrue(doc.isSupported('Core', Xerces.XMLUni.fgZeroLenString))

        self.assertTrue(doc.isSupported('coRe', '1.0'))

        self.assertTrue(doc.isSupported('core', '2.0'))

        self.assertTrue(doc.isSupported('cORe', '3.0'))
        self.assertFalse(doc.isSupported('cORe', '4.0'))

        self.assertTrue(doc.isSupported('Traversal', None))

        self.assertFalse(doc.isSupported('traVersal', '1.0'))

        self.assertTrue(doc.isSupported('Range', Xerces.XMLUni.fgZeroLenString))

        self.assertFalse(doc.isSupported('raNge', '1.0'))

        self.assertTrue(doc.isSupported('RaNge', '2.0'))

        self.assertFalse(doc.isSupported('HTML', None))

        self.assertFalse(doc.isSupported('Views', None))

        self.assertFalse(doc.isSupported('StyleSheets', None))

        self.assertFalse(doc.isSupported('CSS', None))

        self.assertFalse(doc.isSupported('CSS2', Xerces.XMLUni.fgZeroLenString))
        self.assertFalse(doc.isSupported('Events', None))

        self.assertFalse(doc.isSupported('UIEvents', None))

        self.assertFalse(doc.isSupported('MouseEvents', None))

        self.assertFalse(doc.isSupported('MutationEvents', None))

        self.assertFalse(doc.isSupported('HTMLEvents', None))

        doc.release()

    def test_createDocumentType(self):
        """CreateDocumentType"""
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        self.assertNotEqual(dt, None)
        self.assertEqual(dt.getNodeType(), Xerces.DOMNode.DOCUMENT_TYPE_NODE)
        self.assertEqual(dt.getNodeName(), 'foo:docName')
        self.assertEqual(dt.getNamespaceURI(), None)
        self.assertEqual(dt.getPrefix(), None)
        self.assertEqual(dt.getLocalName(), None)
        self.assertEqual(dt.getPublicId(), 'pubId')
        self.assertEqual(dt.getSystemId(), 'http://sysId')
        self.assertEqual(dt.getInternalSubset(), None)
        self.assertEqual(dt.getOwnerDocument(), None)

        nnm = dt.getEntities()
        self.assertEqual(nnm.getLength(), 0)
        nnm = dt.getNotations()
        self.assertEqual(nnm.getLength(), 0)

        # release the documentType (dt) which is an orphaned node (does not have the owner)
        dt.release()

        #
        # Qualified name without prefix should also work.
        #
        dt = impl.createDocumentType('docName', 'pubId', 'http://sysId')

        self.assertNotEqual(dt, None)
        self.assertEqual(dt.getNodeType(), Xerces.DOMNode.DOCUMENT_TYPE_NODE)
        self.assertEqual(dt.getNodeName(), 'docName')
        self.assertEqual(dt.getNamespaceURI(), None)
        self.assertEqual(dt.getPrefix(), None)
        self.assertEqual(dt.getLocalName(), None)
        self.assertEqual(dt.getPublicId(), 'pubId')
        self.assertEqual(dt.getSystemId(), 'http://sysId')
        self.assertEqual(dt.getInternalSubset(), None)
        self.assertEqual(dt.getOwnerDocument(), None)

        # Creating a DocumentType with invalid or malformed qName should fail.
        with self.assertRaises(Xerces.PyDOMException) as e:
            impl.createDocumentType('<docName', 'pubId', 'http://sysId')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.INVALID_CHARACTER_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            impl.createDocumentType(':docName', 'pubId', 'http://sysId')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            impl.createDocumentType('docName:', 'pubId', 'http://sysId')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # release the documentType (dt) which is an orphaned node (does not have the owner)
        dt.release()

    def test_createDocument(self):
        """DOMImplementation::CreateDocument"""
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')
        dt = None

        doc = impl.createDocument(Xerces.XMLUni.fgZeroLenString, 'a', dt)

        doc.getNodeName()
        doc.release()

    def test_createDocument_2(self):
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        doc = impl.createDocument('http://document.namespace', 'foo:docName', dt)

        self.assertEqual(dt.getOwnerDocument(), doc)
        self.assertEqual(doc.getOwnerDocument(), None)

        self.assertEqual(doc.getNodeType(), Xerces.DOMNode.DOCUMENT_NODE)
        self.assertEqual(doc.getDoctype(), dt)

        self.assertEqual(doc.getNodeName(), '#document')

        self.assertEqual(doc.getNodeValue(), None)
        self.assertEqual(doc.getNamespaceURI(), None)
        self.assertEqual(doc.getPrefix(), None)
        self.assertEqual(doc.getLocalName(), None)

        el = doc.getDocumentElement()

        self.assertEqual(el.getLocalName(), 'docName')

        self.assertEqual(el.getNamespaceURI(), 'http://document.namespace')
        self.assertEqual(el.getNodeName(), 'foo:docName')
        self.assertEqual(el.getOwnerDocument(), doc)
        self.assertEqual(el.getParentNode(), doc)

        self.assertEqual(el.getPrefix(), 'foo')

        self.assertEqual(el.getTagName(), 'foo:docName')
        self.assertFalse(el.hasChildNodes())

        #
        # Creating a second document with the same docType object should fail.
        #
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc2 = impl.createDocument('pubId', 'foo:docName', dt)
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.WRONG_DOCUMENT_ERR)

        # release the document, the documentType (dt) still has the owner, and thus no need to release
        doc.release()

        # Creating a document with null NamespaceURI and DocumentType
        doc = impl.createDocument('pubId', 'foo:docName', None)
        doc.release()

        # Namespace tests of createDocument are covered by createElementNS below

    def test_createElementNS(self):
        """CreateElementNS methods"""
        # Set up an initial (root element only) document.
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        doc = impl.createDocument('http://document.namespace', 'foo:docName', dt)
        rootEl = doc.getDocumentElement()

        #
        # CreateElementNS
        #
        ela = doc.createElementNS('http://nsa', 'a:ela')  # prefix and URI

        self.assertEqual(ela.getNodeName(), 'a:ela')
        self.assertEqual(ela.getNamespaceURI(), 'http://nsa')
        self.assertEqual(ela.getPrefix(), 'a')
        self.assertEqual(ela.getLocalName(), 'ela')
        self.assertEqual(ela.getTagName(), 'a:ela')

        elb = doc.createElementNS('http://nsb', 'elb')  # URI, no prefix.

        self.assertEqual(elb.getNodeName(), 'elb')
        self.assertEqual(elb.getNamespaceURI(), 'http://nsb')
        self.assertEqual(elb.getPrefix(), None)
        self.assertEqual(elb.getLocalName(), 'elb')
        self.assertEqual(elb.getTagName(), 'elb')

        elc = doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'elc')  # No URI, no prefix.

        self.assertEqual(elc.getNodeName(), 'elc')
        self.assertEqual(elc.getNamespaceURI(), None)
        self.assertEqual(elc.getPrefix(), None)
        self.assertEqual(elc.getLocalName(), 'elc')
        self.assertEqual(elc.getTagName(), 'elc')

        rootEl.appendChild(ela)
        rootEl.appendChild(elb)
        rootEl.appendChild(elc)

        # Badly formed qualified name
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', '<a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.INVALID_CHARACTER_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', ':a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', 'a:')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', 'a::a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', 'a:a:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # xml:a must have namespaceURI == "http://www.w3.org/XML/1998/namespace"
        self.assertEqual(doc.createElementNS('http://www.w3.org/XML/1998/namespace', 'xml:a').getNamespaceURI(), 'http://www.w3.org/XML/1998/namespace')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS('http://nsa', 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(None, 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # unlike Attribute, xmlns (no different from foo) can have any namespaceURI for Element
        self.assertEqual(doc.createElementNS('http://nsa', 'xmlns').getNamespaceURI(), 'http://nsa')

        self.assertEqual(doc.createElementNS('http://www.w3.org/XML/1998/namespace', 'xmlns').getNamespaceURI(), 'http://www.w3.org/XML/1998/namespace')
        self.assertEqual(doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'xmlns').getNamespaceURI(), None)
        self.assertEqual(doc.createElementNS(None, 'xmlns').getNamespaceURI(), None)

        # unlike Attribute, xmlns:a (no different from foo:a) can have any namespaceURI for Element
        # except "" and null
        self.assertEqual(doc.createElementNS('http://nsa', 'xmlns:a').getNamespaceURI(), 'http://nsa')
        self.assertEqual(doc.createElementNS('http://www.w3.org/XML/1998/namespace', 'xmlns:a').getNamespaceURI(), 'http://www.w3.org/XML/1998/namespace')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(None, 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # In fact, any prefix != null should have a namespaceURI != 0 or != ""
        self.assertEqual(doc.createElementNS('http://nsa', 'foo:a').getNamespaceURI(), 'http://nsa')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'foo:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createElementNS(None, 'foo:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Change prefix
        elem = doc.createElementNS('http://nsa', 'foo:a')
        elem.setPrefix('bar')
        self.assertEqual(elem.getNodeName(), 'bar:a')
        self.assertEqual(elem.getNamespaceURI(), 'http://nsa')
        self.assertEqual(elem.getPrefix(), 'bar')
        self.assertEqual(elem.getLocalName(), 'a')
        self.assertEqual(elem.getTagName(), 'bar:a')
        # The spec does not prevent us from setting prefix to a node without prefix
        elem = doc.createElementNS('http://nsa', 'a')
        elem.setPrefix('bar')
        self.assertEqual(elem.getNodeName(), 'bar:a')
        self.assertEqual(elem.getNamespaceURI(), 'http://nsa')
        self.assertEqual(elem.getPrefix(), 'bar')
        self.assertEqual(elem.getLocalName(), 'a')
        self.assertEqual(elem.getTagName(), 'bar:a')

        # Special case for xml:a where namespaceURI must be xmlURI
        elem = doc.createElementNS('http://www.w3.org/XML/1998/namespace', 'foo:a')
        elem.setPrefix('xml')
        elem = doc.createElementNS('http://nsa', 'foo:a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            elem.setPrefix('xml')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        # However, there is no restriction on prefix xmlns
        elem.setPrefix('xmlns')
        # Also an element can not have a prefix with namespaceURI == null or ""
        elem = doc.createElementNS(None, 'a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            elem.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        elem = doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            elem.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Only prefix of Element and Attribute can be changed
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Prefix of readonly Element can not be changed.
        # However, there is no way to create such DOMElement* for testing yet.

        # release the document, the documentType (dt) still has the owner, and thus no need to release
        doc.release()

    def test_createAttributeNS(self):
        """CreateAttributeNS methods"""
        # Set up an initial (root element only) document.
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        doc = impl.createDocument('http://document.namespace', 'foo:docName', dt)
        rootEl = doc.getDocumentElement()

        #
        # CreateAttributeNS
        #
        attra = doc.createAttributeNS('http://nsa', 'a:attra')  # prefix and URI
        self.assertEqual(attra.getNodeName(), 'a:attra')
        self.assertEqual(attra.getNamespaceURI(), 'http://nsa')

        self.assertEqual(attra.getPrefix(), 'a')

        self.assertEqual(attra.getLocalName(), 'attra')
        self.assertEqual(attra.getName(), 'a:attra')
        self.assertEqual(attra.getOwnerElement(), None)

        attra = doc.createAttributeNS('http://nsb', 'attrb')  # URI, no prefix.
        self.assertEqual(attra.getNodeName(), 'attrb')
        self.assertEqual(attra.getNamespaceURI(), 'http://nsb')

        self.assertEqual(attra.getPrefix(), None)

        self.assertEqual(attra.getLocalName(), 'attrb')
        self.assertEqual(attra.getName(), 'attrb')
        self.assertEqual(attra.getOwnerElement(), None)

        attra = doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'attrc')
        self.assertEqual(attra.getNodeName(), 'attrc')
        self.assertEqual(attra.getNamespaceURI(), None)
        self.assertEqual(attra.getPrefix(), None)
        self.assertEqual(attra.getLocalName(), 'attrc')
        self.assertEqual(attra.getName(), 'attrc')
        self.assertEqual(attra.getOwnerElement(), None)

        # Badly formed qualified name
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', '<a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.INVALID_CHARACTER_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', ':a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'a:')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'a::a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'a:a:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # xml:a must have namespaceURI == "http://www.w3.org/XML/1998/namespace"
        self.assertEqual(doc.createAttributeNS('http://www.w3.org/XML/1998/namespace', 'xml:a').getNamespaceURI(), 'http://www.w3.org/XML/1998/namespace')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(None, 'xml:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # unlike Element, xmlns must have namespaceURI == "http://www.w3.org/2000/xmlns/"
        self.assertEqual(doc.createAttributeNS('http://www.w3.org/2000/xmlns/', 'xmlns').getNamespaceURI(), 'http://www.w3.org/2000/xmlns/')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://www.w3.org/XML/1998/namespace', 'xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(None, 'xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # unlike Element, xmlns:a must have namespaceURI == "http://www.w3.org/2000/xmlns/"
        self.assertEqual(doc.createAttributeNS('http://www.w3.org/2000/xmlns/', 'xmlns:a').getNamespaceURI(), 'http://www.w3.org/2000/xmlns/')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://nsa', 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS('http://www.w3.org/XML/1998/namespace', 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(None, 'xmlns:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # In fact, any prefix != null should have a namespaceURI != 0 or != ""
        self.assertEqual(doc.createAttributeNS('http://nsa', 'foo:a').getNamespaceURI(), 'http://nsa')
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'foo:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.createAttributeNS(None, 'foo:a')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Change prefix
        attr = doc.createAttributeNS('http://nsa', 'foo:a')
        attr.setPrefix('bar')

        self.assertEqual(attr.getNodeName(), 'bar:a')
        self.assertEqual(attr.getNamespaceURI(), 'http://nsa')
        self.assertEqual(attr.getPrefix(), 'bar')
        self.assertEqual(attr.getName(), 'bar:a')
        # The spec does not prevent us from setting prefix to a node without prefix
        self.assertEqual(attr.getLocalName(), 'a')
        attr = doc.createAttributeNS('http://nsa', 'a')
        self.assertEqual(attr.getPrefix(), None)
        attr.setPrefix('bar')
        self.assertEqual(attr.getNodeName(), 'bar:a')
        self.assertEqual(attr.getNamespaceURI(), 'http://nsa')
        self.assertEqual(attr.getPrefix(), 'bar')
        self.assertEqual(attr.getName(), 'bar:a')

        # Special case for xml:a where namespaceURI must be xmlURI
        attr = doc.createAttributeNS('http://www.w3.org/XML/1998/namespace', 'foo:a')
        attr.setPrefix('xml')
        attr = doc.createAttributeNS('http://nsa', 'foo:a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('xml')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        # Special case for xmlns:a where namespaceURI must be xmlURI
        attr = doc.createAttributeNS('http://www.w3.org/2000/xmlns/', 'foo:a')

        attr.setPrefix('xmlns')
        attr = doc.createAttributeNS('http://nsa', 'foo:a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        # Special case for xmlns where no prefix can be set
        attr = doc.createAttributeNS('http://www.w3.org/2000/xmlns/', 'xmlns')

        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        # Also an attribute can not have a prefix with namespaceURI == null or ""
        attr = doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)
        attr = doc.createAttributeNS(None, 'a')
        with self.assertRaises(Xerces.PyDOMException) as e:
            attr.setPrefix('xmlns')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Only prefix of Element and Attribute can be changed
        with self.assertRaises(Xerces.PyDOMException) as e:
            doc.setPrefix('foo')
        self.assertEqual(e.exception.cause.code, Xerces.DOMException.NAMESPACE_ERR)

        # Prefix of readonly Attribute can not be changed.
        # However, there is no way to create such DOMAttribute for testing yet.

        # release the document, the documentType (dt) still has the owner, and thus no need to release
        doc.release()

    def test_getElementsByTagName(self):
        """getElementsByTagName*"""
        # Set up an initial (root element only) document.
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        doc = impl.createDocument('http://document.namespace', 'foo:docName', dt)
        rootEl = doc.getDocumentElement()

        #
        # Populate the document
        #
        ela = doc.createElementNS('http://nsa', 'a:ela')
        rootEl.appendChild(ela)

        elb = doc.createElementNS('http://nsb', 'elb')
        rootEl.appendChild(elb)

        elc = doc.createElementNS(Xerces.XMLUni.fgZeroLenString, 'elc')
        rootEl.appendChild(elc)

        eld = doc.createElementNS('http://nsa', 'd:ela')
        rootEl.appendChild(eld)

        ele = doc.createElementNS('http://nse', 'elb')
        rootEl.appendChild(ele)

        #
        # Access with DOM Level 1 getElementsByTagName
        #
        nl = doc.getElementsByTagName('a:ela')
        self.assertEqual(nl.getLength(), 1)
        self.assertEqual(nl.item(0), ela)

        nl = doc.getElementsByTagName('elb')
        self.assertEqual(nl.getLength(), 2)
        self.assertEqual(nl.item(0), elb)
        self.assertEqual(nl.item(1), ele)

        nl = doc.getElementsByTagName('d:ela')
        self.assertEqual(nl.getLength(), 1)
        self.assertEqual(nl.item(0), eld)

        #
        # Access with DOM Level 2 getElementsByTagNameNS
        #
        nl = doc.getElementsByTagNameNS(Xerces.XMLUni.fgZeroLenString, 'elc')
        self.assertEqual(nl.getLength(), 1)
        self.assertEqual(nl.item(0), elc)

        nl = doc.getElementsByTagNameNS(None, 'elc')
        self.assertEqual(nl.getLength(), 1)
        self.assertEqual(nl.item(0), elc)

        nl = doc.getElementsByTagNameNS('http://nsa', 'ela')
        self.assertEqual(nl.getLength(), 2)
        self.assertEqual(nl.item(0), ela)
        self.assertEqual(nl.item(1), eld)

        nl = doc.getElementsByTagNameNS(Xerces.XMLUni.fgZeroLenString, 'elb')
        self.assertEqual(nl.getLength(), 0)

        nl = doc.getElementsByTagNameNS('http://nsb', 'elb')
        self.assertEqual(nl.getLength(), 1)
        self.assertEqual(nl.item(0), elb)

        nl = doc.getElementsByTagNameNS('*', 'elb')
        self.assertEqual(nl.getLength(), 2)
        self.assertEqual(nl.item(0), elb)
        self.assertEqual(nl.item(1), ele)

        nl = doc.getElementsByTagNameNS('http://nsa', '*')
        self.assertEqual(nl.getLength(), 2)
        self.assertEqual(nl.item(0), ela)
        self.assertEqual(nl.item(1), eld)

        nl = doc.getElementsByTagNameNS('*', '*')
        self.assertEqual(nl.getLength(), 6)  # Gets the document root element, plus 5 more
        self.assertEqual(nl.item(6), None)
        #self.assertEqual(nl.item(-1), None)

        nl = rootEl.getElementsByTagNameNS('*', '*')
        self.assertEqual(nl.getLength(), 5)

        nl = rootEl.getElementsByTagNameNS('http://nsa', 'd:ela')
        self.assertEqual(nl.getLength(), 0)

        #
        # Node lists are Live
        #
        nl = doc.getElementsByTagNameNS('*', '*')
        nla = ela.getElementsByTagNameNS('*', '*')

        self.assertEqual(nl.getLength(), 6)
        self.assertEqual(nla.getLength(), 0)

        rem = rootEl.removeChild(elc)
        rem.release()
        self.assertEqual(nl.getLength(), 5)
        self.assertEqual(nla.getLength(), 0)

        ela.appendChild(elc)
        self.assertEqual(nl.getLength(), 6)
        self.assertEqual(nla.getLength(), 1)

        # release the document, the documentType (dt) still has the owner, and thus no need to release
        doc.release()

    def test_attributes_and_NamesNodeMaps(self):
        """Attributes and NamedNodeMaps."""
        # Set up an initial (root element only) document.
        impl = Xerces.DOMImplementationRegistry.getDOMImplementation('Core')

        dt = impl.createDocumentType('foo:docName', 'pubId', 'http://sysId')

        doc = impl.createDocument('http://document.namespace', 'foo:docName', dt)
        rootEl = doc.getDocumentElement()

        #
        # Create a set of attributes and hang them on the root element.
        #
        attra = doc.createAttributeNS('http://nsa', 'a:attra')
        rem = rootEl.setAttributeNodeNS(attra)
        if rem:
            rem.release()

        #
        # Check that the attribute nodes were created with the correct properties.
        #
        self.assertEqual(attra.getNodeName(), 'a:attra')
        self.assertEqual(attra.getNamespaceURI(), 'http://nsa')

        self.assertEqual(attra.getLocalName(), 'attra')
        self.assertEqual(attra.getName(), 'a:attra')
        self.assertEqual(attra.getNodeType(), Xerces.DOMNode.ATTRIBUTE_NODE)
        self.assertEqual(attra.getNodeValue(), None)

        self.assertEqual(attra.getPrefix(), 'a')
        self.assertTrue(attra.getSpecified())
        self.assertEqual(attra.getValue(), None)

        #
        # Create a set of attributes and hang them on the root element.
        #
        attrb = doc.createAttributeNS('http://nsb', 'attrb')
        rem = rootEl.setAttributeNodeNS(attrb)
        if rem:
            rem.release()

        attrc = doc.createAttributeNS(Xerces.XMLUni.fgZeroLenString, 'attrc')
        rem = rootEl.setAttributeNodeNS(attrc)
        if rem:
            rem.release()

        # this one will replace the attra
        attrd = doc.createAttributeNS('http://nsa', 'd:attra')
        rem = rootEl.setAttributeNodeNS(attrd)
        if rem:
            rem.release()

        attre = doc.createAttributeNS('http://nse', 'attrb')
        rem = rootEl.setAttributeNodeNS(attre)
        if rem:
            rem.release()

        # Test methods of NamedNodeMap
        nnm = rootEl.getAttributes()
        self.assertEqual(nnm.getLength(), 4)

        self.assertEqual(nnm.getNamedItemNS('http://nsa', 'attra'), attrd)
        self.assertEqual(nnm.getNamedItemNS('http://nsb', 'attrb'), attrb)
        self.assertEqual(nnm.getNamedItemNS(Xerces.XMLUni.fgZeroLenString, 'attra'), None)
        self.assertEqual(nnm.getNamedItemNS('http://nsa', 'attrb'), None)

        self.assertEqual(nnm.getNamedItemNS('http://nse', 'attrb'), attre)

        self.assertEqual(nnm.getNamedItemNS(Xerces.XMLUni.fgZeroLenString, 'attrc'), attrc)

        # Test hasAttributes, hasAttribute, hasAttributeNS
        self.assertFalse(doc.hasAttributes())
        self.assertFalse(attrc.hasAttributes())
        self.assertTrue(rootEl.hasAttributes())
        self.assertTrue(rootEl.hasAttribute('attrc'))

        self.assertFalse(rootEl.hasAttribute('wrong'))

        self.assertTrue(rootEl.hasAttributeNS('http://nsa', 'attra'))
        self.assertFalse(rootEl.hasAttributeNS('http://nsa', 'wrong'))

        # release the document, the documentType (dt) still has the owner, and thus no need to release
        doc.release()

class DOMReleaseTests(unittest.TestCase):
    """DOMReleaseTests    Test if the release() function"""

    def test_domReleaseTests(self):
        tempStr = 'status'
        tempStr2 = 'true'
        tempStr3 = 'root'

        # create document
        cpXMLDocument = Xerces.DOMImplementation.getImplementation().createDocument()
        # create root element
        cpRoot = cpXMLDocument.createElement(tempStr3)
        # create status attribute
        cpRoot.setAttribute(tempStr, tempStr2)
        pAttr = cpRoot.getAttributeNode(tempStr)

        # simulate setting the attribute value
        #    The setValue and setAttribute should call release internally so that
        #    the overall memory usage is not increased
        for i in range(20000):
            pAttr.setValue(tempStr2)
        for i in range(20000):
            # same problem
            cpRoot.removeAttribute(tempStr)
            cpRoot.setAttribute(tempStr, tempStr2)

        # simulate changing node value
        #    the overall memory usage is not increased
        for i in range(20000):
            tempchar = 'time is %d'%Xerces.XMLPlatformUtils.getCurrentMillis()
            pAttr.setNodeValue(tempchar)

        text = cpXMLDocument.createTextNode(tempStr3)
        for i in range(20000):
            tempchar = 'time is %d'%Xerces.XMLPlatformUtils.getCurrentMillis()
            text.setNodeValue(tempchar)

        cpXMLDocument.release()

