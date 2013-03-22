/*
 * SAX2XMLReaderImpl.cpp
 *
 *  Created on: 2013/03/13
 *      Author: mugwort_rc
 */

#include "SAX2XMLReaderImpl.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/sax2/ContentHandler.hpp>
#include <xercesc/sax2/LexicalHandler.hpp>
#include <xercesc/sax2/DeclHandler.hpp>
#include <xercesc/validators/common/GrammarResolver.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>
#include <xercesc/util/XMLResourceIdentifier.hpp>
#include <xercesc/framework/psvi/PSVIHandler.hpp>
#include <xercesc/sax/DTDHandler.hpp>
#include <xercesc/sax/EntityResolver.hpp>
#include <xercesc/sax/ErrorHandler.hpp>
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLDocumentHandler.hpp>
#include <xercesc/framework/XMLElementDecl.hpp>
#include <xercesc/framework/XMLEntityDecl.hpp>
#include <xercesc/sax/InputSource.hpp>
#include <xercesc/framework/XMLBuffer.hpp>
#include <xercesc/util/XMLEntityResolver.hpp>

#include <xercesc/parsers/SAX2XMLReaderImpl.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class SAX2XMLReaderImplDefVisitor
: public boost::python::def_visitor<SAX2XMLReaderImplDefVisitor<STR> >
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("getFeature", &SAX2XMLReaderImplDefVisitor<STR>::getFeature)
	.def("getProperty", &SAX2XMLReaderImplDefVisitor<STR>::getProperty, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
	.def("setFeature", &SAX2XMLReaderImplDefVisitor<STR>::setFeature)
	.def("setProperty", &SAX2XMLReaderImplDefVisitor<STR>::setProperty)
	.def("parse", &SAX2XMLReaderImplDefVisitor<STR>::parse)
	.def("getGrammar", &SAX2XMLReaderImplDefVisitor<STR>::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("docCharacters", &SAX2XMLReaderImplDefVisitor::docCharacters)
	.def("docComment", &SAX2XMLReaderImplDefVisitor::docComment)
	.def("docPI", &SAX2XMLReaderImplDefVisitor::docPI)
	.def("endElement", &SAX2XMLReaderImplDefVisitor::endElement)
	.def("ignorableWhitespace", &SAX2XMLReaderImplDefVisitor::ignorableWhitespace)
	.def("startElement", &SAX2XMLReaderImplDefVisitor::startElement)
	.def("XMLDecl", &SAX2XMLReaderImplDefVisitor::XMLDecl)
	.def("error", &SAX2XMLReaderImplDefVisitor::error)
	.def("expandSystemId", &SAX2XMLReaderImplDefVisitor::expandSystemId)
	.def("doctypeComment", &SAX2XMLReaderImplDefVisitor::doctypeComment)
	.def("doctypeDecl", &SAX2XMLReaderImplDefVisitor::doctypeDecl)
	.def("doctypePI", &SAX2XMLReaderImplDefVisitor::doctypePI)
	.def("doctypeWhitespace", &SAX2XMLReaderImplDefVisitor::doctypeWhitespace)
	.def("TextDecl", &SAX2XMLReaderImplDefVisitor::TextDecl)
	;
}

static bool getFeature(xercesc::SAX2XMLReaderImpl& self, const STR& name) {
	XMLString buff(name);
	return self.getFeature(buff.ptr());
}

static void* getProperty(xercesc::SAX2XMLReaderImpl& self, const STR& name) {
	XMLString buff(name);
	return self.getProperty(buff.ptr());
}

static void setFeature(xercesc::SAX2XMLReaderImpl& self, const STR& name, const bool value) {
	XMLString buff(name);
	self.setFeature(buff.ptr(), value);
}

static void setProperty(xercesc::SAX2XMLReaderImpl& self, const STR& name, void* value) {
	XMLString buff(name);
	self.setProperty(buff.ptr(), value);
}

static void parse(xercesc::SAX2XMLReaderImpl& self, const STR& systemId) {
	XMLString buff(systemId);
	self.parse(buff.ptr());
}

static xercesc::Grammar* getGrammar(xercesc::SAX2XMLReaderImpl& self, const STR& nameSpaceKey) {
	XMLString buff(nameSpaceKey);
	return self.getGrammar(buff.ptr());
}

static void docCharacters(xercesc::SAX2XMLReaderImpl& self, const STR& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.docCharacters(buff.ptr(), buff.size(), cdataSection);
}

static void docComment(xercesc::SAX2XMLReaderImpl& self, const STR& comment) {
	XMLString buff(comment);
	self.docComment(buff.ptr());
}

static void docPI(xercesc::SAX2XMLReaderImpl& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.docPI(buff1.ptr(), buff2.ptr());
}

static void endElement(xercesc::SAX2XMLReaderImpl& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const STR& prefixName) {
	XMLString buff(prefixName);
	self.endElement(elemDecl, uriId, isRoot, buff.ptr());
}

static void ignorableWhitespace(xercesc::SAX2XMLReaderImpl& self, const XMLString& chars, const bool cdataSection) {
	XMLString buff(chars);
	self.ignorableWhitespace(buff.ptr(), buff.size(), cdataSection);
}

static void startElement(xercesc::SAX2XMLReaderImpl& self, const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const STR& prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	XMLString buff(prefixName);
	self.startElement(elemDecl, uriId, buff.ptr(), attrList, attrCount, isEmpty, isRoot);
}

static void XMLDecl(xercesc::SAX2XMLReaderImpl& self, const STR& versionStr, const STR& encodingStr, const STR& standaloneStr, const STR& autoEncodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr), buff3(standaloneStr), buff4(autoEncodingStr);
	self.XMLDecl(buff1.ptr(), buff2.ptr(), buff3.ptr(), buff4.ptr());
}

