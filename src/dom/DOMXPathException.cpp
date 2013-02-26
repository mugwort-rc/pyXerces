/*
 * DOMXPathException.cpp
 *
 *  Created on: 2013/02/24
 *      Author: mugwort_rc
 */

#include "DOMXPathException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMXPathException.hpp>

namespace pyxerces {

void DOMXPathException_init(void) {
	//! xercesc::DOMXPathException
	auto DOMXPathException = boost::python::class_<xercesc::DOMXPathException, boost::noncopyable, boost::python::bases<xercesc::DOMException> >("DOMXPathException")
			.def(boost::python::init<short, short, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::DOMXPathException&>())
			;
	boost::python::scope DOMXPathExceptionScope = DOMXPathException;
	//! xercesc::DOMXPathException::ExceptionCode
	boost::python::enum_<xercesc::DOMXPathException::ExceptionCode>("ExceptionCode")
			.value("INVALID_EXPRESSION_ERR", xercesc::DOMXPathException::INVALID_EXPRESSION_ERR)
			.value("TYPE_ERR", xercesc::DOMXPathException::TYPE_ERR)
			.value("NO_RESULT_ERROR", xercesc::DOMXPathException::NO_RESULT_ERROR)
			.export_values()
			;
}

} /* namespace pyxerces */