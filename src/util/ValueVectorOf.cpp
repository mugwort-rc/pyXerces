/*
 * ValueVectorOf.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "ValueVectorOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! SchemaElementDecl
#include <xercesc/validators/schema/SchemaElementDecl.hpp>

#include <xercesc/util/ValueVectorOf.hpp>

namespace pyxerces {

//! ValueVectorOf
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(ValueVectorOfContainsElemntOverloads, containsElement, 1, 2)

template <typename NAME, typename TElem>
void ValueVectorOf(void) {
	char pyName[13 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueVectorOf";
	//! xercesc::ValueVectorOf
	boost::python::class_<xercesc::ValueVectorOf<TElem> >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def("addElement", &xercesc::ValueVectorOf<TElem>::addElement)
			.def("setElementAt", &xercesc::ValueVectorOf<TElem>::setElementAt)
			.def("insertElementAt", &xercesc::ValueVectorOf<TElem>::insertElementAt)
			.def("removeElementAt", &xercesc::ValueVectorOf<TElem>::removeElementAt)
			.def("removeAllElements", &xercesc::ValueVectorOf<TElem>::removeAllElements)
			.def("containsElement", &xercesc::ValueVectorOf<TElem>::containsElement, ValueVectorOfContainsElemntOverloads())
			.def("elementAt", static_cast<TElem&(xercesc::ValueVectorOf<TElem>::*)(const XMLSize_t)>(&xercesc::ValueVectorOf<TElem>::elementAt), boost::python::return_internal_reference<>())
			.def("curCapacity", &xercesc::ValueVectorOf<TElem>::curCapacity)
			.def("size", &xercesc::ValueVectorOf<TElem>::size)
			.def("getMemoryManager", &xercesc::ValueVectorOf<TElem>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("ensureExtraCapacity", &xercesc::ValueVectorOf<TElem>::ensureExtraCapacity)
			.def("rawData", &xercesc::ValueVectorOf<TElem>::rawData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

template <typename TElem>
class ValueVectorOfBasicTypeDefVisitor
: public boost::python::def_visitor<ValueVectorOfBasicTypeDefVisitor<TElem> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("elementAt", &ValueVectorOfBasicTypeDefVisitor<TElem>::elementAt)
	.def("rawData", &ValueVectorOfBasicTypeDefVisitor<TElem>::rawData)
	;
}

static TElem elementAt(xercesc::ValueVectorOf<TElem>& self, const XMLSize_t getAt) {
	return self.elementAt(getAt);
}

static TElem rawData(xercesc::ValueVectorOf<TElem>& self) {
	return *self.rawData();
}

};

template <typename NAME, typename TElem>
void ValueVectorOfBasicType(void) {
	char pyName[13 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueVectorOf";
	//! xercesc::ValueVectorOf
	boost::python::class_<xercesc::ValueVectorOf<TElem> >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def(ValueVectorOfBasicTypeDefVisitor<TElem>())
			.def("addElement", &xercesc::ValueVectorOf<TElem>::addElement)
			.def("setElementAt", &xercesc::ValueVectorOf<TElem>::setElementAt)
			.def("insertElementAt", &xercesc::ValueVectorOf<TElem>::insertElementAt)
			.def("removeElementAt", &xercesc::ValueVectorOf<TElem>::removeElementAt)
			.def("removeAllElements", &xercesc::ValueVectorOf<TElem>::removeAllElements)
			.def("containsElement", &xercesc::ValueVectorOf<TElem>::containsElement, ValueVectorOfContainsElemntOverloads())
			//.def("elementAt", static_cast<TElem&(xercesc::ValueVectorOf<TElem>::*)(const XMLSize_t)>(&xercesc::ValueVectorOf<TElem>::elementAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("curCapacity", &xercesc::ValueVectorOf<TElem>::curCapacity)
			.def("size", &xercesc::ValueVectorOf<TElem>::size)
			.def("getMemoryManager", &xercesc::ValueVectorOf<TElem>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("ensureExtraCapacity", &xercesc::ValueVectorOf<TElem>::ensureExtraCapacity)
			//.def("rawData", &xercesc::ValueVectorOf<TElem>::rawData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

template <typename TElem>
class ValueVectorOfPointerDefVisitor
: public boost::python::def_visitor<ValueVectorOfPointerDefVisitor<TElem> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("elementAt", &ValueVectorOfPointerDefVisitor<TElem>::elementAt, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("rawData", &ValueVectorOfPointerDefVisitor<TElem>::rawData, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static TElem elementAt(xercesc::ValueVectorOf<TElem>& self, const XMLSize_t getAt) {
	return self.elementAt(getAt);
}

static TElem rawData(xercesc::ValueVectorOf<TElem>& self) {
	return *self.rawData();
}

};

template <typename NAME, typename TElem>
void ValueVectorOfPointer(void) {
	char pyName[13 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueVectorOf";
	//! xercesc::ValueVectorOf
	boost::python::class_<xercesc::ValueVectorOf<TElem> >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def(ValueVectorOfPointerDefVisitor<TElem>())
			.def("addElement", &xercesc::ValueVectorOf<TElem>::addElement)
			.def("setElementAt", &xercesc::ValueVectorOf<TElem>::setElementAt)
			.def("insertElementAt", &xercesc::ValueVectorOf<TElem>::insertElementAt)
			.def("removeElementAt", &xercesc::ValueVectorOf<TElem>::removeElementAt)
			.def("removeAllElements", &xercesc::ValueVectorOf<TElem>::removeAllElements)
			.def("containsElement", &xercesc::ValueVectorOf<TElem>::containsElement, ValueVectorOfContainsElemntOverloads())
			//.def("elementAt", static_cast<TElem&(xercesc::ValueVectorOf<TElem>::*)(const XMLSize_t)>(&xercesc::ValueVectorOf<TElem>::elementAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("curCapacity", &xercesc::ValueVectorOf<TElem>::curCapacity)
			.def("size", &xercesc::ValueVectorOf<TElem>::size)
			.def("getMemoryManager", &xercesc::ValueVectorOf<TElem>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("ensureExtraCapacity", &xercesc::ValueVectorOf<TElem>::ensureExtraCapacity)
			//.def("rawData", &xercesc::ValueVectorOf<TElem>::rawData, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

void ValueVectorOf_init(void) {
	//! xercesc::ValueVectorOf
	typedef boost::mpl::string<'Unsi', 'gned', 'Int'> UnsignedIntStr;
	typedef boost::mpl::string<'Sche', 'maEl', 'emen', 'tDec', 'lPoi', 'nter'> SchemaElementDeclStr;
	ValueVectorOfBasicType<UnsignedIntStr, unsigned int>();
	ValueVectorOfPointer<SchemaElementDeclStr, xercesc::SchemaElementDecl*>();
}

} /* namespace pyxerces */