static void error(xercesc::SAX2XMLReaderImpl& self, const unsigned int errCode, const STR& errDomain, const xercesc::XMLErrorReporter::ErrTypes type, const STR& errorText, const STR& systemId, const STR& publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	XMLString buff1(errDomain), buff2(errorText), buff3(systemId), buff4(publicId);
	self.error(errCode, buff1.ptr(), type, buff2.ptr(), buff3.ptr(), buff4.ptr(), lineNum, colNum);
}

static bool expandSystemId(xercesc::SAX2XMLReaderImpl& self, const STR& systemId, xercesc::XMLBuffer& toFill) {
	XMLString buff(systemId);
	return self.expandSystemId(buff.ptr(), toFill);
}

static void doctypeComment(xercesc::SAX2XMLReaderImpl& self, const STR& comment) {
	XMLString buff(comment);
	self.doctypeComment(buff.ptr());
}

static void doctypeDecl(xercesc::SAX2XMLReaderImpl& self, const xercesc::DTDElementDecl& elemDecl, const STR& publicId, const STR& systemId, const bool hasIntSubset, const bool hasExtSubset) {
	XMLString buff1(publicId), buff2(systemId);
	self.doctypeDecl(elemDecl, buff1.ptr(), buff2.ptr(), hasIntSubset, hasExtSubset);
}

static void doctypePI(xercesc::SAX2XMLReaderImpl& self, const STR& target, const STR& data) {
	XMLString buff1(target), buff2(data);
	self.doctypePI(buff1.ptr(), buff2.ptr());
}

static void doctypeWhitespace(xercesc::SAX2XMLReaderImpl& self, const STR& chars) {
	XMLString buff(chars);
	self.doctypeWhitespace(buff.ptr(), buff.size());
}

static void TextDecl(xercesc::SAX2XMLReaderImpl& self, const XMLString& versionStr, const XMLString& encodingStr) {
	XMLString buff1(versionStr), buff2(encodingStr);
	self.TextDecl(buff1.ptr(), buff2.ptr());
}

};

