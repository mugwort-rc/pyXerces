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

template <class STR>
class DOMXPathNSResolverDefVisitor
: public boost::python::def_visitor<DOMXPathNSResolverDefVisitor<STR> >
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

static const XMLCh* lookupNamespaceURI(xercesc::DOMXPathNSResolver& self, const STR& prefix) {
	XMLString buff(prefix);
	return self.lookupNamespaceURI(buff.ptr());
}

static const XMLCh* lookupPrefix(xercesc::DOMXPathNSResolver& self, const STR& namespaceURI) {
	XMLString buff(namespaceURI);
	return self.lookupPrefix(buff.ptr());
}

static void addNamespaceBinding(xercesc::DOMXPathNSResolver& self, const STR& prefix, const STR& uri) {
	XMLString buff1(prefix), buff2(uri);
	self.addNamespaceBinding(buff1.ptr(), buff2.ptr());
}

};

void DOMXPathNSResolver_init(void) {
	//! xercesc::DOMXPathNSResolver
	boost::python::class_<xercesc::DOMXPathNSResolver, boost::noncopyable>("DOMXPathNSResolver", boost::python::no_init)
			.def(DOMXPathNSResolverDefVisitor<XMLString>())
			.def(DOMXPathNSResolverDefVisitor<std::string>())
			.def("lookupNamespaceURI", &xercesc::DOMXPathNSResolver::lookupNamespaceURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("lookupPrefix", &xercesc::DOMXPathNSResolver::lookupPrefix, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("addNamespaceBinding", &xercesc::DOMXPathNSResolver::addNamespaceBinding)
			.def("release", &xercesc::DOMXPathNSResolver::release)
			;
}

} /* namespace pyxerces */
