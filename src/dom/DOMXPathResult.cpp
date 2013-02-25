/*
 * DOMXPathResult.cpp
 *
 *  Created on: 2013/02/24
 *      Author: mugwort_rc
 */

#include "DOMXPathResult.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMXPathExpression.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMTypeInfo.hpp>			//!< for forward declaration
#include <xercesc/dom/DOMNode.hpp>				//!< for forward declaration
#include <xercesc/dom/DOMXPathResult.hpp>

namespace pyxerces {

void DOMXPathResult_init(void) {
	//! xercesc::DOMXPathResult
	auto DOMXPathResult = boost::python::class_<xercesc::DOMXPathResult, boost::noncopyable>("DOMXPathResult", boost::python::no_init)
			.def("getResultType", &xercesc::DOMXPathResult::getResultType)
			.def("getTypeInfo", &xercesc::DOMXPathResult::getTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isNode", &xercesc::DOMXPathResult::isNode)
			.def("getBooleanValue", &xercesc::DOMXPathResult::getBooleanValue)
			.def("getIntegerValue", &xercesc::DOMXPathResult::getIntegerValue)
			.def("getNumberValue", &xercesc::DOMXPathResult::getNumberValue)
			.def("getStringValue", &xercesc::DOMXPathResult::getStringValue, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeValue", &xercesc::DOMXPathResult::getNodeValue, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("iterateNext", &xercesc::DOMXPathResult::iterateNext)
			.def("getInvalidIteratorState", &xercesc::DOMXPathResult::getInvalidIteratorState)
			.def("snapshotItem", &xercesc::DOMXPathResult::snapshotItem)
			.def("getSnapshotLength", &xercesc::DOMXPathResult::getSnapshotLength)
			.def("release", &xercesc::DOMXPathResult::release)
			;
	boost::python::scope DOMXPathResultScope = DOMXPathResult;
	//! xercesc::DOMXPathResult::ResultType
	boost::python::enum_<xercesc::DOMXPathResult::ResultType>("ResultType")
			.value("ANY_TYPE", xercesc::DOMXPathResult::ANY_TYPE)
			.value("NUMBER_TYPE", xercesc::DOMXPathResult::NUMBER_TYPE)
			.value("STRING_TYPE", xercesc::DOMXPathResult::STRING_TYPE)
			.value("BOOLEAN_TYPE", xercesc::DOMXPathResult::BOOLEAN_TYPE)
			.value("UNORDERED_NODE_ITERATOR_TYPE", xercesc::DOMXPathResult::UNORDERED_NODE_ITERATOR_TYPE)
			.value("ORDERED_NODE_ITERATOR_TYPE", xercesc::DOMXPathResult::ORDERED_NODE_ITERATOR_TYPE)
			.value("UNORDERED_NODE_SNAPSHOT_TYPE", xercesc::DOMXPathResult::UNORDERED_NODE_SNAPSHOT_TYPE)
			.value("ORDERED_NODE_SNAPSHOT_TYPE", xercesc::DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE)
			.value("ANY_UNORDERED_NODE_TYPE", xercesc::DOMXPathResult::ANY_UNORDERED_NODE_TYPE)
			.value("FIRST_ORDERED_NODE_TYPE", xercesc::DOMXPathResult::FIRST_ORDERED_NODE_TYPE)
			.value("FIRST_RESULT_TYPE", xercesc::DOMXPathResult::FIRST_RESULT_TYPE)
			.value("ITERATOR_RESULT_TYPE", xercesc::DOMXPathResult::ITERATOR_RESULT_TYPE)
			.value("SNAPSHOT_RESULT_TYPE", xercesc::DOMXPathResult::SNAPSHOT_RESULT_TYPE)
			.export_values()
			;
}

} /* namespace pyxerces */