class SAX2XMLReaderImplWrapper
: public xercesc::SAX2XMLReaderImpl, public boost::python::wrapper<xercesc::SAX2XMLReaderImpl>
{
public:
SAX2XMLReaderImplWrapper(xercesc::MemoryManager* const  manager = xercesc::XMLPlatformUtils::fgMemoryManager, xercesc::XMLGrammarPool* const gramPool = 0)
: xercesc::SAX2XMLReaderImpl(manager, gramPool)
{}

xercesc::ContentHandler* getContentHandler() const {
	if(boost::python::override getContentHandler = this->get_override("getContentHandler")){
		return getContentHandler();
	}else{
		return xercesc::SAX2XMLReaderImpl::getContentHandler();
	}
}

xercesc::DTDHandler* getDTDHandler() const {
	if(boost::python::override getDTDHandler = this->get_override("getDTDHandler")){
		return getDTDHandler();
	}else{
		return xercesc::SAX2XMLReaderImpl::getDTDHandler();
	}
}

xercesc::EntityResolver* getEntityResolver() const {
	if(boost::python::override getEntityResolver = this->get_override("getEntityResolver")){
		return getEntityResolver();
	}else{
		return xercesc::SAX2XMLReaderImpl::getEntityResolver();
	}
}

xercesc::ErrorHandler* getErrorHandler() const {
	if(boost::python::override getErrorHandler = this->get_override("getErrorHandler")){
		return getErrorHandler();
	}else{
		return xercesc::SAX2XMLReaderImpl::getErrorHandler();
	}
}

bool getFeature(const XMLCh* const name) const {
	if(boost::python::override getFeature = this->get_override("getFeature")){
		return getFeature(XMLString(name));
	}else{
		return xercesc::SAX2XMLReaderImpl::getFeature(name);
	}
}

void* getProperty(const XMLCh* const name) const {
	if(boost::python::override getProperty = this->get_override("getProperty")){
		return getProperty(XMLString(name));
	}else{
		return xercesc::SAX2XMLReaderImpl::getProperty(name);
	}
}

void setContentHandler(xercesc::ContentHandler* const handler) {
	if(boost::python::override setContentHandler = this->get_override("setContentHandler")){
		setContentHandler(boost::python::ptr(handler));
	}else{
		xercesc::SAX2XMLReaderImpl::setContentHandler(handler);
	}
}

void setDTDHandler(xercesc::DTDHandler* const handler) {
	if(boost::python::override setDTDHandler = this->get_override("setDTDHandler")){
		setDTDHandler(boost::python::ptr(handler));
	}else{
		xercesc::SAX2XMLReaderImpl::setDTDHandler(handler);
	}
}

void setEntityResolver(xercesc::EntityResolver* const resolver) {
	if(boost::python::override setEntityResolver = this->get_override("setEntityResolver")){
		setEntityResolver(boost::python::ptr(resolver));
	}else{
		xercesc::SAX2XMLReaderImpl::setEntityResolver(resolver);
	}
}

void setErrorHandler(xercesc::ErrorHandler* const handler) {
	if(boost::python::override setErrorHandler = this->get_override("setErrorHandler")){
		setErrorHandler(boost::python::ptr(handler));
	}else{
		xercesc::SAX2XMLReaderImpl::setErrorHandler(handler);
	}
}

void setFeature(const XMLCh* const name, const bool value) {
	if(boost::python::override setFeature = this->get_override("setFeature")){
		setFeature(XMLString(name), value);
	}else{
		xercesc::SAX2XMLReaderImpl::setFeature(name, value);
	}
}

void setProperty(const XMLCh* const name, void* value) {
	if(boost::python::override setProperty = this->get_override("setProperty")){
		setProperty(XMLString(name), value);
	}else{
		xercesc::SAX2XMLReaderImpl::setProperty(name, value);
	}
}

void parse(const xercesc::InputSource& source) {
	if(boost::python::override parse = this->get_override("parse")){
		parse(boost::ref(source));
	}else{
		xercesc::SAX2XMLReaderImpl::parse(source);
	}
}

void parse(const XMLCh* const systemId) {
	if(boost::python::override parse = this->get_override("parse")){
		parse(XMLString(systemId));
	}else{
		xercesc::SAX2XMLReaderImpl::parse(systemId);
	}
}

void parse(const char* const systemId) {
	if(boost::python::override parse = this->get_override("parse")){
		parse(systemId);
	}else{
		xercesc::SAX2XMLReaderImpl::parse(systemId);
	}
}

xercesc::DeclHandler* getDeclarationHandler() const {
	if(boost::python::override getDeclarationHandler = this->get_override("getDeclarationHandler")){
		return getDeclarationHandler();
	}else{
		return xercesc::SAX2XMLReaderImpl::getDeclarationHandler();
	}
}

xercesc::LexicalHandler* getLexicalHandler() const {
	if(boost::python::override getLexicalHandler = this->get_override("getLexicalHandler")){
		return getLexicalHandler();
	}else{
		return xercesc::SAX2XMLReaderImpl::getLexicalHandler();
	}
}

void setDeclarationHandler(xercesc::DeclHandler* const handler) {
	if(boost::python::override setDeclarationHandler = this->get_override("setDeclarationHandler")){
		setDeclarationHandler(boost::python::ptr(handler));
	}else{
		xercesc::SAX2XMLReaderImpl::setDeclarationHandler(handler);
	}
}

void setLexicalHandler(xercesc::LexicalHandler* const handler) {
	if(boost::python::override setLexicalHandler = this->get_override("setLexicalHandler")){
		setLexicalHandler(boost::python::ptr(handler));
	}else{
		xercesc::SAX2XMLReaderImpl::setLexicalHandler(handler);
	}
}

xercesc::XMLValidator* getValidator() const {
	if(boost::python::override getValidator = this->get_override("getValidator")){
		return getValidator();
	}else{
		return xercesc::SAX2XMLReaderImpl::getValidator();
	}
}

XMLSize_t getErrorCount() const {
	if(boost::python::override getErrorCount = this->get_override("getErrorCount")){
		return getErrorCount();
	}else{
		return xercesc::SAX2XMLReaderImpl::getErrorCount();
	}
}

bool getExitOnFirstFatalError() const {
	if(boost::python::override getExitOnFirstFatalError = this->get_override("getExitOnFirstFatalError")){
		return getExitOnFirstFatalError();
	}else{
		return xercesc::SAX2XMLReaderImpl::getExitOnFirstFatalError();
	}
}

bool getValidationConstraintFatal() const {
	if(boost::python::override getValidationConstraintFatal = this->get_override("getValidationConstraintFatal")){
		return getValidationConstraintFatal();
	}else{
		return xercesc::SAX2XMLReaderImpl::getValidationConstraintFatal();
	}
}

xercesc::Grammar* getGrammar(const XMLCh* const nameSpaceKey) {
	if(boost::python::override getGrammar = this->get_override("getGrammar")){
		return getGrammar(XMLString(nameSpaceKey));
	}else{
		return xercesc::SAX2XMLReaderImpl::getGrammar(nameSpaceKey);
	}
}

xercesc::Grammar* getRootGrammar() {
	if(boost::python::override getRootGrammar = this->get_override("getRootGrammar")){
		return getRootGrammar();
	}else{
		return xercesc::SAX2XMLReaderImpl::getRootGrammar();
	}
}

const XMLCh* getURIText(unsigned int uriId) const {
	if(boost::python::override getURIText = this->get_override("getURIText")){
		return getURIText(uriId);
	}else{
		return xercesc::SAX2XMLReaderImpl::getURIText(uriId);
	}
}

XMLFilePos getSrcOffset() const {
	if(boost::python::override getSrcOffset = this->get_override("getSrcOffset")){
		return getSrcOffset();
	}else{
		return xercesc::SAX2XMLReaderImpl::getSrcOffset();
	}
}

void setValidator(xercesc::XMLValidator* valueToAdopt) {
	if(boost::python::override setValidator = this->get_override("setValidator")){
		setValidator(boost::python::ptr(valueToAdopt));
	}else{
		xercesc::SAX2XMLReaderImpl::setValidator(valueToAdopt);
	}
}

void setExitOnFirstFatalError(const bool newState) {
	if(boost::python::override setExitOnFirstFatalError = this->get_override("setExitOnFirstFatalError")){
		setExitOnFirstFatalError(newState);
	}else{
		xercesc::SAX2XMLReaderImpl::setExitOnFirstFatalError(newState);
	}
}

void setValidationConstraintFatal(const bool newState) {
	if(boost::python::override setValidationConstraintFatal = this->get_override("setValidationConstraintFatal")){
		setValidationConstraintFatal(newState);
	}else{
		xercesc::SAX2XMLReaderImpl::setValidationConstraintFatal(newState);
	}
}

bool parseFirst(const XMLCh* const systemId, xercesc::XMLPScanToken& toFill) {
	if(boost::python::override parseFirst = this->get_override("parseFirst")){
		return parseFirst(XMLString(systemId), boost::ref(toFill));
	}else{
		return xercesc::SAX2XMLReaderImpl::parseFirst(systemId, toFill);
	}
}

bool parseFirst(const char* const systemId, xercesc::XMLPScanToken& toFill) {
	if(boost::python::override parseFirst = this->get_override("parseFirst")){
		return parseFirst(systemId, boost::ref(toFill));
	}else{
		return xercesc::SAX2XMLReaderImpl::parseFirst(systemId, toFill);
	}
}

bool parseFirst(const xercesc::InputSource& source, xercesc::XMLPScanToken& toFill) {
	if(boost::python::override parseFirst = this->get_override("parseFirst")){
		return parseFirst(boost::ref(source), boost::ref(toFill));
	}else{
		return xercesc::SAX2XMLReaderImpl::parseFirst(source, toFill);
	}
}

bool parseNext(xercesc::XMLPScanToken& token) {
	if(boost::python::override parseNext = this->get_override("parseNext")){
		return parseNext(boost::ref(token));
	}else{
		return xercesc::SAX2XMLReaderImpl::parseNext(token);
	}
}

void parseReset(xercesc::XMLPScanToken& token) {
	if(boost::python::override parseReset = this->get_override("parseReset")){
		parseReset(boost::ref(token));
	}else{
		xercesc::SAX2XMLReaderImpl::parseReset(token);
	}
}

xercesc::Grammar* loadGrammar(const xercesc::InputSource& source, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	if(boost::python::override loadGrammar = this->get_override("loadGrammar")){
		return loadGrammar(boost::ref(source), grammarType, toCache);
	}else{
		return xercesc::SAX2XMLReaderImpl::loadGrammar(source, grammarType, toCache);
	}
}

xercesc::Grammar* loadGrammar(const XMLCh* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	if(boost::python::override loadGrammar = this->get_override("loadGrammar")){
		return loadGrammar(XMLString(systemId), grammarType, toCache);
	}else{
		return xercesc::SAX2XMLReaderImpl::loadGrammar(systemId, grammarType, toCache);
	}
}

xercesc::Grammar* loadGrammar(const char* const systemId, const xercesc::Grammar::GrammarType grammarType, const bool toCache = false) {
	if(boost::python::override loadGrammar = this->get_override("loadGrammar")){
		return loadGrammar(systemId, grammarType, toCache);
	}else{
		return xercesc::SAX2XMLReaderImpl::loadGrammar(systemId, grammarType, toCache);
	}
}

void resetCachedGrammarPool() {
	if(boost::python::override resetCachedGrammarPool = this->get_override("resetCachedGrammarPool")){
		resetCachedGrammarPool();
	}else{
		xercesc::SAX2XMLReaderImpl::resetCachedGrammarPool();
	}
}

void setInputBufferSize(const XMLSize_t bufferSize) {
	if(boost::python::override setInputBufferSize = this->get_override("setInputBufferSize")) {
		setInputBufferSize(bufferSize);
	}else{
		xercesc::SAX2XMLReader::setInputBufferSize(bufferSize);
	}
}

void installAdvDocHandler(xercesc::XMLDocumentHandler* const toInstall) {
	if(boost::python::override installAdvDocHandler = this->get_override("installAdvDocHandler")){
		installAdvDocHandler(boost::python::ptr(toInstall));
	}else{
		xercesc::SAX2XMLReaderImpl::installAdvDocHandler(toInstall);
	}
}

bool removeAdvDocHandler(xercesc::XMLDocumentHandler* const toRemove) {
	if(boost::python::override removeAdvDocHandler = this->get_override("removeAdvDocHandler")){
		return removeAdvDocHandler(boost::python::ptr(toRemove));
	}else{
		return xercesc::SAX2XMLReaderImpl::removeAdvDocHandler(toRemove);
	}
}

void docCharacters(const XMLCh* const chars, const XMLSize_t length, const bool cdataSection) {
	if(boost::python::override docCharacters = this->get_override("docCharacters")){
		docCharacters(XMLString(chars), length, cdataSection);
	}else{
		xercesc::SAX2XMLReaderImpl::docCharacters(chars, length, cdataSection);
	}
}

void docComment(const XMLCh* const comment) {
	if(boost::python::override docComment = this->get_override("docComment")){
		docComment(XMLString(comment));
	}else{
		xercesc::SAX2XMLReaderImpl::docComment(comment);
	}
}

void docPI(const XMLCh* const target, const XMLCh* const data) {
	if(boost::python::override docPI = this->get_override("docPI")){
		docPI(XMLString(target), XMLString(data));
	}else{
		xercesc::SAX2XMLReaderImpl::docPI(target, data);
	}
}

void endDocument() {
	if(boost::python::override endDocument = this->get_override("endDocument")){
		endDocument();
	}else{
		xercesc::SAX2XMLReaderImpl::endDocument();
	}
}

void endElement(const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const bool isRoot, const XMLCh* const prefixName = 0) {
	if(boost::python::override endElement = this->get_override("endElement")){
		endElement(boost::ref(elemDecl), uriId, isRoot, XMLString(prefixName));
	}else{
		xercesc::SAX2XMLReaderImpl::endElement(elemDecl, uriId, isRoot, prefixName);
	}
}

void endEntityReference(const xercesc::XMLEntityDecl& entDecl) {
	if(boost::python::override endEntityReference = this->get_override("endEntityReference")){
		endEntityReference(boost::ref(entDecl));
	}else{
		xercesc::SAX2XMLReaderImpl::endEntityReference(entDecl);
	}
}

void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length, const bool cdataSection) {
	if(boost::python::override ignorableWhitespace = this->get_override("ignorableWhitespace")){
		ignorableWhitespace(XMLString(chars), length, cdataSection);
	}else{
		xercesc::SAX2XMLReaderImpl::ignorableWhitespace(chars, length, cdataSection);
	}
}

