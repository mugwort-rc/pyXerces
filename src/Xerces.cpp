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
#include "framework/ValidationContext.h"
#include "framework/XMLAttDef.h"
#include "framework/XMLAttDefList.h"
#include "framework/XMLBuffer.h"
#include "framework/XMLContentModel.h"
#include "framework/XMLDocumentHandler.h"
#include "framework/XMLDTDDescription.h"
#include "framework/XMLElementDecl.h"
#include "framework/XMLEntityDecl.h"
#include "framework/XMLEntityHandler.h"
#include "framework/XMLErrorReporter.h"
#include "framework/XMLFormatter.h"
#include "framework/XMLGrammarDescription.h"
#include "framework/XMLGrammarPool.h"
#include "framework/XMLNotationDecl.h"
#include "framework/XMLPScanToken.h"
#include "framework/XMLRecognizer.h"
#include "framework/XMLRefInfo.h"
#include "framework/XMLSchemaDescription.h"
#include "framework/XMLValidator.h"
// framework/psvi
#include "framework/psvi/PSVIHandler.h"
#include "framework/psvi/XSAnnotation.h"
#include "framework/psvi/XSAttributeDeclaration.h"
#include "framework/psvi/XSAttributeGroupDefinition.h"
#include "framework/psvi/XSAttributeUse.h"
#include "framework/psvi/XSComplexTypeDefinition.h"
#include "framework/psvi/XSConstants.h"
#include "framework/psvi/XSElementDeclaration.h"
#include "framework/psvi/XSFacet.h"
#include "framework/psvi/XSIDCDefinition.h"
#include "framework/psvi/XSModel.h"
#include "framework/psvi/XSModelGroup.h"
#include "framework/psvi/XSModelGroupDefinition.h"
#include "framework/psvi/XSMultiValueFacet.h"
#include "framework/psvi/XSNamedMap.h"
#include "framework/psvi/XSNamespaceItem.h"
#include "framework/psvi/XSNotationDeclaration.h"
#include "framework/psvi/XSObject.h"
#include "framework/psvi/XSSimpleTypeDefinition.h"
#include "framework/psvi/XSTypeDefinition.h"
#include "framework/psvi/XSWildcard.h"

// internal
#include "internal/XProtoType.h"
#include "internal/XSerializable.h"

// parsers
#include "parsers/AbstractDOMParser.h"
#include "parsers/SAXParser.h"
#include "parsers/XercesDOMParser.h"

// sax
#include "sax/AttributeList.h"
#include "sax/DocumentHandler.h"
#include "sax/DTDHandler.h"
#include "sax/EntityResolver.h"
#include "sax/ErrorHandler.h"
#include "sax/HandlerBase.h"
#include "sax/InputSource.h"
#include "sax/Parser.h"
#include "sax/SAXException.h"
#include "sax/SAXParseException.h"

// sax2
#include "sax2/ContentHandler.h"
#include "sax2/DeclHandler.h"
#include "sax2/DefaultHandler.h"
#include "sax2/LexicalHandler.h"

// util
#include "util/ArrayIndexOutOfBoundsException.h"
#include "util/BaseRefVectorOf.h"
#include "util/BinInputStream.h"
#include "util/EmptyStackException.h"
#include "util/IllegalArgumentException.h"
#include "util/InvalidCastException.h"
#include "util/IOException.h"
#include "util/KVStringPair.h"
#include "util/NameIdPool.h"
#include "util/NoSuchElementException.h"
#include "util/NullPointerException.h"
#include "util/NumberFormatException.h"
#include "util/OutOfMemoryException.h"
#include "util/PanicHandler.h"
#include "util/ParseException.h"
#include "util/PlatformUtils.h"
#include "util/PSVIUni.h"
#include "util/QName.h"
#include "util/RefArrayVectorOf.h"
#include "util/RefHash2KeysTableOf.h"
#include "util/RefHash3KeysIdPool.h"
#include "util/RefHashTableOf.h"
#include "util/RefVectorOf.h"
#include "util/RuntimeException.h"
#include "util/SchemaDateTimeException.h"
#include "util/SecurityManager.h"
#include "util/StringPool.h"
#include "util/TranscodingException.h"
#include "util/TransService.h"
#include "util/UnexpectedEOFException.h"
#include "util/UnsupportedEncodingException.h"
#include "util/UTFDataFormatException.h"
#include "util/ValueVectorOf.h"
#include "util/XMLEntityResolver.h"
#include "util/XMLEnumerator.h"
#include "util/XMLException.h"
#include "util/XMLExceptMsgs.h"
#include "util/XMLFileMgr.h"
#include "util/XMLMsgLoader.h"
#include "util/XMLMutexMgr.h"
#include "util/XMLNetAccessor.h"
#include "util/XMLString.h"
#include "util/XMLUni.h"

