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

class XMLErrorReporterDefVisitor
: public boost::python::def_visitor<XMLErrorReporterDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("error", static_cast<void(*)(xercesc::XMLErrorReporter&, const unsigned int, const XMLString&, const xercesc::XMLErrorReporter::ErrTypes, const XMLString&, const XMLString&, const XMLString&, const XMLFileLoc, const XMLFileLoc)>(&XMLErrorReporterDefVisitor::error))
	.def("error", static_cast<void(*)(xercesc::XMLErrorReporter&, const unsigned int, const std::string&, const xercesc::XMLErrorReporter::ErrTypes, const std::string&, const std::string&, const std::string&, const XMLFileLoc, const XMLFileLoc)>(&XMLErrorReporterDefVisitor::error))
	;
}

static void error(xercesc::XMLErrorReporter& self, const unsigned int errCode, const XMLString& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const XMLString& errorText, const XMLString& systemId, const XMLString& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	self.error(errCode, errDomain.ptr(), type, errorText.ptr(), systemId.ptr(), publicId.ptr(), lineNum, colNum);
}

static void error(xercesc::XMLErrorReporter& self, const unsigned int errCode, const std::string& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const std::string& errorText, const std::string& systemId, const std::string& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	XMLErrorReporterDefVisitor::error(self, errCode, buff1, type, buff2, buff3, buff4, lineNum, colNum);
}

};

void XMLErrorReporter_init(void) {
	//! xercesc::XMLErrorReporter
	auto XMLErrorReporter = boost::python::class_<xercesc::XMLErrorReporter, boost::noncopyable>("XMLErrorReporter", boost::python::no_init)
			.def(XMLErrorReporterDefVisitor())
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
