/*
 * BinInputStream.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "BinInputStream.h"

#include <boost/python.hpp>
#include <xercesc/util/BinInputStream.hpp>

namespace pyxerces {

void BinInputStream_init(void) {
	//! xercesc::BinInputStream
	boost::python::class_<xercesc::BinInputStream, boost::noncopyable>("BinInputStream", boost::python::no_init)
			.def("curPos", &xercesc::BinInputStream::curPos)
			.def("readBytes", &xercesc::BinInputStream::readBytes)
			.def("getContentType", &xercesc::BinInputStream::getContentType, boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
