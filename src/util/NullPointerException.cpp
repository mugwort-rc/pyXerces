/*
 * NullPointerException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "NullPointerException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/NullPointerException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! NullPointerException
MakePythonTranslateXMLException(NullPointerException)

void NullPointerException_init(void) {
	//! xercesc::NullPointerException
	MakePythonXMLException(NullPointerException)
}

} /* namespace pyxerces */
