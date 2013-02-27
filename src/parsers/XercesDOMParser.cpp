/*
 * XercesDOMParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "XercesDOMParser.h"

#include <boost/python.hpp>
#include <xercesc/sax/InputSource.hpp>					//!< for forward declaration
#include <xercesc/framework/XMLValidator.hpp>			//!< for forward declaration
#include <xercesc/framework/XMLGrammarPool.hpp>			//!< for forward declaration
#include <xercesc/sax/ErrorHandler.hpp>					//!< for forward declaration
#include <xercesc/sax/EntityResolver.hpp>				//!< for forward declaration
#include <xercesc/util/XMLEntityResolver.hpp>			//!< for forward declaration
#include <xercesc/validators/common/Grammar.hpp>		//!< for forward declaration
#include <xercesc/parsers/XercesDOMParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! XercesDOMParser
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XercesDOMParserLoadGrammarOverloads, loadGrammar, 2, 3)

class XercesDOMParserDefVisitor
: public boost::python::def_visitor<XercesDOMParserDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getGrammar", static_cast<xercesc::Grammar*(*)(xercesc::XercesDOMParser&, const XMLString&)>(&XercesDOMParserDefVisitor::getGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("getGrammar", static_cast<xercesc::Grammar*(*)(xercesc::XercesDOMParser&, const std::string&)>(&XercesDOMParserDefVisitor::getGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("error", static_cast<void(*)(xercesc::XercesDOMParser&, const unsigned int, const XMLString&, const xercesc::XMLErrorReporter::ErrTypes, const XMLString&, const XMLString&, const XMLString&, const XMLFileLoc, const XMLFileLoc)>(&XercesDOMParserDefVisitor::error))
	.def("error", static_cast<void(*)(xercesc::XercesDOMParser&, const unsigned int, const std::string&, const xercesc::XMLErrorReporter::ErrTypes, const std::string&, const std::string&, const std::string&, const XMLFileLoc, const XMLFileLoc)>(&XercesDOMParserDefVisitor::error))
	.def("expandSystemId", static_cast<bool(*)(xercesc::XercesDOMParser&, const XMLString&, xercesc::XMLBuffer&)>(&XercesDOMParserDefVisitor::expandSystemId))
	.def("expandSystemId", static_cast<bool(*)(xercesc::XercesDOMParser&, const std::string&, xercesc::XMLBuffer&)>(&XercesDOMParserDefVisitor::expandSystemId))
	;
}

static xercesc::Grammar* getGrammar(xercesc::XercesDOMParser& self, const XMLString& nameSpaceKey) {
	return self.getGrammar(nameSpaceKey.ptr());
}

static xercesc::Grammar* getGrammar(xercesc::XercesDOMParser& self, const std::string& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return XercesDOMParserDefVisitor::getGrammar(self, buff);
}

static void error(xercesc::XercesDOMParser& self, const unsigned int errCode, const XMLString& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const XMLString& errorText, const XMLString& systemId, const XMLString& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	self.error(errCode, errDomain.ptr(), type, errorText.ptr(), systemId.ptr(), publicId.ptr(), lineNum, colNum);
}

static void error(xercesc::XercesDOMParser& self, const unsigned int errCode, const std::string& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const std::string& errorText, const std::string& systemId, const std::string& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	XercesDOMParserDefVisitor::error(self, errCode, buff1, type, buff2, buff3, buff4, lineNum, colNum);
}

static bool expandSystemId(xercesc::XercesDOMParser& self, const XMLString& systemId, xercesc::XMLBuffer& toFill) {
	return self.expandSystemId(systemId.ptr(), toFill);
}

static bool expandSystemId(xercesc::XercesDOMParser& self, const std::string& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return XercesDOMParserDefVisitor::expandSystemId(self, buff, toFill);
}

};

void XercesDOMParser_init(void) {
	//! xercesc::XercesDOMParser
	boost::python::class_<xercesc::XercesDOMParser, boost::noncopyable, boost::python::bases<xercesc::AbstractDOMParser>, boost::shared_ptr<xercesc::XercesDOMParser> >("XercesDOMParser", boost::python::init<boost::python::optional<xercesc::XMLValidator* const, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const> >())
			.def(XercesDOMParserDefVisitor())
			.def("getErrorHandler", static_cast<xercesc::ErrorHandler*(xercesc::XercesDOMParser::*)(void)>(&xercesc::XercesDOMParser::getErrorHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEntityResolver", static_cast<xercesc::EntityResolver*(xercesc::XercesDOMParser::*)(void)>(&xercesc::XercesDOMParser::getEntityResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXMLEntityResolver", static_cast<xercesc::XMLEntityResolver*(xercesc::XercesDOMParser::*)(void)>(&xercesc::XercesDOMParser::getXMLEntityResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("isCachingGrammarFromParse", &xercesc::XercesDOMParser::isCachingGrammarFromParse)
			.def("isUsingCachedGrammarInParse", &xercesc::XercesDOMParser::isUsingCachedGrammarInParse)
			.def("getGrammar", &xercesc::XercesDOMParser::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRootGrammar", &xercesc::XercesDOMParser::getRootGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIText", &xercesc::XercesDOMParser::getURIText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcOffset", &xercesc::XercesDOMParser::getSrcOffset)
			.def("getIgnoreCachedDTD", &xercesc::XercesDOMParser::getIgnoreCachedDTD)
			.def("setErrorHandler", &xercesc::XercesDOMParser::setErrorHandler)
			.def("setEntityResolver", &xercesc::XercesDOMParser::setEntityResolver)
			.def("setXMLEntityResolver", &xercesc::XercesDOMParser::setXMLEntityResolver)
			.def("cachingGrammarFromParse", &xercesc::XercesDOMParser::cacheGrammarFromParse)
			.def("usingCachedGrammarInParse", &xercesc::XercesDOMParser::useCachedGrammarInParse)
			.def("setIgnoreCachedDTD", &xercesc::XercesDOMParser::setIgnoreCachedDTD)
			.def("resetDocumentPool", &xercesc::XercesDOMParser::resetDocumentPool)
			.def("error", &xercesc::XercesDOMParser::error)
			.def("resetErrors", &xercesc::XercesDOMParser::resetErrors)
			.def("endInputSource", &xercesc::XercesDOMParser::endInputSource)
			.def("expandSystemId", &xercesc::XercesDOMParser::expandSystemId)
			.def("resetEntities", &xercesc::XercesDOMParser::resetEntities)
			.def("resolveEntity", &xercesc::XercesDOMParser::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", &xercesc::XercesDOMParser::startInputSource)
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::XercesDOMParser::*)(const xercesc::InputSource&, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::XercesDOMParser::loadGrammar), pyxerces::XercesDOMParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::XercesDOMParser::*)(const XMLCh*, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::XercesDOMParser::loadGrammar), pyxerces::XercesDOMParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::XercesDOMParser::*)(const char*, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::XercesDOMParser::loadGrammar), pyxerces::XercesDOMParserLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("resetCachedGrammarPool", &xercesc::XercesDOMParser::resetCachedGrammarPool)
			;
}

} /* namespace pyxerces */
