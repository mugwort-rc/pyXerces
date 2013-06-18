/*
 * Exception.cpp
 *
 *  Created on: 2013/06/18
 *      Author: mugwort_rc
 */

#include "Exception.h"

#include <boost/python.hpp>

namespace pyxerces {

PyObject* createException(const std::string& name, PyObject* baseType) {
	const std::string className     = "Py" + name;
	const std::string scopeName     = boost::python::extract<std::string>(boost::python::scope().attr("__name__"));
	const std::string qualifiedName = scopeName + "." + className;

	PyObject* type = PyErr_NewException(const_cast<char*>(qualifiedName.c_str()), baseType, nullptr);
	if ( ! type ) {
		boost::python::throw_error_already_set();
	}
	boost::python::scope().attr(className.c_str()) = boost::python::handle<>(boost::python::borrowed(type));

	return type;
}

} /* namespace pyxerces */
