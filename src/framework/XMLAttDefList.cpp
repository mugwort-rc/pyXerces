/*
 * XMLAttDefList.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLAttDefList.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/framework/XMLAttDef.hpp>

#include <xercesc/framework/XMLAttDefList.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLAttDefListDefVisitor
: public boost::python::def_visitor<XMLAttDefListDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findAttDef", static_cast<xercesc::XMLAttDef*(*)(xercesc::XMLAttDefList&, const unsigned int, const STR&)>(&XMLAttDefListDefVisitor<STR>::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("findAttDef", static_cast<xercesc::XMLAttDef*(*)(xercesc::XMLAttDefList&, const STR&, const STR&)>(&XMLAttDefListDefVisitor<STR>::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLAttDef* findAttDef(xercesc::XMLAttDefList& self, const unsigned int uriID, const STR& attName) {
	XMLString buff(attName);
	return self.findAttDef(uriID, buff.ptr());
}

static xercesc::XMLAttDef* findAttDef(xercesc::XMLAttDefList& self, const STR& attURI, const STR& attName) {
	XMLString buff1(attURI), buff2(attName);
	return self.findAttDef(buff1.ptr(), buff2.ptr());
}

};

void XMLAttDefList_init(void) {
	//! xercesc::XMLAttDefList
	boost::python::class_<xercesc::XMLAttDefList, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLAttDefList", boost::python::no_init)
			.def(XMLAttDefListDefVisitor<XMLString>())
			.def(XMLAttDefListDefVisitor<std::string>())
			.def("isEmpty", &xercesc::XMLAttDefList::isEmpty)
			.def("findAttDef", static_cast<xercesc::XMLAttDef*(xercesc::XMLAttDefList::*)(const unsigned int, const XMLCh* const)>(&xercesc::XMLAttDefList::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("findAttDef", static_cast<xercesc::XMLAttDef*(xercesc::XMLAttDefList::*)(const XMLCh*, const XMLCh* const)>(&xercesc::XMLAttDefList::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttDefCount", &xercesc::XMLAttDefList::getAttDefCount)
			.def("getAttDef", static_cast<xercesc::XMLAttDef&(xercesc::XMLAttDefList::*)(XMLSize_t)>(&xercesc::XMLAttDefList::getAttDef), boost::python::return_internal_reference<>())
			PyDECL_XSERIALIZABLE(XMLAttDefList)
			.def("getMemoryManager", &xercesc::XMLAttDefList::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
