/*
 * DOMRange.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMRange.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMDocumentFragment.hpp>

#include <xercesc/dom/DOMRange.hpp>

namespace pyxerces {

class DOMRangeWrapper
: public xercesc::DOMRange, public boost::python::wrapper<xercesc::DOMRange>
{
public:
xercesc::DOMNode* getStartContainer() const {
	return this->get_override("getStartContainer")();
}

XMLSize_t getStartOffset() const {
	return this->get_override("getStartOffset")();
}

xercesc::DOMNode* getEndContainer() const {
	return this->get_override("getEndContainer")();
}

XMLSize_t getEndOffset() const {
	return this->get_override("getEndOffset")();
}

bool getCollapsed() const {
	return this->get_override("getCollapsed")();
}

const xercesc::DOMNode* getCommonAncestorContainer() const {
	return this->get_override("getCommonAncestorContainer")();
}

void setStart(const xercesc::DOMNode *refNode, XMLSize_t offset) {
	this->get_override("setStart")(boost::python::ptr(refNode), offset);
}

void setEnd(const xercesc::DOMNode *refNode, XMLSize_t offset) {
	this->get_override("setEnd")(boost::python::ptr(refNode), offset);
}

void setStartBefore(const xercesc::DOMNode *refNode) {
	this->get_override("setStartBefore")(boost::python::ptr(refNode));
}

void setStartAfter(const xercesc::DOMNode *refNode) {
	this->get_override("setStartAfter")(boost::python::ptr(refNode));
}

void setEndBefore(const xercesc::DOMNode *refNode) {
	this->get_override("setEndBefore")(boost::python::ptr(refNode));
}

void setEndAfter(const xercesc::DOMNode *refNode) {
	this->get_override("setEndAfter")(boost::python::ptr(refNode));
}

void collapse(bool toStart) {
	this->get_override("collapse")(toStart);
}

void selectNode(const xercesc::DOMNode *refNode) {
	this->get_override("selectNode")(boost::python::ptr(refNode));
}

void selectNodeContents(const xercesc::DOMNode *refNode) {
	this->get_override("selectNodeContents")(boost::python::ptr(refNode));
}

short compareBoundaryPoints(CompareHow how, const xercesc::DOMRange* sourceRange) const {
	return this->get_override("compareBoundaryPoints")(how, boost::python::ptr(sourceRange));
}

void deleteContents() {
	this->get_override("deleteContents")();
}

xercesc::DOMDocumentFragment* extractContents() {
	return this->get_override("extractContents")();
}

xercesc::DOMDocumentFragment* cloneContents() const {
	return this->get_override("cloneContents")();
}

void insertNode(xercesc::DOMNode *newNode) {
	this->get_override("insertNode")(boost::python::ptr(newNode));
}

void surroundContents(xercesc::DOMNode *newParent) {
	this->get_override("surroundContents")(boost::python::ptr(newParent));
}

DOMRange* cloneRange() const {
	return this->get_override("cloneRange")();
}

const XMLCh* toString() const {
	return this->get_override("toString")();
}

void detach() {
	this->get_override("detach")();
}

void release() {
	this->get_override("release")();
}

};

void DOMRange_init(void) {
	//! xercesc::DOMRange
	auto DOMRange = boost::python::class_<DOMRangeWrapper, boost::noncopyable>("DOMRange")
			.def("getStartContainer", boost::python::pure_virtual(&xercesc::DOMRange::getStartContainer), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getStartOffset", boost::python::pure_virtual(&xercesc::DOMRange::getStartOffset))
			.def("getEndContainer", boost::python::pure_virtual(&xercesc::DOMRange::getEndContainer), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEndOffset", boost::python::pure_virtual(&xercesc::DOMRange::getEndOffset))
			.def("getCollapsed", boost::python::pure_virtual(&xercesc::DOMRange::getCollapsed))
			.def("getCommonAncestorContainer", boost::python::pure_virtual(&xercesc::DOMRange::getCommonAncestorContainer), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setStart", boost::python::pure_virtual(&xercesc::DOMRange::setStart))
			.def("setEnd", boost::python::pure_virtual(&xercesc::DOMRange::setEnd))
			.def("setStartBefore", boost::python::pure_virtual(&xercesc::DOMRange::setStartBefore))
			.def("setStartAfter", boost::python::pure_virtual(&xercesc::DOMRange::setStartAfter))
			.def("setEndBefore", boost::python::pure_virtual(&xercesc::DOMRange::setEndBefore))
			.def("setEndAfter", boost::python::pure_virtual(&xercesc::DOMRange::setEndAfter))
			.def("collapse", boost::python::pure_virtual(&xercesc::DOMRange::collapse))
			.def("selectNode", boost::python::pure_virtual(&xercesc::DOMRange::selectNode))
			.def("selectNodeContents", boost::python::pure_virtual(&xercesc::DOMRange::selectNodeContents))
			.def("compareBoundaryPoints", boost::python::pure_virtual(&xercesc::DOMRange::compareBoundaryPoints))
			.def("deleteContents", boost::python::pure_virtual(&xercesc::DOMRange::deleteContents))
			.def("extractContents", boost::python::pure_virtual(&xercesc::DOMRange::extractContents), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("cloneContents", boost::python::pure_virtual(&xercesc::DOMRange::cloneContents), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("insertNode", boost::python::pure_virtual(&xercesc::DOMRange::insertNode))
			.def("surroundContents", boost::python::pure_virtual(&xercesc::DOMRange::surroundContents))
			.def("cloneRange", boost::python::pure_virtual(&xercesc::DOMRange::cloneRange), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("toString", boost::python::pure_virtual(&xercesc::DOMRange::toString), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("detach", boost::python::pure_virtual(&xercesc::DOMRange::detach))
			.def("release", boost::python::pure_virtual(&xercesc::DOMRange::release))
			;
	boost::python::scope DOMRangeScope = DOMRange;
	//! xercesc::DOMRange::CompareHow
	boost::python::enum_<xercesc::DOMRange::CompareHow>("CompareHow")
			.value("START_TO_START", xercesc::DOMRange::START_TO_START)
			.value("START_TO_END", xercesc::DOMRange::START_TO_END)
			.value("END_TO_END", xercesc::DOMRange::END_TO_END)
			.value("END_TO_START", xercesc::DOMRange::END_TO_START)
			;
}

} /* namespace pyxerces */
