/*
 * RefArrayVectorOf.cpp
 *
 *  Created on: 2013/03/03
 *      Author: mugwort_rc
 */

#include "RefArrayVectorOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>
#include <xercesc/util/RefArrayVectorOf.hpp>

#include "XMLString.h"

namespace pyxerces {

template <typename NAME, typename TElem>
void RefArrayVectorOf(void) {
	char pyName[16 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "RefArrayVectorOf";
	//! xercesc::RefArrayVectorOf
	boost::python::class_<xercesc::RefArrayVectorOf<TElem>, boost::noncopyable, boost::python::bases<xercesc::BaseRefVectorOf<TElem> > >(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("setElementAt", &xercesc::RefArrayVectorOf<TElem>::setElementAt)
			.def("removeAllElements", &xercesc::RefArrayVectorOf<TElem>::removeAllElements)
			.def("removeElementAt", &xercesc::RefArrayVectorOf<TElem>::removeElementAt)
			.def("removeLastElement", &xercesc::RefArrayVectorOf<TElem>::removeLastElement)
			.def("cleanup", &xercesc::RefArrayVectorOf<TElem>::cleanup)
			;
}

class RefArrayVectorOfXMLChDefVisitor
: public boost::python::def_visitor<RefArrayVectorOfXMLChDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("setElementAt", &RefArrayVectorOfXMLChDefVisitor::setElementAt)
	;
}

static void setElementAt(xercesc::RefArrayVectorOf<XMLCh>& self, const XMLString& toSet, const XMLSize_t setAt) {
	self.setElementAt(toSet.ptr(), setAt);
}

};

void RefArrayVectorOfXMLCh(void) {
	//! xercesc::RefArrayVectorOf
	boost::python::class_<xercesc::RefArrayVectorOf<XMLCh>, boost::noncopyable, boost::python::bases<xercesc::BaseRefVectorOf<XMLCh> > >("RefArrayVectorOfXMLCh", boost::python::init<const XMLSize_t, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(RefArrayVectorOfXMLChDefVisitor())
			.def("setElementAt", &xercesc::RefArrayVectorOf<XMLCh>::setElementAt)
			.def("removeAllElements", &xercesc::RefArrayVectorOf<XMLCh>::removeAllElements)
			.def("removeElementAt", &xercesc::RefArrayVectorOf<XMLCh>::removeElementAt)
			.def("removeLastElement", &xercesc::RefArrayVectorOf<XMLCh>::removeLastElement)
			.def("cleanup", &xercesc::RefArrayVectorOf<XMLCh>::cleanup)
			;
}


void RefArrayVectorOf_init(void) {
	//! xercesc::RefArrayVectorOf
	RefArrayVectorOfXMLCh();
}

} /* namespace pyxerces */
