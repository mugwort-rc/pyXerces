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

template <class STR>
class DOMLSSerializerDefVisitor
: public boost::python::def_visitor<DOMLSSerializerDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setNewLine", &DOMLSSerializerDefVisitor::setNewLine)
	.def("writeToURI", &DOMLSSerializerDefVisitor::writeToURI)
	;
}

static void setNewLine(xercesc::DOMLSSerializer& self, const STR& newLine) {
	XMLString buff(newLine);
	self.setNewLine(buff.ptr());
}

static bool writeToURI(xercesc::DOMLSSerializer& self, xercesc::DOMNode* nodeToWrite, const STR& uri) {
	XMLString buff(uri);
	return self.writeToURI(nodeToWrite, buff.ptr());
}

};

void DOMLSSerializer_init(void) {
	//! xercesc::DOMLSSerializer
	boost::python::class_<xercesc::DOMLSSerializer, boost::noncopyable>("DOMLSSerializer", boost::python::no_init)
			.def(DOMLSSerializerDefVisitor<XMLString>())
			.def(DOMLSSerializerDefVisitor<std::string>())
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
