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

void XMLGrammarPool_init(void) {
	//! xercesc::XMLGrammarPool
	boost::python::class_<xercesc::XMLGrammarPool, boost::noncopyable>("XMLGrammarPool", boost::python::no_init)
			.def(XMLGrammarPoolDefVisitor<XMLString>())
			.def(XMLGrammarPoolDefVisitor<std::string>())
			.def("cacheGrammar", &xercesc::XMLGrammarPool::cacheGrammar)
			.def("retrieveGrammar", &xercesc::XMLGrammarPool::retrieveGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("orphanGrammar", &xercesc::XMLGrammarPool::orphanGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getGrammarEnumerator", &xercesc::XMLGrammarPool::getGrammarEnumerator)
			.def("clear", &xercesc::XMLGrammarPool::clear)
			.def("lockPool", &xercesc::XMLGrammarPool::lockPool)
			.def("unlockPool", &xercesc::XMLGrammarPool::unlockPool)
			.def("createDTDGrammar", &xercesc::XMLGrammarPool::createDTDGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createSchemaGrammar", &xercesc::XMLGrammarPool::createSchemaGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDTDDescription", &xercesc::XMLGrammarPool::createDTDDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createSchemaDescription", &xercesc::XMLGrammarPool::createSchemaDescription, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXSModel", &xercesc::XMLGrammarPool::getXSModel, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::XMLGrammarPool::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIStringPool", &xercesc::XMLGrammarPool::getURIStringPool, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serializeGrammars", &xercesc::XMLGrammarPool::serializeGrammars)
			.def("deserializeGrammars", &xercesc::XMLGrammarPool::deserializeGrammars)
			.def("setIgnoreSerializedAnnotations", &xercesc::XMLGrammarPool::setIgnoreSerializedAnnotations)
			.def("getIgnoreSerializedAnnotations", &xercesc::XMLGrammarPool::getIgnoreSerializedAnnotations)
			;
}

} /* namespace pyxerces */
