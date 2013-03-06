/*
 * RefHash3KeysIdPool.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "RefHash3KeysIdPool.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! SchemaElementDecl
#include <xercesc/validators/schema/SchemaElementDecl.hpp>

#include <xercesc/util/RefHash3KeysIdPool.hpp>

namespace pyxerces {

template <typename NAME, typename TVal, typename THasher = xercesc::StringHasher>
void RefHash3KeysIdPool(void) {
	char pyName[18 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefHash3KeysIdPool";
	//! xercesc::RefHash3KeysIdPool
	boost::python::class_<xercesc::RefHash3KeysIdPool<TVal>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<const XMLSize_t, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const THasher&, boost::python::optional<const XMLSize_t, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, boost::python::optional<const XMLSize_t, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, const THasher&, boost::python::optional<const XMLSize_t, xercesc::MemoryManager* const> >())
			.def("isEmpty", &xercesc::RefHash3KeysIdPool<TVal, THasher>::isEmpty)
			.def("containsKey", &xercesc::RefHash3KeysIdPool<TVal, THasher>::containsKey)
			.def("removeAll", &xercesc::RefHash3KeysIdPool<TVal, THasher>::removeAll)
			.def("getByKey", static_cast<TVal*(xercesc::RefHash3KeysIdPool<TVal, THasher>::*)(const void* const, const int, const int)>(&xercesc::RefHash3KeysIdPool<TVal, THasher>::getByKey), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getById", static_cast<TVal*(xercesc::RefHash3KeysIdPool<TVal, THasher>::*)(const unsigned int)>(&xercesc::RefHash3KeysIdPool<TVal, THasher>::getById), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::RefHash3KeysIdPool<TVal, THasher>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getHashModulus", &xercesc::RefHash3KeysIdPool<TVal, THasher>::getHashModulus)
			.def("put", &xercesc::RefHash3KeysIdPool<TVal, THasher>::put)
			;
}

template <typename NAME, typename TVal, typename THasher = xercesc::StringHasher>
void RefHash3KeysIdPoolEnumerator(void) {
	char pyName[28 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefHash3KeysIdPoolEnumerator";
	//! xercesc::RefHash3KeysIdPoolEnumerator
	boost::python::class_<xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>, boost::python::bases<xercesc::XMLEnumerator<TVal> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<xercesc::RefHash3KeysIdPool<TVal, THasher>* const, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("hasMoreElements", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::hasMoreElements)
			.def("nextElement", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::nextElement, boost::python::return_internal_reference<>())
			.def("Reset", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::Reset)
			.def("size", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::size)
			.def("resetKey", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::resetKey)
			.def("nextElementKey", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::nextElementKey)
			.def("hasMoreKeys", &xercesc::RefHash3KeysIdPoolEnumerator<TVal, THasher>::hasMoreKeys)
			;
}

void RefHash3KeysIdPool_init(void) {
	typedef boost::mpl::string<'Sche', 'maEl', 'emen', 'tDec', 'l'> SchemaElementDeclStr;
	//! xercesc::RefHash3KeysIdPool
	RefHash3KeysIdPool<SchemaElementDeclStr, xercesc::SchemaElementDecl>();
}

} /* namespace pyxerces */
