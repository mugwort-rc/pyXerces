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

template <typename STR>
class XMLNotationDeclDefVisitor
: public boost::python::def_visitor<XMLNotationDeclDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const STR, const STR, const STR, const STR, xercesc::MemoryManager* const)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const STR, const STR, const STR, const STR)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const STR, const STR, const STR, xercesc::MemoryManager* const)>(&XMLNotationDecl_fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::XMLNotationDecl*(*)(const STR, const STR, const STR)>(&XMLNotationDecl_fromstring)))
	.def("setName", &XMLNotationDeclDefVisitor<STR>::setName)
	.def("setPublicId", &XMLNotationDeclDefVisitor<STR>::setPublicId)
	.def("setSystemId", &XMLNotationDeclDefVisitor<STR>::setSystemId)
	.def("setBaseURI", &XMLNotationDeclDefVisitor<STR>::setBaseURI)
	;
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const STR notName, const STR pubId, const STR sysId, const STR baseURI, xercesc::MemoryManager* const manager) {
	XMLString buff1(notName), buff2(pubId), buff3(sysId), buff4(baseURI);
	return new xercesc::XMLNotationDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr(), manager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const STR notName, const STR pubId, const STR sysId, const STR baseURI) {
	return XMLNotationDecl_fromstring(notName, pubId, sysId, baseURI, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const STR notName, const STR pubId, const STR sysId, xercesc::MemoryManager* const manager) {
	XMLString buff1(notName), buff2(pubId), buff3(sysId);
	return new xercesc::XMLNotationDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), nullptr, manager);
}

static xercesc::XMLNotationDecl* XMLNotationDecl_fromstring(const STR notName, const STR pubId, const STR sysId) {
	return XMLNotationDecl_fromstring(notName, pubId, sysId, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static void setName(xercesc::XMLNotationDecl& self, const STR notName) {
	XMLString buff(notName);
	self.setName(buff.ptr());
}

static void setPublicId(xercesc::XMLNotationDecl& self, const STR newId) {
	XMLString buff(newId);
	self.setPublicId(buff.ptr());
}

static void setSystemId(xercesc::XMLNotationDecl& self, const STR newId) {
	XMLString buff(newId);
	self.setSystemId(buff.ptr());
}

static void setBaseURI(xercesc::XMLNotationDecl& self, const STR newId) {
	XMLString buff(newId);
	self.setBaseURI(buff.ptr());
}

};

void XMLNotationDecl_init(void) {
	//! xercesc::XMLNotationDecl
	boost::python::class_<xercesc::XMLNotationDecl, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLNotationDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const XMLCh* const, const XMLCh* const, boost::python::optional<const XMLCh* const, xercesc::MemoryManager* const> >())
			.def(XMLNotationDeclDefVisitor<XMLString&>())
			.def(XMLNotationDeclDefVisitor<char*>())
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