void resetDocument() {
	if(boost::python::override resetDocument = this->get_override("resetDocument")){
		resetDocument();
	}else{
		xercesc::SAX2XMLReaderImpl::resetDocument();
	}
}

void startDocument() {
	if(boost::python::override startDocument = this->get_override("startDocument")){
		startDocument();
	}else{
		xercesc::SAX2XMLReaderImpl::startDocument();
	}
}

void startElement(const xercesc::XMLElementDecl& elemDecl, const unsigned int uriId, const XMLCh* const prefixName, const xercesc::RefVectorOf<xercesc::XMLAttr>& attrList, const XMLSize_t attrCount, const bool isEmpty, const bool isRoot) {
	if(boost::python::override startElement = this->get_override("startElement")){
		startElement(boost::ref(elemDecl), uriId, XMLString(prefixName), boost::ref(attrList), attrCount, isEmpty, isRoot);
	}else{
		xercesc::SAX2XMLReaderImpl::startElement(elemDecl, uriId, prefixName, attrList, attrCount, isEmpty, isRoot);
	}
}

void startEntityReference(const xercesc::XMLEntityDecl& entDecl) {
	if(boost::python::override startEntityReference = this->get_override("startEntityReference")){
		startEntityReference(boost::ref(entDecl));
	}else{
		xercesc::SAX2XMLReaderImpl::startEntityReference(entDecl);
	}
}

