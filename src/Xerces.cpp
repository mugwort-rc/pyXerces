/*
 * Xerces.cpp
 *
 *  Created on: 2013/01/29
 *      Author: mugwort_rc
 */

#include <Python.h>
#include <boost/python.hpp>
#define BOOST_PYTHON_STATIC_LIB

// dom
#include "dom/DOMAttr.h"
#include "dom/DOMCDATASection.h"
#include "dom/DOMCharacterData.h"
#include "dom/DOMComment.h"
#include "dom/DOMConfiguration.h"
#include "dom/DOMDocument.h"
#include "dom/DOMDocumentFragment.h"
#include "dom/DOMDocumentRange.h"
#include "dom/DOMDocumentTraversal.h"
#include "dom/DOMDocumentType.h"
#include "dom/DOMElement.h"
#include "dom/DOMEntity.h"
#include "dom/DOMEntityReference.h"
#include "dom/DOMError.h"
#include "dom/DOMErrorHandler.h"
#include "dom/DOMException.h"
#include "dom/DOMImplementation.h"
#include "dom/DOMImplementationList.h"
#include "dom/DOMImplementationLS.h"
#include "dom/DOMImplementationRegistry.h"
#include "dom/DOMLocator.h"
#include "dom/DOMLSException.h"
#include "dom/DOMLSInput.h"
#include "dom/DOMLSOutput.h"
#include "dom/DOMLSParser.h"
#include "dom/DOMLSParserFilter.h"
#include "dom/DOMLSSerializer.h"
#include "dom/DOMLSSerializerFilter.h"
#include "dom/DOMNamedNodeMap.h"
#include "dom/DOMNode.h"
#include "dom/DOMNodeFilter.h"
#include "dom/DOMNodeIterator.h"
#include "dom/DOMNodeList.h"
#include "dom/DOMNotation.h"
#include "dom/DOMProcessingInstruction.h"
#include "dom/DOMRange.h"
#include "dom/DOMRangeException.h"
#include "dom/DOMStringList.h"
#include "dom/DOMText.h"
#include "dom/DOMTreeWalker.h"
#include "dom/DOMTypeInfo.h"
#include "dom/DOMXPathEvaluator.h"
#include "dom/DOMXPathException.h"
#include "dom/DOMXPathExpression.h"
#include "dom/DOMXPathNamespace.h"
#include "dom/DOMXPathNSResolver.h"
#include "dom/DOMXPathResult.h"

// framework
#include "framework/LocalFileFormatTarget.h"
#include "framework/MemBufFormatTarget.h"
#include "framework/MemBufInputSource.h"
#include "framework/MemoryManager.h"
#include "framework/StdOutFormatTarget.h"
#include "framework/XMLBuffer.h"
#include "framework/XMLContentModel.h"
#include "framework/XMLDocumentHandler.h"
#include "framework/XMLElementDecl.h"
#include "framework/XMLEntityHandler.h"
#include "framework/XMLErrorReporter.h"
#include "framework/XMLFormatter.h"
#include "framework/XMLGrammarDescription.h"
#include "framework/XMLRecognizer.h"
#include "framework/XMLValidator.h"
#include "framework/psvi/PSVIHandler.h"

// internal
#include "internal/XProtoType.h"
#include "internal/XSerializable.h"

// parsers
#include "parsers/AbstractDOMParser.h"
#include "parsers/XercesDOMParser.h"

// sax
#include "sax/EntityResolver.h"
#include "sax/ErrorHandler.h"
#include "sax/InputSource.h"
#include "sax/SAXException.h"
#include "sax/SAXParseException.h"

// util
#include "util/ArrayIndexOutOfBoundsException.h"
#include "util/BinInputStream.h"
#include "util/EmptyStackException.h"
#include "util/IllegalArgumentException.h"
#include "util/InvalidCastException.h"
#include "util/IOException.h"
#include "util/NoSuchElementException.h"
#include "util/NullPointerException.h"
#include "util/NumberFormatException.h"
#include "util/OutOfMemoryException.h"
#include "util/ParseException.h"
#include "util/PlatformUtils.h"
#include "util/QName.h"
#include "util/RuntimeException.h"
#include "util/SchemaDateTimeException.h"
#include "util/SecurityManager.h"
#include "util/TranscodingException.h"
#include "util/TransService.h"
#include "util/UnexpectedEOFException.h"
#include "util/UnsupportedEncodingException.h"
#include "util/UTFDataFormatException.h"
#include "util/XMLEntityResolver.h"
#include "util/XMLException.h"
#include "util/XMLExceptMsgs.h"
#include "util/XMLFileMgr.h"
#include "util/XMLMsgLoader.h"
#include "util/XMLMutexMgr.h"
#include "util/XMLString.h"
#include "util/XMLUni.h"

// validators
#include "validators/common/ContentLeafNameTypeVector.h"
#include "validators/common/ContentSpecNode.h"
#include "validators/common/Grammar.h"
#include "validators/datatype/InvalidDatatypeFacetException.h"
#include "validators/datatype/InvalidDatatypeValueException.h"
#include "validators/DTD/DocTypeHandler.h"
#include "validators/DTD/DTDValidator.h"
#include "validators/schema/identity/XPathException.h"

