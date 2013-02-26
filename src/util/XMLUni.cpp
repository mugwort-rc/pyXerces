/*
 * XMLUni.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "XMLUni.h"

#include <boost/python.hpp>
#include <xercesc/util/XMLUni.hpp>

#include "XMLString.h"

namespace pyxerces {

void XMLUni_init(void) {
	//! xercesc::XMLUni
	auto XMLUni = boost::python::class_<xercesc::XMLUni, boost::noncopyable>("XMLUni", boost::python::no_init)
			.setattr("fgAnyString", XMLChPtr(xercesc::XMLUni::fgAnyString))
		    .setattr("fgAttListString", XMLChPtr(xercesc::XMLUni::fgAttListString))
		    .setattr("fgCommentString", XMLChPtr(xercesc::XMLUni::fgCommentString))
		    .setattr("fgCDATAString", XMLChPtr(xercesc::XMLUni::fgCDATAString))
		    .setattr("fgCDATAString", XMLChPtr(xercesc::XMLUni::fgDefaultString))
		    .setattr("fgDocTypeString", XMLChPtr(xercesc::XMLUni::fgDocTypeString))
		    .setattr("fgEBCDICEncodingString", XMLChPtr(xercesc::XMLUni::fgEBCDICEncodingString))
		    .setattr("fgElemString", XMLChPtr(xercesc::XMLUni::fgElemString))
		    .setattr("fgEmptyString", XMLChPtr(xercesc::XMLUni::fgEmptyString))
		    .setattr("fgEncodingString", XMLChPtr(xercesc::XMLUni::fgEncodingString))
		    .setattr("fgEntitString", XMLChPtr(xercesc::XMLUni::fgEntitString))
		    .setattr("fgEntityString", XMLChPtr(xercesc::XMLUni::fgEntityString))
		    .setattr("fgEntitiesString", XMLChPtr(xercesc::XMLUni::fgEntitiesString))
		    .setattr("fgEnumerationString", XMLChPtr(xercesc::XMLUni::fgEnumerationString))
		    .setattr("fgExceptDomain", XMLChPtr(xercesc::XMLUni::fgExceptDomain))
		    .setattr("fgFixedString", XMLChPtr(xercesc::XMLUni::fgFixedString))
		    .setattr("fgIBM037EncodingString", XMLChPtr(xercesc::XMLUni::fgIBM037EncodingString))
		    .setattr("fgIBM037EncodingString2", XMLChPtr(xercesc::XMLUni::fgIBM037EncodingString2))
		    .setattr("fgIBM1047EncodingString", XMLChPtr(xercesc::XMLUni::fgIBM1047EncodingString))
		    .setattr("fgIBM1047EncodingString2", XMLChPtr(xercesc::XMLUni::fgIBM1047EncodingString2))
		    .setattr("fgIBM1140EncodingString", XMLChPtr(xercesc::XMLUni::fgIBM1140EncodingString))
		    .setattr("fgIBM1140EncodingString2", XMLChPtr(xercesc::XMLUni::fgIBM1140EncodingString2))
		    .setattr("fgIBM1140EncodingString3", XMLChPtr(xercesc::XMLUni::fgIBM1140EncodingString3))
		    .setattr("fgIBM1140EncodingString4", XMLChPtr(xercesc::XMLUni::fgIBM1140EncodingString4))
		    .setattr("fgIESString", XMLChPtr(xercesc::XMLUni::fgIESString))
		    .setattr("fgIDString", XMLChPtr(xercesc::XMLUni::fgIDString))
		    .setattr("fgIDRefString", XMLChPtr(xercesc::XMLUni::fgIDRefString))
		    .setattr("fgIDRefsString", XMLChPtr(xercesc::XMLUni::fgIDRefsString))
		    .setattr("fgImpliedString", XMLChPtr(xercesc::XMLUni::fgImpliedString))
		    .setattr("fgIgnoreString", XMLChPtr(xercesc::XMLUni::fgIgnoreString))
		    .setattr("fgIncludeString", XMLChPtr(xercesc::XMLUni::fgIncludeString))
		    .setattr("fgISO88591EncodingString", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString))
		    .setattr("fgISO88591EncodingString2", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString2))
		    .setattr("fgISO88591EncodingString3", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString3))
		    .setattr("fgISO88591EncodingString4", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString4))
		    .setattr("fgISO88591EncodingString5", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString5))
		    .setattr("fgISO88591EncodingString6", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString6))
		    .setattr("fgISO88591EncodingString7", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString7))
		    .setattr("fgISO88591EncodingString8", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString8))
		    .setattr("fgISO88591EncodingString9", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString9))
		    .setattr("fgISO88591EncodingString10", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString10))
		    .setattr("fgISO88591EncodingString11", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString11))
		    .setattr("fgISO88591EncodingString12", XMLChPtr(xercesc::XMLUni::fgISO88591EncodingString12))
		    .setattr("fgLocalHostString", XMLChPtr(xercesc::XMLUni::fgLocalHostString))
		    .setattr("fgNoString", XMLChPtr(xercesc::XMLUni::fgNoString))
		    .setattr("fgNotationString", XMLChPtr(xercesc::XMLUni::fgNotationString))
		    .setattr("fgNDATAString", XMLChPtr(xercesc::XMLUni::fgNDATAString))
		    .setattr("fgNmTokenString", XMLChPtr(xercesc::XMLUni::fgNmTokenString))
		    .setattr("fgNmTokensString", XMLChPtr(xercesc::XMLUni::fgNmTokensString))
		    .setattr("fgPCDATAString", XMLChPtr(xercesc::XMLUni::fgPCDATAString))
		    .setattr("fgPIString", XMLChPtr(xercesc::XMLUni::fgPIString))
		    .setattr("fgPubIDString", XMLChPtr(xercesc::XMLUni::fgPubIDString))
		    .setattr("fgRefString", XMLChPtr(xercesc::XMLUni::fgRefString))
		    .setattr("fgRequiredString", XMLChPtr(xercesc::XMLUni::fgRequiredString))
		    .setattr("fgStandaloneString", XMLChPtr(xercesc::XMLUni::fgStandaloneString))
		    .setattr("fgVersion1_0", XMLChPtr(xercesc::XMLUni::fgVersion1_0))
		    .setattr("fgVersion1_1", XMLChPtr(xercesc::XMLUni::fgVersion1_1))
		    .setattr("fgSysIDString", XMLChPtr(xercesc::XMLUni::fgSysIDString))
		    .setattr("fgUnknownURIName", XMLChPtr(xercesc::XMLUni::fgUnknownURIName))
		    .setattr("fgUCS4EncodingString", XMLChPtr(xercesc::XMLUni::fgUCS4EncodingString))
		    .setattr("fgUCS4EncodingString2", XMLChPtr(xercesc::XMLUni::fgUCS4EncodingString2))
		    .setattr("fgUCS4EncodingString3", XMLChPtr(xercesc::XMLUni::fgUCS4EncodingString3))
		    .setattr("fgUCS4EncodingString4", XMLChPtr(xercesc::XMLUni::fgUCS4EncodingString4))
		    .setattr("fgUCS4EncodingString5", XMLChPtr(xercesc::XMLUni::fgUCS4EncodingString5))
		    .setattr("fgUCS4BEncodingString", XMLChPtr(xercesc::XMLUni::fgUCS4BEncodingString))
		    .setattr("fgUCS4BEncodingString2", XMLChPtr(xercesc::XMLUni::fgUCS4BEncodingString2))
		    .setattr("fgUCS4LEncodingString", XMLChPtr(xercesc::XMLUni::fgUCS4LEncodingString))
		    .setattr("fgUCS4LEncodingString2", XMLChPtr(xercesc::XMLUni::fgUCS4LEncodingString2))
		    .setattr("fgUSASCIIEncodingString", XMLChPtr(xercesc::XMLUni::fgUSASCIIEncodingString))
		    .setattr("fgUSASCIIEncodingString2", XMLChPtr(xercesc::XMLUni::fgUSASCIIEncodingString2))
		    .setattr("fgUSASCIIEncodingString3", XMLChPtr(xercesc::XMLUni::fgUSASCIIEncodingString3))
		    .setattr("fgUSASCIIEncodingString4", XMLChPtr(xercesc::XMLUni::fgUSASCIIEncodingString4))
		    .setattr("fgUTF8EncodingString", XMLChPtr(xercesc::XMLUni::fgUTF8EncodingString))
		    .setattr("fgUTF8EncodingString2", XMLChPtr(xercesc::XMLUni::fgUTF8EncodingString2))
		    .setattr("fgUTF16EncodingString", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString))
		    .setattr("fgUTF16EncodingString2", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString2))
		    .setattr("fgUTF16EncodingString3", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString3))
		    .setattr("fgUTF16EncodingString4", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString4))
		    .setattr("fgUTF16EncodingString5", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString5))
		    .setattr("fgUTF16EncodingString6", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString6))
		    .setattr("fgUTF16EncodingString7", XMLChPtr(xercesc::XMLUni::fgUTF16EncodingString7))
		    .setattr("fgUTF16BEncodingString", XMLChPtr(xercesc::XMLUni::fgUTF16BEncodingString))
		    .setattr("fgUTF16BEncodingString2", XMLChPtr(xercesc::XMLUni::fgUTF16BEncodingString2))
		    .setattr("fgUTF16LEncodingString", XMLChPtr(xercesc::XMLUni::fgUTF16LEncodingString))
		    .setattr("fgUTF16LEncodingString2", XMLChPtr(xercesc::XMLUni::fgUTF16LEncodingString2))
		    .setattr("fgVersionString", XMLChPtr(xercesc::XMLUni::fgVersionString))
		    .setattr("fgValidityDomain", XMLChPtr(xercesc::XMLUni::fgValidityDomain))
		    .setattr("fgWin1252EncodingString", XMLChPtr(xercesc::XMLUni::fgWin1252EncodingString))
		    .setattr("fgXMLChEncodingString", XMLChPtr(xercesc::XMLUni::fgXMLChEncodingString))
		    .setattr("fgXMLDOMMsgDomain", XMLChPtr(xercesc::XMLUni::fgXMLDOMMsgDomain))
		    .setattr("fgXMLString", XMLChPtr(xercesc::XMLUni::fgXMLString))
		    .setattr("fgXMLStringSpace", XMLChPtr(xercesc::XMLUni::fgXMLStringSpace))
		    .setattr("fgXMLStringHTab", XMLChPtr(xercesc::XMLUni::fgXMLStringHTab))
		    .setattr("fgXMLStringCR", XMLChPtr(xercesc::XMLUni::fgXMLStringCR))
		    .setattr("fgXMLStringLF", XMLChPtr(xercesc::XMLUni::fgXMLStringLF))
		    .setattr("fgXMLStringSpaceU", XMLChPtr(xercesc::XMLUni::fgXMLStringSpaceU))
		    .setattr("fgXMLStringHTabU", XMLChPtr(xercesc::XMLUni::fgXMLStringHTabU))
		    .setattr("fgXMLStringCRU", XMLChPtr(xercesc::XMLUni::fgXMLStringCRU))
		    .setattr("fgXMLStringLFU", XMLChPtr(xercesc::XMLUni::fgXMLStringLFU))
		    .setattr("fgXMLDeclString", XMLChPtr(xercesc::XMLUni::fgXMLDeclString))
		    .setattr("fgXMLDeclStringSpace", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringSpace))
		    .setattr("fgXMLDeclStringHTab", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringHTab))
		    .setattr("fgXMLDeclStringLF", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringLF))
		    .setattr("fgXMLDeclStringCR", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringCR))
		    .setattr("fgXMLDeclStringSpaceU", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringSpaceU))
		    .setattr("fgXMLDeclStringHTabU", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringHTabU))
		    .setattr("fgXMLDeclStringLFU", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringLFU))
		    .setattr("fgXMLDeclStringCRU", XMLChPtr(xercesc::XMLUni::fgXMLDeclStringCRU))
		    .setattr("fgXMLNSString", XMLChPtr(xercesc::XMLUni::fgXMLNSString))
		    .setattr("fgXMLNSColonString", XMLChPtr(xercesc::XMLUni::fgXMLNSColonString))
		    .setattr("fgXMLNSURIName", XMLChPtr(xercesc::XMLUni::fgXMLNSURIName))
		    .setattr("fgXMLErrDomain", XMLChPtr(xercesc::XMLUni::fgXMLErrDomain))
		    .setattr("fgXMLURIName", XMLChPtr(xercesc::XMLUni::fgXMLURIName))
		    .setattr("fgInfosetURIName", XMLChPtr(xercesc::XMLUni::fgInfosetURIName))
		    .setattr("fgYesString", XMLChPtr(xercesc::XMLUni::fgYesString))
		    .setattr("fgZeroLenString", XMLChPtr(xercesc::XMLUni::fgZeroLenString))
		    .setattr("fgDTDEntityString", XMLChPtr(xercesc::XMLUni::fgDTDEntityString))
		    .setattr("fgAmp", XMLChPtr(xercesc::XMLUni::fgAmp))
		    .setattr("fgLT", XMLChPtr(xercesc::XMLUni::fgLT))
		    .setattr("fgGT", XMLChPtr(xercesc::XMLUni::fgGT))
		    .setattr("fgQuot", XMLChPtr(xercesc::XMLUni::fgQuot))
		    .setattr("fgApos", XMLChPtr(xercesc::XMLUni::fgApos))
		    .setattr("fgWFXMLScanner", XMLChPtr(xercesc::XMLUni::fgWFXMLScanner))
		    .setattr("fgIGXMLScanner", XMLChPtr(xercesc::XMLUni::fgIGXMLScanner))
		    .setattr("fgSGXMLScanner", XMLChPtr(xercesc::XMLUni::fgSGXMLScanner))
		    .setattr("fgDGXMLScanner", XMLChPtr(xercesc::XMLUni::fgDGXMLScanner))
		    .setattr("fgXSAXMLScanner", XMLChPtr(xercesc::XMLUni::fgXSAXMLScanner))
		    .setattr("fgCDataStart", XMLChPtr(xercesc::XMLUni::fgCDataStart))
		    .setattr("fgCDataEnd", XMLChPtr(xercesc::XMLUni::fgCDataEnd))

		    // Exception Name
		    .setattr("fgArrayIndexOutOfBoundsException_Name", XMLChPtr(xercesc::XMLUni::fgArrayIndexOutOfBoundsException_Name))
		    .setattr("fgEmptyStackException_Name", XMLChPtr(xercesc::XMLUni::fgEmptyStackException_Name))
		    .setattr("fgIllegalArgumentException_Name", XMLChPtr(xercesc::XMLUni::fgIllegalArgumentException_Name))
		    .setattr("fgInvalidCastException_Name", XMLChPtr(xercesc::XMLUni::fgInvalidCastException_Name))
		    .setattr("fgIOException_Name", XMLChPtr(xercesc::XMLUni::fgIOException_Name))
		    .setattr("fgNoSuchElementException_Name", XMLChPtr(xercesc::XMLUni::fgNoSuchElementException_Name))
		    .setattr("fgNullPointerException_Name", XMLChPtr(xercesc::XMLUni::fgNullPointerException_Name))
		    .setattr("fgXMLPlatformUtilsException_Name", XMLChPtr(xercesc::XMLUni::fgXMLPlatformUtilsException_Name))
		    .setattr("fgRuntimeException_Name", XMLChPtr(xercesc::XMLUni::fgRuntimeException_Name))
		    .setattr("fgTranscodingException_Name", XMLChPtr(xercesc::XMLUni::fgTranscodingException_Name))
		    .setattr("fgUnexpectedEOFException_Name", XMLChPtr(xercesc::XMLUni::fgUnexpectedEOFException_Name))
		    .setattr("fgUnsupportedEncodingException_Name", XMLChPtr(xercesc::XMLUni::fgUnsupportedEncodingException_Name))
		    .setattr("fgUnsupportedEncodingException_Name", XMLChPtr(xercesc::XMLUni::fgUTFDataFormatException_Name))
		    .setattr("fgNetAccessorException_Name", XMLChPtr(xercesc::XMLUni::fgNetAccessorException_Name))
		    .setattr("fgMalformedURLException_Name", XMLChPtr(xercesc::XMLUni::fgMalformedURLException_Name))
		    .setattr("fgNumberFormatException_Name", XMLChPtr(xercesc::XMLUni::fgNumberFormatException_Name))
		    .setattr("fgParseException_Name", XMLChPtr(xercesc::XMLUni::fgParseException_Name))
		    .setattr("fgInvalidDatatypeFacetException_Name", XMLChPtr(xercesc::XMLUni::fgInvalidDatatypeFacetException_Name))
		    .setattr("fgInvalidDatatypeValueException_Name", XMLChPtr(xercesc::XMLUni::fgInvalidDatatypeValueException_Name))
		    .setattr("fgSchemaDateTimeException_Name", XMLChPtr(xercesc::XMLUni::fgSchemaDateTimeException_Name))
		    .setattr("fgXPathException_Name", XMLChPtr(xercesc::XMLUni::fgXPathException_Name))
		    .setattr("fgXSerializationException_Name", XMLChPtr(xercesc::XMLUni::fgXSerializationException_Name))
		    .setattr("fgXMLXIncludeException_Name", XMLChPtr(xercesc::XMLUni::fgXMLXIncludeException_Name))

		    // Numerical String
		    .setattr("fgNegINFString", XMLChPtr(xercesc::XMLUni::fgNegINFString))
		    .setattr("fgNegZeroString", XMLChPtr(xercesc::XMLUni::fgNegZeroString))
		    .setattr("fgPosZeroString", XMLChPtr(xercesc::XMLUni::fgPosZeroString))
		    .setattr("fgPosINFString", XMLChPtr(xercesc::XMLUni::fgPosINFString))
		    .setattr("fgNaNString", XMLChPtr(xercesc::XMLUni::fgNaNString))
		    .setattr("fgEString", XMLChPtr(xercesc::XMLUni::fgEString))
		    .setattr("fgZeroString", XMLChPtr(xercesc::XMLUni::fgZeroString))
		    .setattr("fgNullString", XMLChPtr(xercesc::XMLUni::fgNullString))

		    // Xerces features/properties names
		    .setattr("fgXercesDynamic", XMLChPtr(xercesc::XMLUni::fgXercesDynamic))
		    .setattr("fgXercesSchema", XMLChPtr(xercesc::XMLUni::fgXercesSchema))
		    .setattr("fgXercesSchemaFullChecking", XMLChPtr(xercesc::XMLUni::fgXercesSchemaFullChecking))
		    .setattr("fgXercesLoadSchema", XMLChPtr(xercesc::XMLUni::fgXercesLoadSchema))
		    .setattr("fgXercesIdentityConstraintChecking", XMLChPtr(xercesc::XMLUni::fgXercesIdentityConstraintChecking))
		    .setattr("fgXercesSchemaExternalSchemaLocation", XMLChPtr(xercesc::XMLUni::fgXercesSchemaExternalSchemaLocation))
		    .setattr("fgXercesSchemaExternalNoNameSpaceSchemaLocation", XMLChPtr(xercesc::XMLUni::fgXercesSchemaExternalNoNameSpaceSchemaLocation))
		    .setattr("fgXercesSecurityManager", XMLChPtr(xercesc::XMLUni::fgXercesSecurityManager))
		    .setattr("fgXercesLoadExternalDTD", XMLChPtr(xercesc::XMLUni::fgXercesLoadExternalDTD))
		    .setattr("fgXercesContinueAfterFatalError", XMLChPtr(xercesc::XMLUni::fgXercesContinueAfterFatalError))
		    .setattr("fgXercesValidationErrorAsFatal", XMLChPtr(xercesc::XMLUni::fgXercesValidationErrorAsFatal))
		    .setattr("fgXercesUserAdoptsDOMDocument", XMLChPtr(xercesc::XMLUni::fgXercesUserAdoptsDOMDocument))
		    .setattr("fgXercesCacheGrammarFromParse", XMLChPtr(xercesc::XMLUni::fgXercesCacheGrammarFromParse))
		    .setattr("fgXercesCacheGrammarFromParse", XMLChPtr(xercesc::XMLUni::fgXercesUseCachedGrammarInParse))
		    .setattr("fgXercesScannerName", XMLChPtr(xercesc::XMLUni::fgXercesScannerName))
		    .setattr("fgXercesParserUseDocumentFromImplementation", XMLChPtr(xercesc::XMLUni::fgXercesParserUseDocumentFromImplementation))
		    .setattr("fgXercesCalculateSrcOfs", XMLChPtr(xercesc::XMLUni::fgXercesCalculateSrcOfs))
		    .setattr("fgXercesStandardUriConformant", XMLChPtr(xercesc::XMLUni::fgXercesStandardUriConformant))
		    .setattr("fgXercesDOMHasPSVIInfo", XMLChPtr(xercesc::XMLUni::fgXercesDOMHasPSVIInfo))
		    .setattr("fgXercesGenerateSyntheticAnnotations", XMLChPtr(xercesc::XMLUni::fgXercesGenerateSyntheticAnnotations))
		    .setattr("fgXercesValidateAnnotations", XMLChPtr(xercesc::XMLUni::fgXercesValidateAnnotations))
		    .setattr("fgXercesIgnoreCachedDTD", XMLChPtr(xercesc::XMLUni::fgXercesIgnoreCachedDTD))
		    .setattr("fgXercesIgnoreAnnotations", XMLChPtr(xercesc::XMLUni::fgXercesIgnoreAnnotations))
		    .setattr("fgXercesDisableDefaultEntityResolution", XMLChPtr(xercesc::XMLUni::fgXercesDisableDefaultEntityResolution))
		    .setattr("fgXercesSkipDTDValidation", XMLChPtr(xercesc::XMLUni::fgXercesSkipDTDValidation))
		    .setattr("fgXercesEntityResolver", XMLChPtr(xercesc::XMLUni::fgXercesEntityResolver))
		    .setattr("fgXercesHandleMultipleImports", XMLChPtr(xercesc::XMLUni::fgXercesHandleMultipleImports))
		    .setattr("fgXercesDoXInclude", XMLChPtr(xercesc::XMLUni::fgXercesDoXInclude))
		    .setattr("fgXercesLowWaterMark", XMLChPtr(xercesc::XMLUni::fgXercesLowWaterMark))

		    // SAX2 features/properties names
		    .setattr("fgSAX2CoreValidation", XMLChPtr(xercesc::XMLUni::fgSAX2CoreValidation))
		    .setattr("fgSAX2CoreNameSpaces", XMLChPtr(xercesc::XMLUni::fgSAX2CoreNameSpaces))
		    .setattr("fgSAX2CoreNameSpacePrefixes", XMLChPtr(xercesc::XMLUni::fgSAX2CoreNameSpacePrefixes))

		    // Introduced in DOM Level 3
		    // DOMLSParser features
		    .setattr("fgDOMCanonicalForm", XMLChPtr(xercesc::XMLUni::fgDOMCanonicalForm))
		    .setattr("fgDOMCDATASections", XMLChPtr(xercesc::XMLUni::fgDOMCDATASections))
		    .setattr("fgDOMComments", XMLChPtr(xercesc::XMLUni::fgDOMComments))
		    .setattr("fgDOMCharsetOverridesXMLEncoding", XMLChPtr(xercesc::XMLUni::fgDOMCharsetOverridesXMLEncoding))
		    .setattr("fgDOMCheckCharacterNormalization", XMLChPtr(xercesc::XMLUni::fgDOMCheckCharacterNormalization))
		    .setattr("fgDOMDatatypeNormalization", XMLChPtr(xercesc::XMLUni::fgDOMDatatypeNormalization))
		    .setattr("fgDOMDisallowDoctype", XMLChPtr(xercesc::XMLUni::fgDOMDisallowDoctype))
		    .setattr("fgDOMElementContentWhitespace", XMLChPtr(xercesc::XMLUni::fgDOMElementContentWhitespace))
		    .setattr("fgDOMErrorHandler", XMLChPtr(xercesc::XMLUni::fgDOMErrorHandler))
		    .setattr("fgDOMEntities", XMLChPtr(xercesc::XMLUni::fgDOMEntities))
		    .setattr("fgDOMIgnoreUnknownCharacterDenormalization", XMLChPtr(xercesc::XMLUni::fgDOMIgnoreUnknownCharacterDenormalization))
		    .setattr("fgDOMInfoset", XMLChPtr(xercesc::XMLUni::fgDOMInfoset))
		    .setattr("fgDOMNamespaces", XMLChPtr(xercesc::XMLUni::fgDOMNamespaces))
		    .setattr("fgDOMNamespaceDeclarations", XMLChPtr(xercesc::XMLUni::fgDOMNamespaceDeclarations))
		    .setattr("fgDOMNormalizeCharacters", XMLChPtr(xercesc::XMLUni::fgDOMNormalizeCharacters))
		    .setattr("fgDOMResourceResolver", XMLChPtr(xercesc::XMLUni::fgDOMResourceResolver))
		    .setattr("fgDOMSchemaLocation", XMLChPtr(xercesc::XMLUni::fgDOMSchemaLocation))
		    .setattr("fgDOMSchemaType", XMLChPtr(xercesc::XMLUni::fgDOMSchemaType))
		    .setattr("fgDOMSplitCDATASections", XMLChPtr(xercesc::XMLUni::fgDOMSplitCDATASections))
		    .setattr("fgDOMSupportedMediatypesOnly", XMLChPtr(xercesc::XMLUni::fgDOMSupportedMediatypesOnly))
		    .setattr("fgDOMValidate", XMLChPtr(xercesc::XMLUni::fgDOMValidate))
		    .setattr("fgDOMValidateIfSchema", XMLChPtr(xercesc::XMLUni::fgDOMValidateIfSchema))
		    .setattr("fgDOMWellFormed", XMLChPtr(xercesc::XMLUni::fgDOMWellFormed))

		    .setattr("fgDOMXMLSchemaType", XMLChPtr(xercesc::XMLUni::fgDOMXMLSchemaType))
		    .setattr("fgDOMDTDType", XMLChPtr(xercesc::XMLUni::fgDOMDTDType))

		    // Introduced in DOM Level 3
		    // DOMLSSerializer feature
		    .setattr("fgDOMWRTCanonicalForm", XMLChPtr(xercesc::XMLUni::fgDOMWRTCanonicalForm))
		    .setattr("fgDOMWRTDiscardDefaultContent", XMLChPtr(xercesc::XMLUni::fgDOMWRTDiscardDefaultContent))
		    .setattr("fgDOMWRTEntities", XMLChPtr(xercesc::XMLUni::fgDOMWRTEntities))
		    .setattr("fgDOMWRTFormatPrettyPrint", XMLChPtr(xercesc::XMLUni::fgDOMWRTFormatPrettyPrint))
		    .setattr("fgDOMWRTNormalizeCharacters", XMLChPtr(xercesc::XMLUni::fgDOMWRTNormalizeCharacters))
		    .setattr("fgDOMWRTSplitCdataSections", XMLChPtr(xercesc::XMLUni::fgDOMWRTSplitCdataSections))
		    .setattr("fgDOMWRTValidation", XMLChPtr(xercesc::XMLUni::fgDOMWRTValidation))
		    .setattr("fgDOMWRTWhitespaceInElementContent", XMLChPtr(xercesc::XMLUni::fgDOMWRTWhitespaceInElementContent))
		    .setattr("fgDOMWRTBOM", XMLChPtr(xercesc::XMLUni::fgDOMWRTBOM))
		    .setattr("fgDOMXMLDeclaration", XMLChPtr(xercesc::XMLUni::fgDOMXMLDeclaration))
		    .setattr("fgDOMWRTXercesPrettyPrint", XMLChPtr(xercesc::XMLUni::fgDOMWRTXercesPrettyPrint))

		    // Private interface names
		    .setattr("fgXercescInterfacePSVITypeInfo", XMLChPtr(xercesc::XMLUni::fgXercescInterfacePSVITypeInfo))
		    .setattr("fgXercescInterfaceDOMDocumentTypeImpl", XMLChPtr(xercesc::XMLUni::fgXercescInterfaceDOMDocumentTypeImpl))
		    .setattr("fgXercescInterfaceDOMDocumentImpl", XMLChPtr(xercesc::XMLUni::fgXercescInterfaceDOMDocumentImpl))
		    .setattr("fgXercescInterfaceDOMMemoryManager", XMLChPtr(xercesc::XMLUni::fgXercescInterfaceDOMMemoryManager))

		    // Locale
		    .setattr("fgXercescDefaultLocale", std::string(xercesc::XMLUni::fgXercescDefaultLocale))

		    // Default Exception String
		    .setattr("fgDefErrMsg", XMLChPtr(xercesc::XMLUni:: fgDefErrMsg))

		    // Datatype
		    .setattr("fgDefErrMsg", XMLChPtr(xercesc::XMLUni::fgValueZero))
		    .setattr("fgNegOne", XMLChPtr(xercesc::XMLUni::fgNegOne))
		    .setattr("fgValueOne", XMLChPtr(xercesc::XMLUni::fgValueOne))
		    .setattr("fgLongMaxInc", XMLChPtr(xercesc::XMLUni::fgLongMaxInc))
		    .setattr("fgLongMinInc", XMLChPtr(xercesc::XMLUni::fgLongMinInc))
		    .setattr("fgIntMaxInc", XMLChPtr(xercesc::XMLUni::fgIntMaxInc))
		    .setattr("fgIntMinInc", XMLChPtr(xercesc::XMLUni::fgIntMinInc))
		    .setattr("fgShortMaxInc", XMLChPtr(xercesc::XMLUni::fgShortMaxInc))
		    .setattr("fgShortMinInc", XMLChPtr(xercesc::XMLUni::fgShortMinInc))
		    .setattr("fgByteMaxInc", XMLChPtr(xercesc::XMLUni::fgByteMaxInc))
		    .setattr("fgByteMinInc", XMLChPtr(xercesc::XMLUni::fgByteMinInc))
		    .setattr("fgULongMaxInc", XMLChPtr(xercesc::XMLUni::fgULongMaxInc))
		    .setattr("fgUIntMaxInc", XMLChPtr(xercesc::XMLUni::fgUIntMaxInc))
		    .setattr("fgUShortMaxInc", XMLChPtr(xercesc::XMLUni::fgUShortMaxInc))
		    .setattr("fgUByteMaxInc", XMLChPtr(xercesc::XMLUni::fgUByteMaxInc))
		    .setattr("fgLangPattern", XMLChPtr(xercesc::XMLUni::fgLangPattern))
		    //.setattr("", XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[][8]))
		    .setattr("fgBooleanValueSpaceArraySize", xercesc::XMLUni::fgBooleanValueSpaceArraySize)
			;
	boost::python::list fgBooleanValueSpace;
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[0]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[1]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[2]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[3]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[4]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[5]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[6]));
	fgBooleanValueSpace.append(XMLChPtr(xercesc::XMLUni::fgBooleanValueSpace[7]));
	XMLUni.setattr("fgBooleanValueSpace", fgBooleanValueSpace);
}

} /* namespace pyxerces */