/*
 * XPathException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "XPathException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/validators/schema/identity/XPathException.hpp>

#include "../../../util/XMLException.h"

namespace pyxerces {

//! XPathException
MakePythonTranslateXMLException(XPathException)

void XPathException_init(void) {
	//! xercesc::XPathException
	MakePythonXMLException(XPathException)
}

} /* namespace pyxerces */
