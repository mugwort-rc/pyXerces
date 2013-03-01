/*
 * LocalFileFormatTarget.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "LocalFileFormatTarget.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>			//!< for forward declaration
#include <xercesc/framework/LocalFileFormatTarget.hpp>

namespace pyxerces {

class LocalFileFormatTargetDefVisitor
: public boost::python::def_visitor<LocalFileFormatTargetDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("writeChars", &LocalFileFormatTargetDefVisitor::writeChars)
	;
}

static void writeChars(xercesc::LocalFileFormatTarget& self, const std::string& toWrite, xercesc::XMLFormatter* formatter) {
	self.writeChars(reinterpret_cast<const unsigned char*>(toWrite.c_str()), toWrite.size(), formatter);
}

};

void LocalFileFormatTarget_init(void) {
	//! xercesc::LocalFileFormatTarget
	boost::python::class_<xercesc::LocalFileFormatTarget, boost::noncopyable, boost::python::bases<xercesc::XMLFormatTarget> >("LocalFileFormatTarget", boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(LocalFileFormatTargetDefVisitor())
			.def("writeChars", &xercesc::LocalFileFormatTarget::writeChars)
			.def("flush", &xercesc::LocalFileFormatTarget::flush)
			;
}

} /* namespace pyxerces */
