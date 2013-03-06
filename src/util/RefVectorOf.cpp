/*
 * RefVectorOf.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "RefVectorOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! XSAnnotation
#include <xercesc/framework/psvi/XSAnnotation.hpp>
//! XSAttributeUse
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
//! XSFacet
#include <xercesc/framework/psvi/XSFacet.hpp>
//! XSMultiValueFacet
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
//! XSNamespaceItem
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
//! XSParticle
#include <xercesc/framework/psvi/XSParticle.hpp>
//! XSSimpleTypeDefinition
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
//! XercesLocationPath
#include <xercesc/validators/schema/identity/XercesXPath.hpp>

#include <xercesc/util/RefVectorOf.hpp>

namespace pyxerces {

template <typename NAME, typename TElem>
void RefVectorOf(void) {
	char pyName[11 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefVectorOf";
	//! xercesc::RefVectorOf
	boost::python::class_<xercesc::RefVectorOf<TElem>, boost::noncopyable, boost::python::bases<xercesc::BaseRefVectorOf<TElem> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			;
}

void RefVectorOf_init(void) {
	typedef boost::mpl::string<'XSAn', 'nota', 'tion'> XSAnnotationStr;
	typedef boost::mpl::string<'XSAt', 'trib', 'uteU', 'se'> XSAttributeUseStr;
	typedef boost::mpl::string<'XSFa', 'cet'> XSFacetStr;
	typedef boost::mpl::string<'XSMu', 'ltiV', 'alue', 'Face', 't'> XSMultiValueFacetStr;
	typedef boost::mpl::string<'XSNa', 'mesp', 'aceI', 'tem'> XSNamespaceItemStr;
	typedef boost::mpl::string<'XSPa', 'rtic', 'le'> XSParticleStr;
	typedef boost::mpl::string<'XSSi', 'mple', 'Type', 'Defi', 'niti', 'on'> XSSimpleTypeDefinitionStr;
	typedef boost::mpl::string<'Xerc', 'esLo', 'cati', 'onPa', 'th'> XercesLocationPathStr;
	//! xercesc::RefVectorOf
	RefVectorOf<XSAnnotationStr, xercesc::XSAnnotation>();
	RefVectorOf<XSAttributeUseStr, xercesc::XSAttributeUse>();
	RefVectorOf<XSFacetStr, xercesc::XSFacet>();
	RefVectorOf<XSMultiValueFacetStr, xercesc::XSMultiValueFacet>();
	RefVectorOf<XSNamespaceItemStr, xercesc::XSNamespaceItem>();
	RefVectorOf<XSParticleStr, xercesc::XSParticle>();
	RefVectorOf<XSSimpleTypeDefinitionStr, xercesc::XSSimpleTypeDefinition>();
	RefVectorOf<XercesLocationPathStr, xercesc::XercesLocationPath>();
}

} /* namespace pyxerces */
