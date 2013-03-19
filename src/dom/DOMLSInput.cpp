/*
 * DOMLSInput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSInput.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/InputSource.hpp>

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

class DOMLSInputWrapper
: public xercesc::DOMLSInput, public boost::python::wrapper<xercesc::DOMLSInput>
{
public:
const XMLCh* getStringData() const {
	return this->get_override("getStringData")();
}

xercesc::InputSource* getByteStream() const {
	return this->get_override("getByteStream")();
}

const XMLCh* getEncoding() const {
	return this->get_override("getEncoding")();
}

const XMLCh* getPublicId() const {
	return this->get_override("getPublicId")();
}

const XMLCh* getSystemId() const {
	return this->get_override("getSystemId")();
}

const XMLCh* getBaseURI() const {
	return this->get_override("getBaseURI")();
}

void setStringData(const XMLCh* data) {
	this->get_override("setStringData")(XMLString(data));
}

void setByteStream(xercesc::InputSource* stream) {
	this->get_override("setByteStream")(boost::python::ptr(stream));
}

void setEncoding(const XMLCh* const encodingStr) {
	this->get_override("setEncoding")(XMLString(encodingStr));
}

void setPublicId(const XMLCh* const publicId) {
	this->get_override("setPublicId")(XMLString(publicId));
}

void setSystemId(const XMLCh* const systemId) {
	this->get_override("setSystemId")(XMLString(systemId));
}

void setBaseURI(const XMLCh* const baseURI) {
	this->get_override("setBaseURI")(XMLString(baseURI));
}

void setIssueFatalErrorIfNotFound(bool flag) {
	this->get_override("setIssueFatalErrorIfNotFound")(flag);
}

bool getIssueFatalErrorIfNotFound() const {
	return this->get_override("getIssueFatalErrorIfNotFound")();
}

void release() {
	this->get_override("release")();
}

};

void DOMLSInput_init(void) {
	//! xercesc::DOMLSInput
	boost::python::class_<DOMLSInputWrapper, boost::noncopyable>("DOMLSInput")
			.def(DOMLSInputDefVisitor<XMLString>())
			.def(DOMLSInputDefVisitor<std::string>())
			.def("getStringData", boost::python::pure_virtual(&xercesc::DOMLSInput::getStringData), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getByteStream", boost::python::pure_virtual(&xercesc::DOMLSInput::getByteStream), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", boost::python::pure_virtual(&xercesc::DOMLSInput::getEncoding), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", boost::python::pure_virtual(&xercesc::DOMLSInput::getPublicId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", boost::python::pure_virtual(&xercesc::DOMLSInput::getSystemId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseURI", boost::python::pure_virtual(&xercesc::DOMLSInput::getBaseURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setStringData", boost::python::pure_virtual(&xercesc::DOMLSInput::setStringData))
			.def("setByteStream", boost::python::pure_virtual(&xercesc::DOMLSInput::setByteStream))
			.def("setEncoding", boost::python::pure_virtual(&xercesc::DOMLSInput::setEncoding))
			.def("setPublicId", boost::python::pure_virtual(&xercesc::DOMLSInput::setPublicId))
			.def("setSystemId", boost::python::pure_virtual(&xercesc::DOMLSInput::setSystemId))
			.def("setBaseURI", boost::python::pure_virtual(&xercesc::DOMLSInput::setBaseURI))
			.def("setIssueFatalErrorIfNotFound", boost::python::pure_virtual(&xercesc::DOMLSInput::setIssueFatalErrorIfNotFound))
			.def("getIssueFatalErrorIfNotFound", boost::python::pure_virtual(&xercesc::DOMLSInput::getIssueFatalErrorIfNotFound))
			.def("release", boost::python::pure_virtual(&xercesc::DOMLSInput::release))
			;
}

} /* namespace pyxerces */
