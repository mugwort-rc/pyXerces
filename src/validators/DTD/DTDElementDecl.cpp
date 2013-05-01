/*
 * DTDElementDecl.cpp
 *
 *  Created on: 2013/03/06
 *      Author: mugwort_rc
 */

#include "DTDElementDecl.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/validators/DTD/DTDAttDefList.hpp>

#include <xercesc/validators/DTD/DTDElementDecl.hpp>

#include "../../internal/XSerializable.h"
#include "../../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class DTDElementDeclDefVisitor
: public boost::python::def_visitor<DTDElementDeclDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDElementDecl*(*)(const STR, const unsigned int, const xercesc::DTDElementDecl::ModelTypes, xercesc::MemoryManager* const)>(&DTDElementDecl_init)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::DTDElementDecl*(*)(const STR, const unsigned int, const xercesc::DTDElementDecl::ModelTypes)>(&DTDElementDecl_init)))
	.def("getAttDef", &DTDElementDeclDefVisitor<STR>::getAttDef, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DTDElementDecl* DTDElementDecl_init(const STR elemRawName, const unsigned int uriId, const xercesc::DTDElementDecl::ModelTypes modelType, xercesc::MemoryManager* const manager) {
	XMLString buff(elemRawName);
	return new xercesc::DTDElementDecl(buff.ptr(), uriId, modelType, manager);
}

static xercesc::DTDElementDecl* DTDElementDecl_init(const STR elemRawName, const unsigned int uriId, const xercesc::DTDElementDecl::ModelTypes modelType) {
	return DTDElementDecl_init(elemRawName, uriId, modelType, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::DTDAttDef* getAttDef(xercesc::DTDElementDecl& self, const STR attName) {
	XMLString buff(attName);
	return self.getAttDef(buff.ptr());
}

};

void DTDElementDecl_init(void) {
	//! xercesc::DTDElementDecl
	boost::python::class_<xercesc::DTDElementDecl, boost::noncopyable, boost::python::bases<xercesc::XMLElementDecl> >("DTDElementDecl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, const unsigned int, const xercesc::DTDElementDecl::ModelTypes, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::QName* const, const xercesc::DTDElementDecl::ModelTypes, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(DTDElementDeclDefVisitor<XMLString&>())
			.def(DTDElementDeclDefVisitor<char*>())
			.def("getAttDefList", &xercesc::DTDElementDecl::getAttDefList, boost::python::return_internal_reference<>())
			.def("getCharDataOpts", &xercesc::DTDElementDecl::getCharDataOpts)
			.def("hasAttDefs", &xercesc::DTDElementDecl::hasAttDefs)
			.def("getContentSpec", static_cast<xercesc::ContentSpecNode*(xercesc::DTDElementDecl::*)(void)>(&xercesc::DTDElementDecl::getContentSpec), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentSpec", &xercesc::DTDElementDecl::setContentSpec)
			.def("getContentModel", &xercesc::DTDElementDecl::getContentModel, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentModel", &xercesc::DTDElementDecl::setContentModel)
			.def("getFormattedContentModel", &xercesc::DTDElementDecl::getFormattedContentModel, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getKey", &xercesc::DTDElementDecl::getKey, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttDef", static_cast<xercesc::DTDAttDef*(xercesc::DTDElementDecl::*)(const XMLCh* const)>(&xercesc::DTDElementDecl::getAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getModelType", &xercesc::DTDElementDecl::getModelType)
			.def("addAttDef", &xercesc::DTDElementDecl::addAttDef)
			.def("setModelType", &xercesc::DTDElementDecl::setModelType)
			PyDECL_XSERIALIZABLE(DTDElementDecl)
			.def("getObjectType", &xercesc::DTDElementDecl::getObjectType)
			;
}

} /* namespace pyxerces */

