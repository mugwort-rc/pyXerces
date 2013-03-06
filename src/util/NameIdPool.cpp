/*
 * NameIdPool.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "NameIdPool.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>
#include <xercesc/framework/XMLNotationDecl.hpp>

#include <xercesc/util/NameIdPool.hpp>

#include "XMLString.h"

namespace pyxerces {

template <typename TElem, class STR>
class NameIdPoolDefVisitor
: public boost::python::def_visitor<NameIdPoolDefVisitor<TElem, STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("containsKey", &NameIdPoolDefVisitor<TElem, STR>::containsKey)
	.def("getByKey", &NameIdPoolDefVisitor<TElem, STR>::getByKey, boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static bool containsKey(xercesc::NameIdPool<TElem>& self, const STR& key) {
	XMLString buff(key);
	return self.containsKey(buff.ptr());
}

static TElem* getByKey(xercesc::NameIdPool<TElem>& self, const STR& key) {
	XMLString buff(key);
	return self.getByKey(buff.ptr());
}

};

template <typename NAME, typename TElem>
void NameIdPool(void) {
	char pyName[10 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "NameIdPool";
	//! xercesc::NameIdPool
	boost::python::class_<xercesc::NameIdPool<TElem>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<const XMLSize_t, xercesc::MemoryManager* const> >())
			.def(NameIdPoolDefVisitor<TElem, XMLString>())
			.def(NameIdPoolDefVisitor<TElem, std::string>())
			.def("containsKey", &xercesc::NameIdPool<TElem>::containsKey)
			.def("removeAll", &xercesc::NameIdPool<TElem>::removeAll)
			.def("getByKey", static_cast<TElem*(xercesc::NameIdPool<TElem>::*)(const XMLCh* const)>(&xercesc::NameIdPool<TElem>::getByKey), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getById", static_cast<TElem*(xercesc::NameIdPool<TElem>::*)(const XMLSize_t)>(&xercesc::NameIdPool<TElem>::getById), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMemoryManager", &xercesc::NameIdPool<TElem>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("put", &xercesc::NameIdPool<TElem>::put)
			;
}

template <typename NAME, typename TElem>
void NameIdPoolEnumerator(void) {
	char pyName[20 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "NameIdPoolEnumerator";
	// xercesc::NameIdPoolEnumerator
	boost::python::class_<xercesc::NameIdPoolEnumerator<TElem>, boost::python::bases<xercesc::XMLEnumerator<TElem> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<xercesc::NameIdPool<TElem>* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("hasMoreElements", &xercesc::NameIdPoolEnumerator<TElem>::hasMoreElements)
			.def("nextElement", &xercesc::NameIdPoolEnumerator<TElem>::nextElement, boost::python::return_internal_reference<>())
			.def("Reset", &xercesc::NameIdPoolEnumerator<TElem>::Reset)
			.def("size", &xercesc::NameIdPoolEnumerator<TElem>::size)
			;
}

void NameIdPool_init(void) {
	//! xercesc::NameIdPool
	typedef boost::mpl::string<'DTDE', 'ntit', 'yDec', 'l'> DTDEntityDeclStr;
	typedef boost::mpl::string<'DTDE', 'leme', 'ntDe', 'cl'> DTDElementDeclStr;
	typedef boost::mpl::string<'XMLN', 'otat', 'ionD', 'ecl'> XMLNotationDeclStr;
	NameIdPool<DTDEntityDeclStr, xercesc::DTDEntityDecl>();
	//! xercesc::NameIdPoolEnumerator
	NameIdPoolEnumerator<DTDElementDeclStr, xercesc::DTDElementDecl>();
	NameIdPoolEnumerator<DTDEntityDeclStr, xercesc::DTDEntityDecl>();
	NameIdPoolEnumerator<XMLNotationDeclStr, xercesc::XMLNotationDecl>();
}

} /* namespace pyxerces */
