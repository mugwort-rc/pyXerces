/*
 * TranscodingException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "TranscodingException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/util/TranscodingException.hpp>

#include "XMLException.h"

namespace pyxerces {

//! TranscodingException
MakePythonTranslateXMLException(TranscodingException)

void TranscodingException_init(void) {
	//! xercesc::TranscodingException
	MakePythonXMLException(TranscodingException)
}

} /* namespace pyxerces */
