/*
 * RuntimeException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "RuntimeException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/RuntimeException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! RuntimeException
MakePythonTranslateXMLException(RuntimeException)

void RuntimeException_init(void) {
	//! xercesc::RuntimeException
	MakePythonXMLException(RuntimeException)
}

} /* namespace pyxerces */
