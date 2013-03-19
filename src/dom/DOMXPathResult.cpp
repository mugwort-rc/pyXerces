/*
 * DOMXPathResult.cpp
 *
 *  Created on: 2013/02/24
 *      Author: mugwort_rc
 */

#include "DOMXPathResult.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMXPathNSResolver.hpp>
#include <xercesc/dom/DOMXPathExpression.hpp>
#include <xercesc/dom/DOMTypeInfo.hpp>
#include <xercesc/dom/DOMNode.hpp>

#include <xercesc/dom/DOMXPathResult.hpp>

namespace pyxerces {

class DOMXPathResultWrapper
: public xercesc::DOMXPathResult, public boost::python::wrapper<xercesc::DOMXPathResult>
{
public:
ResultType getResultType() const {
	return this->get_override("getResultType")();
}

const xercesc::DOMTypeInfo *getTypeInfo() const {
	return this->get_override("getTypeInfo")();
}

bool isNode() const {
	return this->get_override("isNode")();
}

bool getBooleanValue() const {
	return this->get_override("getBooleanValue")();
}

int getIntegerValue() const {
	return this->get_override("getIntegerValue")();
}

double getNumberValue() const {
	return this->get_override("getNumberValue")();
}

const XMLCh* getStringValue() const {
	return this->get_override("getStringValue")();
}

xercesc::DOMNode* getNodeValue() const {
	return this->get_override("getNodeValue")();
}

bool iterateNext() {
	return this->get_override("iterateNext")();
}

bool getInvalidIteratorState() const {
	return this->get_override("getInvalidIteratorState")();
}

bool snapshotItem(XMLSize_t index) {
	return this->get_override("snapshotItem")(index);
}

XMLSize_t getSnapshotLength() const {
	return this->get_override("getSnapshotLength")();
}

void release() {
	this->get_override("release")();
}

};

void DOMXPathResult_init(void) {
	//! xercesc::DOMXPathResult
	auto DOMXPathResult = boost::python::class_<DOMXPathResultWrapper, boost::noncopyable>("DOMXPathResult")
			.def("getResultType", boost::python::pure_virtual(&xercesc::DOMXPathResult::getResultType))
			.def("getTypeInfo", boost::python::pure_virtual(&xercesc::DOMXPathResult::getTypeInfo), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isNode", boost::python::pure_virtual(&xercesc::DOMXPathResult::isNode))
			.def("getBooleanValue", boost::python::pure_virtual(&xercesc::DOMXPathResult::getBooleanValue))
			.def("getIntegerValue", boost::python::pure_virtual(&xercesc::DOMXPathResult::getIntegerValue))
			.def("getNumberValue", boost::python::pure_virtual(&xercesc::DOMXPathResult::getNumberValue))
			.def("getStringValue", boost::python::pure_virtual(&xercesc::DOMXPathResult::getStringValue), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNodeValue", boost::python::pure_virtual(&xercesc::DOMXPathResult::getNodeValue), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("iterateNext", boost::python::pure_virtual(&xercesc::DOMXPathResult::iterateNext))
			.def("getInvalidIteratorState", boost::python::pure_virtual(&xercesc::DOMXPathResult::getInvalidIteratorState))
			.def("snapshotItem", boost::python::pure_virtual(&xercesc::DOMXPathResult::snapshotItem))
			.def("getSnapshotLength", boost::python::pure_virtual(&xercesc::DOMXPathResult::getSnapshotLength))
			.def("release", boost::python::pure_virtual(&xercesc::DOMXPathResult::release))
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
