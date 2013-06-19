/*
 * XSNamedMap.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XSNamedMap.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/StringPool.hpp>

//! XSObject
#include <xercesc/framework/psvi/XSObject.hpp>

#include <xercesc/framework/psvi/XSNamedMap.hpp>

#include "../../util/XMLString.h"

namespace pyxerces {

template <typename TVal>
class XSNamedMapDefVisitor
: public boost::python::def_visitor<XSNamedMapDefVisitor<TVal> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("itemByName", &XSNamedMapDefVisitor<TVal>::itemByName, boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("addElement", &XSNamedMapDefVisitor<TVal>::addElement)
	;
}

TVal* itemByName(xercesc::XSNamedMap<TVal>& self, const XMLString& compNamespace, const XMLString& localName) {
	return self.itemByName(compNamespace.ptr(), localName.ptr());
}

void addElement(xercesc::XSNamedMap<TVal>& self, TVal* toAdd, const XMLString& key1, const XMLString& key2) {
	self.addElement(toAdd, key1.ptr(), key2.ptr());
}

};

template <typename NAME, typename TVal>
void XSNamedMap(void) {
	char pyName[10 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "XSNamedMap";
	//! xercesc::XSNamedMap
	boost::python::class_<xercesc::XSNamedMap<TVal>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, const XMLSize_t, xercesc::XMLStringPool*, const bool, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(XSNamedMapDefVisitor<TVal>())
			.def("getLength", &xercesc::XSNamedMap<TVal>::getLength)
			.def("item", static_cast<TVal*(xercesc::XSNamedMap<TVal>::*)(XMLSize_t)>(&xercesc::XSNamedMap<TVal>::item), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("itemByName", &xercesc::XSNamedMap<TVal>::itemByName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("addElement", &xercesc::XSNamedMap<TVal>::addElement)
			;
}

void XSNamedMap_init(void) {
	typedef boost::mpl::string<'XSOb', 'ject'> XSObjectStr;
	//! xercesc::XSNamedMap
	XSNamedMap<XSObjectStr, xercesc::XSObject>();
}

} /* namespace pyxerces */
