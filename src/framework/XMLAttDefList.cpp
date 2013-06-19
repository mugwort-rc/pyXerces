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

class XMLAttDefListDefVisitor
: public boost::python::def_visitor<XMLAttDefListDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("findAttDef", static_cast<xercesc::XMLAttDef*(*)(xercesc::XMLAttDefList&, const unsigned int, const XMLString&)>(&XMLAttDefListDefVisitor::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("findAttDef", static_cast<xercesc::XMLAttDef*(*)(xercesc::XMLAttDefList&, const XMLString&, const XMLString&)>(&XMLAttDefListDefVisitor::findAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::XMLAttDef* findAttDef(xercesc::XMLAttDefList& self, const unsigned int uriID, const XMLString& attName) {
	return self.findAttDef(uriID, attName.ptr());
}

static xercesc::XMLAttDef* findAttDef(xercesc::XMLAttDefList& self, const XMLString& attURI, const XMLString& attName) {
	return self.findAttDef(attURI.ptr(), attName.ptr());
}

};

class XMLAttDefListWrapper
: public xercesc::XMLAttDefList, public boost::python::wrapper<xercesc::XMLAttDefList>
{
public:
bool isEmpty() const {
	return this->get_override("isEmpty")();
}

xercesc::XMLAttDef* findAttDef(const unsigned int uriID, const XMLCh* const attName) {
	return this->get_override("findAttDef")(uriID, XMLString(attName));
}

const xercesc::XMLAttDef* findAttDef(const unsigned int uriID, const XMLCh* const attName) const {
	return this->get_override("findAttDef")(uriID, XMLString(attName));
}

xercesc::XMLAttDef* findAttDef(const XMLCh* const attURI, const XMLCh* const attName) {
	return this->get_override("findAttDef")(XMLString(attURI), XMLString(attName));
}

const xercesc::XMLAttDef* findAttDef(const XMLCh* const attURI, const XMLCh* const attName) const {
	return this->get_override("findAttDef")(XMLString(attURI), XMLString(attName));
}

XMLSize_t getAttDefCount() const {
	return this->get_override("getAttDefCount")();
}

xercesc::XMLAttDef &getAttDef(XMLSize_t index) {
	return this->get_override("getAttDef")(index);
}

const xercesc::XMLAttDef &getAttDef(XMLSize_t index) const {
	return this->get_override("getAttDef")(index);
}

PyDECL_XSERIALIZABLEWrapper

};

void XMLAttDefList_init(void) {
	//! xercesc::XMLAttDefList
	boost::python::class_<XMLAttDefListWrapper, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLAttDefList")
			.def(XMLAttDefListDefVisitor())
			.def("isEmpty", boost::python::pure_virtual(&xercesc::XMLAttDefList::isEmpty))
			.def("findAttDef", boost::python::pure_virtual(static_cast<xercesc::XMLAttDef*(xercesc::XMLAttDefList::*)(const unsigned int, const XMLCh* const)>(&xercesc::XMLAttDefList::findAttDef)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("findAttDef", boost::python::pure_virtual(static_cast<xercesc::XMLAttDef*(xercesc::XMLAttDefList::*)(const XMLCh*, const XMLCh* const)>(&xercesc::XMLAttDefList::findAttDef)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttDefCount", boost::python::pure_virtual(&xercesc::XMLAttDefList::getAttDefCount))
			.def("getAttDef", boost::python::pure_virtual(static_cast<xercesc::XMLAttDef&(xercesc::XMLAttDefList::*)(XMLSize_t)>(&xercesc::XMLAttDefList::getAttDef)), boost::python::return_internal_reference<>())
			PyDECL_XSERIALIZABLE(XMLAttDefList)
			.def("getMemoryManager", &xercesc::XMLAttDefList::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
