/*
 * DOMLSOutput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSOutput.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLFormatter.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSOutput.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMLSOutputDefVisitor
: public boost::python::def_visitor<DOMLSOutputDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setEncoding", static_cast<void(*)(xercesc::DOMLSOutput&, const XMLString&)>(&DOMLSOutputDefVisitor::setEncoding))
	.def("setEncoding", static_cast<void(*)(xercesc::DOMLSOutput&, const std::string&)>(&DOMLSOutputDefVisitor::setEncoding))
	.def("setSystemId", static_cast<void(*)(xercesc::DOMLSOutput&, const XMLString&)>(&DOMLSOutputDefVisitor::setSystemId))
	.def("setSystemId", static_cast<void(*)(xercesc::DOMLSOutput&, const std::string&)>(&DOMLSOutputDefVisitor::setSystemId))
	;
}

static void setEncoding(xercesc::DOMLSOutput& self, const XMLString& encodingStr) {
	self.setEncoding(encodingStr.ptr());
}

static void setEncoding(xercesc::DOMLSOutput& self, const std::string& encodingStr) {
	XMLString buff(encodingStr);
	DOMLSOutputDefVisitor::setEncoding(self, buff);
}

static void setSystemId(xercesc::DOMLSOutput& self, const XMLString& systemId) {
	self.setSystemId(systemId.ptr());
}

static void setSystemId(xercesc::DOMLSOutput& self, const std::string& systemId) {
	XMLString buff(systemId);
	DOMLSOutputDefVisitor::setSystemId(self, buff);
}

};

void DOMLSOutput_init(void) {
	//! xercesc::DOMLSOutput
	boost::python::class_<xercesc::DOMLSOutput, boost::noncopyable>("DOMLSOutput", boost::python::no_init)
			.def(DOMLSOutputDefVisitor())
			.def("getByteStream", &xercesc::DOMLSOutput::getByteStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::DOMLSOutput::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMLSOutput::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setByteStream", &xercesc::DOMLSOutput::setByteStream)
			.def("setEncoding", &xercesc::DOMLSOutput::setEncoding)
			.def("setSystemId", &xercesc::DOMLSOutput::setSystemId)
			.def("release", &xercesc::DOMLSOutput::release)
			;
}

} /* namespace pyxerces */
