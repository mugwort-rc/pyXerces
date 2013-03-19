/*
 * XSerializable.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XSerializable.h"

#include <boost/python.hpp>
#include <xercesc/internal/XSerializable.hpp>

namespace pyxerces {

class XSerializableWrapper
: public xercesc::XSerializable, public boost::python::wrapper<xercesc::XSerializable>
{
public:
PyDECL_XSERIALIZABLEWrapper
};

void XSerializable_init(void) {
	//! xercesc::XSerializable
	boost::python::class_<xercesc::XSerializable, boost::noncopyable>("XSerializable", boost::python::no_init)
			.def("isSerializable", boost::python::pure_virtual(&xercesc::XSerializable::isSerializable))
			.def("serialize", boost::python::pure_virtual(&xercesc::XSerializable::serialize))
			.def("getProtoType", boost::python::pure_virtual(&xercesc::XSerializable::getProtoType), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
