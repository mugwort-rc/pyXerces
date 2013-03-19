/*
 * DOMTreeWalker.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "DOMTreeWalker.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMTreeWalker.hpp>

namespace pyxerces {

class DOMTreeWalkerWrapper
: public xercesc::DOMTreeWalker, public boost::python::wrapper<xercesc::DOMTreeWalker>
{
public:
bool test;
xercesc::DOMNode* getRoot() {
	return this->get_override("getRoot")();
}

xercesc::DOMNodeFilter::ShowType getWhatToShow() {
	return this->get_override("getWhatToShow")();
}

xercesc::DOMNodeFilter*	 getFilter() {
	return this->get_override("getFilter")();
}

bool getExpandEntityReferences() {
	return this->get_override("getExpandEntityReferences")();
}

xercesc::DOMNode* getCurrentNode() {
	return this->get_override("getCurrentNode")();
}

xercesc::DOMNode* parentNode() {
	return this->get_override("parentNode")();
}

xercesc::DOMNode* firstChild() {
	return this->get_override("firstChild")();
}

xercesc::DOMNode* lastChild() {
	return this->get_override("lastChild")();
}

xercesc::DOMNode* previousSibling() {
	return this->get_override("previousSibling")();
}

xercesc::DOMNode* nextSibling() {
	return this->get_override("nextSibling")();
}

xercesc::DOMNode* previousNode() {
	return this->get_override("previousNode")();
}

xercesc::DOMNode* nextNode() {
	return this->get_override("nextNode")();
}

void setCurrentNode(xercesc::DOMNode* currentNode) {
	this->get_override("setCurrentNode")(boost::python::ptr(currentNode));
}

void release() {
	this->get_override("release")();
}

};

void DOMTreeWalker_init(void) {
	//! xercesc::DOMTreeWalker
	boost::python::class_<DOMTreeWalkerWrapper, boost::noncopyable>("DOMTreeWalker")
			.def("getRoot", boost::python::pure_virtual(&xercesc::DOMTreeWalker::getRoot), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getWhatToShow", boost::python::pure_virtual(&xercesc::DOMTreeWalker::getWhatToShow))
			.def("getFilter", boost::python::pure_virtual(&xercesc::DOMTreeWalker::getFilter), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getExpandEntityReferences", boost::python::pure_virtual(&xercesc::DOMTreeWalker::getExpandEntityReferences))
			.def("getCurrentNode", boost::python::pure_virtual(&xercesc::DOMTreeWalker::getCurrentNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("parentNode", boost::python::pure_virtual(&xercesc::DOMTreeWalker::parentNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("firstChild", boost::python::pure_virtual(&xercesc::DOMTreeWalker::firstChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("lastChild", boost::python::pure_virtual(&xercesc::DOMTreeWalker::lastChild), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousSibling", boost::python::pure_virtual(&xercesc::DOMTreeWalker::previousSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("nextSibling", boost::python::pure_virtual(&xercesc::DOMTreeWalker::nextSibling), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("previousNode", boost::python::pure_virtual(&xercesc::DOMTreeWalker::previousNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("nextNode", boost::python::pure_virtual(&xercesc::DOMTreeWalker::nextNode), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setCurrentNode", boost::python::pure_virtual(&xercesc::DOMTreeWalker::setCurrentNode))
			.def("release", boost::python::pure_virtual(&xercesc::DOMTreeWalker::release))
			;
}

} /* namespace pyxerces */
