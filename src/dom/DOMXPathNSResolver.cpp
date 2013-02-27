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
	.def("lookupNamespaceURI", static_cast<const XMLCh*(*)(xercesc::DOMXPathNSResolver&, const XMLString&)>(&DOMXPathNSResolverDefVisitor::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupNamespaceURI", static_cast<const XMLCh*(*)(xercesc::DOMXPathNSResolver&, const std::string&)>(&DOMXPathNSResolverDefVisitor::lookupNamespaceURI), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupPrefix", static_cast<const XMLCh*(*)(xercesc::DOMXPathNSResolver&, const XMLString&)>(&DOMXPathNSResolverDefVisitor::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("lookupPrefix", static_cast<const XMLCh*(*)(xercesc::DOMXPathNSResolver&, const std::string&)>(&DOMXPathNSResolverDefVisitor::lookupPrefix), boost::python::return_value_policy<boost::python::return_by_value>())
	.def("addNamespaceBinding", static_cast<void(*)(xercesc::DOMXPathNSResolver&, const XMLString&, const XMLString&)>(&DOMXPathNSResolverDefVisitor::addNamespaceBinding))
	.def("addNamespaceBinding", static_cast<void(*)(xercesc::DOMXPathNSResolver&, const std::string&, const std::string&)>(&DOMXPathNSResolverDefVisitor::addNamespaceBinding))
	;
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMXPathNSResolver& self, const XMLString& prefix) {
	return self.lookupNamespaceURI(prefix.ptr());
}

static const XMLCh* lookupNamespaceURI(xercesc::DOMXPathNSResolver& self, const std::string& prefix) {
	XMLString buff(prefix);
	return DOMXPathNSResolverDefVisitor::lookupNamespaceURI(self, buff);
}

static const XMLCh* lookupPrefix(xercesc::DOMXPathNSResolver& self, const XMLString& namespaceURI) {
	return self.lookupPrefix(namespaceURI.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMXPathNSResolver& self, const std::string& namespaceURI) {
	XMLString buff(namespaceURI);
	return DOMXPathNSResolverDefVisitor::lookupPrefix(self, buff);
}

static void addNamespaceBinding(xercesc::DOMXPathNSResolver& self, const XMLString& prefix, const XMLString& uri) {
	self.addNamespaceBinding(prefix.ptr(), uri.ptr());
}

static void addNamespaceBinding(xercesc::DOMXPathNSResolver& self, const std::string& prefix, const std::string& uri) {
	XMLString buff1(prefix), buff2(uri);
	DOMXPathNSResolverDefVisitor::addNamespaceBinding(self, buff1, buff2);
}

};

void DOMXPathNSResolver_init(void) {
	//! xercesc::DOMXPathNSResolver
	boost::python::class_<xercesc::DOMXPathNSResolver, boost::noncopyable>("DOMXPathNSResolver", boost::python::no_init)
			.def(DOMXPathNSResolverDefVisitor())
			.def("lookupNamespaceURI", &xercesc::DOMXPathNSResolver::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("lookupPrefix", &xercesc::DOMXPathNSResolver::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("addNamespaceBinding", &xercesc::DOMXPathNSResolver::addNamespaceBinding)
			.def("release", &xercesc::DOMXPathNSResolver::release)
			;
}

} /* namespace pyxerces */
