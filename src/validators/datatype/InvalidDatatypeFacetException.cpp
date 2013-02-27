/*
 * InvalidDatatypeFacetException.cpp
 *
 *  Created on: 2013/02/28
 *      Author: mugwort_rc
 */

#include "InvalidDatatypeFacetException.h"

#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>				//!< for forward declaration
#include <xercesc/validators/datatype/InvalidDatatypeFacetException.hpp>

#include "../../util/XMLException.h"

namespace pyxerces {

//! InvalidDatatypeFacetException
MakePythonTranslateXMLException(InvalidDatatypeFacetException)

void InvalidDatatypeFacetException_init(void) {
	//! xercesc::InvalidDatatypeFacetException
	MakePythonXMLException(InvalidDatatypeFacetException)
}

} /* namespace pyxerces */
