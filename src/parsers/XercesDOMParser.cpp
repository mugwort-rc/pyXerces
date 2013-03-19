/*
 * XercesDOMParser.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "XercesDOMParser.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>
#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/sax/EntityResolver.hpp>
#include <xercesc/util/XMLEntityResolver.hpp>
#include <xercesc/validators/common/Grammar.hpp>

#include <xercesc/parsers/XercesDOMParser.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class XercesDOMParserDefVisitor
: public boost::python::def_visitor<XercesDOMParserDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getGrammar", &XercesDOMParserDefVisitor::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("error", &XercesDOMParserDefVisitor::error)
	.def("expandSystemId", &XercesDOMParserDefVisitor::expandSystemId)
	;
}

static xercesc::Grammar* getGrammar(xercesc::XercesDOMParser& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.getGrammar(buff.ptr());
}

static void error(xercesc::XercesDOMParser& self, const unsigned int errCode, const STR& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const STR& errorText, const STR& systemId, const STR& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	self.error(errCode, buff1.ptr(), type, buff2.ptr(), buff3.ptr(), buff4.ptr(), lineNum, colNum);
}

static bool expandSystemId(xercesc::XercesDOMParser& self, const STR& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return self.expandSystemId(buff.ptr(), toFill);
}

};

class XercesDOMParserWrapper
: public xercesc::XercesDOMParser, public boost::python::wrapper<xercesc::XercesDOMParser>
{
public:
// ---------- XMLErrorReporter ----------
void error(const unsigned int errCode, const XMLCh* const errDomain, const xercesc::XMLErrorReporter::ErrTypes  type, const XMLCh* const errorText, const XMLCh* const systemId, const XMLCh* const publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	if(boost::python::override error = this->get_override("error")){
		error(errCode, XMLString(errDomain), type, XMLString(errorText), XMLString(systemId), XMLString(publicId), lineNum, colNum);
	}else{
		xercesc::XercesDOMParser::error(errCode, errDomain, type, errorText, systemId, publicId, lineNum, colNum);
	}
}

void resetErrors() {
	if(boost::python::override resetErrors = this->get_override("resetErrors")){
		resetErrors();
	}else{
		xercesc::XercesDOMParser::resetErrors();
	}
}

// ---------- XMLEntityHandler ----------
void endInputSource(const xercesc::InputSource& inputSource) {
	if(boost::python::override endInputSource = this->get_override("endInputSource")){
		endInputSource(boost::ref(inputSource));
	}else{
		xercesc::XercesDOMParser::endInputSource(inputSource);
	}
}

bool expandSystemId(const XMLCh* const systemId, xercesc::XMLBuffer& toFill) {
	if(boost::python::override expandSystemId = this->get_override("expandSystemId")){
		return expandSystemId(XMLString(systemId), boost::ref(toFill));
	}else{
		return xercesc::XercesDOMParser::expandSystemId(systemId, toFill);
	}
}

void resetEntities() {
	if(boost::python::override resetEntities = this->get_override("resetEntities")){
		resetEntities();
	}else{
		xercesc::XercesDOMParser::resetEntities();
	}
}

xercesc::InputSource* resolveEntity(xercesc::XMLResourceIdentifier* resourceIdentifier) {
	if(boost::python::override resolveEntity = this->get_override("resolveEntity")){
		return resolveEntity(boost::python::ptr(resourceIdentifier));
	}else{
		return xercesc::XercesDOMParser::resolveEntity(resourceIdentifier);
	}
}

void startInputSource(const xercesc::InputSource& inputSource) {
	if(boost::python::override startInputSource = this->get_override("startInputSource")){
		startInputSource(inputSource);
	}else{
		xercesc::XercesDOMParser::startInputSource(inputSource);
	}
}

};

//! XercesDOMParser
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XercesDOMParserLoadGrammarOverloads, loadGrammar, 2, 3)

void XercesDOMParser_init(void) {
	//! xercesc::XercesDOMParser
	boost::python::class_<XercesDOMParserWrapper, boost::noncopyable, boost::python::bases<xercesc::AbstractDOMParser>, boost::shared_ptr<xercesc::XercesDOMParser> >("XercesDOMParser", boost::python::init<boost::python::optional<xercesc::XMLValidator* const, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const> >())
			.def(XercesDOMParserDefVisitor<XMLString>())
			.def(XercesDOMParserDefVisitor<std::string>())
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
