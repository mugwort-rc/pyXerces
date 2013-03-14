/*
 * RefHashTableOf.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "RefHashTableOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! XMLAttDef
#include <xercesc/framework/XMLAttDef.hpp>
//! XMLRefInfo
#include <xercesc/framework/XMLRefInfo.hpp>
//! XSAnnotation
#include <xercesc/framework/psvi/XSAnnotation.hpp>
//! KVStringPair
#include <xercesc/util/KVStringPair.hpp>
//! Grammar
#include <xercesc/validators/common/Grammar.hpp>
//! ComplexTypeInfo
#include <xercesc/validators/schema/ComplexTypeInfo.hpp>
//! XercesAttGroupInfo
#include <xercesc/validators/schema/XercesAttGroupInfo.hpp>
//! XercesGroupInfo
#include <xercesc/validators/schema/XercesGroupInfo.hpp>

#include <xercesc/util/RefHashTableOf.hpp>

namespace pyxerces {

template <typename NAME, typename TVal, typename THasher = xercesc::StringHasher>
void RefHashTableOf(void) {
	char pyName[14 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefHashTableOf";
	//! xercesc::RefHashTableOf
	boost::python::class_<xercesc::RefHashTableOf<TVal, THasher>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const THasher&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, const THasher&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("isEmpty", &xercesc::RefHashTableOf<TVal, THasher>::isEmpty)
			.def("containsKey", &xercesc::RefHashTableOf<TVal, THasher>::containsKey)
			.def("removeKey", &xercesc::RefHashTableOf<TVal, THasher>::removeKey)
			.def("removeAll", &xercesc::RefHashTableOf<TVal, THasher>::removeAll)
			.def("cleanup", &xercesc::RefHashTableOf<TVal, THasher>::cleanup)
			.def("reinitialize", &xercesc::RefHashTableOf<TVal, THasher>::reinitialize)
			.def("transferElement", &xercesc::RefHashTableOf<TVal, THasher>::transferElement)
			.def("orphanKey", &xercesc::RefHashTableOf<TVal, THasher>::orphanKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("get", static_cast<TVal*(xercesc::RefHashTableOf<TVal, THasher>::*)(const void* const key)>(&xercesc::RefHashTableOf<TVal, THasher>::get), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::RefHashTableOf<TVal, THasher>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getHashModulus", &xercesc::RefHashTableOf<TVal, THasher>::getHashModulus)
			.def("getCount", &xercesc::RefHashTableOf<TVal, THasher>::getCount)
			.def("setAdoptElements", &xercesc::RefHashTableOf<TVal, THasher>::setAdoptElements)
			.def("put", &xercesc::RefHashTableOf<TVal, THasher>::put)
			;
}

template <typename NAME, typename TVal, typename THasher = xercesc::StringHasher>
void RefHashTableOfEnumerator(void) {
	char pyName[24 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefHashTableOfEnumerator";
	//! xercesc::RefHashTableOfEnumerator
	boost::python::class_<xercesc::RefHashTableOfEnumerator<TVal, THasher>, boost::python::bases<xercesc::XMLEnumerator<TVal> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<xercesc::RefHashTableOf<TVal, THasher>* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("hasMoreElements", &xercesc::RefHashTableOfEnumerator<TVal, THasher>::hasMoreElements)
			.def("nextElement", &xercesc::RefHashTableOfEnumerator<TVal, THasher>::nextElement, boost::python::return_internal_reference<>())
			.def("Reset", &xercesc::RefHashTableOfEnumerator<TVal, THasher>::Reset)
			.def("nextElementKey", &xercesc::RefHashTableOfEnumerator<TVal, THasher>::nextElementKey, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			;
}

//! for XMLCh
void RefHashTableOfXMLCh(void) {
	//! xercesc::RefHashTableOf
	boost::python::class_<xercesc::RefHashTableOf<XMLCh>, boost::noncopyable>("RefHashTableOfXMLCh", boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const XMLCh&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, const xercesc::StringHasher&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("isEmpty", &xercesc::RefHashTableOf<XMLCh>::isEmpty)
			.def("containsKey", &xercesc::RefHashTableOf<XMLCh>::containsKey)
			.def("removeKey", &xercesc::RefHashTableOf<XMLCh>::removeKey)
			.def("removeAll", &xercesc::RefHashTableOf<XMLCh>::removeAll)
			.def("cleanup", &xercesc::RefHashTableOf<XMLCh>::cleanup)
			.def("reinitialize", &xercesc::RefHashTableOf<XMLCh>::reinitialize)
			.def("transferElement", &xercesc::RefHashTableOf<XMLCh>::transferElement)
			.def("orphanKey", &xercesc::RefHashTableOf<XMLCh>::orphanKey, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("get", static_cast<const XMLCh*(xercesc::RefHashTableOf<XMLCh>::*)(const void* const key) const>(&xercesc::RefHashTableOf<XMLCh>::get), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::RefHashTableOf<XMLCh>::getMemoryManager, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getHashModulus", &xercesc::RefHashTableOf<XMLCh>::getHashModulus)
			.def("getCount", &xercesc::RefHashTableOf<XMLCh>::getCount)
			.def("setAdoptElements", &xercesc::RefHashTableOf<XMLCh>::setAdoptElements)
			.def("put", &xercesc::RefHashTableOf<XMLCh>::put)
			;
}

void RefHashTableOf_init(void) {
	typedef boost::mpl::string<'XMLA', 'ttDe', 'f'> XMLAttDefStr;
	typedef boost::mpl::string<'XMLR', 'efIn', 'fo'> XMLRefInfoStr;
	typedef boost::mpl::string<'XSAn', 'nota', 'tion'> XSAnnotationStr;
	typedef boost::mpl::string<'KVSt', 'ring', 'Pair'> KVStringPairStr;
	typedef boost::mpl::string<'Gram', 'mar'> GrammarStr;
	typedef boost::mpl::string<'Comp', 'lexT', 'ypeI', 'nfo'> ComplexTypeInfoStr;
	typedef boost::mpl::string<'Xerc', 'esAt', 'tGro', 'upIn', 'fo'> XercesAttGroupInfoStr;
	typedef boost::mpl::string<'Xerc', 'esGr', 'oupI', 'nfo'> XercesGroupInfoStr;
	//! xercesc::RefHashTableOf
	RefHashTableOf<XMLAttDefStr, xercesc::XMLAttDef>();
	RefHashTableOf<XMLRefInfoStr, xercesc::XMLRefInfo>();
	RefHashTableOf<XSAnnotationStr, xercesc::XSAnnotation, xercesc::PtrHasher>();
	RefHashTableOf<KVStringPairStr, xercesc::KVStringPair>();
	RefHashTableOf<GrammarStr, xercesc::Grammar>();
	RefHashTableOf<ComplexTypeInfoStr, xercesc::ComplexTypeInfo>();
	RefHashTableOf<XercesAttGroupInfoStr, xercesc::XercesAttGroupInfo>();
	RefHashTableOf<XercesGroupInfoStr, xercesc::XercesGroupInfo>();
	//! XMLCh
	RefHashTableOfXMLCh();

	//! xercesc::RefHashTableOfEnumerator
	RefHashTableOfEnumerator<GrammarStr, xercesc::Grammar>();
}

} /* namespace pyxerces */
