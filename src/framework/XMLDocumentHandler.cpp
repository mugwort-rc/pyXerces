/*
 * XMLDocumentHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLDocumentHandler.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLElementDecl.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLEntityDecl.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLDocumentHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLDocumentHandlerDefVisitor
: public boost::python::def_visitor<XMLDocumentHandlerDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("docCharacters", &XMLDocumentHandlerDefVisitor::docCharacters)
	.def("docComment", &XMLDocumentHandlerDefVisitor::docComment)
	.def("docPI", &XMLDocumentHandlerDefVisitor::docPI)
	.def("endElement", &XMLDocumentHandlerDefVisitor::endElement)
	.def("ignorableWhitespace", &XMLDocumentHandlerDefVisitor::ignorableWhitespace)
	.def("startElement", &XMLDocumentHandlerDefVisitor::startElement)
	.def("XMLDecl", &XMLDocumentHandlerDefVisitor::XMLDecl)
	;
}

static void docCharacters(xercesc::XMLDocumentHandler& self, const STR& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.docCharacters(buff.ptr(), buff.size(), cdataSection);
}

static void docComment(xercesc::XMLDocumentHandler& self, const STR& comment) {
	XMLString buff(comment);
	self.docComment(buff.ptr());
}

static void docPI(xercesc::XMLDocumentHandler& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.docPI(buff1.ptr(), buff2.ptr());
}

static void endElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const STR& prefixName) {
	XMLString buff(prefixName);
	self.endElement(elemDecl, uriId, isRoot, buff.ptr());
}

static void ignorableWhitespace(xercesc::XMLDocumentHandler& self, const XMLString& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size(), cdataSection);
}

static void startElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const STR& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	self.startElement(elemDecl, uriId, buff.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::XMLDocumentHandler& self, const STR& versionStr, const STR& encodingStr, const STR& standaloneStr, const STR& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	self.XMLDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

};

void XMLDocumentHandler_init(void) {
	//! xercesc::XMLDocumentHandler
	boost::python::class_<xercesc::XMLDocumentHandler, boost::noncopyable>("XMLDocumentHandler", boost::python::no_init)
			.def(XMLDocumentHandlerDefVisitor<XMLString>())
			.def(XMLDocumentHandlerDefVisitor<std::string>())
			.def("docCharacters", &xercesc::XMLDocumentHandler::docCharacters)
			.def("docComment", &xercesc::XMLDocumentHandler::docComment)
			.def("docPI", &xercesc::XMLDocumentHandler::docPI)
			.def("endDocument", &xercesc::XMLDocumentHandler::endDocument)
			.def("endElement", &xercesc::XMLDocumentHandler::endElement)
			.def("endEntityReference", &xercesc::XMLDocumentHandler::endEntityReference)
			.def("ignorableWhitespace", &xercesc::XMLDocumentHandler::ignorableWhitespace)
			.def("resetDocument", &xercesc::XMLDocumentHandler::resetDocument)
			.def("startDocument", &xercesc::XMLDocumentHandler::startDocument)
			.def("startElement", &xercesc::XMLDocumentHandler::startElement)
			.def("startEntityReference", &xercesc::XMLDocumentHandler::startEntityReference)
			.def("XMLDecl", &xercesc::XMLDocumentHandler::XMLDecl)
			;
}

} /* namespace pyxerces */
