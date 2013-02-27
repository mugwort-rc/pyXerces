/*
 * UnsupportedEncodingException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "UnsupportedEncodingException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/UnsupportedEncodingException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! UnsupportedEncodingException
MakePythonTranslateXMLException(UnsupportedEncodingException)

void UnsupportedEncodingException_init(void) {
	//! xercesc::UnsupportedEncodingException
	MakePythonXMLException(UnsupportedEncodingException)
}

} /* namespace pyxerces */
