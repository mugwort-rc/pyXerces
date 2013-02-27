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

//! XProtoType
BOOST_PYTHON_FUNCTION_OVERLOADS(XProtoTypeLoadOverloads, xercesc::XProtoType::load, 2, 3)

void load(xercesc::XSerializeEngine& serEng, const std::string& name, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	xercesc::XProtoType::load(serEng, const_cast<unsigned char*>(reinterpret_cast<const unsigned char*>(name.c_str())), manager);
}

//! load
BOOST_PYTHON_FUNCTION_OVERLOADS(XProtoTypeCastedLoadOverloads, load, 2, 3)

void XProtoType_init(void) {
	//! xercesc::XProtoType
	boost::python::class_<xercesc::XProtoType, boost::noncopyable>("XProtoType")
			.def("store", &xercesc::XProtoType::store)
			.def("load", &xercesc::XProtoType::load, XProtoTypeLoadOverloads())
			.def("load", &load, XProtoTypeCastedLoadOverloads())
			.staticmethod("load")
			.def_readwrite("fClassName", &xercesc::XProtoType::fClassName)
			// XXX
			//.def_readwrite("fCreateObject", &xercesc::XProtoType::fCreateObject)
			;
}

} /* namespace pyxerces */
