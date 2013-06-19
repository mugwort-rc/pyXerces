/*
 * DOMXPathNSResolver.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMXPathNSResolver.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMXPathNSResolverDefVisitor
: public boost::python::def_visitor<DOMXPathNSResolverDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("lookupNamespaceURI", &DOMXPathNSResolverDefVisitor::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupPrefix", &DOMXPathNSResolverDefVisitor::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
	.def("addNamespaceBinding", &DOMXPathNSResolverDefVisitor::addNamespaceBinding)
	;
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMXPathNSResolver& self, const XMLString& prefix) {
	return self.lookupNamespaceURI(prefix.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMXPathNSResolver& self, const XMLString& namespaceURI) {
	return self.lookupPrefix(namespaceURI.ptr());
}

static void addNamespaceBinding(xercesc::DOMXPathNSResolver& self, const XMLString& prefix, const XMLString& uri) {
	self.addNamespaceBinding(prefix.ptr(), uri.ptr());
}

};

class DOMXPathNSResolverWrapper
: public xercesc::DOMXPathNSResolver, public boost::python::wrapper<xercesc::DOMXPathNSResolver>
{
public:
const XMLCh* lookupNamespaceURI(const XMLCh* prefix) const {
	return this->get_override("lookupNamespaceURI")(XMLString(prefix));
}

const XMLCh* lookupPrefix(const XMLCh* URI) const {
	return this->get_override("lookupPrefix")(XMLString(URI));
}

void addNamespaceBinding(const XMLCh* prefix, const XMLCh* uri) {
	this->get_override("addNamespaceBinding")(XMLString(prefix), XMLString(uri));
}

void release() {
	this->get_override("release")();
}

};

void DOMXPathNSResolver_init(void) {
	//! xercesc::DOMXPathNSResolver
	boost::python::class_<DOMXPathNSResolverWrapper, boost::noncopyable>("DOMXPathNSResolver")
			.def(DOMXPathNSResolverDefVisitor())
			.def("lookupNamespaceURI", boost::python::pure_virtual(&xercesc::DOMXPathNSResolver::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("lookupPrefix", boost::python::pure_virtual(&xercesc::DOMXPathNSResolver::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("addNamespaceBinding", boost::python::pure_virtual(&xercesc::DOMXPathNSResolver::addNamespaceBinding))
			.def("release", boost::python::pure_virtual(&xercesc::DOMXPathNSResolver::release))
			;
}

} /* namespace pyxerces */
