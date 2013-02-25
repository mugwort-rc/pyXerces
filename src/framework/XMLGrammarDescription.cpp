/*
 * XMLGrammarDescription.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLGrammarDescription.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLGrammarDescription.hpp>

namespace pyxerces {

void XMLGrammarDescription_init(void) {
	//! xercesc::XMLGrammarDescription
	boost::python::class_<xercesc::XMLGrammarDescription, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLGrammarDescription", boost::python::no_init)
			.def("getGrammarType", &xercesc::XMLGrammarDescription::getGrammarType)
			.def("getGrammarKey", &xercesc::XMLGrammarDescription::getGrammarKey, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::XMLGrammarDescription::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isSerializable", &xercesc::XMLGrammarDescription::isSerializable)
			.def("getProtoType", &xercesc::XMLGrammarDescription::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serialize", &xercesc::XMLGrammarDescription::serialize)
			;
}

} /* namespace pyxerces */
