/*
 * DOMCharacterData.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMCharacterData.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMCharacterData.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMCharacterDataDefVisitor
: public boost::python::def_visitor<DOMCharacterDataDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("appendData", static_cast<void(*)(xercesc::DOMCharacterData&, const XMLString&)>(&DOMCharacterDataDefVisitor::appendData))
	.def("appendData", static_cast<void(*)(xercesc::DOMCharacterData&, const std::string&)>(&DOMCharacterDataDefVisitor::appendData))
	.def("insertData", static_cast<void(*)(xercesc::DOMCharacterData&, XMLSize_t, const XMLString&)>(&DOMCharacterDataDefVisitor::insertData))
	.def("insertData", static_cast<void(*)(xercesc::DOMCharacterData&, XMLSize_t, const std::string&)>(&DOMCharacterDataDefVisitor::insertData))
	.def("replaceData", static_cast<void(*)(xercesc::DOMCharacterData&, XMLSize_t, XMLSize_t, const XMLString&)>(&DOMCharacterDataDefVisitor::replaceData))
	.def("replaceData", static_cast<void(*)(xercesc::DOMCharacterData&, XMLSize_t, XMLSize_t, const std::string&)>(&DOMCharacterDataDefVisitor::replaceData))
	.def("setData", static_cast<void(*)(xercesc::DOMCharacterData&, const XMLString&)>(&DOMCharacterDataDefVisitor::setData))
	.def("setData", static_cast<void(*)(xercesc::DOMCharacterData&, const std::string&)>(&DOMCharacterDataDefVisitor::setData))
	;
}

static void appendData(xercesc::DOMCharacterData& self, const XMLString& arg) {
	self.appendData(arg.ptr());
}

static void appendData(xercesc::DOMCharacterData& self, const std::string& arg) {
	XMLString buff(arg);
	DOMCharacterDataDefVisitor::appendData(self, buff);
}

static void insertData(xercesc::DOMCharacterData& self, XMLSize_t offset, const XMLString& arg) {
	self.insertData(offset, arg.ptr());
}

static void insertData(xercesc::DOMCharacterData& self, XMLSize_t offset, const std::string& arg) {
	XMLString buff(arg);
	DOMCharacterDataDefVisitor::insertData(self, offset, buff);
}

static void replaceData(xercesc::DOMCharacterData& self, XMLSize_t offset, XMLSize_t count, const XMLString& arg) {
	self.replaceData(offset, count, arg.ptr());
}

static void replaceData(xercesc::DOMCharacterData& self, XMLSize_t offset, XMLSize_t count, const std::string& arg) {
	XMLString buff(arg);
	DOMCharacterDataDefVisitor::replaceData(self, offset, count, buff);
}

static void setData(xercesc::DOMCharacterData& self, const XMLString& data) {
	self.setData(data.ptr());
}

static void setData(xercesc::DOMCharacterData& self, const std::string& data) {
	XMLString buff(data);
	DOMCharacterDataDefVisitor::setData(self, buff);
}
};

void DOMCharacterData_init(void) {
	//! xercesc::DOMCharacterData
	boost::python::class_<xercesc::DOMCharacterData, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMCharacterData", boost::python::no_init)
			.def(DOMCharacterDataDefVisitor())
			.def("getData", &xercesc::DOMCharacterData::getData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLength", &xercesc::DOMCharacterData::getLength)
			.def("substringData", &xercesc::DOMCharacterData::substringData, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("appendData", &xercesc::DOMCharacterData::appendData)
			.def("insertData", &xercesc::DOMCharacterData::insertData)
			.def("deleteData", &xercesc::DOMCharacterData::deleteData)
			.def("replaceData", &xercesc::DOMCharacterData::replaceData)
			.def("setData", &xercesc::DOMCharacterData::setData)
			;
}

} /* namespace pyxerces */
