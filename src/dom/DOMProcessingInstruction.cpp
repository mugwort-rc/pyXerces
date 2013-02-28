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

template <class STR>
class DOMProcessingInstructionDefVisitor
: public boost::python::def_visitor<DOMProcessingInstructionDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setData", &DOMProcessingInstructionDefVisitor::setData)
	;
}

static void setData(xercesc::DOMProcessingInstruction& self, const STR& data) {
	XMLString buff(data);
	self.setData(buff.ptr());
}

};

void DOMProcessingInstruction_init(void) {
	//! xercesc::DOMProcessingInstruction
	boost::python::class_<xercesc::DOMProcessingInstruction, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMProcessingInstruction", boost::python::no_init)
			.def(DOMProcessingInstructionDefVisitor<XMLString>())
			.def(DOMProcessingInstructionDefVisitor<std::string>())
			.def("getTarget", &xercesc::DOMProcessingInstruction::getTarget, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getData", &xercesc::DOMProcessingInstruction::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setData", &xercesc::DOMProcessingInstruction::setData)
			;
}

} /* namespace pyxerces */
