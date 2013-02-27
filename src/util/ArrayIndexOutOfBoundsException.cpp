/*
 * ArrayIndexOutOfBoundsException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "ArrayIndexOutOfBoundsException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/ArrayIndexOutOfBoundsException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! ArrayIndexOutOfBoundsException
MakePythonTranslateXMLException(ArrayIndexOutOfBoundsException)

void ArrayIndexOutOfBoundsException_init(void) {
	//! xercesc::ArrayIndexOutOfBoundsException
	MakePythonXMLException(ArrayIndexOutOfBoundsException)
}

} /* namespace pyxerces */
