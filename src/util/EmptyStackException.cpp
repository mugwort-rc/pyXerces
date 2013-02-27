/*
 * EmptyStackException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "EmptyStackException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/EmptyStackException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! EmptyStackException
MakePythonTranslateXMLException(EmptyStackException)

void EmptyStackException_init(void) {
	//! xercesc::EmptyStackException
	MakePythonXMLException(EmptyStackException)
}

} /* namespace pyxerces */
