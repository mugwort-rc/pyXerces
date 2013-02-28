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

#include "../../util/XMLString.h"

namespace pyxerces {

//! XercesDOMParser
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(GrammarPutElemDeclOverloads, putElemDecl, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(GrammarPutElemDeclMiniOverloads, putElemDecl, 1, 2)

template <class STR>
class GrammarDefVisitor
: public boost::python::def_visitor<GrammarDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findOrAddElemDecl", &GrammarDefVisitor::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElemId", &GrammarDefVisitor::getElemId)
	.def("getElemDecl", &GrammarDefVisitor::getElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDecl", &GrammarDefVisitor::getNotationDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::Grammar&, const unsigned int, const STR&, const STR&, const STR&, unsigned int, const bool)>(&GrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::Grammar&, const unsigned int, const STR&, const STR&, const STR&, unsigned int)>(&GrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLElementDecl* findOrAddElemDecl(xercesc::Grammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope, bool& wasAdded) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.findOrAddElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, wasAdded);
}

static XMLSize_t getElemId(xercesc::Grammar& self, const unsigned int uriId, const STR& baseName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(qName);
	return self.getElemId(uriId, buff1.ptr(), buff2.ptr(), scope);
}

static xercesc::XMLElementDecl* getElemDecl(xercesc::Grammar& self, const unsigned int uriId, const STR& baseName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(qName);
	return self.getElemDecl(uriId, buff1.ptr(), buff2.ptr(), scope);
}

static xercesc::XMLNotationDecl* getNotationDecl(xercesc::Grammar& self, const STR& notName) {
	XMLString buff(notName);
	return self.getNotationDecl(buff.ptr());
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::Grammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope, const bool notDeclared) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.putElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, notDeclared);
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::Grammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.putElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, false);
}

};

void Grammar_init(void) {
	//! xercesc::Grammar
	auto Grammar = boost::python::class_<xercesc::Grammar, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("Grammar", boost::python::no_init)
			.def(GrammarDefVisitor<XMLString>())
			.def(GrammarDefVisitor<std::string>())
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
