/*
 * StdOutFormatTarget.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "StdOutFormatTarget.h"

#include <boost/python.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>

namespace pyxerces {

class StdOutFormatTargetDefVisitor
: public boost::python::def_visitor<StdOutFormatTargetDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("writeChars", &StdOutFormatTargetDefVisitor::writeChars)
	;
}

static void writeChars(xercesc::StdOutFormatTarget& self, const std::string& toWrite, xercesc::XMLFormatter* formatter) {
	self.writeChars(reinterpret_cast<const unsigned char*>(toWrite.c_str()), toWrite.size(), formatter);
}

};

void StdOutFormatTarget_init(void) {
	//! xercesc::StdOutFormatTarget
	boost::python::class_<xercesc::StdOutFormatTarget, boost::noncopyable, boost::python::bases<xercesc::XMLFormatTarget> >("StdOutFormatTarget")
			.def(StdOutFormatTargetDefVisitor())
			.def("writeChars", &xercesc::StdOutFormatTarget::writeChars)
			.def("flush", &xercesc::StdOutFormatTarget::flush)
			;
}

} /* namespace pyxerces */
