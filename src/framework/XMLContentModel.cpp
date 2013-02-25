/*
 * XMLContentModel.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLContentModel.h"

#include <boost/python.hpp>
#include <xercesc/validators/common/ContentLeafNameTypeVector.hpp>		//!< for forward declaration
#include <xercesc/validators/common/GrammarResolver.hpp>				//!< for forward declaration
#include <xercesc/util/StringPool.hpp>									//!< for forward declaration
#include <xercesc/framework/XMLValidator.hpp>							//!< for forward declaration
#include <xercesc/validators/schema/SchemaGrammar.hpp>					//!< for forward declaration
#include <xercesc/validators/schema/SubstitutionGroupComparator.hpp>	//!< for forward declaration
#include <xercesc/framework/XMLContentModel.hpp>

namespace pyxerces {

//! XMLContentModel
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLContentModelValidateContentOverloads, validateContent, 4, 5)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLContentModelValidateContentSpecialOverloads, validateContentSpecial, 6, 7)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLContentModelCheckUniqueParticleAttributionOverloads, checkUniqueParticleAttribution, 5, 6)

void XMLContentModel_init(void) {
	//! xercesc::XMLContentModel
	boost::python::class_<xercesc::XMLContentModel, boost::noncopyable>("XMLContentModel", boost::python::no_init)
			.def("validateContent", &xercesc::XMLContentModel::validateContent, XMLContentModelValidateContentOverloads())
			.def("validateContentSpecial", &xercesc::XMLContentModel::validateContentSpecial, XMLContentModelValidateContentSpecialOverloads())
			.def("checkUniqueParticleAttribution", &xercesc::XMLContentModel::checkUniqueParticleAttribution, XMLContentModelCheckUniqueParticleAttributionOverloads())
			.def("getContentLeafNameTypeVector", &xercesc::XMLContentModel::getContentLeafNameTypeVector, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextState", &xercesc::XMLContentModel::getNextState)
			.def("handleRepetitions", &xercesc::XMLContentModel::handleRepetitions)
			.def_readonly("gInvalidTrans", &xercesc::XMLContentModel::gInvalidTrans)
			.def_readonly("gEOCFakeId", &xercesc::XMLContentModel::gEOCFakeId)
			.def_readonly("gEpsilonFakeId", &xercesc::XMLContentModel::gEpsilonFakeId)
			;
}

} /* namespace pyxerces */
