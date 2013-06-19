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

class DTDGrammarDefVisitor
: public boost::python::def_visitor<DTDGrammarDefVisitor>
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
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::DTDGrammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int, const bool)>(&DTDGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::DTDGrammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int)>(&DTDGrammarDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getEntityDecl", &DTDGrammarDefVisitor::getEntityDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLElementDecl* findOrAddElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, bool& wasAdded) {
	return self.findOrAddElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, wasAdded);
}

static XMLSize_t getElemId(xercesc::DTDGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemId(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLElementDecl* getElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemDecl(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLNotationDecl* getNotationDecl(xercesc::DTDGrammar& self, const XMLString& notName) {
	return self.getNotationDecl(notName.ptr());
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, const bool notDeclared) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, notDeclared);
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::DTDGrammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, false);
}

static xercesc::DTDEntityDecl* getEntityDecl(xercesc::DTDGrammar& self, const XMLString& entName) {
	return self.getEntityDecl(entName.ptr());
}

};

class DTDGrammarWrapper
: public xercesc::DTDGrammar, public boost::python::wrapper<xercesc::DTDGrammar>
{
public:
DTDGrammarWrapper(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::DTDGrammar(manager)
{}
// ---------- Grammar ----------
GrammarType getGrammarType() const {
	if(boost::python::override getGrammarType = this->get_override("getGrammarType")){
		return getGrammarType();
	}else{
		return xercesc::DTDGrammar::getGrammarType();
	}
}

const XMLCh* getTargetNamespace() const {
	if(boost::python::override getTargetNamespace = this->get_override("getTargetNamespace")){
		return getTargetNamespace();
	}else{
		return xercesc::DTDGrammar::getTargetNamespace();
	}
}

bool getValidated() const {
	if(boost::python::override getValidated = this->get_override("getValidated")){
		return getValidated();
	}else{
		return xercesc::DTDGrammar::getValidated();
	}
}

xercesc::XMLElementDecl* findOrAddElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const prefixName, const XMLCh* const qName, unsigned int scope, bool& wasAdded) {
	if(boost::python::override findOrAddElemDecl = this->get_override("findOrAddElemDecl")){
		boost::python::tuple result = findOrAddElemDecl(uriId, XMLString(baseName), XMLString(prefixName), XMLString(qName), scope);
		wasAdded = boost::python::extract<bool>(result[1]);
		return boost::python::extract<xercesc::XMLElementDecl*>(result[0]);
	}else{
		return xercesc::DTDGrammar::findOrAddElemDecl(uriId, baseName, prefixName, qName, scope, wasAdded);
	}
}

XMLSize_t getElemId(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) const {
	if(boost::python::override getElemId = this->get_override("getElemId")){
		return getElemId(uriId, XMLString(baseName), XMLString(qName), scope);
	}else{
		return xercesc::DTDGrammar::getElemId(uriId, baseName, qName, scope);
	}
}

const xercesc::XMLElementDecl* getElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) const {
	if(boost::python::override getElemDecl = this->get_override("getElemDecl")){
		return getElemDecl(uriId, XMLString(baseName), XMLString(qName), scope);
	}else{
		return xercesc::DTDGrammar::getElemDecl(uriId, baseName, qName, scope);
	}
}

xercesc::XMLElementDecl* getElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) {
	if(boost::python::override getElemDecl = this->get_override("getElemDecl")){
		return getElemDecl(uriId, XMLString(baseName), XMLString(qName), scope);
	}else{
		return xercesc::DTDGrammar::getElemDecl(uriId, baseName, qName, scope);
	}
}

const xercesc::XMLElementDecl* getElemDecl(const unsigned int elemId) const {
	if(boost::python::override getElemDecl = this->get_override("getElemDecl")){
		return getElemDecl(elemId);
	}else{
		return xercesc::DTDGrammar::getElemDecl(elemId);
	}
}

xercesc::XMLElementDecl* getElemDecl(const unsigned int elemId) {
	if(boost::python::override getElemDecl = this->get_override("getElemDecl")){
		return getElemDecl(elemId);
	}else{
		return xercesc::DTDGrammar::getElemDecl(elemId);
	}
}

const xercesc::XMLNotationDecl* getNotationDecl(const XMLCh* const notName) const {
	if(boost::python::override getNotationDecl = this->get_override("getNotationDecl")){
		return getNotationDecl(XMLString(notName));
	}else{
		return xercesc::DTDGrammar::getNotationDecl(notName);
	}
}

xercesc::XMLNotationDecl* getNotationDecl(const XMLCh* const notName) {
	if(boost::python::override getNotationDecl = this->get_override("getNotationDecl")){
		return getNotationDecl(XMLString(notName));
	}else{
		return xercesc::DTDGrammar::getNotationDecl(notName);
	}
}

xercesc::XMLElementDecl* putElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const prefixName, const XMLCh* const qName, unsigned int scope, const bool notDeclared = false) {
	if(boost::python::override putElemDecl = this->get_override("putElemDecl")){
		return putElemDecl(uriId, XMLString(baseName), XMLString(prefixName), XMLString(qName), scope, notDeclared);
	}else{
		return xercesc::DTDGrammar::putElemDecl(uriId, baseName, prefixName, qName, notDeclared);
	}
}

XMLSize_t putElemDecl(xercesc::XMLElementDecl* const elemDecl, const bool notDeclared = false) {
	if(boost::python::override putElemDecl = this->get_override("putElemDecl")){
		return putElemDecl(boost::python::ptr(elemDecl), notDeclared);
	}else{
		return xercesc::DTDGrammar::putElemDecl(elemDecl, notDeclared);
	}
}

XMLSize_t putNotationDecl(xercesc::XMLNotationDecl* const notationDecl) const {
	if(boost::python::override putNotationDecl = this->get_override("putNotationDecl")){
		return putNotationDecl(boost::python::ptr(notationDecl));
	}else{
		return xercesc::DTDGrammar::putNotationDecl(notationDecl);
	}
}

void setValidated(const bool newState) {
	if(boost::python::override setValidated = this->get_override("setValidated")){
		setValidated(newState);
	}else{
		xercesc::DTDGrammar::setValidated(newState);
	}
}

void reset() {
	if(boost::python::override reset = this->get_override("reset")){
		reset();
	}else{
		return xercesc::DTDGrammar::reset();
	}
}

void setGrammarDescription(xercesc::XMLGrammarDescription* desc) {
	if(boost::python::override setGrammarDescription = this->get_override("setGrammarDescription")){
		setGrammarDescription(boost::python::ptr(desc));
	}else{
		return xercesc::DTDGrammar::setGrammarDescription(desc);
	}
}

xercesc::XMLGrammarDescription* getGrammarDescription() const {
	if(boost::python::override getGrammarDescription = this->get_override("getGrammarDescription")){
		return getGrammarDescription();
	}else{
		return xercesc::DTDGrammar::getGrammarDescription();
	}
}

PyDECL_XSERIALIZABLEWrapper

};

//! DTDGrammar
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DTDGrammarPutElemDeclOverloads, putElemDecl, 5, 6)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DTDGrammarPutElemDeclMiniOverloads, putElemDecl, 1, 2)

void DTDGrammar_init(void) {
	//! xercesc::DTDGrammar
	boost::python::class_<DTDGrammarWrapper, boost::noncopyable, boost::python::bases<xercesc::Grammar> >("DTDGrammar", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(DTDGrammarDefVisitor())
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
