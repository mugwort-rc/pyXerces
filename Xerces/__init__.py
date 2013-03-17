# -*- coding: utf-8 -*-

from __Xerces import *

# Initialize Xerces
try:
    XMLPlatformUtils.Initialize()
except XMLException, toCatch:
    print 'Error during Xerces-c Initialization.'
    print '  Exception message:%s'%toCatch.getMessage()
        
XMLPlatformUtils.Initialize()

# DOMImplementationImpl
g1_0   = XMLString('1.0')
g2_0   = XMLString('2.0')
g3_0   = XMLString('3.0')
gTrav  = XMLString('Traversal')
gCore  = XMLString('Core')
gRange = XMLString('Range')
gLS    = XMLString('LS')
gXPath = XMLString('XPath')

# util
StringList             = RefArrayVectorOfXMLCh
ValueVectorOfXMLSize_t = ValueVectorOfUnsignedInt

class RefVectorOfPyObject(BaseRefVectorOfPyObject):
    def __init__(self, maxElems, manager = XMLPlatformUtils.fgMemoryManager):
        BaseRefVectorOfPyObject.__init__(self, maxElems, manager)
        
        self.buffer = []
    
    def addElement(self, toAdd):
        self.buffer.append(toAdd)
        BaseRefVectorOfPyObject.addElement(self, toAdd)

def tostring(node):
    impl = DOMImplementationRegistry.getDOMImplementation(gLS.ptr())
    serializer = impl.createLSSerializer()
    serializer.getDomConfig().setParameter(XMLUni.fgDOMXMLDeclaration.ptr(), False)
    return str(XMLString(serializer.writeToString(node)))

