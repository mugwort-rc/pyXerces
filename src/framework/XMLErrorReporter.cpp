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
	.def("error", &XMLErrorReporterDefVisitor::error)
	;
}

static void error(xercesc::XMLErrorReporter& self, const unsigned int errCode, const XMLString& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const XMLString& errorText, const XMLString& systemId, const XMLString& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	self.error(errCode, errDomain.ptr(), type, errorText.ptr(), systemId.ptr(), systemId.ptr(), lineNum, colNum);
}

};

class XMLErrorReporterWrapper
: public xercesc::XMLErrorReporter, public boost::python::wrapper<xercesc::XMLErrorReporter>
{
public:
void error(const unsigned int errCode, const XMLCh* const errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const XMLCh* const errorText, const XMLCh* const systemId, const XMLCh* const publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	this->get_override("error")(errCode, XMLString(errDomain), type, XMLString(errorText), XMLString(systemId), XMLString(publicId), lineNum, colNum);
}

void resetErrors() {
	this->get_override("resetErrors")();
}

};

void XMLErrorReporter_init(void) {
	//! xercesc::XMLErrorReporter
	auto XMLErrorReporter = boost::python::class_<XMLErrorReporterWrapper, boost::noncopyable>("XMLErrorReporter")
			.def(XMLErrorReporterDefVisitor())
			.def("error", boost::python::pure_virtual(&xercesc::XMLErrorReporter::error))
			.def("resetErrors", boost::python::pure_virtual(&xercesc::XMLErrorReporter::resetErrors))
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
