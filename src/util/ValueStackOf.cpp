/*
 * ValueStackOf.cpp
 *
 *  Created on: 2013/03/11
 *      Author: mugwort_rc
 */

#include "ValueStackOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>
#include <xercesc/util/ValueStackOf.hpp>

namespace pyxerces {

// ------------------------------------------------------
//! for class

template <typename NAME, typename TElem>
void ValueStackOf(void) {
	char pyName[12 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueStackOf";
	//! xercesc::ValueStackOf
	boost::python::class_<xercesc::ValueStackOf<TElem>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def("push", &xercesc::ValueStackOf<TElem>::push)
			.def("peek", &xercesc::ValueStackOf<TElem>::peek, boost::python::return_internal_reference<>())
			.def("pop", &xercesc::ValueStackOf<TElem>::pop)
			.def("removeAllElements", &xercesc::ValueStackOf<TElem>::removeAllElements)
			.def("empty", &xercesc::ValueStackOf<TElem>::empty)
			.def("curCapacity", &xercesc::ValueStackOf<TElem>::curCapacity)
			.def("size", &xercesc::ValueStackOf<TElem>::size)
			;
}

// ------------------------------------------------------
//! for basic type

template <typename TElem>
class ValueStackOfBasicTypeDefVisitor
: public boost::python::def_visitor<ValueStackOfBasicTypeDefVisitor<TElem> >
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("peek", &ValueStackOfBasicTypeDefVisitor<TElem>::peek)
	;
}

static TElem peek(xercesc::ValueStackOf<TElem>& self) {
	return self.peek();
}
};

template <typename NAME, typename TElem>
void ValueStackOfBasicType(void) {
	char pyName[12 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueStackOf";
	//! xercesc::ValueStackOf
	boost::python::class_<xercesc::ValueStackOf<TElem>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def(ValueStackOfBasicTypeDefVisitor<TElem>())
			.def("push", &xercesc::ValueStackOf<TElem>::push)
			//.def("peek", &xercesc::ValueStackOf<TElem>::peek, boost::python::return_internal_reference<>())
			.def("pop", &xercesc::ValueStackOf<TElem>::pop)
			.def("removeAllElements", &xercesc::ValueStackOf<TElem>::removeAllElements)
			.def("empty", &xercesc::ValueStackOf<TElem>::empty)
			.def("curCapacity", &xercesc::ValueStackOf<TElem>::curCapacity)
			.def("size", &xercesc::ValueStackOf<TElem>::size)
			;
}

// ------------------------------------------------------
//! for PyObject

class ValueStackOfPyObjectDefVisitor
: public boost::python::def_visitor<ValueStackOfPyObjectDefVisitor>
{
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("peek", &ValueStackOfPyObjectDefVisitor::peek)
	;
}

static boost::python::object peek(xercesc::ValueStackOf<PyObject>& self) {
	PyObject* ptr = const_cast<PyObject*>(&self.peek());
	boost::python::handle<> handle(boost::python::borrowed<>(ptr));
	return boost::python::object(handle);
}

};

void ValueStackOfPyObject(void) {
	//! xercesc::ValueStackOf<PyObject>
	boost::python::class_<xercesc::ValueStackOf<PyObject>, boost::noncopyable>("ValueStackOfPyObject", boost::python::init<const XMLSize_t, boost::python::optional<xercesc::MemoryManager* const, const bool> >())
			.def(ValueStackOfPyObjectDefVisitor())
			.def("push", &xercesc::ValueStackOf<PyObject>::push)
			//.def("peek", &xercesc::ValueStackOf<PyObject>::peek, boost::python::return_internal_reference<>())
			.def("pop", &xercesc::ValueStackOf<PyObject>::pop)
			.def("removeAllElements", &xercesc::ValueStackOf<PyObject>::removeAllElements)
			.def("empty", &xercesc::ValueStackOf<PyObject>::empty)
			.def("curCapacity", &xercesc::ValueStackOf<PyObject>::curCapacity)
			.def("size", &xercesc::ValueStackOf<PyObject>::size)
			;
}

// ------------------------------------------------------
//! enumerator

template <typename NAME, typename TElem>
void ValueStackEnumerator(void) {
	char pyName[20 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "ValueStackEnumerator";
	//! xercesc::ValueStackEnumerator
	boost::python::class_<xercesc::ValueStackEnumerator<TElem>, boost::noncopyable, boost::python::bases<xercesc::XMLEnumerator<TElem> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<xercesc::ValueStackOf<TElem>* const, boost::python::optional<const bool> >())
			.def("hasMoreElements", &xercesc::ValueStackEnumerator<TElem>::hasMoreElements)
			.def("nextElement", &xercesc::ValueStackEnumerator<TElem>::nextElement, boost::python::return_internal_reference<>())
			.def("Reset", &xercesc::ValueStackEnumerator<TElem>::Reset)
			;
}

// ------------------------------------------------------

void ValueStackOf_init(void) {
	typedef boost::mpl::string<'Bool'> ValueStackOfBool;
	//! xercesc::ValueStackOf
	ValueStackOfBasicType<ValueStackOfBool, bool>();
	//! PyObject
	ValueStackOfPyObject();
	//! xercesc::ValueStackEnumerator
}

} /* namespace pyxerces */
