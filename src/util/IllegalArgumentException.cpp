/*
 * IllegalArgumentException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "IllegalArgumentException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/IllegalArgumentException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! IllegalArgumentException
MakePythonTranslateXMLException(IllegalArgumentException)

void IllegalArgumentException_init(void) {
	//! xercesc::IllegalArgumentException
	MakePythonXMLException(IllegalArgumentException)
}

} /* namespace pyxerces */
