/*
 * EntityResolver.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "EntityResolver.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>		//!< for forward declaration
#include <xercesc/sax/EntityResolver.hpp>

namespace pyxerces {

class EntityResolverWrapper
: public xercesc::EntityResolver, public boost::python::wrapper<xercesc::EntityResolver>
{
public:
	xercesc::InputSource* resolveEntity(const XMLCh* const publicId, const XMLCh* const systemId) {
		return this->get_override("resolveEntity")(publicId, systemId);
	}

};

void EntityResolver_init(void) {
	//! xercesc::EntityResolver
	boost::python::class_<EntityResolverWrapper, boost::noncopyable>("EntityResolver")
			.def("resolveEntity", &xercesc::EntityResolver::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
