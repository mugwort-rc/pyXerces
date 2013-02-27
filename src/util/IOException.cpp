/*
 * IOException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "IOException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/IOException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! IOException
MakePythonTranslateXMLException(IOException)

void IOException_init(void) {
	//! xercesc::IOException
	MakePythonXMLException(IOException)
}

} /* namespace pyxerces */
