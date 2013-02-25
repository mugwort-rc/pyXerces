# -*- coding: utf-8 -*-

from __Xerces import *
from XercesDOMParser import XercesDOMParser

# Initialize Xerces
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

def tostring(node):
    impl = DOMImplementationRegistry.getDOMImplementation(gLS.ptr())
    serializer = impl.createLSSerializer()
    serializer.getDomConfig().setParameter(XMLUni.fgDOMXMLDeclaration.ptr(), False)
    return str(XMLString(serializer.writeToString(node)))

