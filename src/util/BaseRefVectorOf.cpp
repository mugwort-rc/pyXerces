/*
 * BaseRefVectorOf.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "BaseRefVectorOf.h"

#include <boost/mpl/string.hpp>
#include <boost/python.hpp>

//! XSAnnotation
#include <xercesc/framework/psvi/XSAnnotation.hpp>
//! XSAttributeUse
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
//! XSFacet
#include <xercesc/framework/psvi/XSFacet.hpp>
//! XSMultiValueFacet
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
//! XSNamespaceItem
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
//! XSParticle
#include <xercesc/framework/psvi/XSParticle.hpp>
//! XSSimpleTypeDefinition
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
//! XercesLocationPath
#include <xercesc/validators/schema/identity/XercesXPath.hpp>

#include <xercesc/util/BaseRefVectorOf.hpp>

#include "XMLString.h"

namespace pyxerces {

//! for class
template <typename NAME, class TElem>
void BaseRefVectorOf(void) {
	char pyName[15 + BOOST_MPL_LIMIT_STRING_SIZE + 1] = "BaseRefVectorOf";
	//! xercesc::BaseRefVectorOf
	boost::python::class_<xercesc::BaseRefVectorOf<TElem>, boost::noncopyable>(strcat(pyName, boost::mpl::c_str<NAME>::value), boost::python::init<const XMLSize_t, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def("addElement", &xercesc::BaseRefVectorOf<TElem>::addElement)
			.def("setElementAt", &xercesc::BaseRefVectorOf<TElem>::setElementAt)
			.def("insertElementAt", &xercesc::BaseRefVectorOf<TElem>::insertElementAt)
			.def("orphanElementAt", &xercesc::BaseRefVectorOf<TElem>::orphanElementAt, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAllElements", &xercesc::BaseRefVectorOf<TElem>::removeAllElements)
			.def("removeElementAt", &xercesc::BaseRefVectorOf<TElem>::removeElementAt)
			.def("removeLastElement", &xercesc::BaseRefVectorOf<TElem>::removeLastElement)
			.def("containsElement", &xercesc::BaseRefVectorOf<TElem>::containsElement)
			.def("cleanup", &xercesc::BaseRefVectorOf<TElem>::cleanup)
			.def("reinitialize", &xercesc::BaseRefVectorOf<TElem>::reinitialize)
			.def("curCapacity", &xercesc::BaseRefVectorOf<TElem>::curCapacity)
			.def("elementAt", static_cast<TElem*(xercesc::BaseRefVectorOf<TElem>::*)(const XMLSize_t)>(&xercesc::BaseRefVectorOf<TElem>::elementAt), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("size", &xercesc::BaseRefVectorOf<TElem>::size)
			.def("getMemoryManager", &xercesc::BaseRefVectorOf<TElem>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("ensureExtraCapacity", &xercesc::BaseRefVectorOf<TElem>::ensureExtraCapacity)
			;
}

class BaseRefVectorOfXMLChDefVisitor
: public boost::python::def_visitor<BaseRefVectorOfXMLChDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("orphanElementAt", &BaseRefVectorOfXMLChDefVisitor::orphanElementAt, boost::python::return_value_policy<boost::python::return_by_value>())
	;
}

static const XMLCh* orphanElementAt(xercesc::BaseRefVectorOf<XMLCh>& self, const XMLSize_t orphanAt) {
	return self.orphanElementAt(orphanAt);
}

};

template <class STR>
class BaseRefVectorOfXMLChStringDefVisitor
: public boost::python::def_visitor<BaseRefVectorOfXMLChStringDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("addElement", &BaseRefVectorOfXMLChStringDefVisitor<STR>::addElement)
	.def("setElementAt", &BaseRefVectorOfXMLChStringDefVisitor<STR>::setElementAt)
	.def("insertElementAt", &BaseRefVectorOfXMLChStringDefVisitor<STR>::insertElementAt)
	.def("containsElement", &BaseRefVectorOfXMLChStringDefVisitor<STR>::containsElement)
	;
}

static void addElement(xercesc::BaseRefVectorOf<XMLCh>& self, const STR& toAdd) {
	XMLString buff(toAdd);
	self.addElement(buff.ptr());
}

static void setElementAt(xercesc::BaseRefVectorOf<XMLCh>& self, const STR& toSet, const XMLSize_t setAt) {
	XMLString buff(toSet);
	self.setElementAt(buff.ptr(), setAt);
}

static void insertElementAt(xercesc::BaseRefVectorOf<XMLCh>& self, const STR& toInsert, const XMLSize_t insertAt) {
	XMLString buff(toInsert);
	self.insertElementAt(buff.ptr(), insertAt);
}

static bool containsElement(xercesc::BaseRefVectorOf<XMLCh>& self, const STR& toCheck) {
	XMLString buff(toCheck);
	return self.containsElement(buff.ptr());
}

};

//! for XMLCh
void BaseRefVectorOfXMLCh(void) {
	//! xercesc::BaseRefVectorOf
	boost::python::class_<xercesc::BaseRefVectorOf<XMLCh>, boost::noncopyable>("BaseRefVectorOfXMLCh", boost::python::init<const XMLSize_t, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(BaseRefVectorOfXMLChDefVisitor())
			.def(BaseRefVectorOfXMLChStringDefVisitor<XMLString>())
			.def(BaseRefVectorOfXMLChStringDefVisitor<std::string>())
			.def("addElement", &xercesc::BaseRefVectorOf<XMLCh>::addElement)
			.def("setElementAt", &xercesc::BaseRefVectorOf<XMLCh>::setElementAt)
			.def("insertElementAt", &xercesc::BaseRefVectorOf<XMLCh>::insertElementAt)
			//.def("orphanElementAt", &xercesc::BaseRefVectorOf<XMLCh>::orphanElementAt, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("removeAllElements", &xercesc::BaseRefVectorOf<XMLCh>::removeAllElements)
			.def("removeElementAt", &xercesc::BaseRefVectorOf<XMLCh>::removeElementAt)
			.def("removeLastElement", &xercesc::BaseRefVectorOf<XMLCh>::removeLastElement)
			.def("containsElement", &xercesc::BaseRefVectorOf<XMLCh>::containsElement)
			.def("cleanup", &xercesc::BaseRefVectorOf<XMLCh>::cleanup)
			.def("reinitialize", &xercesc::BaseRefVectorOf<XMLCh>::reinitialize)
			.def("curCapacity", &xercesc::BaseRefVectorOf<XMLCh>::curCapacity)
			.def("elementAt", static_cast<const XMLCh*(xercesc::BaseRefVectorOf<XMLCh>::*)(const XMLSize_t) const>(&xercesc::BaseRefVectorOf<XMLCh>::elementAt), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("size", &xercesc::BaseRefVectorOf<XMLCh>::size)
			.def("getMemoryManager", &xercesc::BaseRefVectorOf<XMLCh>::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("ensureExtraCapacity", &xercesc::BaseRefVectorOf<XMLCh>::ensureExtraCapacity)
			;
}

void BaseRefVectorOf_init(void) {
	typedef boost::mpl::string<'XSAn', 'nota', 'tion'> XSAnnotationStr;
	typedef boost::mpl::string<'XSAt', 'trib', 'uteU', 'se'> XSAttributeUseStr;
	typedef boost::mpl::string<'XSFa', 'cet'> XSFacetStr;
	typedef boost::mpl::string<'XSMu', 'ltiV', 'alue', 'Face', 't'> XSMultiValueFacetStr;
	typedef boost::mpl::string<'XSNa', 'mesp', 'aceI', 'tem'> XSNamespaceItemStr;
	typedef boost::mpl::string<'XSPa', 'rtic', 'le'> XSParticleStr;
	typedef boost::mpl::string<'XSSi', 'mple', 'Type', 'Defi', 'niti', 'on'> XSSimpleTypeDefinitionStr;
	typedef boost::mpl::string<'Xerc', 'esLo', 'cati', 'onPa', 'th'> XercesLocationPathStr;
	//! xercesc::BaseRefVectorOf
	BaseRefVectorOf<XSAnnotationStr, xercesc::XSAnnotation>();
	BaseRefVectorOf<XSAttributeUseStr, xercesc::XSAttributeUse>();
	BaseRefVectorOf<XSFacetStr, xercesc::XSFacet>();
	BaseRefVectorOf<XSMultiValueFacetStr, xercesc::XSMultiValueFacet>();
	BaseRefVectorOf<XSNamespaceItemStr, xercesc::XSNamespaceItem>();
	BaseRefVectorOf<XSParticleStr, xercesc::XSParticle>();
	BaseRefVectorOf<XSSimpleTypeDefinitionStr, xercesc::XSSimpleTypeDefinition>();
	BaseRefVectorOf<XercesLocationPathStr, xercesc::XercesLocationPath>();
	//! XMLCh
	BaseRefVectorOfXMLCh();
}

} /* namespace pyxerces */