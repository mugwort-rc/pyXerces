/*
 * XMLEntityHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLEntityHandler.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLBuffer.hpp>
#include <xercesc/util/XMLResourceIdentifier.hpp>

#include <xercesc/framework/XMLEntityHandler.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLEntityHandlerDefVisitor
: public boost::python::def_visitor<XMLEntityHandlerDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("expandSystemId", &XMLEntityHandlerDefVisitor::expandSystemId)
	;
}

static bool expandSystemId(xercesc::XMLEntityHandler& self, const STR& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return self.expandSystemId(buff.ptr(), toFill);
}

};

class XMLEntityHandlerWrapper
: public xercesc::XMLEntityHandler, public boost::python::wrapper<xercesc::XMLEntityHandler>
{
public:
void endInputSource(const xercesc::InputSource& inputSource) {
	this->get_override("endInputSource")(boost::ref(inputSource));
}

bool expandSystemId(const XMLCh* const systemId, xercesc::XMLBuffer& toFill) {
	return this->get_override("expandSystemId")(XMLString(systemId), boost::ref(toFill));
}

void resetEntities() {
	this->get_override("resetEntities")();
}

xercesc::InputSource* resolveEntity(xercesc::XMLResourceIdentifier* resourceIdentifier) {
	return this->get_override("resolveEntity")(boost::python::ptr(resourceIdentifier));
}

void startInputSource(const xercesc::InputSource& inputSource) {
	this->get_override("startInputSource")(boost::ref(inputSource));
}

};

void XMLEntityHandler_init(void) {
	//! xercesc::XMLEntityHandler
	boost::python::class_<XMLEntityHandlerWrapper, boost::noncopyable>("XMLEntityHandler")
			.def(XMLEntityHandlerDefVisitor<XMLString>())
			.def(XMLEntityHandlerDefVisitor<std::string>())
			.def("endInputSource", boost::python::pure_virtual(&xercesc::XMLEntityHandler::endInputSource))
			.def("expandSystemId", boost::python::pure_virtual(&xercesc::XMLEntityHandler::expandSystemId))
			.def("resetEntities", boost::python::pure_virtual(&xercesc::XMLEntityHandler::resetEntities))
			.def("resolveEntity", boost::python::pure_virtual(&xercesc::XMLEntityHandler::resolveEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", boost::python::pure_virtual(&xercesc::XMLEntityHandler::startInputSource))
			;
}

} /* namespace pyxerces */
