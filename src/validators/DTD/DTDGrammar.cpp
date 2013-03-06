/*
 * DTDGrammar.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "DTDGrammar.h"

#include <boost/python.hpp>
#include <xercesc/validators/DTD/DTDGrammar.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

//! DTDGrammar
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DTDGrammarPutElemDeclOverloads, putElemDecl, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DTDGrammarPutElemDeclMiniOverloads, putElemDecl, 1, 2)

template <class STR>
class DTDGrammarDefVisitor
: public boost::python::def_visitor<DTDGrammarDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findOrAddElemDecl", &DTDGrammarDefVisitor::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElemId", &DTDGrammarDefVisitor::getElemId)
	.def("getElemDecl", &DTDGrammarDefVisitor::getElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDecl", &DTDGrammarDefVisitor::getNotationDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::DTDGrammar&, const unsigned int, const STR&, const STR&, const STR&, unsigned int, const bool)>(&DTDGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::DTDGrammar&, const unsigned int, const STR&, const STR&, const STR&, unsigned int)>(&DTDGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getEntityDecl", &DTDGrammarDefVisitor::getEntityDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLElementDecl* findOrAddElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope, bool& wasAdded) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.findOrAddElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, wasAdded);
}

static XMLSize_t getElemId(xercesc::DTDGrammar& self, const unsigned int uriId, const STR& baseName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(qName);
	return self.getElemId(uriId, buff1.ptr(), buff2.ptr(), scope);
}

static xercesc::XMLElementDecl* getElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const STR& baseName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(qName);
	return self.getElemDecl(uriId, buff1.ptr(), buff2.ptr(), scope);
}

static xercesc::XMLNotationDecl* getNotationDecl(xercesc::DTDGrammar& self, const STR& notName) {
	XMLString buff(notName);
	return self.getNotationDecl(buff.ptr());
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope, const bool notDeclared) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.putElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, notDeclared);
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const STR& baseName, const STR& prefixName, const STR& qName, unsigned int scope) {
	XMLString buff1(baseName), buff2(prefixName), buff3(qName);
	return self.putElemDecl(uriId, buff1.ptr(), buff2.ptr(), buff3.ptr(), scope, false);
}

static xercesc::DTDEntityDecl* getEntityDecl(xercesc::DTDGrammar& self, const STR& entName) {
	XMLString buff(entName);
	return self.getEntityDecl(buff.ptr());
}

};

void DTDGrammar_init(void) {
	//! xercesc::DTDGrammar
	boost::python::class_<xercesc::DTDGrammar, boost::noncopyable, boost::python::bases<xercesc::Grammar> >("DTDGrammar", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getGrammarType", &xercesc::DTDGrammar::getGrammarType)
			.def("getTargetNamespace", &xercesc::DTDGrammar::getTargetNamespace, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("findOrAddElemDecl", &xercesc::DTDGrammar::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemId", &xercesc::DTDGrammar::getElemId)
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::DTDGrammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, unsigned int)>(&xercesc::DTDGrammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::DTDGrammar::*)(const unsigned int)>(&xercesc::DTDGrammar::getElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", static_cast<xercesc::XMLNotationDecl*(xercesc::DTDGrammar::*)(const XMLCh* const)>(&xercesc::DTDGrammar::getNotationDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getValidated", &xercesc::DTDGrammar::getValidated)
			.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(xercesc::DTDGrammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, unsigned int, const bool)>(&xercesc::DTDGrammar::putElemDecl), DTDGrammarPutElemDeclOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("putElemDecl", static_cast<XMLSize_t(xercesc::DTDGrammar::*)(xercesc::XMLElementDecl* const, const bool)>(&xercesc::DTDGrammar::putElemDecl), DTDGrammarPutElemDeclMiniOverloads())
			.def("putNotationDecl", &xercesc::DTDGrammar::putNotationDecl)
			.def("setValidated", &xercesc::DTDGrammar::setValidated)
			.def("reset", &xercesc::DTDGrammar::reset)
			.def("getEntityDecl", static_cast<xercesc::DTDEntityDecl*(xercesc::DTDGrammar::*)(const XMLCh* const)>(&xercesc::DTDGrammar::getEntityDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEntityDeclPool", static_cast<xercesc::NameIdPool<xercesc::DTDEntityDecl>*(xercesc::DTDGrammar::*)(void)>(&xercesc::DTDGrammar::getEntityDeclPool), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemEnumerator", &xercesc::DTDGrammar::getElemEnumerator)
			.def("getEntityEnumerator", &xercesc::DTDGrammar::getEntityEnumerator)
			.def("getNotationEnumerator", &xercesc::DTDGrammar::getNotationEnumerator)
			.def("setGrammarDescription", &xercesc::DTDGrammar::setGrammarDescription)
			.def("getGrammarDescription", &xercesc::DTDGrammar::getGrammarDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("putEntityDecl", &xercesc::DTDGrammar::putEntityDecl)
			PyDECL_XSERIALIZABLE(DTDGrammar)
			;
}

} /* namespace pyxerces */
