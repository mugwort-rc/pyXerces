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

template <class STR>
class DOMImplementationStringDefVisitor
: public boost::python::def_visitor<DOMImplementationStringDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("hasFeature", &DOMImplementationStringDefVisitor::hasFeature)
	.def("createDocumentType", &DOMImplementationStringDefVisitor::createDocumentType, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const STR&, const STR&, xercesc::DOMDocumentType*, xercesc::MemoryManager* const)>(&DOMImplementationStringDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createDocument", static_cast<xercesc::DOMDocument*(*)(xercesc::DOMImplementation&, const STR&, const STR&, xercesc::DOMDocumentType*)>(&DOMImplementationStringDefVisitor::createDocument), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getFeature", &DOMImplementationStringDefVisitor::getFeature, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	;
}

static bool hasFeature(xercesc::DOMImplementation& self, const STR& feature, const STR& version) {
	XMLString buff1(feature), buff2(version);
	return self.hasFeature(buff1.ptr(), buff2.ptr());
}

static xercesc::DOMDocumentType* createDocumentType(xercesc::DOMImplementation& self, const STR& qualifiedName, const STR& publicId, const STR& systemId) {
	XMLString buff1(qualifiedName), buff2(publicId), buff3(systemId);
	return self.createDocumentType(buff1.ptr(), buff2.ptr(), buff3.ptr());
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const STR& namespaceURI, const STR& qualifiedName, xercesc::DOMDocumentType* doctype, xercesc::MemoryManager* const manager) {
	XMLString buff1(namespaceURI), buff2(qualifiedName);
	return self.createDocument(buff1.ptr(), buff2.ptr(), doctype, manager);
}

static xercesc::DOMDocument* createDocument(xercesc::DOMImplementation& self, const STR& namespaceURI, const STR& qualifiedName, xercesc::DOMDocumentType* doctype) {
	return DOMImplementationStringDefVisitor::createDocument(self, namespaceURI, qualifiedName, doctype, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void* getFeature(xercesc::DOMImplementation& self, const STR& feature, const STR& version) {
	XMLString buff1(feature), buff2(version);
	return self.getFeature(buff1.ptr(), buff2.ptr());
}

};

void DOMImplementation_init(void) {
	//! xercesc::DOMImplementation
	boost::python::class_<xercesc::DOMImplementation, boost::noncopyable, boost::python::bases<xercesc::DOMImplementationLS> >("DOMImplementation", boost::python::no_init)
			.def(DOMImplementationDefVisitor())
			.def(DOMImplementationStringDefVisitor<XMLString>())
			.def(DOMImplementationStringDefVisitor<std::string>())
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
