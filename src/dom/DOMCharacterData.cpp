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

template <class STR>
class DOMCharacterDataDefVisitor
: public boost::python::def_visitor<DOMCharacterDataDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("appendData", &DOMCharacterDataDefVisitor::appendData)
	.def("insertData", &DOMCharacterDataDefVisitor::insertData)
	.def("replaceData", &DOMCharacterDataDefVisitor::replaceData)
	.def("setData", &DOMCharacterDataDefVisitor::setData)
	;
}

static void appendData(xercesc::DOMCharacterData& self, const STR& arg) {
	XMLString buff(arg);
	self.appendData(buff.ptr());
}

static void insertData(xercesc::DOMCharacterData& self, XMLSize_t offset, const STR& arg) {
	XMLString buff(arg);
	self.insertData(offset, buff);
}

static void replaceData(xercesc::DOMCharacterData& self, XMLSize_t offset, XMLSize_t count, const STR& arg) {
	XMLString buff(arg);
	self.replaceData(offset, count, buff.ptr());
}

static void setData(xercesc::DOMCharacterData& self, const STR& data) {
	XMLString buff(data);
	self.setData(buff.ptr());
}

};

void DOMCharacterData_init(void) {
	//! xercesc::DOMCharacterData
	boost::python::class_<xercesc::DOMCharacterData, boost::noncopyable, boost::python::bases<xercesc::DOMNode> >("DOMCharacterData", boost::python::no_init)
			.def(DOMCharacterDataDefVisitor<XMLString>())
			.def(DOMCharacterDataDefVisitor<std::string>())
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
