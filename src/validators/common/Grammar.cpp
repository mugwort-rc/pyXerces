/*
 * Grammar.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include "Grammar.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLGrammarDescription.hpp>	//!< for forward declaration
#include <xercesc/validators/common/Grammar.hpp>

namespace pyxerces {

//! XercesDOMParser
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(GrammarPutElemDeclOverloads, putElemDecl, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(GrammarPutElemDeclMiniOverloads, putElemDecl, 1, 2)

void Grammar_init(void) {
	//! xercesc::Grammar
	auto Grammar = boost::python::class_<xercesc::Grammar, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("Grammar", boost::python::no_init)
			.def("getGrammarType", &xercesc::Grammar::getGrammarType)
			.def("getTargetNamespace", &xercesc::Grammar::getTargetNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValidated", &xercesc::Grammar::getValidated)
			.def("findOrAddElemDecl", &xercesc::Grammar::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemId", &xercesc::Grammar::getElemId)
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, unsigned int)>(&xercesc::Grammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int)>(&xercesc::Grammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLNotationDecl*(xercesc::Grammar::*)(const XMLCh* const)>(&xercesc::Grammar::getNotationDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, unsigned int, const bool)>(&xercesc::Grammar::putElemDecl), GrammarPutElemDeclOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("putElemDecl", static_cast<XMLSize_t(xercesc::Grammar::*)(xercesc::XMLElementDecl* const, const bool)>(&xercesc::Grammar::putElemDecl), GrammarPutElemDeclMiniOverloads())
			.def("putNotationDecl", &xercesc::Grammar::putNotationDecl)
			.def("setValidated", &xercesc::Grammar::setValidated)
			.def("reset", &xercesc::Grammar::reset)
			.def("setGrammarDescription", &xercesc::Grammar::setGrammarDescription)
			.def("getGrammarDescription", &xercesc::Grammar::getGrammarDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isSerializable", &xercesc::Grammar::isSerializable)
			.def("getProtoType", &xercesc::Grammar::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serialize", &xercesc::Grammar::serialize)
			.def("storeGrammar", &xercesc::Grammar::storeGrammar)
			.def("loadGrammar", &xercesc::Grammar::loadGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("storeGrammar")
			.staticmethod("loadGrammar")
			;
	boost::python::scope GrammarScope = Grammar;
	//! xercesc::Grammar::GrammarType
	boost::python::enum_<xercesc::Grammar::GrammarType>("GrammarType")
			.value("DTDGrammarType", xercesc::Grammar::DTDGrammarType)
			.value("SchemaGrammarType", xercesc::Grammar::SchemaGrammarType)
			.value("UnKnown", xercesc::Grammar::UnKnown)
			;
}

} /* namespace pyxerces */
