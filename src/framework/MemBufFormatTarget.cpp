/*
 * MemBufFormatTarget.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include "MemBufFormatTarget.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>		//!< for forward declaration
#include <xercesc/framework/MemBufFormatTarget.hpp>

namespace pyxerces {

class MemBufFormatTargetDefVisitor
: public boost::python::def_visitor<MemBufFormatTargetDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getStringBuffer", &MemBufFormatTargetDefVisitor::getStringBuffer)
	;
}

static std::string getStringBuffer(xercesc::MemBufFormatTarget& self) {
	return std::string(reinterpret_cast<const char*>(self.getRawBuffer()), self.getLen());
}

};

void MemBufFormatTarget_init(void) {
	//! xercesc::MemBufFormatTarget
	boost::python::class_<xercesc::MemBufFormatTarget, boost::noncopyable, boost::python::bases<xercesc::XMLFormatTarget> >("MemBufFormatTarget", boost::python::init<boost::python::optional<XMLSize_t, xercesc::MemoryManager* const> >())
			.def(MemBufFormatTargetDefVisitor())
			.def("writeChars", &xercesc::MemBufFormatTarget::writeChars)
			.def("getRawBuffer", &xercesc::MemBufFormatTarget::getRawBuffer, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("getLen", &xercesc::MemBufFormatTarget::getLen)
			.def("reset", &xercesc::MemBufFormatTarget::reset)
			;
}

} /* namespace pyxerces */
