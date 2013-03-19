/*
 * XMLGrammarPool.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "XMLGrammarPool.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/framework/XMLGrammarDescription.hpp>
#include <xercesc/validators/DTD/DTDGrammar.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>
#include <xercesc/framework/XMLDTDDescription.hpp>
#include <xercesc/framework/XMLSchemaDescription.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/BinOutputStream.hpp>

#include <xercesc/framework/XMLGrammarPool.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLGrammarPoolDefVisitor
: public boost::python::def_visitor<XMLGrammarPoolDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("orphanGrammar", &XMLGrammarPoolDefVisitor::orphanGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDTDDescription", &XMLGrammarPoolDefVisitor::createDTDDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createSchemaDescription", &XMLGrammarPoolDefVisitor::createSchemaDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::Grammar* orphanGrammar(xercesc::XMLGrammarPool& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.orphanGrammar(buff.ptr());
}

static xercesc::XMLDTDDescription* createDTDDescription(xercesc::XMLGrammarPool& self, const STR& systemId) {
	XMLString buff(systemId);
	return self.createDTDDescription(buff.ptr());
}

static xercesc::XMLSchemaDescription* createSchemaDescription(xercesc::XMLGrammarPool& self, const STR& targetNamespace) {
	XMLString buff(targetNamespace);
	return self.createSchemaDescription(buff.ptr());
}

};

class XMLGrammarPoolWrapper
: public xercesc::XMLGrammarPool, public boost::python::wrapper<xercesc::XMLGrammarPool>
{
public:
bool cacheGrammar(xercesc::Grammar* const gramToCache) {
	return this->get_override("cacheGrammar")(boost::python::ptr(gramToCache));
}

xercesc::Grammar* retrieveGrammar(xercesc::XMLGrammarDescription* const gramDesc) {
	return this->get_override("retrieveGrammar")(boost::python::ptr(gramDesc));
}

xercesc::Grammar* orphanGrammar(const XMLCh* const nameSpaceKey) {
	return this->get_override("orphanGrammar")(XMLString(nameSpaceKey));
}

xercesc::RefHashTableOfEnumerator<xercesc::Grammar> getGrammarEnumerator() const {
	return this->get_override("getGrammarEnumerator")();
}

bool clear() {
	return this->get_override("clear")();
}

void lockPool() {
	this->get_override("lockPool")();
}

void unlockPool() {
	this->get_override("unlockPool")();
}

xercesc::DTDGrammar* createDTDGrammar() {
	return this->get_override("createDTDGrammar")();
}

xercesc::SchemaGrammar* createSchemaGrammar() {
	return this->get_override("createSchemaGrammar")();
}

xercesc::XMLDTDDescription* createDTDDescription(const XMLCh* const systemId) {
	return this->get_override("createDTDDescription")(XMLString(systemId));
}

xercesc::XMLSchemaDescription* createSchemaDescription(const XMLCh* const targetNamespace) {
	return this->get_override("createSchemaDescription")(XMLString(targetNamespace));
}

xercesc::XSModel *getXSModel(bool& XSModelWasChanged) {
	boost::python::tuple result = this->get_override("getXSModel")();
	XSModelWasChanged = boost::python::extract<bool>(result[1]);
	return boost::python::extract<xercesc::XSModel*>(result[0]);
}

xercesc::XMLStringPool *getURIStringPool() {
	return this->get_override("getURIStringPool")();
}

void serializeGrammars(xercesc::BinOutputStream* const stream) {
	this->get_override("serializeGrammars")(boost::python::ptr(stream));
}

void deserializeGrammars(xercesc::BinInputStream* const stream) {
	this->get_override("deserializeGrammars")(boost::python::ptr(stream));
}

};

void XMLGrammarPool_init(void) {
	//! xercesc::XMLGrammarPool
	boost::python::class_<XMLGrammarPoolWrapper, boost::noncopyable>("XMLGrammarPool")
			.def(XMLGrammarPoolDefVisitor<XMLString>())
			.def(XMLGrammarPoolDefVisitor<std::string>())
			.def("cacheGrammar", boost::python::pure_virtual(&xercesc::XMLGrammarPool::cacheGrammar))
			.def("retrieveGrammar", boost::python::pure_virtual(&xercesc::XMLGrammarPool::retrieveGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("orphanGrammar", boost::python::pure_virtual(&xercesc::XMLGrammarPool::orphanGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getGrammarEnumerator", boost::python::pure_virtual(&xercesc::XMLGrammarPool::getGrammarEnumerator))
			.def("clear", boost::python::pure_virtual(&xercesc::XMLGrammarPool::clear))
			.def("lockPool", boost::python::pure_virtual(&xercesc::XMLGrammarPool::lockPool))
			.def("unlockPool", boost::python::pure_virtual(&xercesc::XMLGrammarPool::unlockPool))
			.def("createDTDGrammar", boost::python::pure_virtual(&xercesc::XMLGrammarPool::createDTDGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createSchemaGrammar", boost::python::pure_virtual(&xercesc::XMLGrammarPool::createSchemaGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDTDDescription", boost::python::pure_virtual(&xercesc::XMLGrammarPool::createDTDDescription), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createSchemaDescription", boost::python::pure_virtual(&xercesc::XMLGrammarPool::createSchemaDescription), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXSModel", boost::python::pure_virtual(&xercesc::XMLGrammarPool::getXSModel), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::XMLGrammarPool::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIStringPool", boost::python::pure_virtual(&xercesc::XMLGrammarPool::getURIStringPool), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serializeGrammars", boost::python::pure_virtual(&xercesc::XMLGrammarPool::serializeGrammars))
			.def("deserializeGrammars", boost::python::pure_virtual(&xercesc::XMLGrammarPool::deserializeGrammars))
			.def("setIgnoreSerializedAnnotations", &xercesc::XMLGrammarPool::setIgnoreSerializedAnnotations)
			.def("getIgnoreSerializedAnnotations", &xercesc::XMLGrammarPool::getIgnoreSerializedAnnotations)
			;
}

} /* namespace pyxerces */