void XMLDecl(const XMLCh* const versionStr, const XMLCh* const encodingStr, const XMLCh* const standaloneStr, const XMLCh* const autoEncodingStr) {
	if(boost::python::override XMLDecl = this->get_override("XMLDecl")){
		XMLDecl(XMLString(versionStr), XMLString(encodingStr), XMLString(standaloneStr), XMLString(autoEncodingStr));
	}else{
		xercesc::SAX2XMLReaderImpl::XMLDecl(versionStr, encodingStr, standaloneStr, autoEncodingStr);
	}
}

void error(const unsigned int errCode, const XMLCh* const errDomain, const ErrTypes type, const XMLCh* const errorText, const XMLCh* const systemId, const XMLCh* const publicId, const XMLFileLoc lineNum, const XMLFileLoc colNum) {
	if(boost::python::override error = this->get_override("error")){
		error(errCode, XMLString(errDomain), type, XMLString(errorText), XMLString(systemId), XMLString(publicId), lineNum, colNum);
	}else{
		xercesc::SAX2XMLReaderImpl::error(errCode, errDomain, type, errorText, systemId, publicId, lineNum, colNum);
	}
}

void resetErrors() {
	if(boost::python::override resetErrors = this->get_override("resetErrors")){
		resetErrors();
	}else{
		xercesc::SAX2XMLReaderImpl::resetErrors();
	}
}

void endInputSource(const xercesc::InputSource& inputSource) {
	if(boost::python::override endInputSource = this->get_override("endInputSource")){
		endInputSource(boost::ref(inputSource));
	}else{
		xercesc::SAX2XMLReaderImpl::endInputSource(inputSource);
	}
}

bool expandSystemId(const XMLCh* const systemId, xercesc::XMLBuffer& toFill) {
	if(boost::python::override expandSystemId = this->get_override("expandSystemId")){
		return expandSystemId(XMLString(systemId), boost::ref(toFill));
	}else{
		return xercesc::SAX2XMLReaderImpl::expandSystemId(systemId, toFill);
	}
}