BOOST_PYTHON_MODULE(__Xerces)
{
	// ==================================================
	// bases
	// --------------------------------------------------
	// dom
	pyxerces::DOMNode_init();
	pyxerces::DOMCharacterData_init();
	pyxerces::DOMDocumentRange_init();
	pyxerces::DOMDocumentTraversal_init();
	pyxerces::DOMException_init();
	pyxerces::DOMText_init();
	pyxerces::DOMImplementationLS_init();
	pyxerces::DOMNodeFilter_init();
	pyxerces::DOMXPathEvaluator_init();
	// framework
	pyxerces::XMLDocumentHandler_init();
	pyxerces::XMLEntityHandler_init();
	pyxerces::XMLErrorReporter_init();
	pyxerces::XMLFormatter_init();
	pyxerces::XMLValidator_init();
	// framework/psvi
	pyxerces::PSVIHandler_init();
	// internal
	pyxerces::XSerializable_init();
	// sax
	pyxerces::InputSource_init();
	// util
	pyxerces::XMLException_init();
	// validators/DTD
	pyxerces::DocTypeHandler_init();

	// inherited bases
	// parsers
	pyxerces::AbstractDOMParser_init();

	// ==================================================
	// dom
	// --------------------------------------------------
	pyxerces::DOMAttr_init();
	pyxerces::DOMCDATASection_init();
	pyxerces::DOMComment_init();
	pyxerces::DOMConfiguration_init();
	pyxerces::DOMDocument_init();
	pyxerces::DOMDocumentFragment_init();
	pyxerces::DOMDocumentType_init();
	pyxerces::DOMElement_init();
	pyxerces::DOMEntity_init();
	pyxerces::DOMEntityReference_init();
	pyxerces::DOMError_init();
	pyxerces::DOMErrorHandler_init();
	pyxerces::DOMImplementation_init();
	pyxerces::DOMImplementationList_init();
	pyxerces::DOMImplementationRegistry_init();
	pyxerces::DOMLocator_init();
	pyxerces::DOMLSException_init();
	pyxerces::DOMLSInput_init();
	pyxerces::DOMLSOutput_init();
	pyxerces::DOMLSParser_init();
	pyxerces::DOMLSParserFilter_init();
	pyxerces::DOMLSSerializer_init();
	pyxerces::DOMLSSerializerFilter_init();
	pyxerces::DOMNamedNodeMap_init();
	pyxerces::DOMNodeIterator_init();
	pyxerces::DOMNodeList_init();
	pyxerces::DOMNotation_init();
	pyxerces::DOMProcessingInstruction_init();
	pyxerces::DOMRange_init();
	pyxerces::DOMRangeException_init();
	pyxerces::DOMStringList_init();
	pyxerces::DOMTreeWalker_init();
	pyxerces::DOMTypeInfo_init();
	pyxerces::DOMXPathException_init();
	pyxerces::DOMXPathExpression_init();
	pyxerces::DOMXPathNamespace_init();
	pyxerces::DOMXPathNSResolver_init();
	pyxerces::DOMXPathResult_init();

	// ==================================================
	// framework
	// --------------------------------------------------
	pyxerces::LocalFileFormatTarget_init();
	pyxerces::MemBufFormatTarget_init();
	pyxerces::MemBufInputSource_init();
	pyxerces::MemoryManager_init();
	pyxerces::StdOutFormatTarget_init();
	pyxerces::XMLBuffer_init();
	pyxerces::XMLContentModel_init();
	pyxerces::XMLElementDecl_init();
	pyxerces::XMLGrammarDescription_init();
	pyxerces::XMLRecognizer_init();

	// ==================================================
	// internal
	// --------------------------------------------------
	pyxerces::XProtoType_init();

	// ==================================================
	// parsers
	// --------------------------------------------------
	pyxerces::XercesDOMParser_init();

	// ==================================================
	// sax
	// --------------------------------------------------
	pyxerces::EntityResolver_init();
	pyxerces::ErrorHandler_init();
	pyxerces::SAXException_init();
	pyxerces::SAXParseException_init();

	// ==================================================
	// util
	// --------------------------------------------------
	pyxerces::ArrayIndexOutOfBoundsException_init();
	pyxerces::BinInputStream_init();
	pyxerces::EmptyStackException_init();
	pyxerces::IllegalArgumentException_init();
	pyxerces::InvalidCastException_init();
	pyxerces::IOException_init();
	pyxerces::NoSuchElementException_init();
	pyxerces::NullPointerException_init();
	pyxerces::NumberFormatException_init();
	pyxerces::OutOfMemoryException_init();
	pyxerces::ParseException_init();
	pyxerces::PlatformUtils_init();
	pyxerces::QName_init();
	pyxerces::RuntimeException_init();
	pyxerces::SchemaDateTimeException_init();
	pyxerces::SecurityManager_init();
	pyxerces::TranscodingException_init();
	pyxerces::TransService_init();
	pyxerces::UnexpectedEOFException_init();
	pyxerces::UnsupportedEncodingException_init();
	pyxerces::UTFDataFormatException_init();
	pyxerces::XMLEntityResolver_init();
	pyxerces::XMLExceptMsgs_init();
	pyxerces::XMLFileMgr_init();
	pyxerces::XMLMsgLoader_init();
	pyxerces::XMLMutexMgr_init();
	pyxerces::XMLString_init();
	pyxerces::XMLUni_init();

	// ==================================================
	// validators
	// --------------------------------------------------
	// common
	pyxerces::ContentLeafNameTypeVector_init();
	pyxerces::ContentSpecNode_init();
	pyxerces::Grammar_init();
	// datatype
	pyxerces::InvalidDatatypeFacetException_init();
	pyxerces::InvalidDatatypeValueException_init();
	// DTD
	pyxerces::DTDValidator_init();
	// schema
	pyxerces::XPathException_init();
}
