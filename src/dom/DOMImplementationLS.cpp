/*
 * DOMImplementationLS.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationLS.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSInput.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMLSOutput.hpp>					//!< for forward declaration
#include <xercesc/dom/DOMLSSerializer.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMLSParser.hpp>					//!< for forward declaration
#include <xercesc/framework/XMLGrammarPool.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMImplementationLS.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! DOMImplementationLS
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSParserOverloads, createLSParser, 2, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSSerializerOverloads, createLSSerializer, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSInputOverloads, createLSInput, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSOutputOverloads, createLSOutput, 0, 1)

class DOMImplementationLSDefVisitor
: public boost::python::def_visitor<DOMImplementationLSDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const XMLString&, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const std::string&, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const XMLString&, xercesc::MemoryManager* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const std::string&, xercesc::MemoryManager* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const XMLString&)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const std::string&)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const XMLString& schemaType, xercesc::MemoryManager* const manager, xercesc::XMLGrammarPool* const gramPool) {
	return self.createLSParser(mode, schemaType.ptr(), manager, gramPool);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const std::string& schemaType, xercesc::MemoryManager* const manager, xercesc::XMLGrammarPool* const gramPool) {
	XMLString buff(schemaType);
	return DOMImplementationLSDefVisitor::createLSParser(self, mode, buff, manager, gramPool);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const XMLString& schemaType, xercesc::MemoryManager* const manager) {
	return self.createLSParser(mode, schemaType.ptr(), manager, nullptr);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const std::string& schemaType, xercesc::MemoryManager* const manager) {
	XMLString buff(schemaType);
	return DOMImplementationLSDefVisitor::createLSParser(self, mode, buff, manager, nullptr);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const XMLString& schemaType) {
	return self.createLSParser(mode, schemaType.ptr(), xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const std::string& schemaType) {
	XMLString buff(schemaType);
	return DOMImplementationLSDefVisitor::createLSParser(self, mode, buff, xercesc::XMLPlatformUtils::fgMemoryManager);
}
};

void DOMImplementationLS_init(void) {
	//! xercesc::DOMImplementationLS
	auto DOMImplementationLS = boost::python::class_<xercesc::DOMImplementationLS, boost::noncopyable>("DOMImplementationLS", boost::python::no_init)
			.def(DOMImplementationLSDefVisitor())
			.def("createLSParser", &xercesc::DOMImplementationLS::createLSParser, DOMImplementationLSCreateLSParserOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSSerializer", &xercesc::DOMImplementationLS::createLSSerializer, DOMImplementationLSCreateLSSerializerOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSInput", &xercesc::DOMImplementationLS::createLSInput, DOMImplementationLSCreateLSInputOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createLSOutput", &xercesc::DOMImplementationLS::createLSOutput, DOMImplementationLSCreateLSOutputOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			;
	boost::python::scope DOMImplementationLSScope = DOMImplementationLS;
	//! xercesc::DOMImplementationLS::DOMImplementationLSMode
	boost::python::enum_<xercesc::DOMImplementationLS::DOMImplementationLSMode>("DOMImplementationLSMode")
			.value("MODE_SYNCHRONOUS", xercesc::DOMImplementationLS::MODE_SYNCHRONOUS)
			.value("MODE_ASYNCHRONOUS", xercesc::DOMImplementationLS::MODE_ASYNCHRONOUS)
			.export_values()
			;
}

} /* namespace pyxerces */
