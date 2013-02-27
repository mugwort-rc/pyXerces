/*
 * DOMLSSerializer.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSSerializer.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMLSOutput.hpp>		//!< for forward declaration
#include <xercesc/dom/DOMLSSerializer.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! DOMLSSerializer
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMLSSerializerWriteToStringOverloads, writeToString, 1, 2)

class DOMLSSerializerDefVisitor
: public boost::python::def_visitor<DOMLSSerializerDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setNewLine", static_cast<void(*)(xercesc::DOMLSSerializer&, const XMLString&)>(&DOMLSSerializerDefVisitor::setNewLine))
	.def("setNewLine", static_cast<void(*)(xercesc::DOMLSSerializer&, const std::string&)>(&DOMLSSerializerDefVisitor::setNewLine))
	.def("writeToURI", static_cast<bool(*)(xercesc::DOMLSSerializer&, xercesc::DOMNode*, const XMLString&)>(&DOMLSSerializerDefVisitor::writeToURI))
	.def("writeToURI", static_cast<bool(*)(xercesc::DOMLSSerializer&, xercesc::DOMNode*, const std::string&)>(&DOMLSSerializerDefVisitor::writeToURI))
	;
}

static void setNewLine(xercesc::DOMLSSerializer& self, const XMLString& newLine) {
	self.setNewLine(newLine.ptr());
}

static void setNewLine(xercesc::DOMLSSerializer& self, const std::string& newLine) {
	XMLString buff(newLine);
	DOMLSSerializerDefVisitor::setNewLine(self, buff);
}

static bool writeToURI(xercesc::DOMLSSerializer& self, xercesc::DOMNode* nodeToWrite, const XMLString& uri) {
	return self.writeToURI(nodeToWrite, uri.ptr());
}

static bool writeToURI(xercesc::DOMLSSerializer& self, xercesc::DOMNode* nodeToWrite, const std::string& uri) {
	XMLString buff(uri);
	return DOMLSSerializerDefVisitor::writeToURI(self, nodeToWrite, buff);
}
};

void DOMLSSerializer_init(void) {
	//! xercesc::DOMLSSerializer
	boost::python::class_<xercesc::DOMLSSerializer, boost::noncopyable>("DOMLSSerializer", boost::python::no_init)
			.def(DOMLSSerializerDefVisitor())
			.def("getDomConfig", &xercesc::DOMLSSerializer::getDomConfig, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNewLine", &xercesc::DOMLSSerializer::setNewLine)
			.def("setFilter", &xercesc::DOMLSSerializer::setFilter)
			.def("getNewLine", &xercesc::DOMLSSerializer::getNewLine, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFilter", &xercesc::DOMLSSerializer::getFilter, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("write", &xercesc::DOMLSSerializer::write)
			.def("writeToURI", &xercesc::DOMLSSerializer::writeToURI)
			.def("writeToString", &xercesc::DOMLSSerializer::writeToString, DOMLSSerializerWriteToStringOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("release", &xercesc::DOMLSSerializer::release)
			;
}

} /* namespace pyxerces */
