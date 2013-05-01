/*
 * DOMLSOutput.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSOutput.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLFormatter.hpp>

#include <xercesc/dom/DOMLSOutput.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class DOMLSOutputDefVisitor
: public boost::python::def_visitor<DOMLSOutputDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setEncoding", &DOMLSOutputDefVisitor::setEncoding)
	.def("setSystemId", &DOMLSOutputDefVisitor::setSystemId)
	;
}

static void setEncoding(xercesc::DOMLSOutput& self, const STR encodingStr) {
	XMLString buff(encodingStr);
	self.setEncoding(buff.ptr());
}

static void setSystemId(xercesc::DOMLSOutput& self, const STR systemId) {
	XMLString buff(systemId);
	self.setSystemId(buff.ptr());
}

};

class DOMLSOutputWrapper
: public xercesc::DOMLSOutput, public boost::python::wrapper<xercesc::DOMLSOutput>
{
public:
xercesc::XMLFormatTarget* getByteStream() const {
	return this->get_override("getByteStream")();
}

const XMLCh* getEncoding() const {
	return this->get_override("getEncoding")();
}

const XMLCh* getSystemId() const {
	return this->get_override("getSystemId")();
}

void setByteStream(xercesc::XMLFormatTarget* stream) {
	this->get_override("setByteStream")(boost::python::ptr(stream));
}

void setEncoding(const XMLCh* const encodingStr) {
	this->get_override("setEncoding")(XMLString(encodingStr));
}

void setSystemId(const XMLCh* const systemId) {
	this->get_override("setSystemId")(XMLString(systemId));
}

void release() {
	this->get_override("release")();
}

};

void DOMLSOutput_init(void) {
	//! xercesc::DOMLSOutput
	boost::python::class_<DOMLSOutputWrapper, boost::noncopyable>("DOMLSOutput")
			.def(DOMLSOutputDefVisitor<XMLString&>())
			.def(DOMLSOutputDefVisitor<char*>())
			.def("getByteStream", boost::python::pure_virtual(&xercesc::DOMLSOutput::getByteStream), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", boost::python::pure_virtual(&xercesc::DOMLSOutput::getEncoding), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", boost::python::pure_virtual(&xercesc::DOMLSOutput::getSystemId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setByteStream", boost::python::pure_virtual(&xercesc::DOMLSOutput::setByteStream))
			.def("setEncoding", boost::python::pure_virtual(&xercesc::DOMLSOutput::setEncoding))
			.def("setSystemId", boost::python::pure_virtual(&xercesc::DOMLSOutput::setSystemId))
			.def("release", boost::python::pure_virtual(&xercesc::DOMLSOutput::release))
			;
}

} /* namespace pyxerces */
