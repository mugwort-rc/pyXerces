/*
 * DOMProcessingInstruction.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMProcessingInstruction.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMProcessingInstruction.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMProcessingInstructionDefVisitor
: public boost::python::def_visitor<DOMProcessingInstructionDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setData", static_cast<void(*)(xercesc::DOMProcessingInstruction&, const XMLString&)>(&DOMProcessingInstructionDefVisitor::setData))
	.def("setData", static_cast<void(*)(xercesc::DOMProcessingInstruction&, const std::string&)>(&DOMProcessingInstructionDefVisitor::setData))
	;
}

static void setData(xercesc::DOMProcessingInstruction& self, const XMLString& data) {
	self.setData(data.ptr());
}

static void setData(xercesc::DOMProcessingInstruction& self, const std::string& data) {
	XMLString buff(data);
	DOMProcessingInstructionDefVisitor::setData(self, buff);
}
};

void DOMProcessingInstruction_init(void) {
	//! xercesc::DOMProcessingInstruction
	boost::python::class_<xercesc::DOMProcessingInstruction, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMProcessingInstruction", boost::python::no_init)
			.def(DOMProcessingInstructionDefVisitor())
			.def("getTarget", &xercesc::DOMProcessingInstruction::getTarget, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getData", &xercesc::DOMProcessingInstruction::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setData", &xercesc::DOMProcessingInstruction::setData)
			;
}

} /* namespace pyxerces */
