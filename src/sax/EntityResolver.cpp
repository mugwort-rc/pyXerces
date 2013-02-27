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

#include "../util/XMLString.h"

namespace pyxerces {

class XMLRecognizerDefVisitor
: public boost::python::def_visitor<XMLRecognizerDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("resolveEntity", static_cast<xercesc::InputSource*(*)(xercesc::EntityResolver&, const XMLString&, const XMLString&)>(&XMLRecognizerDefVisitor::resolveEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("resolveEntity", static_cast<xercesc::InputSource*(*)(xercesc::EntityResolver&, const std::string&, const std::string&)>(&XMLRecognizerDefVisitor::resolveEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::InputSource* resolveEntity(xercesc::EntityResolver& self, const XMLString& publicId, const XMLString& systemId) {
	return self.resolveEntity(publicId.ptr(), systemId.ptr());
}

static xercesc::InputSource* resolveEntity(xercesc::EntityResolver& self, const std::string& publicId, const std::string& systemId) {
	XMLString buff1(publicId), buff2(systemId);
	return XMLRecognizerDefVisitor::resolveEntity(self, buff1, buff2);
}

};

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
