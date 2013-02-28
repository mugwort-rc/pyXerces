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

template <class STR>
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

static void setEncoding(xercesc::DOMLSOutput& self, const STR& encodingStr) {
	XMLString buff(encodingStr);
	self.setEncoding(buff.ptr());
}

static void setSystemId(xercesc::DOMLSOutput& self, const STR& systemId) {
	XMLString buff(systemId);
	self.setSystemId(buff.ptr());
}

};

void DOMLSOutput_init(void) {
	//! xercesc::DOMLSOutput
	boost::python::class_<xercesc::DOMLSOutput, boost::noncopyable>("DOMLSOutput", boost::python::no_init)
			.def(DOMLSOutputDefVisitor<XMLString>())
			.def(DOMLSOutputDefVisitor<std::string>())
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
