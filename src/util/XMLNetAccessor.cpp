/*
 * XMLNetAccessor.cpp
 *
 *  Created on: 2013/03/11
 *      Author: mugwort_rc
 */

#include "XMLNetAccessor.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/BinInputStream.hpp>

#include <xercesc/util/XMLNetAccessor.hpp>

namespace pyxerces {

class XMLNetAccessorWrapper
: public xercesc::XMLNetAccessor, public boost::python::wrapper<xercesc::XMLNetAccessor>
{
public:
const XMLCh* getId() const {
	return this->get_override("getId")();
}

xercesc::BinInputStream* makeNew(const xercesc::XMLURL& urlSrc, const xercesc::XMLNetHTTPInfo* httpInfo=0) {
	return this->get_override("makeNew")(boost::ref(urlSrc), boost::python::ptr(httpInfo));
}

};

void XMLNetAccessor_init(void) {
	//! xercesc::XMLNetAccessor
	boost::python::class_<XMLNetAccessorWrapper, boost::noncopyable>("XMLNetAccessor")
			.def("getId", boost::python::pure_virtual(&xercesc::XMLNetAccessor::getId), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("makeNew", boost::python::pure_virtual(&xercesc::XMLNetAccessor::makeNew), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
