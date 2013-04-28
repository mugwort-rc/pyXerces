/*
 * XMLContentModel.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLContentModel.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/validators/common/ContentLeafNameTypeVector.hpp>
#include <xercesc/validators/common/GrammarResolver.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/framework/XMLValidator.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>
#include <xercesc/validators/schema/SubstitutionGroupComparator.hpp>

#include <xercesc/framework/XMLContentModel.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

// XMLContentModelWrapper::checkUniqueParticleAttribution utility
template<typename TYPE>
class IntegerPointerArray
{
public:
IntegerPointerArray(TYPE* ptr)
: _ptr(ptr)
{}

IntegerPointerArray(const IntegerPointerArray& copy)
: _ptr(copy._ptr)
{}

IntegerPointerArray& operator =(const IntegerPointerArray& rhs) {
	this->_ptr = rhs._ptr;
	return *this;
}

TYPE operator[](unsigned int i){
	return this->_ptr[i];
}

private:
TYPE* _ptr;

};

class XMLContentModelDefaultDefVisitor
: public boost::python::def_visitor<XMLContentModelDefaultDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("validateContent", &XMLContentModelDefaultDefVisitor::validateContent)
	.def("validateContentSpecial", &XMLContentModelDefaultDefVisitor::validateContentSpecial)
	.def("checkUniqueParticleAttribution", &XMLContentModelDefaultDefVisitor::checkUniqueParticleAttribution)
	;
}

static bool validateContent(xercesc::XMLContentModel& self, xercesc::QName** const children, XMLSize_t childCount, unsigned int emptyNamespaceId, XMLSize_t* indexFailingChild) {
	return self.validateContent(children, childCount, emptyNamespaceId, indexFailingChild);
}

static bool validateContentSpecial(xercesc::XMLContentModel& self, xercesc::QName** const children, XMLSize_t childCount, unsigned int emptyNamespaceId, xercesc::GrammarResolver* const pGrammarResolver, xercesc::XMLStringPool* const pStringPool, XMLSize_t* indexFailingChild) {
	return self.validateContentSpecial(children, childCount, emptyNamespaceId, pGrammarResolver, pStringPool, indexFailingChild);
}

static void checkUniqueParticleAttribution(xercesc::XMLContentModel& self, xercesc::SchemaGrammar* const pGrammar, xercesc::GrammarResolver* const pGrammarResolver, xercesc::XMLStringPool* const pStringPool, xercesc::XMLValidator* const pValidator, unsigned int* const pContentSpecOrgURI) {
	self.checkUniqueParticleAttribution(pGrammar, pGrammarResolver, pStringPool, pValidator, pContentSpecOrgURI);
}

};

class XMLContentModelWrapper
: public xercesc::XMLContentModel, public boost::python::wrapper<xercesc::XMLContentModel>
{
public:
bool validateContent(xercesc::QName** const children, XMLSize_t childCount, unsigned int emptyNamespaceId, XMLSize_t* indexFailingChild, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) const {
	boost::python::list childrens;
	for(XMLSize_t i = 0; i < childCount; ++i){
		childrens.append(boost::python::ptr(children[i]));
	}
	boost::python::tuple result = this->get_override("validateContent")(childrens, emptyNamespaceId, boost::python::ptr(manager));
	*indexFailingChild = boost::python::extract<XMLSize_t>(result[1]);
	return boost::python::extract<bool>(result[0]);
}

bool validateContentSpecial(xercesc::QName** const children, XMLSize_t childCount, unsigned int emptyNamespaceId, xercesc::GrammarResolver* const pGrammarResolver, xercesc::XMLStringPool* const pStringPool, XMLSize_t* indexFailingChild, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) const {
	boost::python::list childrens;
	for(XMLSize_t i = 0; i < childCount; ++i){
		childrens.append(boost::python::ptr(children[i]));
	}
	boost::python::tuple result = this->get_override("validateContent")(childrens, emptyNamespaceId, boost::python::ptr(pGrammarResolver), boost::python::ptr(pStringPool), boost::python::ptr(manager));
	*indexFailingChild = boost::python::extract<XMLSize_t>(result[1]);
	return boost::python::extract<bool>(result[0]);
}

void checkUniqueParticleAttribution(xercesc::SchemaGrammar* const pGrammar, xercesc::GrammarResolver* const pGrammarResolver, xercesc::XMLStringPool* const pStringPool, xercesc::XMLValidator* const pValidator, unsigned int* const pContentSpecOrgURI, const XMLCh* pComplexTypeName = 0) {
	this->get_override("checkUniqueParticleAttribution")(boost::python::ptr(pGrammar), boost::python::ptr(pGrammarResolver), boost::python::ptr(pStringPool), boost::python::ptr(pValidator), IntegerPointerArray<unsigned int>(pContentSpecOrgURI), XMLString(pComplexTypeName));
}

xercesc::ContentLeafNameTypeVector* getContentLeafNameTypeVector() const {
	return this->get_override("getContentLeafNameTypeVector")();
}

unsigned int getNextState(unsigned int currentState, XMLSize_t elementIndex) const {
	return this->get_override("getNextState")(currentState, elementIndex);
}

bool handleRepetitions(const xercesc::QName* const curElem, unsigned int curState, unsigned int currentLoop, unsigned int& nextState, unsigned int& nextLoop, XMLSize_t elementIndex, xercesc::SubstitutionGroupComparator* comparator) const {
	boost::python::tuple result = this->get_override("handleRepetitions")(boost::python::ptr(curElem), curState, currentLoop, nextState, nextLoop, elementIndex, boost::python::ptr(comparator));
	nextState = boost::python::extract<unsigned int>(result[1]);
	nextLoop  = boost::python::extract<unsigned int>(result[2]);
	return boost::python::extract<bool>(result[0]);
}

};

void XMLContentModel_init(void) {
	boost::python::class_<IntegerPointerArray<unsigned int> >("IntegerArray", boost::python::no_init)
		.def("__getitem__", &IntegerPointerArray<unsigned int>::operator [])
		;
	//! xercesc::XMLContentModel
	boost::python::class_<XMLContentModelWrapper, boost::noncopyable>("XMLContentModel")
			.def(XMLContentModelDefaultDefVisitor())
			.def("validateContent", boost::python::pure_virtual(&xercesc::XMLContentModel::validateContent))
			.def("validateContentSpecial", boost::python::pure_virtual(&xercesc::XMLContentModel::validateContentSpecial))
			.def("checkUniqueParticleAttribution", boost::python::pure_virtual(&xercesc::XMLContentModel::checkUniqueParticleAttribution))
			.def("getContentLeafNameTypeVector", boost::python::pure_virtual(&xercesc::XMLContentModel::getContentLeafNameTypeVector), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getNextState", boost::python::pure_virtual(&xercesc::XMLContentModel::getNextState))
			.def("handleRepetitions", boost::python::pure_virtual(&xercesc::XMLContentModel::handleRepetitions))
			.add_property("gInvalidTrans", boost::python::make_getter(&xercesc::XMLContentModel::gInvalidTrans))
			.add_property("gEOCFakeId", boost::python::make_getter(&xercesc::XMLContentModel::gEOCFakeId))
			.add_property("gEpsilonFakeId", boost::python::make_getter(&xercesc::XMLContentModel::gEpsilonFakeId))
			;
}

} /* namespace pyxerces */
