/*
 * Grammar.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include "Grammar.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLGrammarDescription.hpp>

//! DTDGrammar
#include <xercesc/validators/DTD/DTDGrammar.hpp>
//! SchemaGrammar
#include <xercesc/validators/schema/SchemaGrammar.hpp>

#include <xercesc/validators/common/Grammar.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

class GrammarDefVisitor
: public boost::python::def_visitor<GrammarDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("toDTDGrammar", &GrammarDefVisitor::toDTDGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("toSchemaGrammar", &GrammarDefVisitor::toSchemaGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DTDGrammar* toDTDGrammar(xercesc::Grammar& self) {
	if(self.getGrammarType() != xercesc::Grammar::DTDGrammarType) {
		return nullptr;
	}
	return reinterpret_cast<xercesc::DTDGrammar*>(&self);
}

static xercesc::SchemaGrammar* toSchemaGrammar(xercesc::Grammar& self) {
	if(self.getGrammarType() != xercesc::Grammar::SchemaGrammarType) {
		return nullptr;
	}
	return reinterpret_cast<xercesc::SchemaGrammar*>(&self);
}

};

class GrammarStringDefVisitor
: public boost::python::def_visitor<GrammarStringDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findOrAddElemDecl", &GrammarStringDefVisitor::findOrAddElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getElemId", &GrammarStringDefVisitor::getElemId)
	.def("getElemDecl", &GrammarStringDefVisitor::getElemDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getNotationDecl", &GrammarStringDefVisitor::getNotationDecl, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::Grammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int, const bool)>(&GrammarStringDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("putElemDecl", static_cast<xercesc::XMLElementDecl*(*)(xercesc::Grammar&, const unsigned int, const XMLString&, const XMLString&, const XMLString&, unsigned int)>(&GrammarStringDefVisitor::putElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLElementDecl* findOrAddElemDecl(xercesc::Grammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, bool& wasAdded) {
	return self.findOrAddElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, wasAdded);
}

static XMLSize_t getElemId(xercesc::Grammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemId(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLElementDecl* getElemDecl(xercesc::Grammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& qName, unsigned int scope) {
	return self.getElemDecl(uriId, baseName.ptr(), qName.ptr(), scope);
}

static xercesc::XMLNotationDecl* getNotationDecl(xercesc::Grammar& self, const XMLString& notName) {
	return self.getNotationDecl(notName.ptr());
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::Grammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope, const bool notDeclared) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, notDeclared);
}

static xercesc::XMLElementDecl* putElemDecl(xercesc::Grammar& self, const unsigned int uriId, const XMLString& baseName, const XMLString& prefixName, const XMLString& qName, unsigned int scope) {
	return self.putElemDecl(uriId, baseName.ptr(), prefixName.ptr(), qName.ptr(), scope, false);
}

};

class GrammarWrapper
: public xercesc::Grammar, public boost::python::wrapper<xercesc::Grammar>
{
public:
GrammarType getGrammarType() const {
	return this->get_override("getGrammarType")();
}

const XMLCh* getTargetNamespace() const {
	return this->get_override("getTargetNamespace")();
}

bool getValidated() const {
	return this->get_override("getValidated")();
}

xercesc::XMLElementDecl* findOrAddElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const prefixName, const XMLCh* const qName, unsigned int scope, bool& wasAdded) {
	boost::python::tuple result = this->get_override("findOrAddElemDecl")(uriId, XMLString(baseName), XMLString(prefixName), XMLString(qName), scope);
	wasAdded = boost::python::extract<bool>(result[1]);
	return boost::python::extract<xercesc::XMLElementDecl*>(result[0]);
}

XMLSize_t getElemId(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) const {
	return this->get_override("getElemId")(uriId, XMLString(baseName), XMLString(qName), scope);
}

const xercesc::XMLElementDecl* getElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) const {
	return this->get_override("getElemDecl")(uriId, XMLString(baseName), XMLString(qName), scope);
}

xercesc::XMLElementDecl* getElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const qName, unsigned int scope) {
	return this->get_override("getElemDecl")(uriId, XMLString(baseName), XMLString(qName), scope);
}

const xercesc::XMLElementDecl* getElemDecl(const unsigned int elemId) const {
	return this->get_override("getElemDecl")(elemId);
}

xercesc::XMLElementDecl* getElemDecl(const unsigned int elemId) {
	return this->get_override("getElemDecl")(elemId);
}

const xercesc::XMLNotationDecl* getNotationDecl(const XMLCh* const notName) const {
	return this->get_override("getNotationDecl")(XMLString(notName));
}

xercesc::XMLNotationDecl* getNotationDecl(const XMLCh* const notName) {
	return this->get_override("getNotationDecl")(XMLString(notName));
}

xercesc::XMLElementDecl* putElemDecl(const unsigned int uriId, const XMLCh* const baseName, const XMLCh* const prefixName, const XMLCh* const qName, unsigned int scope, const bool notDeclared = false) {
	return this->get_override("putElemDecl")(uriId, XMLString(baseName), XMLString(prefixName), XMLString(qName), scope, notDeclared);
}

XMLSize_t putElemDecl(xercesc::XMLElementDecl* const elemDecl, const bool notDeclared = false) {
	return this->get_override("putElemDecl")(boost::python::ptr(elemDecl), notDeclared);
}

XMLSize_t putNotationDecl(xercesc::XMLNotationDecl* const notationDecl) const {
	return this->get_override("putNotationDecl")(boost::python::ptr(notationDecl));
}

void setValidated(const bool newState) {
	this->get_override("setValidated")(newState);
}

void reset() {
	this->get_override("reset")();
}

void setGrammarDescription(xercesc::XMLGrammarDescription* desc) {
	this->get_override("setGrammarDescription")(boost::python::ptr(desc));
}

xercesc::XMLGrammarDescription* getGrammarDescription() const {
	return this->get_override("getGrammarDescription")();
}

PyDECL_XSERIALIZABLEWrapper

};

void Grammar_init(void) {
	//! xercesc::Grammar
	auto Grammar = boost::python::class_<xercesc::Grammar, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("Grammar", boost::python::no_init)
			.def(GrammarDefVisitor())
			.def(GrammarStringDefVisitor())
			.def("getGrammarType", boost::python::pure_virtual(&xercesc::Grammar::getGrammarType))
			.def("getTargetNamespace", boost::python::pure_virtual(&xercesc::Grammar::getTargetNamespace), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getValidated", boost::python::pure_virtual(&xercesc::Grammar::getValidated))
			.def("findOrAddElemDecl", boost::python::pure_virtual(&xercesc::Grammar::findOrAddElemDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemId", boost::python::pure_virtual(&xercesc::Grammar::getElemId))
			.def("getElemDecl", boost::python::pure_virtual(static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, unsigned int)>(&xercesc::Grammar::getElemDecl)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", boost::python::pure_virtual(static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int)>(&xercesc::Grammar::getElemDecl)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElemDecl", boost::python::pure_virtual(static_cast<xercesc::XMLNotationDecl*(xercesc::Grammar::*)(const XMLCh* const)>(&xercesc::Grammar::getNotationDecl)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("putElemDecl", boost::python::pure_virtual(static_cast<xercesc::XMLElementDecl*(xercesc::Grammar::*)(const unsigned int, const XMLCh* const, const XMLCh* const, const XMLCh* const, unsigned int, const bool)>(&xercesc::Grammar::putElemDecl)), (boost::python::arg("uriId"), boost::python::arg("baseName"), boost::python::arg("prefixName"), boost::python::arg("qName"), boost::python::arg("scope"), boost::python::arg("notDeclared") = false), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("putElemDecl", boost::python::pure_virtual(static_cast<XMLSize_t(xercesc::Grammar::*)(xercesc::XMLElementDecl* const, const bool)>(&xercesc::Grammar::putElemDecl)), (boost::python::arg("elemDecl"), boost::python::arg("notDeclared") = false))
			.def("putNotationDecl", boost::python::pure_virtual(&xercesc::Grammar::putNotationDecl))
			.def("setValidated", boost::python::pure_virtual(&xercesc::Grammar::setValidated))
			.def("reset", boost::python::pure_virtual(&xercesc::Grammar::reset))
			.def("setGrammarDescription", boost::python::pure_virtual(&xercesc::Grammar::setGrammarDescription))
			.def("getGrammarDescription", boost::python::pure_virtual(&xercesc::Grammar::getGrammarDescription), boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(Grammar)
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
