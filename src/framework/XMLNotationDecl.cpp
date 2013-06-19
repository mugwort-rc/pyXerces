/*
 * XMLNotationDecl.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLNotationDecl.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

class XMLNotationDeclDefVisitor
: public boost::python::def_visitor<XMLNotationDeclDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const XMLString&, const XMLString&, const XMLString&, const XMLString&, xercesc::MemoryManager* const)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const XMLString&, const XMLString&, const XMLString&, const XMLString&)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const XMLString&, const XMLString&, const XMLString&, xercesc::MemoryManager* const)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const XMLString&, const XMLString&, const XMLString&)>(&XMLNotationDecl_fromstring)))
	.def("setName", &XMLNotationDeclDefVisitor::setName)
	.def("setPublicId", &XMLNotationDeclDefVisitor::setPublicId)
	.def("setSystemId", &XMLNotationDeclDefVisitor::setSystemId)
	.def("setBaseURI", &XMLNotationDeclDefVisitor::setBaseURI)
	;
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const XMLString& notName, const XMLString& pubId, const XMLString& sysId, const XMLString& baseURI, xercesc::MemoryManager* const manager) {
	return new xercesc::XMLNotationDecl(notName.ptr(), pubId.ptr(), sysId.ptr(), baseURI.ptr(), manager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const XMLString& notName, const XMLString& pubId, const XMLString& sysId, const XMLString& baseURI) {
	return XMLNotationDecl_fromstring(notName, pubId, sysId, baseURI, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const XMLString& notName, const XMLString& pubId, const XMLString& sysId, xercesc::MemoryManager* const manager) {
	return new xercesc::XMLNotationDecl(notName.ptr(), pubId.ptr(), sysId.ptr(), nullptr, manager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const XMLString& notName, const XMLString& pubId, const XMLString& sysId) {
	return XMLNotationDecl_fromstring(notName, pubId, sysId, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setName(xercesc::XMLNotationDecl& self, const XMLString& notName) {
	self.setName(notName.ptr());
}

static void setPublicId(xercesc::XMLNotationDecl& self, const XMLString& newId) {
	self.setPublicId(newId.ptr());
}

static void setSystemId(xercesc::XMLNotationDecl& self, const XMLString& newId) {
	self.setSystemId(newId.ptr());
}

static void setBaseURI(xercesc::XMLNotationDecl& self, const XMLString& newId) {
	self.setBaseURI(newId.ptr());
}

};

void XMLNotationDecl_init(void) {
	//! xercesc::XMLNotationDecl
	boost::python::class_<xercesc::XMLNotationDecl, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLNotationDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const XMLCh* const, boost::python::optional<const XMLCh* const, xercesc::MemoryManager* const> >())
			.def(XMLNotationDeclDefVisitor())
			.def("getId", &xercesc::XMLNotationDecl::getId)
			.def("getName", &xercesc::XMLNotationDecl::getName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getPublicId", &xercesc::XMLNotationDecl::getPublicId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::XMLNotationDecl::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseURI", &xercesc::XMLNotationDecl::getBaseURI, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getNameSpaceId", &xercesc::XMLNotationDecl::getNameSpaceId)
			.def("getMemoryManager", &xercesc::XMLNotationDecl::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setId", &xercesc::XMLNotationDecl::setId)
			.def("setName", &xercesc::XMLNotationDecl::setName)
			.def("setPublicId", &xercesc::XMLNotationDecl::setPublicId)
			.def("setSystemId", &xercesc::XMLNotationDecl::setSystemId)
			.def("setBaseURI", &xercesc::XMLNotationDecl::setBaseURI)
			.def("setNameSpaceId", &xercesc::XMLNotationDecl::setNameSpaceId)
			.def("getKey", &xercesc::XMLNotationDecl::getKey, boost::python::return_value_policy<boost::python::return_by_value>())
			PyDECL_XSERIALIZABLE(XMLNotationDecl)
			;
}

} /* namespace pyxerces */