void resetEntities() {
	if(boost::python::override resetEntities = this->get_override("resetEntities")){
		resetEntities();
	}else{
		xercesc::SAX2XMLReaderImpl::resetEntities();
	}
}

xercesc::InputSource* resolveEntity(xercesc::XMLResourceIdentifier* resourceIdentifier) {
	if(boost::python::override resolveEntity = this->get_override("resolveEntity")){
		return resolveEntity(boost::python::ptr(resourceIdentifier));
	}else{
		return xercesc::SAX2XMLReaderImpl::resolveEntity(resourceIdentifier);
	}
}

void startInputSource(const xercesc::InputSource& inputSource) {
	if(boost::python::override startInputSource = this->get_override("startInputSource")){
		startInputSource(boost::ref(inputSource));
	}else{
		xercesc::SAX2XMLReaderImpl::startInputSource(inputSource);
	}
}

void attDef(const xercesc::DTDElementDecl& elemDecl, const xercesc::DTDAttDef& attDef, const bool ignoring) {
	if(boost::python::override _attDef = this->get_override("attDef")){
		_attDef(boost::ref(elemDecl), boost::ref(attDef), ignoring);
	}else{
		xercesc::SAX2XMLReaderImpl::attDef(elemDecl, attDef, ignoring);
	}
}

void doctypeComment(const XMLCh* const comment) {
	if(boost::python::override doctypeComment = this->get_override("doctypeComment")){
		doctypeComment(XMLString(comment));
	}else{
		xercesc::SAX2XMLReaderImpl::doctypeComment(comment);
	}
}

void doctypeDecl(const xercesc::DTDElementDecl& elemDecl, const XMLCh* const publicId, const XMLCh* const systemId, const bool hasIntSubset, const bool hasExtSubset = false) {
	if(boost::python::override doctypeDecl = this->get_override("doctypeDecl")){
		doctypeDecl(boost::ref(elemDecl), XMLString(publicId), XMLString(systemId), hasIntSubset, hasExtSubset);
	}else{
		xercesc::SAX2XMLReaderImpl::doctypeDecl(elemDecl, publicId, systemId, hasIntSubset, hasExtSubset);
	}
}

void doctypePI(const XMLCh* const target, const XMLCh* const data) {
	if(boost::python::override doctypePI = this->get_override("doctypePI")){
		doctypePI(XMLString(target), XMLString(data));
	}else{
		xercesc::SAX2XMLReaderImpl::doctypePI(target, data);
	}
}

void doctypeWhitespace(const XMLCh* const chars, const XMLSize_t length) {
	if(boost::python::override doctypeWhitespace = this->get_override("doctypeWhitespace")){
		doctypeWhitespace(XMLString(chars), length);
	}else{
		xercesc::SAX2XMLReaderImpl::doctypeWhitespace(chars, length);
	}
}

void elementDecl(const xercesc::DTDElementDecl& decl, const bool isIgnored) {
	if(boost::python::override elementDecl = this->get_override("elementDecl")){
		elementDecl(boost::ref(decl), isIgnored);
	}else{
		xercesc::SAX2XMLReaderImpl::elementDecl(decl, isIgnored);
	}
}

void endAttList(const xercesc::DTDElementDecl& elemDecl) {
	if(boost::python::override endAttList = this->get_override("endAttList")){
		endAttList(boost::ref(elemDecl));
	}else{
		xercesc::SAX2XMLReaderImpl::endAttList(elemDecl);
	}
}

void endIntSubset() {
	if(boost::python::override endIntSubset = this->get_override("endIntSubset")){
		endIntSubset();
	}else{
		xercesc::SAX2XMLReaderImpl::endIntSubset();
	}
}

void endExtSubset() {
	if(boost::python::override endExtSubset = this->get_override("endExtSubset")){
		endExtSubset();
	}else{
		xercesc::SAX2XMLReaderImpl::endExtSubset();
	}
}

void entityDecl(const xercesc::DTDEntityDecl&  entityDecl, const bool isPEDecl, const bool isIgnored) {
	if(boost::python::override _entityDecl = this->get_override("entityDecl")){
		_entityDecl(boost::ref(entityDecl), isPEDecl, isIgnored);
	}else{
		xercesc::SAX2XMLReaderImpl::entityDecl(entityDecl, isPEDecl, isIgnored);
	}
}

void resetDocType() {
	if(boost::python::override resetDocType = this->get_override("resetDocType")){
		resetDocType();
	}else{
		xercesc::SAX2XMLReaderImpl::resetDocType();
	}
}

void notationDecl(const xercesc::XMLNotationDecl& notDecl, const bool isIgnored) {
	if(boost::python::override notationDecl = this->get_override("notationDecl")){
		notationDecl(boost::ref(notDecl), isIgnored);
	}else{
		xercesc::SAX2XMLReaderImpl::notationDecl(notDecl, isIgnored);
	}
}

void startAttList(const xercesc::DTDElementDecl& elemDecl) {
	if(boost::python::override startAttList = this->get_override("startAttList")){
		startAttList(boost::ref(elemDecl));
	}else{
		xercesc::SAX2XMLReaderImpl::startAttList(elemDecl);
	}
}

