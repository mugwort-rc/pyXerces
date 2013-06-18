/*
 * Exception.h
 *
 *  Created on: 2013/06/18
 *      Author: mugwort_rc
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <string>
#include <Python.h>

namespace pyxerces {

PyObject* createException(const std::string& name, PyObject* baseType = PyExc_Exception);

} /* namespace pyxerces */
#endif /* EXCEPTION_H_ */
