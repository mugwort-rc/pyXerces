/*
 * EntityResolver.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "EntityResolver.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/InputSource.hpp>

#include <xercesc/sax/EntityResolver.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLRecognizerDefVisitor
: public boost::python::def_visitor<XMLRecognizerDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("resolveEntity", &XMLRecognizerDefVisitor::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::InputSource* resolveEntity(xercesc::EntityResolver& self, const STR& publicId, const STR& systemId) {
	XMLString buff1(publicId), buff2(systemId);
	return self.resolveEntity(buff1.ptr(), buff2.ptr());
}

};

class EntityResolverWrapper
: public xercesc::EntityResolver, public boost::python::wrapper<xercesc::EntityResolver>
{
public:
	xercesc::InputSource* resolveEntity(const XMLCh* const publicId, const XMLCh* const systemId) {
		return this->get_override("resolveEntity")(XMLString(publicId), XMLString(systemId));
	}

};

void EntityResolver_init(void) {
	//! xercesc::EntityResolver
	boost::python::class_<EntityResolverWrapper, boost::noncopyable>("EntityResolver")
			.def(XMLRecognizerDefVisitor<XMLString>())
			.def(XMLRecognizerDefVisitor<std::string>())
			.def("resolveEntity", boost::python::pure_virtual(&xercesc::EntityResolver::resolveEntity), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
