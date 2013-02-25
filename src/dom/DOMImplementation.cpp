/*
 * DOMImplementation.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementation.h"

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
	;
}

static xercesc::DOMImplementationLS* toDOMImplementationLS(xercesc::DOMImplementation& self) {
	return reinterpret_cast<xercesc::DOMImplementationLS*>(&self);
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
