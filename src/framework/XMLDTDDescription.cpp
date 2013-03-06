/*
 * XMLDTDDescription.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XMLDTDDescription.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLDTDDescription.hpp>

#include "../internal/XSerializable.h"
#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLDTDDescriptionDefVisitor
: public boost::python::def_visitor<XMLDTDDescriptionDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setRootName", &XMLDTDDescriptionDefVisitor<STR>::setRootName)
	.def("setSystemId", &XMLDTDDescriptionDefVisitor<STR>::setSystemId)
	;
}

static void setRootName(xercesc::XMLDTDDescription& self, const STR& name) {
	XMLString buff(name);
	self.setRootName(buff.ptr());
}

static void setSystemId(xercesc::XMLDTDDescription& self, const STR& id) {
	XMLString buff(id);
	self.setSystemId(buff.ptr());
}

};

void XMLDTDDescription_init(void) {
	//! xercesc::XMLDTDDescription
	boost::python::class_<xercesc::XMLDTDDescription, boost::noncopyable, boost::python::bases<xercesc::XMLGrammarDescription> >("XMLDTDDescription", boost::python::no_init)
			.def(XMLDTDDescriptionDefVisitor<XMLString>())
			.def(XMLDTDDescriptionDefVisitor<std::string>())
			.def("getGrammarType", &xercesc::XMLDTDDescription::getGrammarType)
			.def("getRootName", &xercesc::XMLDTDDescription::getRootName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::XMLDTDDescription::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setRootName", &xercesc::XMLDTDDescription::setRootName)
			.def("setSystemId", &xercesc::XMLDTDDescription::setSystemId)
			PyDECL_XSERIALIZABLE(XMLDTDDescription)
			;
}

} /* namespace pyxerces */
