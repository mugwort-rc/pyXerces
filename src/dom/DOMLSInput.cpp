/*
 * DOMLSInput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSInput.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>	//!< for forward declaration
#include <xercesc/dom/DOMLSInput.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMLSInputDefVisitor
: public boost::python::def_visitor<DOMLSInputDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setStringData", static_cast<void(*)(xercesc::DOMLSInput&, const XMLString&)>(&DOMLSInputDefVisitor::setStringData))
	.def("setStringData", static_cast<void(*)(xercesc::DOMLSInput&, const std::string&)>(&DOMLSInputDefVisitor::setStringData))
	.def("setEncoding", static_cast<void(*)(xercesc::DOMLSInput&, const XMLString&)>(&DOMLSInputDefVisitor::setEncoding))
	.def("setEncoding", static_cast<void(*)(xercesc::DOMLSInput&, const std::string&)>(&DOMLSInputDefVisitor::setEncoding))
	.def("setPublicId", static_cast<void(*)(xercesc::DOMLSInput&, const XMLString&)>(&DOMLSInputDefVisitor::setPublicId))
	.def("setPublicId", static_cast<void(*)(xercesc::DOMLSInput&, const std::string&)>(&DOMLSInputDefVisitor::setPublicId))
	.def("setSystemId", static_cast<void(*)(xercesc::DOMLSInput&, const XMLString&)>(&DOMLSInputDefVisitor::setSystemId))
	.def("setSystemId", static_cast<void(*)(xercesc::DOMLSInput&, const std::string&)>(&DOMLSInputDefVisitor::setSystemId))
	.def("setBaseURI", static_cast<void(*)(xercesc::DOMLSInput&, const XMLString&)>(&DOMLSInputDefVisitor::setBaseURI))
	.def("setBaseURI", static_cast<void(*)(xercesc::DOMLSInput&, const std::string&)>(&DOMLSInputDefVisitor::setBaseURI))
	;
}

static void setStringData(xercesc::DOMLSInput& self, const XMLString& data) {
	self.setStringData(data.ptr());
}

static void setStringData(xercesc::DOMLSInput& self, const std::string& data) {
	XMLString buff(data);
	DOMLSInputDefVisitor::setStringData(self, buff);
}

static void setEncoding(xercesc::DOMLSInput& self, const XMLString& encodingStr) {
	self.setEncoding(encodingStr.ptr());
}

static void setEncoding(xercesc::DOMLSInput& self, const std::string& encodingStr) {
	XMLString buff(encodingStr);
	DOMLSInputDefVisitor::setEncoding(self, buff);
}

static void setPublicId(xercesc::DOMLSInput& self, const XMLString& publicId) {
	self.setPublicId(publicId.ptr());
}

static void setPublicId(xercesc::DOMLSInput& self, const std::string& publicId) {
	XMLString buff(publicId);
	DOMLSInputDefVisitor::setPublicId(self, buff);
}

static void setSystemId(xercesc::DOMLSInput& self, const XMLString& systemId) {
	self.setSystemId(systemId.ptr());
}

static void setSystemId(xercesc::DOMLSInput& self, const std::string& systemId) {
	XMLString buff(systemId);
	DOMLSInputDefVisitor::setSystemId(self, buff);
}

static void setBaseURI(xercesc::DOMLSInput& self, const XMLString& baseURI) {
	self.setBaseURI(baseURI.ptr());
}

static void setBaseURI(xercesc::DOMLSInput& self, const std::string& baseURI) {
	XMLString buff(baseURI);
	DOMLSInputDefVisitor::setBaseURI(self, buff);
}

};

void DOMLSInput_init(void) {
	//! xercesc::DOMLSInput
	boost::python::class_<xercesc::DOMLSInput, boost::noncopyable>("DOMLSInput", boost::python::no_init)
			.def(DOMLSInputDefVisitor())
			.def("getStringData", &xercesc::DOMLSInput::getStringData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getByteStream", &xercesc::DOMLSInput::getByteStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::DOMLSInput::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::DOMLSInput::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::DOMLSInput::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseURI", &xercesc::DOMLSInput::getBaseURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setStringData", &xercesc::DOMLSInput::setStringData)
			.def("setByteStream", &xercesc::DOMLSInput::setByteStream)
			.def("setEncoding", &xercesc::DOMLSInput::setEncoding)
			.def("setPublicId", &xercesc::DOMLSInput::setPublicId)
			.def("setSystemId", &xercesc::DOMLSInput::setSystemId)
			.def("setBaseURI", &xercesc::DOMLSInput::setBaseURI)
			.def("setIssueFatalErrorIfNotFound", &xercesc::DOMLSInput::setIssueFatalErrorIfNotFound)
			.def("getIssueFatalErrorIfNotFound", &xercesc::DOMLSInput::getIssueFatalErrorIfNotFound)
			.def("release", &xercesc::DOMLSInput::release)
			;
}

} /* namespace pyxerces */
