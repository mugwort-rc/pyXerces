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

class PSVIAttributeListDefVisitor
: public boost::python::def_visitor<PSVIAttributeListDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getAttributePSVIByName", &PSVIAttributeListDefVisitor::getAttributePSVIByName, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getPSVIAttributeToFill", &PSVIAttributeListDefVisitor::getPSVIAttributeToFill, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::PSVIAttribute *getAttributePSVIByName(xercesc::PSVIAttributeList& self, const XMLString& attrName, const XMLString& attrNamespace) {
	return self.getAttributePSVIByName(attrName.ptr(), attrNamespace.ptr());
}

static xercesc::PSVIAttribute *getPSVIAttributeToFill(xercesc::PSVIAttributeList& self, const XMLString& attrName, const XMLString& attrNS) {
	return self.getPSVIAttributeToFill(attrName.ptr(), attrNS.ptr());
}

};

void PSVIAttributeList_init(void) {
	//! xercesc::PSVIAttributeList
	boost::python::class_<xercesc::PSVIAttributeList, boost::noncopyable>("PSVIAttributeList", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(PSVIAttributeListDefVisitor())
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
