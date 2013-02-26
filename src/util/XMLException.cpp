/*
 * XMLException.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "XMLException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>	//!< for forward declaration
#include <xercesc/util/XMLException.hpp>

namespace pyxerces {

//! XMLException
class XMLExceptionWrapper
: public xercesc::XMLException, public boost::python::wrapper<xercesc::XMLException>
{
public:
	XMLExceptionWrapper()
		: xercesc::XMLException()
	{}

	XMLExceptionWrapper(const char* const srcFile, const XMLFileLoc srcLine, xercesc::MemoryManager* const memoryManager = 0)
		: xercesc::XMLException(srcFile, srcLine, memoryManager)
	{}

	XMLExceptionWrapper(const XMLException& toCopy)
		: xercesc::XMLException(toCopy)
	{}

	const XMLCh* getType() const {
		return this->get_override("getType")();
	}
};

PyObject* pyXercesXMLExceptionType = nullptr;

void translateXMLException(const xercesc::XMLException& e) {
	assert(pyXercesXMLExceptionType != nullptr);
	boost::python::object instance(e);
	PyErr_SetObject(pyXercesXMLExceptionType, instance.ptr());
}

void XMLException_init(void) {
	//! xercesc::XMLException
	auto XMLException = boost::python::class_<XMLExceptionWrapper>("XMLException")
			.def(boost::python::init<const char* const, const XMLFileLoc, boost::python::optional<xercesc::MemoryManager*> >())
			.def("getType", &xercesc::XMLException::getType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCode", &xercesc::XMLException::getCode)
			.def("getMessage", &xercesc::XMLException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcFile", &xercesc::XMLException::getSrcFile)
			.def("getSrcLine", &xercesc::XMLException::getSrcLine)
			.def("getErrorType", &xercesc::XMLException::getErrorType)
			.def("setPosition", &xercesc::XMLException::setPosition)
			;
	pyXercesXMLExceptionType = XMLException.ptr();
	boost::python::register_exception_translator<xercesc::XMLException>(&translateXMLException);
}

} /* namespace pyxerces */