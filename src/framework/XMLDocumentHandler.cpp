/*
 * XMLDocumentHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLDocumentHandler.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLElementDecl.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLEntityDecl.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLDocumentHandler.hpp>

namespace pyxerces {

void XMLDocumentHandler_init(void) {
	//! xercesc::XMLDocumentHandler
	boost::python::class_<xercesc::XMLDocumentHandler, boost::noncopyable>("XMLDocumentHandler", boost::python::no_init)
			.def("docCharacters", &xercesc::XMLDocumentHandler::docCharacters)
			.def("docComment", &xercesc::XMLDocumentHandler::docComment)
			.def("docPI", &xercesc::XMLDocumentHandler::docPI)
			.def("endDocument", &xercesc::XMLDocumentHandler::endDocument)
			.def("endElement", &xercesc::XMLDocumentHandler::endElement)
			.def("endEntityReference", &xercesc::XMLDocumentHandler::endEntityReference)
			.def("ignorableWhitespace", &xercesc::XMLDocumentHandler::ignorableWhitespace)
			.def("resetDocument", &xercesc::XMLDocumentHandler::resetDocument)
			.def("startDocument", &xercesc::XMLDocumentHandler::startDocument)
			.def("startElement", &xercesc::XMLDocumentHandler::startElement)
			.def("startEntityReference", &xercesc::XMLDocumentHandler::startEntityReference)
			.def("XMLDecl", &xercesc::XMLDocumentHandler::XMLDecl)
			;
}

} /* namespace pyxerces */
