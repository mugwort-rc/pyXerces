/*
 * InvalidCastException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "InvalidCastException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/InvalidCastException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! InvalidCastException
MakePythonTranslateXMLException(InvalidCastException)

void InvalidCastException_init(void) {
	//! xercesc::InvalidCastException
	MakePythonXMLException(InvalidCastException)
}

} /* namespace pyxerces */
