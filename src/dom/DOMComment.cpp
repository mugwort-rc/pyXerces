/*
 * DOMComment.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMComment.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMComment.hpp>

namespace pyxerces {

void DOMComment_init(void) {
	//! xercesc::DOMComment
	boost::python::class_<xercesc::DOMComment, boost::noncopyable, boost::python::bases<xercesc::DOMCharacterData> >("DOMComment", boost::python::no_init);
}

} /* namespace pyxerces */
