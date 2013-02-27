/*
 * ParseException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "ParseException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/ParseException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! ParseException
MakePythonTranslateXMLException(ParseException)

void ParseException_init(void) {
	//! xercesc::ParseException
	MakePythonXMLException(ParseException)
}

} /* namespace pyxerces */
