/*
 * NoSuchElementException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "NoSuchElementException.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/NoSuchElementException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! NoSuchElementException
MakePythonTranslateXMLException(NoSuchElementException)

void NoSuchElementException_init(void) {
	//! xercesc::NoSuchElementException
	MakePythonXMLException(NoSuchElementException)
}

} /* namespace pyxerces */
