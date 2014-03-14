/*
 * DOMImplementation.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementation.h"

#include <boost/scoped_ptr.hpp>

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMLSInput.hpp>
#include <xercesc/dom/DOMLSOutput.hpp>
#include <xercesc/dom/DOMLSSerializer.hpp>
#include <xercesc/dom/DOMLSParser.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMDocumentType.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/dom/DOMImplementation.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMImplementationDefaultDefVisitor
: public boost::python::def_visitor<DOMImplementationDefaultDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createDocument", &DOMImplementationDefaultDefVisitor::createDocument, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self) {
	return self.createDocument();
}

};

class DOMImplementationDefVisitor
: public boost::python::def_visitor<DOMImplementationDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("toDOMImplementationLS", &DOMImplementationDefVisitor::toDOMImplementationLS, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("loadDOMExceptionMsg", &DOMImplementationDefVisitor::loadDOMExceptionMsg)
	;
}

static xercesc::DOMImplementationLS* toDOMImplementationLS(xercesc::DOMImplementation& self) {
	return reinterpret_cast<xercesc::DOMImplementationLS*>(&self);
}

static boost::python::tuple loadDOMExceptionMsg(xercesc::DOMImplementation& self, const short msgToLoad, const XMLSize_t maxChars) {
	boost::scoped_ptr<XMLCh> buff(new XMLCh[maxChars+1]);
	bool        ret = self.loadDOMExceptionMsg(msgToLoad, buff.get(), maxChars);
	std::string str = XMLString(buff.get()).toString();
	return boost::python::make_tuple(ret, str);
}

};

class DOMImplementationStringDefVisitor
: public boost::python::def_visitor<DOMImplementationStringDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("hasFeature", &DOMImplementationStringDefVisitor::hasFeature)
	.def("createDocumentType", &DOMImplementationStringDefVisitor::createDocumentType, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&, xercesc::DOMDocumentType*, xercesc::MemoryManager* const)>(&DOMImplementationStringDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const XMLString&, const XMLString&, xercesc::DOMDocumentType*)>(&DOMImplementationStringDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getFeature", &DOMImplementationStringDefVisitor::getFeature, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	;
}

static bool hasFeature(xercesc::DOMImplementation& self, const XMLString& feature, const XMLString& version) {
	return self.hasFeature(feature.ptr(), version.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMImplementation& self, const XMLString& qualifiedName, const XMLString& publicId, const XMLString& systemId) {
	return self.createDocumentType(qualifiedName.ptr(), publicId.ptr(), systemId.ptr());
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const XMLString& namespaceURI, const XMLString& qualifiedName, xercesc::DOMDocumentType* doctype, xercesc::MemoryManager* const manager) {
	return self.createDocument(namespaceURI.ptr(), qualifiedName.ptr(), doctype, manager);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const XMLString& namespaceURI, const XMLString& qualifiedName, xercesc::DOMDocumentType* doctype) {
	return DOMImplementationStringDefVisitor::createDocument(self, namespaceURI, qualifiedName, doctype, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void* getFeature(xercesc::DOMImplementation& self, const XMLString& feature, const XMLString& version) {
	return self.getFeature(feature.ptr(), version.ptr());
}

};

class DOMImplementationWrapper
: public xercesc::DOMImplementation, public boost::python::wrapper<xercesc::DOMImplementation>
{
public:
bool  hasFeature(const XMLCh *feature,  const XMLCh *version) const {
	return this->get_override("hasFeature")(XMLString(feature), XMLString(version));
}

xercesc::DOMDocumentType *createDocumentType(const XMLCh *qualifiedName, const XMLCh *publicId, const XMLCh *systemId) {
	return this->get_override("createDocumentType")(XMLString(qualifiedName), XMLString(publicId), XMLString(systemId));
}

xercesc::DOMDocument *createDocument(const XMLCh *namespaceURI, const XMLCh *qualifiedName, xercesc::DOMDocumentType *doctype, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createDocument")(XMLString(namespaceURI), XMLString(qualifiedName), boost::python::ptr(doctype), boost::python::ptr(manager));
}

void* getFeature(const XMLCh* feature, const XMLCh* version) const {
	return this->get_override("getFeature")(XMLString(feature), XMLString(version));
}

xercesc::DOMDocument *createDocument(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createDocument")(boost::python::ptr(manager));
}

//! ---------- DOMImplementationLS ----------
xercesc::DOMLSParser* createLSParser(const DOMImplementationLSMode mode, const XMLCh* const schemaType, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager, xercesc::XMLGrammarPool*  const gramPool = 0) {
	return this->get_override("createLSParser")(mode, XMLString(schemaType), boost::python::ptr(manager), boost::python::ptr(gramPool));
}

xercesc::DOMLSSerializer* createLSSerializer(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSSerializer")(boost::python::ptr(manager));
}

xercesc::DOMLSInput* createLSInput(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSInput")(boost::python::ptr(manager));
}

xercesc::DOMLSOutput* createLSOutput(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSOutput")(boost::python::ptr(manager));
}

};

void DOMImplementation_init(void) {
	//! xercesc::DOMImplementation
	boost::python::class_<DOMImplementationWrapper, boost::noncopyable, boost::python::bases<xercesc::DOMImplementationLS> >("DOMImplementation")
			.def(DOMImplementationDefaultDefVisitor())
			.def(DOMImplementationDefVisitor())
			.def(DOMImplementationStringDefVisitor())
			.def("hasFeature", boost::python::pure_virtual(&xercesc::DOMImplementation::hasFeature))
			.def("createDocumentType", boost::python::pure_virtual(&xercesc::DOMImplementation::createDocumentType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createDocument", boost::python::pure_virtual(static_cast<xercesc::DOMDocument*(xercesc::DOMImplementation::*)(const XMLCh*, const XMLCh*, xercesc::DOMDocumentType*, xercesc::MemoryManager*)>(&xercesc::DOMImplementation::createDocument)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFeature", boost::python::pure_virtual(&xercesc::DOMImplementation::getFeature), boost::python::return_value_policy<boost::python::return_opaque_pointer>())  //!< void*
			.def("createDocument", boost::python::pure_virtual(static_cast<xercesc::DOMDocument*(xercesc::DOMImplementation::*)(xercesc::MemoryManager*)>(&xercesc::DOMImplementation::createDocument)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getImplementation", &xercesc::DOMImplementation::getImplementation, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadDOMExceptionMsg", &xercesc::DOMImplementation::loadDOMExceptionMsg)
			.staticmethod("getImplementation")
			.staticmethod("loadDOMExceptionMsg")
			;
}

} /* namespace pyxerces */
