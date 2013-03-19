/*
 * UnexpectedEOFException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "UnexpectedEOFException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/UnexpectedEOFException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! UnexpectedEOFException
MakePythonTranslateXMLException(UnexpectedEOFException)

void UnexpectedEOFException_init(void) {
	//! xercesc::UnexpectedEOFException
	MakePythonXMLException(UnexpectedEOFException)
}

} /* namespace pyxerces */