// validators
#include "validators/common/ContentLeafNameTypeVector.h"
#include "validators/common/ContentSpecNode.h"
#include "validators/common/Grammar.h"
#include "validators/datatype/DatatypeValidator.h"
#include "validators/datatype/DatatypeValidatorFactory.h"
#include "validators/datatype/InvalidDatatypeFacetException.h"
#include "validators/datatype/InvalidDatatypeValueException.h"
#include "validators/datatype/XMLCanRepGroup.h"
#include "validators/DTD/DocTypeHandler.h"
#include "validators/DTD/DTDElementDecl.h"
#include "validators/DTD/DTDEntityDecl.h"
#include "validators/DTD/DTDGrammar.h"
#include "validators/DTD/DTDValidator.h"
#include "validators/schema/ComplexTypeInfo.h"
#include "validators/schema/PSVIDefs.h"
#include "validators/schema/SchemaAttDef.h"
#include "validators/schema/SchemaElementDecl.h"
#include "validators/schema/SchemaGrammar.h"
#include "validators/schema/XercesAttGroupInfo.h"
#include "validators/schema/XercesGroupInfo.h"
#include "validators/schema/identity/IC_Field.h"
#include "validators/schema/identity/IC_Selector.h"
#include "validators/schema/identity/IdentityConstraint.h"
#include "validators/schema/identity/XercesXPath.h"
#include "validators/schema/identity/XPathException.h"
#include "validators/schema/identity/XPathMatcher.h"

