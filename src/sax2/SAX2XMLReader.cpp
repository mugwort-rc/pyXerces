/*
 * SAX2XMLReader.cpp
 *
 *  Created on: 2013/03/13
 *      Author: mugwort_rc
 */

#include "SAX2XMLReader.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax2/ContentHandler.hpp>
#include <xercesc/sax/DTDHandler.hpp>
#include <xercesc/sax/EntityResolver.hpp>
#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/sax2/LexicalHandler.hpp>
#include <xercesc/sax2/DeclHandler.hpp>
#include <xercesc/framework/XMLDocumentHandler.hpp>

#include <xercesc/sax2/SAX2XMLReader.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class SAX2XMLReaderDefVisitor
: public boost::python::def_visitor<SAX2XMLReaderDefVisitor<STR> >
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getFeature", &SAX2XMLReaderDefVisitor<STR>::getFeature)
	.def("getProperty", &SAX2XMLReaderDefVisitor<STR>::getProperty, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setFeature", &SAX2XMLReaderDefVisitor<STR>::setFeature)
	.def("setProperty", &SAX2XMLReaderDefVisitor<STR>::setProperty)
	.def("parse", &SAX2XMLReaderDefVisitor<STR>::parse)
	.def("getGrammar", &SAX2XMLReaderDefVisitor<STR>::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static bool getFeature(xercesc::SAX2XMLReader& self, const STR& name) {
	XMLString buff(name);
	return self.getFeature(buff.ptr());
}

static void* getProperty(xercesc::SAX2XMLReader& self, const STR& name) {
	XMLString buff(name);
	return self.getProperty(buff.ptr());
}

static void setFeature(xercesc::SAX2XMLReader& self, const STR& name, const bool value) {
	XMLString buff(name);
	self.setFeature(buff.ptr(), value);
}

static void setProperty(xercesc::SAX2XMLReader& self, const STR& name, void* value) {
	XMLString buff(name);
	self.setProperty(buff.ptr(), value);
}

static void parse(xercesc::SAX2XMLReader& self, const STR& systemId) {
	XMLString buff(systemId);
	self.parse(buff.ptr());
}

static xercesc::Grammar* getGrammar(xercesc::SAX2XMLReader& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.getGrammar(buff.ptr());
}

};

class SAX2XMLReaderWrapper
: public xercesc::SAX2XMLReader, public boost::python::wrapper<xercesc::SAX2XMLReader>
{
public:
xercesc::ContentHandler* getContentHandler() const {
	return this->get_override("getContentHandler")();
}

xercesc::DTDHandler* getDTDHandler() const {
	return this->get_override("getDTDHandler")();
}

xercesc::EntityResolver* getEntityResolver() const {
	return this->get_override("getEntityResolver")();
}

xercesc::ErrorHandler* getErrorHandler() const {
	return this->get_override("getErrorHandler")();
}

bool getFeature(const XMLCh* const name) const {
	return this->get_override("getFeature")(XMLString(name));
}

void* getProperty(const XMLCh* const name) const {
	return this->get_override("getProperty")(XMLString(name));
}

void setContentHandler(xercesc::ContentHandler* const handler) {
	this->get_override("setContentHandler")(handler);
}

void setDTDHandler(xercesc::DTDHandler* const handler) {
	this->get_override("setDTDHandler")(handler);
}

void setEntityResolver(xercesc::EntityResolver* const resolver) {
	this->get_override("setEntityResolver")(resolver);
}

void setErrorHandler(xercesc::ErrorHandler* const handler) {
	this->get_override("setErrorHandler")(handler);
}

void setFeature(const XMLCh* const name, const bool value) {
	this->get_override("setFeature")(XMLString(name), value);
}

void setProperty(const XMLCh* const name, void* value) {
	this->get_override("setProperty")(XMLString(name), value);
}

void parse(const xercesc::InputSource& source) {
	this->get_override("parse")(source);
}

void parse(const XMLCh* const systemId) {
	this->get_override("parse")(XMLString(systemId));
}

void parse(const char* const systemId) {
	this->get_override("parse")(systemId);
}

xercesc::DeclHandler* getDeclarationHandler() const {
	return this->get_override("getDeclarationHandler")();
}

xercesc::LexicalHandler* getLexicalHandler() const {
	return this->get_override("getLexicalHandler")();
}

void setDeclarationHandler(xercesc::DeclHandler* const handler) {
	this->get_override("setDeclarationHandler")(handler);
}

void setLexicalHandler(xercesc::LexicalHandler* const handler) {
	this->get_override("setLexicalHandler")(handler);
}

xercesc::XMLValidator* getValidator() const {
	return this->get_override("getValidator")();
}

XMLSize_t getErrorCount() const {
	return this->get_override("getErrorCount")();
}

bool getExitOnFirstFatalError() const {
	return this->get_override("getExitOnFirstFatalError")();
}

bool getValidationConstraintFatal() const {
	return this->get_override("getValidationConstraintFatal")();
}

xercesc::Grammar* getGrammar(const XMLCh* const nameSpaceKey) {
	return this->get_override("getGrammar")(XMLString(nameSpaceKey));
}

xercesc::Grammar* getRootGrammar() {
	return this->get_override("getRootGrammar")();
}

const XMLCh* getURIText(unsigned int uriId) const {
	return this->get_override("getURIText")(uriId);
}

XMLFilePos getSrcOffset() const {
	return this->get_override("getSrcOffset")();
}

void setValidator(xercesc::XMLValidator* valueToAdopt) {
	this->get_override("setValidator")(valueToAdopt);
}

void setExitOnFirstFatalError(const bool newState) {
	this->get_override("setExitOnFirstFatalError")(newState);
}

void setValidationConstraintFatal(const bool newState) {
	this->get_override("setValidationConstraintFatal")(newState);
}

bool parseFirst(const XMLCh* const systemId, xercesc::XMLPScanToken& toFill) {
	return this->get_override("parseFirst")(XMLString(systemId), boost::ref(toFill));
}

bool parseFirst(const char* const systemId, xercesc::XMLPScanToken& toFill) {
	return this->get_override("parseFirst")(systemId, boost::ref(toFill));
}

bool parseFirst(const xercesc::InputSource& source, xercesc::XMLPScanToken& toFill) {
	return this->get_override("parseFirst")(source, boost::ref(toFill));
}

bool parseNext(xercesc::XMLPScanToken& token) {
	return this->get_override("parseNext")(boost::ref(token));
}

void parseReset(xercesc::XMLPScanToken& token) {
	this->get_override("parseReset")(boost::ref(token));
}

xercesc::Grammar* loadGrammar(const xercesc::InputSource& source, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(source, grammarType, toCache);
}

xercesc::Grammar* loadGrammar(const XMLCh* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(XMLString(systemId), grammarType, toCache);
}

xercesc::Grammar* loadGrammar(const char* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	return this->get_override("loadGrammar")(systemId, grammarType, toCache);
}

void resetCachedGrammarPool() {
	this->get_override("resetCachedGrammarPool")();
}

void setInputBufferSize(const XMLSize_t bufferSize) {
	if(boost::python::override setInputBufferSize = this->get_override("setInputBufferSize")) {
		setInputBufferSize(bufferSize);
	}else{
		xercesc::SAX2XMLReader::setInputBufferSize(bufferSize);
	}
}

void installAdvDocHandler(xercesc::XMLDocumentHandler* const toInstall) {
	this->get_override("installAdvDocHandler")(toInstall);
}

bool removeAdvDocHandler(xercesc::XMLDocumentHandler* const toRemove) {
	return this->get_override("removeAdvDocHandler")(toRemove);
}

};

//! SAX2XMLReader
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SAX2XMLReaderLoadGrammarOverloads, loadGrammar, 2, 3)

