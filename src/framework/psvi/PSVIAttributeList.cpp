/*
 * PSVIAttributeList.cpp
 *
 *  Created on: 2013/03/14
 *      Author: mugwort_rc
 */

#include "PSVIAttributeList.h"

#include <boost/python.hpp>
#include <xercesc/framework/psvi/PSVIAttributeList.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class PSVIAttributeListDefVisitor
: public boost::python::def_visitor<PSVIAttributeListDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getAttributePSVIByName", &PSVIAttributeListDefVisitor<STR>::getAttributePSVIByName, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getPSVIAttributeToFill", &PSVIAttributeListDefVisitor<STR>::getPSVIAttributeToFill, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::PSVIAttribute *getAttributePSVIByName(xercesc::PSVIAttributeList& self, const STR attrName, const STR attrNamespace) {
	XMLString buff1(attrName), buff2(attrNamespace);
	return self.getAttributePSVIByName(buff1.ptr(), buff2.ptr());
}

static xercesc::PSVIAttribute *getPSVIAttributeToFill(xercesc::PSVIAttributeList& self, const STR attrName, const STR attrNS) {
	XMLString buff1(attrName), buff2(attrNS);
	return self.getPSVIAttributeToFill(buff1.ptr(), buff2.ptr());
}

};

void PSVIAttributeList_init(void) {
	//! xercesc::PSVIAttributeList
	boost::python::class_<xercesc::PSVIAttributeList, boost::noncopyable>("PSVIAttributeList", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIAttributeListDefVisitor<XMLString&>())
			.def(PSVIAttributeListDefVisitor<char*>())
			.def("getLength", &xercesc::PSVIAttributeList::getLength)
			.def("getAttributePSVIAtIndex", &xercesc::PSVIAttributeList::getAttributePSVIAtIndex, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttributeNameAtIndex", &xercesc::PSVIAttributeList::getAttributeNameAtIndex, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttributeNamespaceAtIndex", &xercesc::PSVIAttributeList::getAttributeNamespaceAtIndex, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAttributePSVIByName", &xercesc::PSVIAttributeList::getAttributePSVIByName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPSVIAttributeToFill", &xercesc::PSVIAttributeList::getPSVIAttributeToFill, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("reset", &xercesc::PSVIAttributeList::reset)
			;
}

} /* namespace pyxerces */
