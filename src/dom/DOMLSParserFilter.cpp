/*
 * DOMLSParserFilter.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSParserFilter.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNode.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMElement.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSParserFilter.hpp>

namespace pyxerces {

void DOMLSParserFilter_init(void) {
	//! xercesc::DOMLSParserFilter
	auto DOMLSParserFilter = boost::python::class_<xercesc::DOMLSParserFilter, boost::noncopyable>("DOMLSParserFilter", boost::python::no_init)
			.def("acceptNode", &xercesc::DOMLSParserFilter::acceptNode)
			.def("startElement", &xercesc::DOMLSParserFilter::startElement)
			.def("getWhatToShow", &xercesc::DOMLSParserFilter::getWhatToShow)
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
