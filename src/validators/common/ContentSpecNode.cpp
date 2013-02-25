/*
 * ContentSpecNode.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "ContentSpecNode.h"

#include <boost/python.hpp>
#include <xercesc/framework/XMLBuffer.hpp>					//!< for forward declaration
#include <xercesc/validators/common/Grammar.hpp>			//!< for forward declaration
#include <xercesc/validators/common/ContentSpecNode.hpp>

namespace pyxerces {

void ContentSpecNode_init(void) {
	//! xercesc::ContentSpecNode
	auto ContentSpecNode = boost::python::class_<xercesc::ContentSpecNode, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("ContentSpecNode", boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::QName* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::XMLElementDecl* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<xercesc::QName* const, const bool, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::ContentSpecNode::NodeTypes, xercesc::ContentSpecNode* const, xercesc::ContentSpecNode* const, boost::python::optional<const bool, const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::ContentSpecNode&>())
			.def("getElement", static_cast<xercesc::QName*(xercesc::ContentSpecNode::*)(void)>(&xercesc::ContentSpecNode::getElement), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getElementDecl", static_cast<xercesc::XMLElementDecl*(xercesc::ContentSpecNode::*)(void)>(&xercesc::ContentSpecNode::getElementDecl), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFirst", static_cast<xercesc::ContentSpecNode*(xercesc::ContentSpecNode::*)(void)>(&xercesc::ContentSpecNode::getFirst), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getSecond", static_cast<xercesc::ContentSpecNode*(xercesc::ContentSpecNode::*)(void)>(&xercesc::ContentSpecNode::getSecond), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getType", &xercesc::ContentSpecNode::getType)
			.def("orphanFirst", &xercesc::ContentSpecNode::orphanFirst, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("orphanSecond", &xercesc::ContentSpecNode::orphanSecond, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getMinOccurs", &xercesc::ContentSpecNode::getMinOccurs)
			.def("getMaxOccurs", &xercesc::ContentSpecNode::getMaxOccurs)
			.def("isFirstAdopted", &xercesc::ContentSpecNode::isFirstAdopted)
			.def("isSecondAdopted", &xercesc::ContentSpecNode::isSecondAdopted)
			.def("setElement", &xercesc::ContentSpecNode::setElement)
			.def("setFirst", &xercesc::ContentSpecNode::setFirst)
			.def("setSecond", &xercesc::ContentSpecNode::setSecond)
			.def("setType", &xercesc::ContentSpecNode::setType)
			.def("setMinOccurs", &xercesc::ContentSpecNode::setMinOccurs)
			.def("setMaxOccurs", &xercesc::ContentSpecNode::setMaxOccurs)
			.def("setAdoptFirst", &xercesc::ContentSpecNode::setAdoptFirst)
			.def("setAdoptSecond", &xercesc::ContentSpecNode::setAdoptSecond)
			.def("formatSpec", &xercesc::ContentSpecNode::formatSpec)
			.def("hasAllContent", &xercesc::ContentSpecNode::hasAllContent)
			.def("getMinTotalRange", &xercesc::ContentSpecNode::getMinTotalRange)
			.def("getMaxTotalRange", &xercesc::ContentSpecNode::getMaxTotalRange)
			.def("isSerializable", &xercesc::ContentSpecNode::isSerializable)
			.def("getProtoType", &xercesc::ContentSpecNode::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("serialize", &xercesc::ContentSpecNode::serialize)
			;
	boost::python::scope ContentSpecNodeScope = ContentSpecNode;
	//! xercesc::ContentSpecNode::NodeTypes
	boost::python::enum_<xercesc::ContentSpecNode::NodeTypes>("NodeTypes")
			.value("Leaf", xercesc::ContentSpecNode::Leaf)
			.value("ZeroOrOne", xercesc::ContentSpecNode::ZeroOrOne)
			.value("ZeroOrMore", xercesc::ContentSpecNode::ZeroOrMore)
			.value("OneOrMore", xercesc::ContentSpecNode::OneOrMore)
			.value("Choice", xercesc::ContentSpecNode::Choice)
			.value("Sequence", xercesc::ContentSpecNode::Sequence)
			.value("Any", xercesc::ContentSpecNode::Any)
			.value("Any_Other", xercesc::ContentSpecNode::Any_Other)
			.value("Any_NS", xercesc::ContentSpecNode::Any_NS)
			.value("All", xercesc::ContentSpecNode::All)
			.value("Loop", xercesc::ContentSpecNode::Loop)
			.value("Any_NS_Choice", xercesc::ContentSpecNode::Any_NS_Choice)
			.value("ModelGroupSequence", xercesc::ContentSpecNode::ModelGroupSequence)
			.value("Any_Lax", xercesc::ContentSpecNode::Any_Lax)
			.value("Any_Other_Lax", xercesc::ContentSpecNode::Any_Other_Lax)
			.value("Any_NS_Lax", xercesc::ContentSpecNode::Any_NS_Lax)
			.value("ModelGroupChoice", xercesc::ContentSpecNode::ModelGroupChoice)
			.value("Any_Skip", xercesc::ContentSpecNode::Any_Skip)
			.value("Any_Other_Skip", xercesc::ContentSpecNode::Any_Other_Skip)
			.value("Any_NS_Skip", xercesc::ContentSpecNode::Any_NS_Skip)
			.value("UnknownType", xercesc::ContentSpecNode::UnknownType)
			.export_values()
			;
}

} /* namespace pyxerces */
