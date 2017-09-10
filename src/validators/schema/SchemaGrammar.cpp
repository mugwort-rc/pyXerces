/*
 * SchemaGrammar.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "SchemaGrammar.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/schema/ComplexTypeInfo.hpp>
#include <xercesc/validators/schema/XercesGroupInfo.hpp>
#include <xercesc/validators/schema/XercesAttGroupInfo.hpp>
#include <xercesc/framework/psvi/XSAnnotation.hpp>

#include <xercesc/validators/schema/SchemaGrammar.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

class SchemaGrammarDefVisitor
: public boost::python::def_visitor<SchemaGrammarDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findOrAddElemDecl", &SchemaGrammarDefVisitor::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElemId", &SchemaGrammarDefVisitor::getElemId)
	.def("getElemDecl", &SchemaGrammarDefVisitor::getElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDecl", &SchemaGrammarDefVisitor::getNotationDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::SchemaGrammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int, const bool)>(&SchemaGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::SchemaGrammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int)>(&SchemaGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLElementDecl* findOrAddElemDecl(xercesc::SchemaGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, bool& wasAdded) {
	return self.findOrAddElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, wasAdded);
}

static XMLSize_t getElemId(xercesc::SchemaGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemId(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLElementDecl* getElemDecl(xercesc::SchemaGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemDecl(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLNotationDecl* getNotationDecl(xercesc::SchemaGrammar& self, const XMLString& notName) {
	return self.getNotationDecl(notName.ptr());
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::SchemaGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, const bool notDeclared) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, notDeclared);
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::SchemaGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, false);
}

};

//! DTDGrammar
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SchemaGrammarPutElemDeclOverloads, putElemDecl, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SchemaGrammarPutElemDeclMiniOverloads, putElemDecl, 1, 2)

void SchemaGrammar_init(void) {
	//! xercesc::SchemaGrammar
	boost::python::class_<xercesc::SchemaGrammar, boost::noncopyable, boost::python::bases<xercesc::Grammar> >("SchemaGrammar", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(SchemaGrammarDefVisitor())
			.def("getGrammarType", &xercesc::SchemaGrammar::getGrammarType)
			.def("getTargetNamespace", &xercesc::SchemaGrammar::getTargetNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("findOrAddElemDecl", &xercesc::SchemaGrammar::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemId", &xercesc::SchemaGrammar::getElemId)
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::SchemaGrammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, unsigned int)>(&xercesc::SchemaGrammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::SchemaGrammar::*)(const unsigned int)>(&xercesc::SchemaGrammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLNotationDecl*(xercesc::SchemaGrammar::*)(const XMLCh* const)>(&xercesc::SchemaGrammar::getNotationDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getValidated", &xercesc::SchemaGrammar::getValidated)
			.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::SchemaGrammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, unsigned int, const bool)>(&xercesc::SchemaGrammar::putElemDecl), SchemaGrammarPutElemDeclOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("putElemDecl", static_cast<XMLSize_t(xercesc::SchemaGrammar::*)(xercesc::XMLElementDecl* const, const bool)>(&xercesc::SchemaGrammar::putElemDecl), SchemaGrammarPutElemDeclMiniOverloads())
			.def("putNotationDecl", &xercesc::SchemaGrammar::putNotationDecl)
			.def("setValidated", &xercesc::SchemaGrammar::setValidated)
			.def("reset", &xercesc::SchemaGrammar::reset)
			.def("getElemEnumerator", &xercesc::SchemaGrammar::getElemEnumerator)
			.def("getNotationEnumerator", &xercesc::SchemaGrammar::getNotationEnumerator)
			.def("getAttributeDeclRegistry", &xercesc::SchemaGrammar::getAttributeDeclRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getComplexTypeRegistry", &xercesc::SchemaGrammar::getComplexTypeRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getGroupInfoRegistry", &xercesc::SchemaGrammar::getGroupInfoRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttGroupInfoRegistry", &xercesc::SchemaGrammar::getAttGroupInfoRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDatatypeRegistry", &xercesc::SchemaGrammar::getDatatypeRegistry, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getValidSubstitutionGroups", &xercesc::SchemaGrammar::getValidSubstitutionGroups, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setTargetNamespace", &xercesc::SchemaGrammar::setTargetNamespace)
			.def("setAttributeDeclRegistry", &xercesc::SchemaGrammar::setAttributeDeclRegistry)
			.def("setComplexTypeRegistry", &xercesc::SchemaGrammar::setComplexTypeRegistry)
			.def("setGroupInfoRegistry", &xercesc::SchemaGrammar::setGroupInfoRegistry)
			.def("setAttGroupInfoRegistry", &xercesc::SchemaGrammar::setAttGroupInfoRegistry)
			.def("setValidSubstitutionGroups", &xercesc::SchemaGrammar::setValidSubstitutionGroups)
			.def("putGroupElemDecl", &xercesc::SchemaGrammar::putGroupElemDecl)
			.def("putAnnotation", &xercesc::SchemaGrammar::putAnnotation)
			.def("addAnnotation", &xercesc::SchemaGrammar::addAnnotation)
			.def("getAnnotation", static_cast<xercesc::XSAnnotation*(xercesc::SchemaGrammar::*)(const void* const)>(&xercesc::SchemaGrammar::getAnnotation), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotation", static_cast<xercesc::XSAnnotation*(xercesc::SchemaGrammar::*)()>(&xercesc::SchemaGrammar::getAnnotation), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAnnotations", static_cast<xercesc::RefHashTableOf<xercesc::XSAnnotation, xercesc::PtrHasher>*(xercesc::SchemaGrammar::*)()>(&xercesc::SchemaGrammar::getAnnotations), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getScopeCount", &xercesc::SchemaGrammar::getScopeCount)
			.def("setScopeCount", &xercesc::SchemaGrammar::setScopeCount)
			.def("getAnonTypeCount", &xercesc::SchemaGrammar::getAnonTypeCount)
			.def("setAnonTypeCount", &xercesc::SchemaGrammar::setAnonTypeCount)
			.def("setGrammarDescription", &xercesc::SchemaGrammar::setGrammarDescription)
			.def("getGrammarDescription", &xercesc::SchemaGrammar::getGrammarDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(SchemaGrammar)
			;
}

} /* namespace pyxerces */
