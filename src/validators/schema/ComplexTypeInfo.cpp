/*
 * ComplexTypeInfo.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "ComplexTypeInfo.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/validators/schema/SchemaAttDefList.hpp>
#include <xercesc/validators/schema/SchemaElementDecl.hpp>
#include <xercesc/validators/schema/XSDLocator.hpp>
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/validators/common/GrammarResolver.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>

#include <xercesc/validators/schema/ComplexTypeInfo.hpp>

#include "../../internal/XSerializable.h"

namespace pyxerces {

//! ComplexTypeInfo
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(ComplexTypeInfoGetContentModelOverloads, getContentModel, 0, 1)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(ComplexTypeInfoSetPreprocessedOverloads, setPreprocessed, 0, 1)

void ComplexTypeInfo_init(void) {
	//! xercesc::ComplexTypeInfo
	boost::python::class_<xercesc::ComplexTypeInfo, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("ComplexTypeInfo", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("getAbstract", &xercesc::ComplexTypeInfo::getAbstract)
			.def("getAdoptContentSpec", &xercesc::ComplexTypeInfo::getAdoptContentSpec)
			.def("containsAttWithTypeId", &xercesc::ComplexTypeInfo::containsAttWithTypeId)
			.def("getPreprocessed", &xercesc::ComplexTypeInfo::getPreprocessed)
			.def("getDerivedBy", &xercesc::ComplexTypeInfo::getDerivedBy)
			.def("getBlockSet", &xercesc::ComplexTypeInfo::getBlockSet)
			.def("getFinalSet", &xercesc::ComplexTypeInfo::getFinalSet)
			.def("getScopeDefined", &xercesc::ComplexTypeInfo::getScopeDefined)
			.def("getElementId", &xercesc::ComplexTypeInfo::getElementId)
			.def("getContentType", &xercesc::ComplexTypeInfo::getContentType)
			.def("elementCount", &xercesc::ComplexTypeInfo::elementCount)
			.def("getTypeName", &xercesc::ComplexTypeInfo::getTypeName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseDatatypeValidator", &xercesc::ComplexTypeInfo::getBaseDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getDatatypeValidator", &xercesc::ComplexTypeInfo::getDatatypeValidator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getBaseComplexTypeInfo", &xercesc::ComplexTypeInfo::getBaseComplexTypeInfo, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getContentSpec", &xercesc::ComplexTypeInfo::getContentSpec, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttWildCard", static_cast<xercesc::SchemaAttDef*(xercesc::ComplexTypeInfo::*)()>(&xercesc::ComplexTypeInfo::getAttWildCard), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttDef", static_cast<xercesc::SchemaAttDef*(xercesc::ComplexTypeInfo::*)(const XMLCh* const, const int)>(&xercesc::ComplexTypeInfo::getAttDef), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getAttDefList", &xercesc::ComplexTypeInfo::getAttDefList, boost::python::return_internal_reference<>())
			.def("elementAt", static_cast<xercesc::SchemaElementDecl*(xercesc::ComplexTypeInfo::*)(const XMLSize_t)>(&xercesc::ComplexTypeInfo::elementAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getContentModel", &xercesc::ComplexTypeInfo::getContentModel, ComplexTypeInfoGetContentModelOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("getFormattedContentModel", &xercesc::ComplexTypeInfo::getFormattedContentModel, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getLocator", &xercesc::ComplexTypeInfo::getLocator, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getTypeLocalName", &xercesc::ComplexTypeInfo::getTypeLocalName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTypeUri", &xercesc::ComplexTypeInfo::getTypeUri, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getAnonymous", &xercesc::ComplexTypeInfo::getAnonymous)
			.def("setAbstract", &xercesc::ComplexTypeInfo::setAbstract)
			.def("setAdoptContentSpec", &xercesc::ComplexTypeInfo::setAdoptContentSpec)
			.def("setAttWithTypeId", &xercesc::ComplexTypeInfo::setAttWithTypeId)
			.def("setPreprocessed", &xercesc::ComplexTypeInfo::setPreprocessed, ComplexTypeInfoSetPreprocessedOverloads())
			.def("setDerivedBy", &xercesc::ComplexTypeInfo::setDerivedBy)
			.def("setBlockSet", &xercesc::ComplexTypeInfo::setBlockSet)
			.def("setFinalSet", &xercesc::ComplexTypeInfo::setFinalSet)
			.def("setScopeDefined", &xercesc::ComplexTypeInfo::setScopeDefined)
			.def("setElementId", &xercesc::ComplexTypeInfo::setElementId)
			.def("setTypeName", &xercesc::ComplexTypeInfo::setTypeName)
			.def("setContentType", &xercesc::ComplexTypeInfo::setContentType)
			.def("setBaseDatatypeValidator", &xercesc::ComplexTypeInfo::setBaseDatatypeValidator)
			.def("setDatatypeValidator", &xercesc::ComplexTypeInfo::setDatatypeValidator)
			.def("setBaseComplexTypeInfo", &xercesc::ComplexTypeInfo::setBaseComplexTypeInfo)
			.def("setContentSpec", &xercesc::ComplexTypeInfo::setContentSpec)
			.def("setAttWildCard", &xercesc::ComplexTypeInfo::setAttWildCard)
			.def("addAttDef", &xercesc::ComplexTypeInfo::addAttDef)
			.def("addElement", &xercesc::ComplexTypeInfo::addElement)
			.def("setLocator", &xercesc::ComplexTypeInfo::setLocator)
			.def("setAnonymous", &xercesc::ComplexTypeInfo::setAnonymous)
			.def("hasAttDefs", &xercesc::ComplexTypeInfo::hasAttDefs)
			.def("contains", &xercesc::ComplexTypeInfo::contains)
			.def("checkUniqueParticleAttribution", &xercesc::ComplexTypeInfo::checkUniqueParticleAttribution)
			.def("getAnyType", &xercesc::ComplexTypeInfo::getAnyType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.staticmethod("getAnyType")
			PyDECL_XSERIALIZABLE(ComplexTypeInfo)
			;
}

} /* namespace pyxerces */
