/*
 * DOMLSParserFilter.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSParserFilter.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMElement.hpp>

#include <xercesc/dom/DOMLSParserFilter.hpp>

namespace pyxerces {

class DOMLSParserFilterWrapper
: public xercesc::DOMLSParserFilter, public boost::python::wrapper<xercesc::DOMLSParserFilter>
{
public:
DOMLSParserFilterWrapper()
{}
~DOMLSParserFilterWrapper()
{}

xercesc::DOMLSParserFilter::FilterAction acceptNode(xercesc::DOMNode* node) {
	return this->get_override("acceptNode")(boost::python::ptr(node));
}

xercesc::DOMLSParserFilter::FilterAction startElement(xercesc::DOMElement* node) {
	return this->get_override("startElement")(boost::python::ptr(node));
}

xercesc::DOMNodeFilter::ShowType getWhatToShow() const {
	return this->get_override("getWhatToShow")();
}

};

void DOMLSParserFilter_init(void) {
	//! xercesc::DOMLSParserFilter
	auto DOMLSParserFilter = boost::python::class_<DOMLSParserFilterWrapper, boost::noncopyable>("DOMLSParserFilter")
			.def("acceptNode", boost::python::pure_virtual(&xercesc::DOMLSParserFilter::acceptNode))
			.def("startElement", boost::python::pure_virtual(&xercesc::DOMLSParserFilter::startElement))
			.def("getWhatToShow", boost::python::pure_virtual(&xercesc::DOMLSParserFilter::getWhatToShow))
			;

	boost::python::scope DOMLSParserFilterScope = DOMLSParserFilter;
	//! xercesc::DOMLSParserFilter::FilterAction
	boost::python::enum_<xercesc::DOMLSParserFilter::FilterAction>("FilterAction")
			.value("FILTER_ACCEPT", xercesc::DOMLSParserFilter::FILTER_ACCEPT)
			.value("FILTER_REJECT", xercesc::DOMLSParserFilter::FILTER_REJECT)
			.value("FILTER_SKIP", xercesc::DOMLSParserFilter::FILTER_SKIP)
			.value("FILTER_INTERRUPT", xercesc::DOMLSParserFilter::FILTER_INTERRUPT)
			;
}

} /* namespace pyxerces */
