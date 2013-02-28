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

template <class STR>
class DOMLSInputDefVisitor
: public boost::python::def_visitor<DOMLSInputDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setStringData", &DOMLSInputDefVisitor::setStringData)
	.def("setEncoding", &DOMLSInputDefVisitor::setEncoding)
	.def("setPublicId", &DOMLSInputDefVisitor::setPublicId)
	.def("setSystemId", &DOMLSInputDefVisitor::setSystemId)
	.def("setBaseURI", &DOMLSInputDefVisitor::setBaseURI)
	;
}

static void setStringData(xercesc::DOMLSInput& self, const STR& data) {
	XMLString buff(data);
	self.setStringData(buff.ptr());
}

static void setEncoding(xercesc::DOMLSInput& self, const STR& encodingStr) {
	XMLString buff(encodingStr);
	self.setEncoding(buff.ptr());
}

static void setPublicId(xercesc::DOMLSInput& self, const STR& publicId) {
	XMLString buff(publicId);
	self.setPublicId(buff.ptr());
}

static void setSystemId(xercesc::DOMLSInput& self, const STR& systemId) {
	XMLString buff(systemId);
	self.setSystemId(buff.ptr());
}

static void setBaseURI(xercesc::DOMLSInput& self, const STR& baseURI) {
	XMLString buff(baseURI);
	self.setBaseURI(buff.ptr());
}

};

void DOMLSInput_init(void) {
	//! xercesc::DOMLSInput
	boost::python::class_<xercesc::DOMLSInput, boost::noncopyable>("DOMLSInput", boost::python::no_init)
			.def(DOMLSInputDefVisitor<XMLString>())
			.def(DOMLSInputDefVisitor<std::string>())
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
