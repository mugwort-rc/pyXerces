/*
 * DOMLSParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSParser.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/dom/DOMLSInput.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMDocument.hpp>

#include <xercesc/dom/DOMLSParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMLSParserDefVisitor
: public boost::python::def_visitor<DOMLSParserDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getGrammar", &DOMLSParserDefVisitor::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::Grammar* getGrammar(xercesc::DOMLSParser& self, const XMLString& nameSpaceKey) {
	return self.getGrammar(nameSpaceKey.ptr());
}

};

class DOMLSParserWrapper
: public xercesc::DOMLSParser, public boost::python::wrapper<xercesc::DOMLSParser>
{
public:
xercesc::DOMConfiguration* getDomConfig() {
	return this->get_override("getDomConfig")();
}

const xercesc::DOMLSParserFilter* getFilter() const {
	return this->get_override("getFilter")();
}

bool getAsync() const {
	return this->get_override("getAsync")();
}

bool getBusy() const {
	return this->get_override("getBusy")();
}

void setFilter(xercesc::DOMLSParserFilter* const filter) {
	this->get_override("setFilter")(boost::python::ptr(filter));
}

xercesc::DOMDocument* parse(const xercesc::DOMLSInput* source) {
	return this->get_override("parse")(boost::python::ptr(source));
}

xercesc::DOMDocument* parseURI(const XMLCh* const uri) {
	return this->get_override("parseURI")(XMLString(uri));
}

xercesc::DOMDocument* parseURI(const char* const uri) {
	return this->get_override("parseURI")(uri);
}

xercesc::DOMNode* parseWithContext(const xercesc::DOMLSInput* source, xercesc::DOMNode* contextNode, const ActionType action) {
	return this->get_override("parseWithContext")(boost::python::ptr(source), boost::python::ptr(contextNode), action);
}

void abort() {
	this->get_override("abort")();
}

void release() {
	this->get_override("release")();
}

void resetDocumentPool() {
	this->get_override("resetDocumentPool")();
}

xercesc::Grammar* loadGrammar(const xercesc::DOMLSInput* source, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(boost::python::ptr(source), grammarType, toCache);
}

xercesc::Grammar* loadGrammar(const XMLCh* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(XMLString(systemId), grammarType, toCache);
}

xercesc::Grammar* loadGrammar(const char* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(systemId, grammarType, toCache);
}

xercesc::Grammar* getGrammar(const XMLCh* const nameSpaceKey) const {
	return this->get_override("getGrammar")(XMLString(nameSpaceKey));
}

xercesc::Grammar* getRootGrammar() const {
	return this->get_override("getRootGrammar")();
}

const XMLCh* getURIText(unsigned int uriId) const {
	return this->get_override("getURIText")(uriId);
}

void resetCachedGrammarPool() {
	this->get_override("resetCachedGrammarPool")();
}

XMLFilePos getSrcOffset() const {
	return this->get_override("getSrcOffset")();
}

};

//! DOMLSParser
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMLSParserLoadGrammarOverloads, loadGrammar, 2, 3)

void DOMLSParser_init(void) {
	//! xercesc::DOMLSParser
	auto DOMLSParser = boost::python::class_<DOMLSParserWrapper, boost::noncopyable>("DOMLSParser")
			.def(DOMLSParserDefVisitor())
			.def("getDomConfig", boost::python::pure_virtual(&xercesc::DOMLSParser::getDomConfig), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFilter", boost::python::pure_virtual(&xercesc::DOMLSParser::getFilter), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAsync", boost::python::pure_virtual(&xercesc::DOMLSParser::getAsync))
			.def("getBusy", boost::python::pure_virtual(&xercesc::DOMLSParser::getBusy))
			.def("setFilter", boost::python::pure_virtual(&xercesc::DOMLSParser::setFilter))
			.def("parse", boost::python::pure_virtual(&xercesc::DOMLSParser::parse), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseURI", boost::python::pure_virtual(static_cast<xercesc::DOMDocument*(xercesc::DOMLSParser::*)(const XMLCh* const)>(&xercesc::DOMLSParser::parseURI)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseURI", boost::python::pure_virtual(static_cast<xercesc::DOMDocument*(xercesc::DOMLSParser::*)(const char* const)>(&xercesc::DOMLSParser::parseURI)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseWithContext", boost::python::pure_virtual(&xercesc::DOMLSParser::parseWithContext), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("abort", boost::python::pure_virtual(&xercesc::DOMLSParser::abort))
			.def("release", boost::python::pure_virtual(&xercesc::DOMLSParser::release))
			.def("resetDocumentPool", boost::python::pure_virtual(&xercesc::DOMLSParser::resetDocumentPool))
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const xercesc::DOMLSInput*, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const XMLCh* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const char* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getGrammar", boost::python::pure_virtual(&xercesc::DOMLSParser::getGrammar), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getRootGrammar", boost::python::pure_virtual(&xercesc::DOMLSParser::getRootGrammar), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getURIText", boost::python::pure_virtual(&xercesc::DOMLSParser::getURIText), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("resetCachedGrammarPool", boost::python::pure_virtual(&xercesc::DOMLSParser::resetCachedGrammarPool))
			.def("getSrcOffset", boost::python::pure_virtual(&xercesc::DOMLSParser::getSrcOffset))
			;
	boost::python::scope DOMLSParserScope = DOMLSParser;
	//! xercesc::DOMLSParser::ActionType
	boost::python::enum_<xercesc::DOMLSParser::ActionType>("ActionType")
			.value("ACTION_APPEND_AS_CHILDREN", xercesc::DOMLSParser::ACTION_APPEND_AS_CHILDREN)
			.value("ACTION_REPLACE_CHILDREN", xercesc::DOMLSParser::ACTION_REPLACE_CHILDREN)
			.value("ACTION_INSERT_BEFORE", xercesc::DOMLSParser::ACTION_INSERT_BEFORE)
			.value("ACTION_INSERT_AFTER", xercesc::DOMLSParser::ACTION_INSERT_AFTER)
			.value("ACTION_REPLACE", xercesc::DOMLSParser::ACTION_REPLACE)
			.export_values()
			;
}

} /* namespace pyxerces */
