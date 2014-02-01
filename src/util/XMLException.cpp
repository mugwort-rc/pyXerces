/*
 * XMLException.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "XMLException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/XMLException.hpp>

#include "../common/Exception.h"

namespace pyxerces {

//! XMLException
class XMLExceptionWrapper
: public xercesc::XMLException, public boost::python::wrapper<xercesc::XMLException>
{
public:
	const XMLCh* getType() const {
		return this->get_override("getType")();
	}
};

PyObject* pyXercesXMLExceptionType = nullptr;

void translateXMLException(const xercesc::XMLException& e) {
	assert(pyXercesXMLExceptionType != nullptr);
	boost::python::object instance(e);

	boost::python::object exceptionType(boost::python::handle<>(boost::python::borrowed(pyXercesXMLExceptionType)));
	exceptionType.attr("cause") = instance;

	PyErr_SetString(pyXercesXMLExceptionType, XMLString(e.getMessage()).toString().c_str());
}

void XMLException_init(void) {
	//! xercesc::XMLException
	auto XMLException = boost::python::class_<XMLExceptionWrapper, boost::noncopyable>("XMLException")
			.def("getType", &xercesc::XMLException::getType, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getCode", &xercesc::XMLException::getCode)
			.def("getMessage", &xercesc::XMLException::getMessage, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcFile", &xercesc::XMLException::getSrcFile)
			.def("getSrcLine", &xercesc::XMLException::getSrcLine)
			.def("getErrorType", &xercesc::XMLException::getErrorType)
			.def("setPosition", &xercesc::XMLException::setPosition)
			;
	pyXercesXMLExceptionType = createException("XMLException");
	boost::python::register_exception_translator<xercesc::XMLException>(&translateXMLException);
}

} /* namespace pyxerces */
