/*
 * DOMText.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMText.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMText.hpp>

namespace pyxerces {

void DOMText_init(void) {
	//! xercesc::DOMText
	boost::python::class_<xercesc::DOMText, boost::noncopyable, boost::python::bases<xercesc::DOMCharacterData> >("DOMText", boost::python::no_init)
			.def("splitText", &xercesc::DOMText::splitText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getIsElementContentWhitespace", &xercesc::DOMText::getIsElementContentWhitespace)
			.def("getWholeText", &xercesc::DOMText::getWholeText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("replaceWholeText", &xercesc::DOMText::replaceWholeText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isIgnorableWhitespace", &xercesc::DOMText::isIgnorableWhitespace)
			;
}

} /* namespace pyxerces */
