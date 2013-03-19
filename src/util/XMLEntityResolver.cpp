/*
 * XMLEntityResolver.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include "XMLEntityResolver.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/InputSource.hpp>

#include <xercesc/util/XMLEntityResolver.hpp>

namespace pyxerces {

class XMLEntityResolverWrapper
: public xercesc::XMLEntityResolver, public boost::python::wrapper<xercesc::XMLEntityResolver>
{
public:
xercesc::InputSource* resolveEntity(xercesc::XMLResourceIdentifier* resourceIdentifier) {
	return this->get_override("resolveEntity")(boost::python::ptr(resourceIdentifier));
}

};

void XMLEntityResolver_init(void) {
	//! xercesc::XMLEntityResolver
	boost::python::class_<XMLEntityResolverWrapper, boost::noncopyable>("XMLEntityResolver")
			.def("resolveEntity", boost::python::pure_virtual(&xercesc::XMLEntityResolver::resolveEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
