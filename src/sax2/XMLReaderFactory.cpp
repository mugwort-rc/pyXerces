/*
 * XMLReaderFactory.cpp
 *
 *  Created on: 2013/06/12
 *      Author: mugwort_rc
 */

#include "XMLReaderFactory.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>

#include <xercesc/sax2/XMLReaderFactory.hpp>

namespace pyxerces {

//! xercesc::XMLReaderFactory
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLReaderFactoryCreateXMLReaderOverloads, xercesc::XMLReaderFactory::createXMLReader, 0, 2)

void XMLReaderFactory_init(void) {
	//! xercesc::XMLReaderFactory
	boost::python::class_<xercesc::XMLReaderFactory, boost::noncopyable>("XMLReaderFactory", boost::python::no_init)
			.def("createXMLReader", static_cast<xercesc::SAX2XMLReader*(*)(xercesc::MemoryManager*, xercesc::XMLGrammarPool*)>(&xercesc::XMLReaderFactory::createXMLReader), XMLReaderFactoryCreateXMLReaderOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("createXMLReader", static_cast<xercesc::SAX2XMLReader*(*)(const XMLCh*)>(&xercesc::XMLReaderFactory::createXMLReader), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("createXMLReader")
			;
}

} /* namespace pyxerces */
