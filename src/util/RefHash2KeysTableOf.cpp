/*
 * RefHash2KeysTableOf.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "RefHash2KeysTableOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! ElemVector
#include <xercesc/validators/schema/SchemaGrammar.hpp>

#include <xercesc/util/RefHash2KeysTableOf.hpp>

namespace pyxerces {

template <typename NAME, class TVal, class THasher = xercesc::StringHasher>
void RefHash2KeysTableOf(void) {
	char pyName[9 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefHash2KeysTableOf";
	//! xercesc::RefHash2KeysTableOf
	boost::python::class_<xercesc::RefHash2KeysTableOf<TVal, THasher>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const THasher&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLSize_t, const bool, const THasher&, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("isEmpty", &xercesc::RefHash2KeysTableOf<TVal, THasher>::isEmpty)
			.def("containsKey", &xercesc::RefHash2KeysTableOf<TVal, THasher>::containsKey)
			.def("removeKey", static_cast<void(xercesc::RefHash2KeysTableOf<TVal, THasher>::*)(const void* const, const int)>(&xercesc::RefHash2KeysTableOf<TVal, THasher>::removeKey))
			.def("removeKey", static_cast<void(xercesc::RefHash2KeysTableOf<TVal, THasher>::*)(const void* const)>(&xercesc::RefHash2KeysTableOf<TVal, THasher>::removeKey))
			.def("removeAll", &xercesc::RefHash2KeysTableOf<TVal, THasher>::removeAll)
			.def("transferElement", &xercesc::RefHash2KeysTableOf<TVal, THasher>::transferElement)
			.def("get", static_cast<TVal*(xercesc::RefHash2KeysTableOf<TVal, THasher>::*)(const void* const, const int)>(&xercesc::RefHash2KeysTableOf<TVal, THasher>::get), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::RefHash2KeysTableOf<TVal, THasher>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getHashModulus", &xercesc::RefHash2KeysTableOf<TVal, THasher>::getHashModulus)
			.def("put", &xercesc::RefHash2KeysTableOf<TVal, THasher>::put)
			;

}

void RefHash2KeysTableOf_init(void) {
	typedef boost::mpl::string<'Elem', 'Vect', 'or'> ElemVectorStr;
	//! xercesc::RefHash2KeysTableOf
	RefHash2KeysTableOf<ElemVectorStr, xercesc::ElemVector>();
}

} /* namespace pyxerces */
