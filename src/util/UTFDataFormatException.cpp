/*
 * UTFDataFormatException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "UTFDataFormatException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/UTFDataFormatException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! UTFDataFormatException
MakePythonTranslateXMLException(UTFDataFormatException)

void UTFDataFormatException_init(void) {
	//! xercesc::UTFDataFormatException
	MakePythonXMLException(UTFDataFormatException)
}

} /* namespace pyxerces */
