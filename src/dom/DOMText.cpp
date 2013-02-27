/*
 * DOMText.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMText.h"

#include <boost/python.hpp>
#include <xercesc/dom/DOMText.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class DOMTextDefVisitor
: public boost::python::def_visitor<DOMTextDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("replaceWholeText", static_cast<xercesc::DOMText*(*)(xercesc::DOMText&, const XMLString&)>(&DOMTextDefVisitor::replaceWholeText), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("replaceWholeText", static_cast<xercesc::DOMText*(*)(xercesc::DOMText&, const std::string&)>(&DOMTextDefVisitor::replaceWholeText), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMText* replaceWholeText(xercesc::DOMText& self, const XMLString& content) {
	return self.replaceWholeText(content.ptr());
}

static xercesc::DOMText* replaceWholeText(xercesc::DOMText& self, const std::string& content) {
	XMLString buff(content);
	return DOMTextDefVisitor::replaceWholeText(self, buff);
}
};

void DOMText_init(void) {
	//! xercesc::DOMText
	boost::python::class_<xercesc::DOMText, boost::noncopyable, boost::python::bases<xercesc::DOMCharacterData> >("DOMText", boost::python::no_init)
			.def(DOMTextDefVisitor())
			.def("splitText", &xercesc::DOMText::splitText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getIsElementContentWhitespace", &xercesc::DOMText::getIsElementContentWhitespace)
			.def("getWholeText", &xercesc::DOMText::getWholeText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("replaceWholeText", &xercesc::DOMText::replaceWholeText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isIgnorableWhitespace", &xercesc::DOMText::isIgnorableWhitespace)
			;
}

} /* namespace pyxerces */
