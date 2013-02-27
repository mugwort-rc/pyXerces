/*
 * UnexpectedEOFException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "UnexpectedEOFException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
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
