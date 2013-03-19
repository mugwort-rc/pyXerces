/*
 * MemBufInputSource.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "MemBufInputSource.h"

#include <boost/python.hpp>

//!< for forward declaration
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/framework/MemBufInputSource.hpp>

namespace pyxerces {

class MemBufInputSourceTargetDefVisitor
: public boost::python::def_visitor<MemBufInputSourceTargetDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("resetMemBufInputSource", &MemBufInputSourceTargetDefVisitor::resetMemBufInputSource)
	;
}

static void resetMemBufInputSource(xercesc::MemBufInputSource& self, const std::string& srcDoc) {
	self.resetMemBufInputSource(reinterpret_cast<const unsigned char*>(srcDoc.c_str()), srcDoc.size());
}

};

xercesc::MemBufInputSource* MemBufInputSource_fromstring(const std::string& src, const std::string& bufId, xercesc::MemoryManager* const manager) {
	XMLByte* buff = new XMLByte[src.size()];
	memcpy(buff, src.c_str(), src.size());
	return new xercesc::MemBufInputSource(buff, src.size(), bufId.c_str(), true, manager);
}

xercesc::MemBufInputSource* MemBufInputSource_fromstring(const std::string& src, const std::string& bufId) {
	return MemBufInputSource_fromstring(src, bufId, xercesc::XMLPlatformUtils::fgMemoryManager);
}

void MemBufInputSource_init(void) {
	//! xercesc::MemBufInputSource
	boost::python::class_<xercesc::MemBufInputSource, boost::noncopyable, boost::python::bases<xercesc::InputSource> >("MemBufInputSource", boost::python::init<const XMLByte* const, const XMLSize_t, const char* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(MemBufInputSourceTargetDefVisitor())
			.def(boost::python::init<const XMLByte* const, const XMLSize_t, const XMLCh* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::MemBufInputSource*(*)(const std::string&, const std::string&, xercesc::MemoryManager* const)>(&MemBufInputSource_fromstring)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::MemBufInputSource*(*)(const std::string&, const std::string&)>(&MemBufInputSource_fromstring)))
			.def("makeStream", &xercesc::MemBufInputSource::makeStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setCopyBufToStream", &xercesc::MemBufInputSource::setCopyBufToStream)
			.def("resetMemBufInputSource", &xercesc::MemBufInputSource::resetMemBufInputSource)
			;
}

} /* namespace pyxerces */
