/*
 * XMLEntityResolver.cpp
 *
 *  Created on: 2013/02/21
 *      Author: mugwort_rc
 */

#include "XMLEntityResolver.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>			//!< for forward declaration
#include <xercesc/util/XMLEntityResolver.hpp>

namespace pyxerces {

class XMLEntityResolverWrapper
: public xercesc::XMLEntityResolver, public boost::python::wrapper<xercesc::XMLEntityResolver>
{
public:
	xercesc::InputSource* resolveEntity(const xercesc::XMLResourceIdentifier* resourceIdentifier) {
		return this->get_override("resolveEntity")(resourceIdentifier);
	}

};

void XMLEntityResolver_init(void) {
	//! xercesc::XMLEntityResolver
	boost::python::class_<xercesc::XMLEntityResolver, boost::noncopyable>("XMLEntityResolver", boost::python::no_init)
			.def("resolveEntity", &xercesc::XMLEntityResolver::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
