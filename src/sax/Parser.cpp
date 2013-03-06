/*
 * Parser.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "Parser.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/DTDHandler.hpp>
#include <xercesc/sax/EntityResolver.hpp>
#include <xercesc/sax/DocumentHandler.hpp>
#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/sax/InputSource.hpp>

#include <xercesc/sax/Parser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! ParserDefVisitor (for XMLString)
class ParserDefVisitor
: public boost::python::def_visitor<ParserDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("parse", &ParserDefVisitor::parse)
	;
}

static void parse(xercesc::Parser& self, const XMLString& systemId) {
	self.parse(systemId.ptr());
}
};

class ParserWrapper
: public xercesc::Parser, public boost::python::wrapper<xercesc::Parser>
{
public:
ParserWrapper()
: xercesc::Parser()
{}

~ParserWrapper()
{}

void setEntityResolver(xercesc::EntityResolver* const resolver) {
	this->get_override("setEntityResolver")(resolver);
}

void setDTDHandler(xercesc::DTDHandler* const handler) {
	this->get_override("setDTDHandler")(handler);
}

void setDocumentHandler(xercesc::DocumentHandler* const handler) {
	this->get_override("setDocumentHandler")(handler);
}

void setErrorHandler(xercesc::ErrorHandler* const handler) {
	this->get_override("setErrorHandler")(handler);
}

void parse(const xercesc::InputSource& source) {
	this->get_override("parse")(source);
}

void parse(const XMLCh* const systemId) {
	this->get_override("parse")(systemId);
}

void parse(const char* const systemId) {
	this->get_override("parse")(systemId);
}

};

void Parser_init(void) {
	//! xercesc::Parser
	boost::python::class_<ParserWrapper, boost::noncopyable>("Parser")
			.def(ParserDefVisitor())
			.def("setEntityResolver", &xercesc::Parser::setEntityResolver)
			.def("setDTDHandler", &xercesc::Parser::setDTDHandler)
			.def("setDocumentHandler", &xercesc::Parser::setDocumentHandler)
			.def("setErrorHandler", &xercesc::Parser::setErrorHandler)
			.def("parse", static_cast<void(xercesc::Parser::*)(const xercesc::InputSource&)>(&xercesc::Parser::parse))
			.def("parse", static_cast<void(xercesc::Parser::*)(const XMLCh* const)>(&xercesc::Parser::parse))
			.def("parse", static_cast<void(xercesc::Parser::*)(const char* const)>(&xercesc::Parser::parse))
			;
}

} /* namespace pyxerces */
