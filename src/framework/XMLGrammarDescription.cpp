/*
 * XMLGrammarDescription.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLGrammarDescription.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLGrammarDescription.hpp>

#include "../internal/XSerializable.h"

namespace pyxerces {

class XMLGrammarDescriptionWrapper
: public xercesc::XMLGrammarDescription, public boost::python::wrapper<xercesc::XMLGrammarDescription>
{
public:
xercesc::Grammar::GrammarType   getGrammarType() const {
	return this->get_override("getGrammarType")();
}

const XMLCh* getGrammarKey() const {
	return this->get_override("getGrammarKey")();
}

PyDECL_XSERIALIZABLEWrapper

};

void XMLGrammarDescription_init(void) {
	//! xercesc::XMLGrammarDescription
	boost::python::class_<XMLGrammarDescriptionWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLGrammarDescription")
			.def("getGrammarType", boost::python::pure_virtual(&xercesc::XMLGrammarDescription::getGrammarType))
			.def("getGrammarKey", boost::python::pure_virtual(&xercesc::XMLGrammarDescription::getGrammarKey), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::XMLGrammarDescription::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(XMLGrammarDescription)
			;
}

} /* namespace pyxerces */
