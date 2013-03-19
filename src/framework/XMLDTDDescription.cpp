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

class XMLDTDDescriptionWrapper
: public xercesc::XMLDTDDescription, public boost::python::wrapper<xercesc::XMLDTDDescription>
{
public:
xercesc::Grammar::GrammarType getGrammarType() const {
    if(boost::python::override getGrammarType = this->get_override("getGrammarType")){
    	return getGrammarType();
    }else{
    	return xercesc::XMLDTDDescription::getGrammarType();
    }
}

const XMLCh* getRootName() const {
	return this->get_override("getRootName")();
}

const XMLCh* getSystemId() const {
	if(boost::python::override getSystemId = this->get_override("getSystemId")){
		return getSystemId();
	}else{
		return xercesc::XMLDTDDescription::getSystemId();
	}
}

void setRootName(const XMLCh* const name) {
	this->get_override("setRootName")(XMLString(name));
}

void setSystemId(const XMLCh* const id) {
	if(boost::python::override setSystemId = this->get_override("setSystemId")){
		setSystemId(XMLString(id));
	}else{
		xercesc::XMLDTDDescription::setSystemId(id);
	}
}

// ---------- XMLGrammarDescription ----------
const XMLCh* getGrammarKey() const {
	return this->get_override("getGrammarKey")();
}

PyDECL_XSERIALIZABLEWrapper

};

void XMLDTDDescription_init(void) {
	//! xercesc::XMLDTDDescription
	boost::python::class_<XMLDTDDescriptionWrapper, boost::noncopyable, boost::python::bases<xercesc::XMLGrammarDescription> >("XMLDTDDescription")
			.def(XMLDTDDescriptionDefVisitor<XMLString>())
			.def(XMLDTDDescriptionDefVisitor<std::string>())
			.def("getGrammarType", &xercesc::XMLDTDDescription::getGrammarType)
			.def("getRootName", boost::python::pure_virtual(&xercesc::XMLDTDDescription::getRootName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSystemId", &xercesc::XMLDTDDescription::getSystemId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("setRootName", boost::python::pure_virtual(&xercesc::XMLDTDDescription::setRootName))
			.def("setSystemId", &xercesc::XMLDTDDescription::setSystemId)
			PyDECL_XSERIALIZABLE(XMLDTDDescription)
			;
}

} /* namespace pyxerces */
