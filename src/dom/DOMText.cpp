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

template <class STR>
class DOMTextDefVisitor
: public boost::python::def_visitor<DOMTextDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("replaceWholeText", &DOMTextDefVisitor::replaceWholeText, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMText* replaceWholeText(xercesc::DOMText& self, const STR& content) {
	XMLString buff(content);
	return self.replaceWholeText(buff.ptr());
}

};

void DOMText_init(void) {
	//! xercesc::DOMText
	boost::python::class_<xercesc::DOMText, boost::noncopyable, boost::python::bases<xercesc::DOMCharacterData> >("DOMText", boost::python::no_init)
			.def(DOMTextDefVisitor<XMLString>())
			.def(DOMTextDefVisitor<std::string>())
			.def("splitText", &xercesc::DOMText::splitText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getIsElementContentWhitespace", &xercesc::DOMText::getIsElementContentWhitespace)
			.def("getWholeText", &xercesc::DOMText::getWholeText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("replaceWholeText", &xercesc::DOMText::replaceWholeText, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isIgnorableWhitespace", &xercesc::DOMText::isIgnorableWhitespace)
			;
}

} /* namespace pyxerces */
