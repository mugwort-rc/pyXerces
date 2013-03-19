/*
 * DOMLocator.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "DOMLocator.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>

#include <xercesc/dom/DOMLocator.hpp>

namespace pyxerces {

class DOMLocatorWrapper
: public xercesc::DOMLocator, public boost::python::wrapper<xercesc::DOMLocator>
{
public:
XMLFileLoc getLineNumber() const {
	return this->get_override("getLineNumber")();
}

XMLFileLoc getColumnNumber() const {
	return this->get_override("getColumnNumber")();
}

XMLFilePos getByteOffset() const {
	return this->get_override("getByteOffset")();
}

XMLFilePos getUtf16Offset() const {
	return this->get_override("getUtf16Offset")();
}

xercesc::DOMNode* getRelatedNode() const {
	return this->get_override("getRelatedNode")();
}

const XMLCh* getURI() const {
	return this->get_override("getURI")();
}

};

void DOMLocator_init(void) {
	//! xercesc::DOMLocator
	boost::python::class_<DOMLocatorWrapper, boost::noncopyable>("DOMLocator")
			.def("getLineNumber", boost::python::pure_virtual(&xercesc::DOMLocator::getLineNumber))
			.def("getColumnNumber", boost::python::pure_virtual(&xercesc::DOMLocator::getColumnNumber))
			.def("getByteOffset", boost::python::pure_virtual(&xercesc::DOMLocator::getByteOffset))
			.def("getUtf16Offset", boost::python::pure_virtual(&xercesc::DOMLocator::getUtf16Offset))
			.def("getRelatedNode", boost::python::pure_virtual(&xercesc::DOMLocator::getRelatedNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURI", boost::python::pure_virtual(&xercesc::DOMLocator::getURI), boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
