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

class XMLDocumentHandlerDefVisitor
: public boost::python::def_visitor<XMLDocumentHandlerDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("docCharacters", static_cast<void(*)(xercesc::XMLDocumentHandler&, const XMLString&, const bool)>(&XMLDocumentHandlerDefVisitor::docCharacters))
	.def("docCharacters", static_cast<void(*)(xercesc::XMLDocumentHandler&, const std::string&, const bool)>(&XMLDocumentHandlerDefVisitor::docCharacters))
	.def("docComment", static_cast<void(*)(xercesc::XMLDocumentHandler&, const XMLString&)>(&XMLDocumentHandlerDefVisitor::docComment))
	.def("docComment", static_cast<void(*)(xercesc::XMLDocumentHandler&, const std::string&)>(&XMLDocumentHandlerDefVisitor::docComment))
	.def("docPI", static_cast<void(*)(xercesc::XMLDocumentHandler&, const XMLString&, const XMLString&)>(&XMLDocumentHandlerDefVisitor::docPI))
	.def("docPI", static_cast<void(*)(xercesc::XMLDocumentHandler&, const std::string&, const std::string&)>(&XMLDocumentHandlerDefVisitor::docPI))
	.def("endElement", static_cast<void(*)(xercesc::XMLDocumentHandler&, const xercesc::XMLElementDecl&, const unsigned int, const bool, const XMLString&)>(&XMLDocumentHandlerDefVisitor::endElement))
	.def("endElement", static_cast<void(*)(xercesc::XMLDocumentHandler&, const xercesc::XMLElementDecl&, const unsigned int, const bool, const std::string&)>(&XMLDocumentHandlerDefVisitor::endElement))
	.def("ignorableWhitespace", static_cast<void(*)(xercesc::XMLDocumentHandler&, const XMLString&, const bool)>(&XMLDocumentHandlerDefVisitor::ignorableWhitespace))
	.def("ignorableWhitespace", static_cast<void(*)(xercesc::XMLDocumentHandler&, const std::string&, const bool)>(&XMLDocumentHandlerDefVisitor::ignorableWhitespace))
	.def("startElement", static_cast<void(*)(xercesc::XMLDocumentHandler&, const xercesc::XMLElementDecl&, const unsigned int, const XMLString&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, const bool, const bool)>(&XMLDocumentHandlerDefVisitor::startElement))
	.def("startElement", static_cast<void(*)(xercesc::XMLDocumentHandler&, const xercesc::XMLElementDecl&, const unsigned int, const std::string&, const xercesc::RefVectorOf<xercesc::XMLAttr>&, const XMLSize_t, const bool, const bool)>(&XMLDocumentHandlerDefVisitor::startElement))
	.def("XMLDecl", static_cast<void(*)(xercesc::XMLDocumentHandler&, const XMLString&, const XMLString&, const XMLString&, const XMLString&)>(&XMLDocumentHandlerDefVisitor::XMLDecl))
	.def("XMLDecl", static_cast<void(*)(xercesc::XMLDocumentHandler&, const std::string&, const std::string&, const std::string&, const std::string&)>(&XMLDocumentHandlerDefVisitor::XMLDecl))
	;
}

static void docCharacters(xercesc::XMLDocumentHandler& self, const XMLString& chars, const bool cdataSection) {
	self.docCharacters(chars.ptr(), chars.size(), cdataSection);
}

static void docCharacters(xercesc::XMLDocumentHandler& self, const std::string& chars, const bool cdataSection) {
	XMLString buff(chars);
	XMLDocumentHandlerDefVisitor::docCharacters(self, buff, cdataSection);
}

static void docComment(xercesc::XMLDocumentHandler& self, const XMLString& comment) {
	self.docComment(comment.ptr());
}

static void docComment(xercesc::XMLDocumentHandler& self, const std::string& comment) {
	XMLString buff(comment);
	XMLDocumentHandlerDefVisitor::docComment(self, buff);
}

static void docPI(xercesc::XMLDocumentHandler& self, const XMLString& target, const XMLString& data) {
	self.docPI(target.ptr(), data.ptr());
}

static void docPI(xercesc::XMLDocumentHandler& self, const std::string& target, const std::string& data) {
	XMLString buff1(target), buff2(data);
	XMLDocumentHandlerDefVisitor::docPI(self, buff1, buff2);
}

static void endElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const XMLString& prefixName) {
	self.endElement(elemDecl, uriId, isRoot, prefixName.ptr());
}

static void endElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const std::string& prefixName) {
	XMLString buff(prefixName);
	XMLDocumentHandlerDefVisitor::endElement(self, elemDecl, uriId, isRoot, buff);
}

static void ignorableWhitespace(xercesc::XMLDocumentHandler& self, const XMLString& chars, const bool cdataSection) {
	self.ignorableWhitespace(chars.ptr(), chars.size(), cdataSection);
}

static void ignorableWhitespace(xercesc::XMLDocumentHandler& self, const std::string& chars, const bool cdataSection) {
	XMLString buff(chars);
	XMLDocumentHandlerDefVisitor::ignorableWhitespace(self, buff, cdataSection);
}

static void startElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const XMLString& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	self.startElement(elemDecl, uriId, prefixName.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void startElement(xercesc::XMLDocumentHandler& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const std::string& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	XMLDocumentHandlerDefVisitor::startElement(self, elemDecl, uriId, buff, attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::XMLDocumentHandler& self, const XMLString& versionStr, const XMLString& encodingStr, const XMLString& standaloneStr, const XMLString& autoEncodingStr) {
	self.XMLDecl(versionStr.ptr(), encodingStr.ptr(), standaloneStr.ptr(), autoEncodingStr.ptr());
}

static void XMLDecl(xercesc::XMLDocumentHandler& self, const std::string& versionStr, const std::string& encodingStr, const std::string& standaloneStr, const std::string& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	XMLDocumentHandlerDefVisitor::XMLDecl(self, buff1, buff2, buff3, buff4);
}

};

void XMLDocumentHandler_init(void) {
	//! xercesc::XMLDocumentHandler
	boost::python::class_<xercesc::XMLDocumentHandler, boost::noncopyable>("XMLDocumentHandler", boost::python::no_init)
			.def(XMLDocumentHandlerDefVisitor())
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
