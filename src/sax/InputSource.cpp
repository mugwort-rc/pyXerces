/*
 * InputSource.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "InputSource.h"

#include <boost/python.hpp>

//!< for forward declaration
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/sax/InputSource.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class InputSourceDefVisitor
: public boost::python::def_visitor<InputSourceDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setEncoding", &InputSourceDefVisitor::setEncoding)
	.def("setPublicId", &InputSourceDefVisitor::setPublicId)
	.def("setSystemId", &InputSourceDefVisitor::setSystemId)
	;
}

static void setEncoding(xercesc::InputSource& self, const STR encodingStr) {
	XMLString buff(encodingStr);
	self.setEncoding(buff.ptr());
}

static void setPublicId(xercesc::InputSource& self, const STR publicId) {
	XMLString buff(publicId);
	self.setPublicId(buff.ptr());
}

static void setSystemId(xercesc::InputSource& self, const STR systemId) {
	XMLString buff(systemId);
	self.setSystemId(buff.ptr());
}

};

void InputSource_init(void) {
	//! xercesc::InputSource
	boost::python::class_<xercesc::InputSource, boost::noncopyable>("InputSouce", boost::python::no_init)
			.def(InputSourceDefVisitor<XMLString&>())
			.def(InputSourceDefVisitor<char*>())
			.def("makeStream", boost::python::pure_virtual(&xercesc::InputSource::makeStream), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEncoding", &xercesc::InputSource::getEncoding, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::InputSource::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::InputSource::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getIssueFatalErrorIfNotFound", &xercesc::InputSource::getIssueFatalErrorIfNotFound)
			.def("getMemoryManager", &xercesc::InputSource::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEncoding", &xercesc::InputSource::setEncoding)
			.def("setPublicId", &xercesc::InputSource::setPublicId)
			.def("setSystemId", &xercesc::InputSource::setSystemId)
			.def("setIssueFatalErrorIfNotFound", &xercesc::InputSource::setIssueFatalErrorIfNotFound)
			;
}

} /* namespace pyxerces */
