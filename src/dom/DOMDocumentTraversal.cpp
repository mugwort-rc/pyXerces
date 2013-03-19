/*
 * DOMDocumentTraversal.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DOMDocumentTraversal.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMNodeIterator.hpp>
#include <xercesc/dom/DOMTreeWalker.hpp>

#include <xercesc/dom/DOMDocumentTraversal.hpp>

namespace pyxerces {

class DOMDocumentTraversalWrapper
: public xercesc::DOMDocumentTraversal, public boost::python::wrapper<xercesc::DOMDocumentTraversal>
{
public:
xercesc::DOMNodeIterator *createNodeIterator(xercesc::DOMNode* root, xercesc::DOMNodeFilter::ShowType whatToShow, xercesc::DOMNodeFilter* filter, bool entityReferenceExpansion) {
	return this->get_override("createNodeIterator")(boost::python::ptr(root), whatToShow, boost::python::ptr(filter), entityReferenceExpansion);
}

xercesc::DOMTreeWalker *createTreeWalker(xercesc::DOMNode* root, xercesc::DOMNodeFilter::ShowType whatToShow, xercesc::DOMNodeFilter* filter, bool entityReferenceExpansion) {
	return this->get_override("createTreeWalker")(boost::python::ptr(root), whatToShow, boost::python::ptr(filter), entityReferenceExpansion);
}

};

void DOMDocumentTraversal_init(void) {
	//! xercesc::DOMDocumentTraversal
	boost::python::class_<DOMDocumentTraversalWrapper, boost::noncopyable>("DOMDocumentTraversal")
			.def("createNodeIterator", boost::python::pure_virtual(&xercesc::DOMDocumentTraversal::createNodeIterator), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createTreeWalker", boost::python::pure_virtual(&xercesc::DOMDocumentTraversal::createTreeWalker), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
