/*
 * DOMLSParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSParser.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSInput.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMNode.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMDocument.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMLSParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! DOMLSParser
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMLSParserLoadGrammarOverloads, loadGrammar, 2, 3)

template <class STR>
class DOMLSParserDefVisitor
: public boost::python::def_visitor<DOMLSParserDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getGrammar", &DOMLSParserDefVisitor::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::Grammar* getGrammar(xercesc::DOMLSParser& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.getGrammar(buff.ptr());
}

};

void DOMLSParser_init(void) {
	//! xercesc::DOMLSParser
	auto DOMLSParser = boost::python::class_<xercesc::DOMLSParser, boost::noncopyable>("DOMLSParser", boost::python::no_init)
			.def(DOMLSParserDefVisitor<XMLString>())
			.def(DOMLSParserDefVisitor<std::string>())
			.def("getDomConfig", &xercesc::DOMLSParser::getDomConfig, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFilter", &xercesc::DOMLSParser::getFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAsync", &xercesc::DOMLSParser::getAsync)
			.def("getBusy", &xercesc::DOMLSParser::getBusy)
			.def("setFilter", &xercesc::DOMLSParser::setFilter)
			.def("parse", &xercesc::DOMLSParser::parse, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseURI", static_cast<xercesc::DOMDocument*(xercesc::DOMLSParser::*)(const XMLCh* const)>(&xercesc::DOMLSParser::parseURI), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseURI", static_cast<xercesc::DOMDocument*(xercesc::DOMLSParser::*)(const char* const)>(&xercesc::DOMLSParser::parseURI), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parseWithContext", &xercesc::DOMLSParser::parseWithContext, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("abort", &xercesc::DOMLSParser::abort)
			.def("release", &xercesc::DOMLSParser::release)
			.def("resetDocumentPool", &xercesc::DOMLSParser::resetDocumentPool)
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const xercesc::DOMLSInput*, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar), DOMLSParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const XMLCh* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar), DOMLSParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::DOMLSParser::*)(const char* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::DOMLSParser::loadGrammar), DOMLSParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("getGrammar", &xercesc::DOMLSParser::getGrammar, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getRootGrammar", &xercesc::DOMLSParser::getRootGrammar, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getURIText", &xercesc::DOMLSParser::getURIText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("resetCachedGrammarPool", &xercesc::DOMLSParser::resetCachedGrammarPool)
			.def("getSrcOffset", &xercesc::DOMLSParser::getSrcOffset)
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
