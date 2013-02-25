/*
 * XProtoType.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XProtoType.h"

#include <boost/python.hpp>
#include <xercesc/internal/XSerializeEngine.hpp>	//!< for forward declaration
#include <xercesc/internal/XSerializable.hpp>		//!< for forward declaration
#include <xercesc/internal/XProtoType.hpp>

namespace pyxerces {

BOOST_PYTHON_FUNCTION_OVERLOADS(XProtoTypeLoadOverloads, xercesc::XProtoType::load, 2, 3)

void XProtoType_init(void) {
	//! xercesc::XProtoType
	boost::python::class_<xercesc::XProtoType, boost::noncopyable>("XProtoType")
			.def("store", &xercesc::XProtoType::store)
			.def("load", &xercesc::XProtoType::load, XProtoTypeLoadOverloads())
			.staticmethod("load")
			.def_readwrite("fClassName", &xercesc::XProtoType::fClassName)
			// XXX
			//.def_readwrite("fCreateObject", &xercesc::XProtoType::fCreateObject)
			;
}

} /* namespace pyxerces */
