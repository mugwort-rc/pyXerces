/*
 * NumberFormatException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "NumberFormatException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/NumberFormatException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! NumberFormatException
MakePythonTranslateXMLException(NumberFormatException)

void NumberFormatException_init(void) {
	//! xercesc::NumberFormatException
	MakePythonXMLException(NumberFormatException)
}

} /* namespace pyxerces */
