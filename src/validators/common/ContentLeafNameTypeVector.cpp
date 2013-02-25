/*
 * ContentLeafNameTypeVector.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "ContentLeafNameTypeVector.h"

#include <boost/python.hpp>
#include <xercesc/validators/common/ContentLeafNameTypeVector.hpp>

namespace pyxerces {

void ContentLeafNameTypeVector_init(void) {
	//! xercesc::ContentLeafNameTypeVector
	boost::python::class_<xercesc::ContentLeafNameTypeVector, boost::noncopyable>("ContentLeafNameTypeVector", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::QName** const, xercesc::ContentSpecNode::NodeTypes* const, const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::ContentLeafNameTypeVector&>())
			.def("getLeafNameAt", &xercesc::ContentLeafNameTypeVector::getLeafNameAt, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLeafTypeAt", &xercesc::ContentLeafNameTypeVector::getLeafTypeAt)
			.def("getLeafCount", &xercesc::ContentLeafNameTypeVector::getLeafCount)
			.def("setValues", &xercesc::ContentLeafNameTypeVector::setValues)
			;
}

} /* namespace pyxerces */
