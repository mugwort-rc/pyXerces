/*
 * DOMNodeFilter.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMNodeFilter.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMNodeFilter.hpp>

namespace pyxerces {

class DOMNodeFilterWrapper
: public xercesc::DOMNodeFilter, public boost::python::wrapper<xercesc::DOMNodeFilter>
{
public:
FilterAction acceptNode (const xercesc::DOMNode* node) const {
	return this->get_override("acceptNode")(boost::python::ptr(node));
}

};

void DOMNodeFilter_init(void) {
	//! xercesc::DOMNodeFilter
	auto DOMNodeFilter = boost::python::class_<DOMNodeFilterWrapper, boost::noncopyable>("DOMNodeFilter")
			.def("acceptNode", boost::python::pure_virtual(&xercesc::DOMNodeFilter::acceptNode))
			;
	boost::python::scope DOMNodeFilterScope = DOMNodeFilter;
	//! xercesc::DOMNodeFilter::FilterAction
	boost::python::enum_<xercesc::DOMNodeFilter::FilterAction>("FilterAction")
			.value("FILTER_ACCEPT", xercesc::DOMNodeFilter::FILTER_ACCEPT)
			.value("FILTER_REJECT", xercesc::DOMNodeFilter::FILTER_REJECT)
			.value("FILTER_SKIP", xercesc::DOMNodeFilter::FILTER_SKIP)
			.export_values()
			;
	//! xercesc::DOMNodeFilter::ShowTypeMasks
	boost::python::enum_<xercesc::DOMNodeFilter::ShowTypeMasks>("ShowTypeMasks")
			.value("SHOW_ALL", xercesc::DOMNodeFilter::SHOW_ALL)
			.value("SHOW_ELEMENT", xercesc::DOMNodeFilter::SHOW_ELEMENT)
			.value("SHOW_ATTRIBUTE", xercesc::DOMNodeFilter::SHOW_ATTRIBUTE)
			.value("SHOW_TEXT", xercesc::DOMNodeFilter::SHOW_TEXT)
			.value("SHOW_CDATA_SECTION", xercesc::DOMNodeFilter::SHOW_CDATA_SECTION)
			.value("SHOW_ENTITY_REFERENCE", xercesc::DOMNodeFilter::SHOW_ENTITY_REFERENCE)
			.value("SHOW_ENTITY", xercesc::DOMNodeFilter::SHOW_ENTITY)
			.value("SHOW_PROCESSING_INSTRUCTION", xercesc::DOMNodeFilter::SHOW_PROCESSING_INSTRUCTION)
			.value("SHOW_COMMENT", xercesc::DOMNodeFilter::SHOW_COMMENT)
			.value("SHOW_DOCUMENT", xercesc::DOMNodeFilter::SHOW_DOCUMENT)
			.value("SHOW_DOCUMENT_TYPE", xercesc::DOMNodeFilter::SHOW_DOCUMENT_TYPE)
			.value("SHOW_DOCUMENT_FRAGMENT", xercesc::DOMNodeFilter::SHOW_DOCUMENT_FRAGMENT)
			.value("SHOW_NOTATION", xercesc::DOMNodeFilter::SHOW_NOTATION)
			.export_values()
			;
}

} /* namespace pyxerces */