void SAX2XMLReader_init(void) {
	//! xercesc::SAX2XMLReader
	auto SAX2XMLReader = boost::python::class_<SAX2XMLReaderWrapper, boost::noncopyable>("SAX2XMLReader")
			.def(SAX2XMLReaderDefVisitor<XMLString>())
			.def(SAX2XMLReaderDefVisitor<std::string>())
			.def("getContentHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getContentHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDTDHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getDTDHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEntityResolver", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getEntityResolver), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrorHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getErrorHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFeature", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getFeature))
			.def("getProperty", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getProperty), boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("setContentHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setContentHandler))
			.def("setDTDHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setDTDHandler))
			.def("setEntityResolver", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setEntityResolver))
			.def("setErrorHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setErrorHandler))
			.def("setFeature", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setFeature))
			.def("setProperty", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setProperty))
			.def("parse", boost::python::pure_virtual(static_cast<void(xercesc::SAX2XMLReader::*)(const xercesc::InputSource&)>(&xercesc::SAX2XMLReader::parse)))
			.def("parse", boost::python::pure_virtual(static_cast<void(xercesc::SAX2XMLReader::*)(const XMLCh* const)>(&xercesc::SAX2XMLReader::parse)))
			.def("parse", boost::python::pure_virtual(static_cast<void(xercesc::SAX2XMLReader::*)(const char* const)>(&xercesc::SAX2XMLReader::parse)))
			.def("getDeclarationHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getDeclarationHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLexicalHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getLexicalHandler), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDeclarationHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setDeclarationHandler))
			.def("setLexicalHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setLexicalHandler))
			.def("getValidator", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getValidator), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrorCount", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getErrorCount))
			.def("getExitOnFirstFatalError", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getExitOnFirstFatalError))
			.def("getValidationConstraintFatal", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getValidationConstraintFatal))
			.def("getGrammar", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRootGrammar", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getRootGrammar), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIText", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getURIText), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcOffset", boost::python::pure_virtual(&xercesc::SAX2XMLReader::getSrcOffset))
			.def("setValidator", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setValidator))
			.def("setExitOnFirstFatalError", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setExitOnFirstFatalError))
			.def("setValidationConstraintFatal", boost::python::pure_virtual(&xercesc::SAX2XMLReader::setValidationConstraintFatal))
			.def("parseFirst", boost::python::pure_virtual(static_cast<bool(xercesc::SAX2XMLReader::*)(const XMLCh* const, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReader::parseFirst)))
			.def("parseFirst", boost::python::pure_virtual(static_cast<bool(xercesc::SAX2XMLReader::*)(const char* const, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReader::parseFirst)))
			.def("parseFirst", boost::python::pure_virtual(static_cast<bool(xercesc::SAX2XMLReader::*)(const xercesc::InputSource&, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReader::parseFirst)))
			.def("parseNext", boost::python::pure_virtual(&xercesc::SAX2XMLReader::parseNext))
			.def("parseReset", boost::python::pure_virtual(&xercesc::SAX2XMLReader::parseReset))
			// TODO: overloads
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::SAX2XMLReader::*)(const xercesc::InputSource&, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReader::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::SAX2XMLReader::*)(const XMLCh* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReader::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("loadGrammar", boost::python::pure_virtual(static_cast<xercesc::Grammar*(xercesc::SAX2XMLReader::*)(const char* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReader::loadGrammar)), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("resetCachedGrammarPool", boost::python::pure_virtual(&xercesc::SAX2XMLReader::resetCachedGrammarPool))
			.def("setInputBufferSize", &xercesc::SAX2XMLReader::setInputBufferSize)
			.def("installAdvDocHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::installAdvDocHandler))
			.def("removeAdvDocHandler", boost::python::pure_virtual(&xercesc::SAX2XMLReader::removeAdvDocHandler))
			;
	boost::python::scope SAX2XMLReaderScope = SAX2XMLReader;
	//! xercesc::SAX2XMLReader::ValSchemes
	boost::python::enum_<xercesc::SAX2XMLReader::ValSchemes>("ValSchemes")
			.value("Val_Never", xercesc::SAX2XMLReader::Val_Never)
			.value("Val_Always", xercesc::SAX2XMLReader::Val_Always)
			.value("Val_Auto", xercesc::SAX2XMLReader::Val_Auto)
			.export_values()
			;
}

} /* namespace pyxerces */
