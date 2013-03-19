/*
 * UnsupportedEncodingException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "UnsupportedEncodingException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

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
