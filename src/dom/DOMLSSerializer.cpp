/*
 * DOMLSSerializer.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMLSSerializer.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMLSOutput.hpp>

#include <xercesc/dom/DOMLSSerializer.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
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

static void setNewLine(xercesc::DOMLSSerializer& self, const STR newLine) {
	XMLString buff(newLine);
	self.setNewLine(buff.ptr());
}

static bool writeToURI(xercesc::DOMLSSerializer& self, xercesc::DOMNode* nodeToWrite, const STR uri) {
	XMLString buff(uri);
	return self.writeToURI(nodeToWrite, buff.ptr());
}

};

class DOMLSSerializerWrapper
: public xercesc::DOMLSSerializer, public boost::python::wrapper<xercesc::DOMLSSerializer>
{
public:
xercesc::DOMConfiguration* getDomConfig() {
	return this->get_override("getDomConfig")();
}

void setNewLine(const XMLCh* const newLine) {
	this->get_override("setNewLine")(XMLString(newLine));
}

void setFilter(xercesc::DOMLSSerializerFilter *filter) {
	this->get_override("setFilter")(boost::python::ptr(filter));
}

const XMLCh* getNewLine() const {
	return this->get_override("getNewLine")();
}

xercesc::DOMLSSerializerFilter* getFilter() const {
	return this->get_override("getFilter")();
}

bool write(const xercesc::DOMNode* nodeToWrite, xercesc::DOMLSOutput* const destination) {
	return this->get_override("write")(boost::python::ptr(nodeToWrite), boost::python::ptr(destination));
}

bool writeToURI(const xercesc::DOMNode* nodeToWrite, const XMLCh* uri) {
	return this->get_override("writeToURI")(boost::python::ptr(nodeToWrite), XMLString(uri));
}

XMLCh* writeToString(const xercesc::DOMNode* nodeToWrite, xercesc::MemoryManager* manager = NULL) {
	return this->get_override("writeToString")(boost::python::ptr(nodeToWrite), boost::python::ptr(manager));
}

void release() {
	this->get_override("release")();
}

};

//! DOMLSSerializer
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMLSSerializerWriteToStringOverloads, writeToString, 1, 2)

void DOMLSSerializer_init(void) {
	//! xercesc::DOMLSSerializer
	boost::python::class_<DOMLSSerializerWrapper, boost::noncopyable>("DOMLSSerializer")
			.def(DOMLSSerializerDefVisitor<XMLString&>())
			.def(DOMLSSerializerDefVisitor<char*>())
			.def("getDomConfig", boost::python::pure_virtual(&xercesc::DOMLSSerializer::getDomConfig), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setNewLine", boost::python::pure_virtual(&xercesc::DOMLSSerializer::setNewLine))
			.def("setFilter", boost::python::pure_virtual(&xercesc::DOMLSSerializer::setFilter))
			.def("getNewLine", boost::python::pure_virtual(&xercesc::DOMLSSerializer::getNewLine), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getFilter", boost::python::pure_virtual(&xercesc::DOMLSSerializer::getFilter), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("write", boost::python::pure_virtual(&xercesc::DOMLSSerializer::write))
			.def("writeToURI", boost::python::pure_virtual(&xercesc::DOMLSSerializer::writeToURI))
			.def("writeToString", boost::python::pure_virtual(&xercesc::DOMLSSerializer::writeToString), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("release", boost::python::pure_virtual(&xercesc::DOMLSSerializer::release))
			;
}

} /* namespace pyxerces */
