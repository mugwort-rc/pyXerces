/*
 * InvalidDatatypeValueException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "InvalidDatatypeValueException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/validators/datatype/InvalidDatatypeValueException.hpp>

#include "../../util/XMLException.h"

namespace pyxerces {

//! InvalidDatatypeValueException
MakePythonTranslateXMLException(InvalidDatatypeValueException)

void InvalidDatatypeValueException_init(void) {
	//! xercesc::InvalidDatatypeValueException
	MakePythonXMLException(InvalidDatatypeValueException)
}

} /* namespace pyxerces */
