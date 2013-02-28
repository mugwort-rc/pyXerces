/*
 * XMLErrorReporter.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLErrorReporter.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLErrorReporter.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XMLErrorReporterDefVisitor
: public boost::python::def_visitor<XMLErrorReporterDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("error", &XMLErrorReporterDefVisitor::error)
	;
}

static void error(xercesc::XMLErrorReporter& self, const unsigned int errCode, const STR& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const STR& errorText, const STR& systemId, const STR& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	self.error(errCode, buff1.ptr(), type, buff2.ptr(), buff3.ptr(), buff4.ptr(), lineNum, colNum);
}

};

void XMLErrorReporter_init(void) {
	//! xercesc::XMLErrorReporter
	auto XMLErrorReporter = boost::python::class_<xercesc::XMLErrorReporter, boost::noncopyable>("XMLErrorReporter", boost::python::no_init)
			.def(XMLErrorReporterDefVisitor<XMLString>())
			.def(XMLErrorReporterDefVisitor<std::string>())
			.def("error", &xercesc::XMLErrorReporter::error)
			.def("resetErrors", &xercesc::XMLErrorReporter::resetErrors)
			;
	boost::python::scope XMLErrorReporterScope = XMLErrorReporter;
	//! xercesc::XMLErrorReporter::ErrTypes
	boost::python::enum_<xercesc::XMLErrorReporter::ErrTypes>("ErrTypes")
			.value("ErrType_Warning", xercesc::XMLErrorReporter::ErrType_Warning)
			.value("ErrType_Error", xercesc::XMLErrorReporter::ErrType_Error)
			.value("ErrType_Fatal", xercesc::XMLErrorReporter::ErrType_Fatal)
			.value("ErrTypes_Unknown", xercesc::XMLErrorReporter::ErrTypes_Unknown)
			.export_values()
			;

}

} /* namespace pyxerces */
