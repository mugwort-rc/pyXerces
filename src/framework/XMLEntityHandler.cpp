/*
 * XMLEntityHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLEntityHandler.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>				//!< for forward declaration
#include <xercesc/framework/XMLBuffer.hpp>			//!< for forward declaration
#include <xercesc/util/XMLResourceIdentifier.hpp>	//!< for forward declaration
#include <xercesc/framework/XMLEntityHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class XMLEntityHandlerDefVisitor
: public boost::python::def_visitor<XMLEntityHandlerDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("expandSystemId", static_cast<bool(*)(xercesc::XMLEntityHandler&, const XMLString&, xercesc::XMLBuffer&)>(&XMLEntityHandlerDefVisitor::expandSystemId))
	.def("expandSystemId", static_cast<bool(*)(xercesc::XMLEntityHandler&, const std::string&, xercesc::XMLBuffer&)>(&XMLEntityHandlerDefVisitor::expandSystemId))
	;
}

static bool expandSystemId(xercesc::XMLEntityHandler& self, const XMLString& systemId, xercesc::XMLBuffer& toFill) {
	return self.expandSystemId(systemId.ptr(), toFill);
}

static bool expandSystemId(xercesc::XMLEntityHandler& self, const std::string& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return XMLEntityHandlerDefVisitor::expandSystemId(self, buff, toFill);
}

};

void XMLEntityHandler_init(void) {
	//! xercesc::XMLEntityHandler
	boost::python::class_<xercesc::XMLEntityHandler, boost::noncopyable>("XMLEntityHandler", boost::python::no_init)
			.def(XMLEntityHandlerDefVisitor())
			.def("endInputSource", &xercesc::XMLEntityHandler::endInputSource)
			.def("expandSystemId", &xercesc::XMLEntityHandler::expandSystemId)
			.def("resetEntities", &xercesc::XMLEntityHandler::resetEntities)
			.def("resolveEntity", &xercesc::XMLEntityHandler::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", &xercesc::XMLEntityHandler::startInputSource)
			;
}

} /* namespace pyxerces */
