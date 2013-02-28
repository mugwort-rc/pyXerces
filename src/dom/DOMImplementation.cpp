/*
 * DOMImplementation.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementation.h"

#include <boost/scoped_ptr.hpp>

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSInput.hpp>			//!< for forward declaration DOMImplementationLS
#include <xercesc/dom/DOMLSOutput.hpp>			//!< for forward declaration DOMImplementationLS
#include <xercesc/dom/DOMLSSerializer.hpp>		//!< for forward declaration DOMImplementationLS
#include <xercesc/dom/DOMLSParser.hpp>			//!< for forward declaration DOMImplementationLS
#include <xercesc/framework/XMLGrammarPool.hpp>	//!< for forward declaration DOMImplementationLS
#include <xercesc/dom/DOMDocument.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMDocumentType.hpp>		//!< for forward declaration
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMImplementation.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! DOMImplementation
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationCreateDocumentOverloads, createDocument, 3, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationCreateDocumentSimpleOverloads, createDocument, 0, 1)

class DOMImplementationDefVisitor
: public boost::python::def_visitor<DOMImplementationDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("toDOMImplementationLS", &DOMImplementationDefVisitor::toDOMImplementationLS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("hasFeature", static_cast<bool(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&)>(&DOMImplementationDefVisitor::hasFeature))
	.def("hasFeature", static_cast<bool(*)(xercesc::DOMImplementation&, const std::string&, const std::string&)>(&DOMImplementationDefVisitor::hasFeature))
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&, const XMLString&)>(&DOMImplementationDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocumentType", static_cast<xercesc::DOMDocumentType*(*)(xercesc::DOMImplementation&, const std::string&, const std::string&, const std::string&)>(&DOMImplementationDefVisitor::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&, xercesc::DOMDocumentType*, xercesc::MemoryManager* const)>(&DOMImplementationDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const std::string&, const std::string&, xercesc::DOMDocumentType*, xercesc::MemoryManager* const)>(&DOMImplementationDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&, xercesc::DOMDocumentType*)>(&DOMImplementationDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const std::string&, const std::string&, xercesc::DOMDocumentType*)>(&DOMImplementationDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getFeature", static_cast<void*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&)>(&DOMImplementationDefVisitor::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("getFeature", static_cast<void*(*)(xercesc::DOMImplementation&, const std::string&, const std::string&)>(&DOMImplementationDefVisitor::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("loadDOMExceptionMsg", &DOMImplementationDefVisitor::loadDOMExceptionMsg)
	;
}

static xercesc::DOMImplementationLS* toDOMImplementationLS(xercesc::DOMImplementation& self) {
	return reinterpret_cast<xercesc::DOMImplementationLS*>(&self);
}

static bool hasFeature(xercesc::DOMImplementation& self, const XMLString& feature, const XMLString& version) {
	return self.hasFeature(feature.ptr(), version.ptr());
}

static bool hasFeature(xercesc::DOMImplementation& self, const std::string& feature, const std::string& version) {
	XMLString buff1(feature), buff2(version);
	return DOMImplementationDefVisitor::hasFeature(self, buff1, buff2);
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMImplementation& self, const XMLString& qualifiedName, const XMLString& publicId, const XMLString& systemId) {
	return self.createDocumentType(qualifiedName.ptr(), publicId.ptr(), systemId.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMImplementation& self, const std::string& qualifiedName, const std::string& publicId, const std::string& systemId) {
	XMLString buff1(qualifiedName), buff2(publicId), buff3(systemId);
	return DOMImplementationDefVisitor::createDocumentType(self, buff1, buff2, buff3);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const XMLString& namespaceURI, const XMLString& qualifiedName, xercesc::DOMDocumentType* doctype, xercesc::MemoryManager* const manager) {
	return self.createDocument(namespaceURI.ptr(), qualifiedName.ptr(), doctype, manager);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const std::string& namespaceURI, const std::string& qualifiedName, xercesc::DOMDocumentType* doctype, xercesc::MemoryManager* const manager) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMImplementationDefVisitor::createDocument(self, buff1, buff2, doctype, manager);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const XMLString& namespaceURI, const XMLString& qualifiedName, xercesc::DOMDocumentType* doctype) {
	return DOMImplementationDefVisitor::createDocument(self, namespaceURI, qualifiedName, doctype, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const std::string& namespaceURI, const std::string& qualifiedName, xercesc::DOMDocumentType* doctype) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return DOMImplementationDefVisitor::createDocument(self, buff1, buff2, doctype);
}

static void* getFeature(xercesc::DOMImplementation& self, const XMLString& feature, const XMLString& version) {
	return self.getFeature(feature.ptr(), version.ptr());
}

static void* getFeature(xercesc::DOMImplementation& self, const std::string& feature, const std::string& version) {
	XMLString buff1(feature), buff2(version);
	return DOMImplementationDefVisitor::getFeature(self, buff1, buff2);
}

static boost::python::tuple loadDOMExceptionMsg(xercesc::DOMImplementation& self, const short msgToLoad, const XMLSize_t maxChars) {
	boost::scoped_ptr<XMLCh> buff(new XMLCh[maxChars+1]);
	bool        ret = self.loadDOMExceptionMsg(msgToLoad, buff.get(), maxChars);
	std::string str = XMLString(buff.get()).toString();
	return boost::python::make_tuple(ret, str);
}

};

void DOMImplementation_init(void) {
	//! xercesc::DOMImplementation
	boost::python::class_<xercesc::DOMImplementation, boost::noncopyable, boost::python::bases<xercesc::DOMImplementationLS> >("DOMImplementation", boost::python::no_init)
			.def(DOMImplementationDefVisitor())
			.def("hasFeature", &xercesc::DOMImplementation::hasFeature)
			.def("createDocumentType", &xercesc::DOMImplementation::createDocumentType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocument", static_cast<xercesc::DOMDocument*(xercesc::DOMImplementation::*)(const XMLCh*, const XMLCh*, xercesc::DOMDocumentType*, xercesc::MemoryManager*)>(&xercesc::DOMImplementation::createDocument), pyxerces::DOMImplementationCreateDocumentOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("getFeature", &xercesc::DOMImplementation::getFeature, boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("createDocument", static_cast<xercesc::DOMDocument*(xercesc::DOMImplementation::*)(xercesc::MemoryManager*)>(&xercesc::DOMImplementation::createDocument), pyxerces::DOMImplementationCreateDocumentSimpleOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("getImplementation", &xercesc::DOMImplementation::getImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadDOMExceptionMsg", &xercesc::DOMImplementation::loadDOMExceptionMsg)
			.staticmethod("getImplementation")
			.staticmethod("loadDOMExceptionMsg")
			;
}

} /* namespace pyxerces */