void startIntSubset() {
	if(boost::python::override startIntSubset = this->get_override("startIntSubset")){
		startIntSubset();
	}else{
		xercesc::SAX2XMLReaderImpl::startIntSubset();
	}
}

void startExtSubset() {
	if(boost::python::override startExtSubset = this->get_override("startExtSubset")){
		startExtSubset();
	}else{
		xercesc::SAX2XMLReaderImpl::startExtSubset();
	}
}

void TextDecl(const XMLCh* const versionStr, const XMLCh* const encodingStr) {
	if(boost::python::override TextDecl = this->get_override("TextDecl")){
		TextDecl(XMLString(versionStr), XMLString(encodingStr));
	}else{
		xercesc::SAX2XMLReaderImpl::TextDecl(versionStr, encodingStr);
	}
}

};

//! SAX2XMLReaderImpl
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SAX2XMLReaderImplLoadGrammarOverloads, loadGrammar, 2, 3)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SAX2XMLReaderImplDoctypeDeclOverloads, doctypeDecl, 4, 5)

void SAX2XMLReaderImpl_init(void) {
	//! xercesc::SAX2XMLReaderImpl
	boost::python::class_<SAX2XMLReaderImplWrapper, boost::noncopyable, boost::python::bases<xercesc::SAX2XMLReader, xercesc::XMLDocumentHandler, xercesc::XMLErrorReporter, xercesc::XMLEntityHandler, xercesc::DocTypeHandler> >("SAX2XMLReaderImpl", boost::python::init<boost::python::optional<xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const> >())
			.def(SAX2XMLReaderImplDefVisitor<XMLString>())
			.def(SAX2XMLReaderImplDefVisitor<std::string>())
			.def("getContentHandler", &xercesc::SAX2XMLReaderImpl::getContentHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDTDHandler", &xercesc::SAX2XMLReaderImpl::getDTDHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getEntityResolver", &xercesc::SAX2XMLReaderImpl::getEntityResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getXMLEntityResolver", &xercesc::SAX2XMLReaderImpl::getXMLEntityResolver, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrorHandler", &xercesc::SAX2XMLReaderImpl::getErrorHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getPSVIHandler", &xercesc::SAX2XMLReaderImpl::getPSVIHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFeature", &xercesc::SAX2XMLReaderImpl::getFeature)
			.def("getProperty", &xercesc::SAX2XMLReaderImpl::getProperty, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("setContentHandler", &xercesc::SAX2XMLReaderImpl::setContentHandler)
			.def("setDTDHandler", &xercesc::SAX2XMLReaderImpl::setDTDHandler)
			.def("setEntityResolver", &xercesc::SAX2XMLReaderImpl::setEntityResolver)
			.def("setXMLEntityResolver", &xercesc::SAX2XMLReaderImpl::setXMLEntityResolver)
			.def("setErrorHandler", &xercesc::SAX2XMLReaderImpl::setErrorHandler)
			.def("setPSVIHandler", &xercesc::SAX2XMLReaderImpl::setPSVIHandler)
			.def("setFeature", &xercesc::SAX2XMLReaderImpl::setFeature)
			.def("setProperty", &xercesc::SAX2XMLReaderImpl::setProperty)
			.def("parse", static_cast<void(xercesc::SAX2XMLReaderImpl::*)(const xercesc::InputSource&)>(&xercesc::SAX2XMLReaderImpl::parse))
			.def("parse", static_cast<void(xercesc::SAX2XMLReaderImpl::*)(const XMLCh* const)>(&xercesc::SAX2XMLReaderImpl::parse))
			.def("parse", static_cast<void(xercesc::SAX2XMLReaderImpl::*)(const char* const)>(&xercesc::SAX2XMLReaderImpl::parse))
			.def("getDeclarationHandler", &xercesc::SAX2XMLReaderImpl::getDeclarationHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getLexicalHandler", &xercesc::SAX2XMLReaderImpl::getLexicalHandler, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setDeclarationHandler", &xercesc::SAX2XMLReaderImpl::setDeclarationHandler)
			.def("setLexicalHandler", &xercesc::SAX2XMLReaderImpl::setLexicalHandler)
			.def("getValidator", &xercesc::SAX2XMLReaderImpl::getValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getErrorCount", &xercesc::SAX2XMLReaderImpl::getErrorCount)
			.def("getExitOnFirstFatalError", &xercesc::SAX2XMLReaderImpl::getExitOnFirstFatalError)
			.def("getValidationConstraintFatal", &xercesc::SAX2XMLReaderImpl::getValidationConstraintFatal)
			.def("getGrammar", &xercesc::SAX2XMLReaderImpl::getGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getRootGrammar", &xercesc::SAX2XMLReaderImpl::getRootGrammar, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getURIText", &xercesc::SAX2XMLReaderImpl::getURIText, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getSrcOffset", &xercesc::SAX2XMLReaderImpl::getSrcOffset)
			.def("setValidator", &xercesc::SAX2XMLReaderImpl::setValidator)
			.def("setExitOnFirstFatalError", &xercesc::SAX2XMLReaderImpl::setExitOnFirstFatalError)
			.def("setValidationConstraintFatal", &xercesc::SAX2XMLReaderImpl::setValidationConstraintFatal)
			.def("parseFirst", static_cast<bool(xercesc::SAX2XMLReaderImpl::*)(const XMLCh* const, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReaderImpl::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::SAX2XMLReaderImpl::*)(const char* const, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReaderImpl::parseFirst))
			.def("parseFirst", static_cast<bool(xercesc::SAX2XMLReaderImpl::*)(const xercesc::InputSource&, xercesc::XMLPScanToken&)>(&xercesc::SAX2XMLReaderImpl::parseFirst))
			.def("parseNext", &xercesc::SAX2XMLReaderImpl::parseNext)
			.def("parseReset", &xercesc::SAX2XMLReaderImpl::parseReset)
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAX2XMLReaderImpl::*)(const xercesc::InputSource&, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReaderImpl::loadGrammar), SAX2XMLReaderImplLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAX2XMLReaderImpl::*)(const XMLCh* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReaderImpl::loadGrammar), SAX2XMLReaderImplLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("loadGrammar", static_cast<xercesc::Grammar*(xercesc::SAX2XMLReaderImpl::*)(const char* const, const xercesc::Grammar::GrammarType, const bool)>(&xercesc::SAX2XMLReaderImpl::loadGrammar), SAX2XMLReaderImplLoadGrammarOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("resetCachedGrammarPool", &xercesc::SAX2XMLReaderImpl::resetCachedGrammarPool)
			.def("setInputBufferSize", &xercesc::SAX2XMLReaderImpl::setInputBufferSize)
			.def("installAdvDocHandler", &xercesc::SAX2XMLReaderImpl::installAdvDocHandler)
			.def("removeAdvDocHandler", &xercesc::SAX2XMLReaderImpl::removeAdvDocHandler)
			.def("docCharacters", &xercesc::SAX2XMLReaderImpl::docCharacters)
			.def("docComment", &xercesc::SAX2XMLReaderImpl::docComment)
			.def("docPI", &xercesc::SAX2XMLReaderImpl::docPI)
			.def("endDocument", &xercesc::SAX2XMLReaderImpl::endDocument)
			.def("endElement", &xercesc::SAX2XMLReaderImpl::endElement)
			.def("endEntityReference", &xercesc::SAX2XMLReaderImpl::endEntityReference)
			.def("ignorableWhitespace", &xercesc::SAX2XMLReaderImpl::ignorableWhitespace)
			.def("resetDocument", &xercesc::SAX2XMLReaderImpl::resetDocument)
			.def("startDocument", &xercesc::SAX2XMLReaderImpl::startDocument)
			.def("startElement", &xercesc::SAX2XMLReaderImpl::startElement)
			.def("startEntityReference", &xercesc::SAX2XMLReaderImpl::startEntityReference)
			.def("XMLDecl", &xercesc::SAX2XMLReaderImpl::XMLDecl)
			.def("error", &xercesc::SAX2XMLReaderImpl::error)
			.def("resetErrors", &xercesc::SAX2XMLReaderImpl::resetErrors)
			.def("endInputSource", &xercesc::SAX2XMLReaderImpl::endInputSource)
			.def("expandSystemId", &xercesc::SAX2XMLReaderImpl::expandSystemId)
			.def("resetEntities", &xercesc::SAX2XMLReaderImpl::resetEntities)
			.def("resolveEntity", &xercesc::SAX2XMLReaderImpl::resolveEntity, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("startInputSource", &xercesc::SAX2XMLReaderImpl::startInputSource)
			.def("attDef", &xercesc::SAX2XMLReaderImpl::attDef)
			.def("doctypeComment", &xercesc::SAX2XMLReaderImpl::doctypeComment)
			.def("doctypeDecl", &xercesc::SAX2XMLReaderImpl::doctypeDecl, SAX2XMLReaderImplDoctypeDeclOverloads())
			.def("doctypePI", &xercesc::SAX2XMLReaderImpl::doctypePI)
			.def("doctypeWhitespace", &xercesc::SAX2XMLReaderImpl::doctypeWhitespace)
			.def("elementDecl", &xercesc::SAX2XMLReaderImpl::elementDecl)
			.def("endAttList", &xercesc::SAX2XMLReaderImpl::endAttList)
			.def("endIntSubset", &xercesc::SAX2XMLReaderImpl::endIntSubset)
			.def("endExtSubset", &xercesc::SAX2XMLReaderImpl::endExtSubset)
			.def("entityDecl", &xercesc::SAX2XMLReaderImpl::entityDecl)
			.def("resetDocType", &xercesc::SAX2XMLReaderImpl::resetDocType)
			.def("notationDecl", &xercesc::SAX2XMLReaderImpl::notationDecl)
			.def("startAttList", &xercesc::SAX2XMLReaderImpl::startAttList)
			.def("startIntSubset", &xercesc::SAX2XMLReaderImpl::startIntSubset)
			.def("startExtSubset", &xercesc::SAX2XMLReaderImpl::startExtSubset)
			.def("TextDecl", &xercesc::SAX2XMLReaderImpl::TextDecl)
			;
}

} /* namespace pyxerces */