BOOST_PYTHON_MODULE(__Xerces)
{
	// ==================================================
	// bases
	// --------------------------------------------------
	// dom
	pyxerces::DOMNode_init();
	pyxerces::DOMDocumentRange_init();
	pyxerces::DOMDocumentTraversal_init();
	pyxerces::DOMException_init();
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
	pyxerces::XSObject_init();
	// internal
	pyxerces::XSerializable_init();
	// sax
	pyxerces::DTDHandler_init();
	pyxerces::InputSource_init();
	pyxerces::Parser_init();
	// sax2
	pyxerces::ContentHandler_init();
	pyxerces::DeclHandler_init();
	pyxerces::LexicalHandler_init();
	// util
	pyxerces::BaseRefVectorOf_init();
	pyxerces::XMLEnumerator_init();
	pyxerces::XMLException_init();
	// validators/DTD
	pyxerces::DocTypeHandler_init();
	// validators/schema/identity
	pyxerces::XPathMatcher_init();

	// inherited (depth:2) classes
	// dom
	pyxerces::DOMCharacterData_init();
	// framework
	pyxerces::XMLEntityDecl_init();
	pyxerces::XMLGrammarDescription_init();
	// framework/psvi
	pyxerces::XSTypeDefinition_init();
	// parsers
	pyxerces::AbstractDOMParser_init();
	// validators/common
	pyxerces::Grammar_init();

	// inherited (depth:3) classes
	// dom
	pyxerces::DOMText_init();

	// --------------------------------------------------
	// util
	pyxerces::XMLString_init();

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
	pyxerces::ValidationContext_init();
	pyxerces::XMLAttDef_init();
	pyxerces::XMLAttDefList_init();
	pyxerces::XMLBuffer_init();
	pyxerces::XMLContentModel_init();
	pyxerces::XMLDTDDescription_init();
	pyxerces::XMLElementDecl_init();
	pyxerces::XMLGrammarPool_init();
	pyxerces::XMLNotationDecl_init();
	pyxerces::XMLPScanToken_init();
	pyxerces::XMLRecognizer_init();
	pyxerces::XMLRefInfo_init();
	pyxerces::XMLSchemaDescription_init();
	// psvi
	pyxerces::XSAnnotation_init();
	pyxerces::XSAttributeDeclaration_init();
	pyxerces::XSAttributeGroupDefinition_init();
	pyxerces::XSAttributeUse_init();
	pyxerces::XSComplexTypeDefinition_init();
	pyxerces::XSConstants_init();
	pyxerces::XSElementDeclaration_init();
	pyxerces::XSFacet_init();
	pyxerces::XSIDCDefinition_init();
	pyxerces::XSModel_init();
	pyxerces::XSModelGroup_init();
	pyxerces::XSModelGroupDefinition_init();
	pyxerces::XSMultiValueFacet_init();
	pyxerces::XSNamedMap_init();
	pyxerces::XSNamespaceItem_init();
	pyxerces::XSNotationDeclaration_init();
	pyxerces::XSSimpleTypeDefinition_init();
	pyxerces::XSWildcard_init();

	// ==================================================
	// internal
	// --------------------------------------------------
	pyxerces::XProtoType_init();

	// ==================================================
	// parsers
	// --------------------------------------------------
	pyxerces::SAXParser_init();
	pyxerces::XercesDOMParser_init();

	// ==================================================
	// sax
	// --------------------------------------------------
	pyxerces::AttributeList_init();
	pyxerces::DocumentHandler_init();
	pyxerces::EntityResolver_init();
	pyxerces::ErrorHandler_init();
	pyxerces::HandlerBase_init();
	pyxerces::SAXException_init();
	pyxerces::SAXParseException_init();

	// ==================================================
	// sax2
	// --------------------------------------------------
	pyxerces::DefaultHandler_init();

	// ==================================================
	// util
	// --------------------------------------------------
	pyxerces::ArrayIndexOutOfBoundsException_init();
	pyxerces::BinInputStream_init();
	pyxerces::EmptyStackException_init();
	pyxerces::IllegalArgumentException_init();
	pyxerces::InvalidCastException_init();
	pyxerces::IOException_init();
	pyxerces::KVStringPair_init();
	pyxerces::NameIdPool_init();
	pyxerces::NoSuchElementException_init();
	pyxerces::NullPointerException_init();
	pyxerces::NumberFormatException_init();
	pyxerces::OutOfMemoryException_init();
	pyxerces::PanicHandler_init();
	pyxerces::ParseException_init();
	pyxerces::PlatformUtils_init();
	pyxerces::PSVIUni_init();
	pyxerces::QName_init();
	pyxerces::RefArrayVectorOf_init();
	pyxerces::RefHash2KeysTableOf_init();
	pyxerces::RefHash3KeysIdPool_init();
	pyxerces::RefHashTableOf_init();
	pyxerces::RefVectorOf_init();
	pyxerces::RuntimeException_init();
	pyxerces::SchemaDateTimeException_init();
	pyxerces::SecurityManager_init();
	pyxerces::StringPool_init();
	pyxerces::TranscodingException_init();
	pyxerces::TransService_init();
	pyxerces::UnexpectedEOFException_init();
	pyxerces::UnsupportedEncodingException_init();
	pyxerces::UTFDataFormatException_init();
	pyxerces::ValueVectorOf_init();
	pyxerces::XMLEntityResolver_init();
	pyxerces::XMLExceptMsgs_init();
	pyxerces::XMLFileMgr_init();
	pyxerces::XMLMsgLoader_init();
	pyxerces::XMLMutexMgr_init();
	pyxerces::XMLNetAccessor_init();
	pyxerces::XMLUni_init();

	// ==================================================
	// validators
	// --------------------------------------------------
	// common
	pyxerces::ContentLeafNameTypeVector_init();
	pyxerces::ContentSpecNode_init();
	// datatype
	pyxerces::DatatypeValidator_init();
	pyxerces::DatatypeValidatorFactory_init();
	pyxerces::InvalidDatatypeFacetException_init();
	pyxerces::InvalidDatatypeValueException_init();
	pyxerces::XMLCanRepGroup_init();
	// DTD
	pyxerces::DTDElementDecl_init();
	pyxerces::DTDEntityDecl_init();
	pyxerces::DTDGrammar_init();
	pyxerces::DTDGrammar_init();
	pyxerces::DTDValidator_init();
	// schema
	pyxerces::ComplexTypeInfo_init();
	pyxerces::PSVIDefs_init();
	pyxerces::SchemaAttDef_init();
	pyxerces::SchemaElementDecl_init();
	pyxerces::SchemaGrammar_init();
	pyxerces::XercesAttGroupInfo_init();
	pyxerces::XercesGroupInfo_init();
	// schema/identity
	pyxerces::IC_Field_init();
	pyxerces::IC_Selector_init();
	pyxerces::IdentityConstraint_init();
	pyxerces::XercesXPath_init();
	pyxerces::XPathException_init();
}
