/*
 * XMLEnumerator.cpp
 *
 *  Created on: 2013/03/01
 *      Author: mugwort_rc
 */

#include "XMLEnumerator.h"

#include <boost/scoped_ptr.hpp>
#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/validators/DTD/DTDElementDecl.hpp>
#include <xercesc/validators/DTD/DTDEntityDecl.hpp>

#include <xercesc/util/XMLEnumerator.hpp>

namespace pyxerces {

template <class T>
class XMLEnumeratorWrapper
: public xercesc::XMLEnumerator<T>, public boost::python::wrapper<xercesc::XMLEnumerator<T> >
{
public:
XMLEnumeratorWrapper()
: xercesc::XMLEnumerator<T>()
{}

~XMLEnumeratorWrapper()
{}

XMLEnumeratorWrapper(const xercesc::XMLEnumerator<T>& copy)
: xercesc::XMLEnumerator<T>(copy)
{}

bool hasMoreElements() const {
	return this->get_override("hasMoreElements")();
}

T& nextElement() {
	return this->get_override("nextElement")();
}

void Reset() {
	this->get_override("Reset")();
}

};

template <typename NAME, typename TVal>
void XMLEnumerator(void) {
	char pyName[13 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "XMLEnumerator";
	//! xercesc::XMLEnumerator
	boost::python::class_<XMLEnumeratorWrapper<TVal> >(strcat(pyName, boost::mpl::c_str<NAME>::value))
			.def("hasMoreElements", &xercesc::XMLEnumerator<TVal>::hasMoreElements)
			.def("nextElement", &xercesc::XMLEnumerator<TVal>::nextElement, boost::python::return_internal_reference<>())
			.def("Reset", &xercesc::XMLEnumerator<TVal>::Reset)
			;
}

void XMLEnumerator_init(void) {
	//! xercesc::XMLEnumerator
	typedef boost::mpl::string<'Gram', 'mar'> GrammarStr;
	typedef boost::mpl::string<'DTDE', 'leme', 'ntDe', 'cl'> DTDElementDeclStr;
	typedef boost::mpl::string<'DTDE', 'ntit', 'yDec', 'l'> DTDEntityDeclStr;
	typedef boost::mpl::string<'XMLN', 'otat', 'ionD', 'ecl'> XMLNotationDeclStr;
	XMLEnumerator<GrammarStr, xercesc::Grammar>();
	XMLEnumerator<DTDElementDeclStr, xercesc::DTDElementDecl>();
	XMLEnumerator<DTDEntityDeclStr, xercesc::DTDEntityDecl>();
	XMLEnumerator<XMLNotationDeclStr, xercesc::XMLNotationDecl>();
}

} /* namespace pyxerces */
