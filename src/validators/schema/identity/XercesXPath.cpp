/*
 * XercesXPath.cpp
 *
 *  Created on: 2013/03/04
 *      Author: mugwort_rc
 */

#include "XercesXPath.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/StringPool.hpp>

#include <xercesc/validators/schema/identity/XercesXPath.hpp>

#include "../../../internal/XSerializable.h"
#include "../../../util/XMLString.h"

namespace pyxerces {

template <class STR>
xercesc::XercesXPath* XercesXPath_fromstring(const STR& xpathExpr, xercesc::XMLStringPool* const stringPool, xercesc::XercesNamespaceResolver* const scopeContext, const unsigned int emptyNamespaceId, const bool isSelector, xercesc::MemoryManager* const manager) {
	XMLString buff(xpathExpr);
	return new xercesc::XercesXPath(buff.ptr(), stringPool, scopeContext, emptyNamespaceId, isSelector, manager);
}

template <class STR>
xercesc::XercesXPath* XercesXPath_fromstring(const STR& xpathExpr, xercesc::XMLStringPool* const stringPool, xercesc::XercesNamespaceResolver* const scopeContext, const unsigned int emptyNamespaceId, const bool isSelector) {
	return XercesXPath_fromstring<STR>(xpathExpr, stringPool, scopeContext, emptyNamespaceId, isSelector, xercesc::XMLPlatformUtils::fgMemoryManager);
}

template <class STR>
xercesc::XercesXPath* XercesXPath_fromstring(const STR& xpathExpr, xercesc::XMLStringPool* const stringPool, xercesc::XercesNamespaceResolver* const scopeContext, const unsigned int emptyNamespaceId) {
	return XercesXPath_fromstring<STR>(xpathExpr, stringPool, scopeContext, emptyNamespaceId, false);

}

template <class STR>
class XPathScannerDefVisitor
: public boost::python::def_visitor<XPathScannerDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("scanExpression", &XPathScannerDefVisitor<STR>::scanExpression)
	;
}

static bool scanExpression(xercesc::XPathScanner& self, const STR& data, XMLSize_t currentOffset, const XMLSize_t endOffset, xercesc::ValueVectorOf<int>* const tokens) {
	XMLString buff(data);
	return self.scanExpression(buff.ptr(), currentOffset, endOffset, tokens);
}

};

void XercesXPath_init(void) {
	//! xercesc::XercesNodeTest
	auto XercesNodeTest = boost::python::class_<xercesc::XercesNodeTest, boost::python::bases<xercesc::XSerializable> >("XercesNodeTest", boost::python::init<const short, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const xercesc::QName* const>())
			.def(boost::python::init<const XMLCh* const, const unsigned int, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__eq__", &xercesc::XercesNodeTest::operator ==)
			.def("__ne__", &xercesc::XercesNodeTest::operator !=)
			.def("getType", &xercesc::XercesNodeTest::getType)
			.def("getName", &xercesc::XercesNodeTest::getName, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(XercesNodeTest)
			;
	//! xercesc::XercesStep
	auto XercesStep = boost::python::class_<xercesc::XercesStep, boost::python::bases<xercesc::XSerializable> >("XercesStep", boost::python::init<const unsigned short, xercesc::XercesNodeTest* const>())
			.def("__eq__", &xercesc::XercesStep::operator ==)
			.def("__ne__", &xercesc::XercesStep::operator !=)
			.def("getAxisType", &xercesc::XercesStep::getAxisType)
			.def("getNodeTest", &xercesc::XercesStep::getNodeTest, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(XercesStep)
			;
	//! xercesc::XercesLocationPath
	auto XercesLocationPath = boost::python::class_<xercesc::XercesLocationPath, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XercesLocationPath", boost::python::init<xercesc::RefVectorOf<xercesc::XercesStep>*>())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__eq__", &xercesc::XercesLocationPath::operator ==)
			.def("__ne__", &xercesc::XercesLocationPath::operator !=)
			.def("getStepSize", &xercesc::XercesLocationPath::getStepSize)
			.def("addStep", &xercesc::XercesLocationPath::addStep)
			.def("getStep", &xercesc::XercesLocationPath::getStep, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(XercesLocationPath)
			;
	//! xercesc::XercesXPath
	auto XercesXPath = boost::python::class_<xercesc::XercesXPath, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XercesXPath", boost::python::init<const XMLCh* const, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int, boost::python::optional<const bool, xercesc::MemoryManager* const> >())
			.def(boost::python::init<boost::python::optional<xercesc::MemoryManager* const> >())
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const XMLString&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int, const bool, xercesc::MemoryManager* const)>(&XercesXPath_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const XMLString&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int, const bool)>(&XercesXPath_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const XMLString&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int)>(&XercesXPath_fromstring<XMLString>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const std::string&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int, const bool, xercesc::MemoryManager* const)>(&XercesXPath_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const std::string&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int, const bool)>(&XercesXPath_fromstring<std::string>)))
			.def("__init__", boost::python::make_constructor(static_cast<xercesc::XercesXPath*(*)(const std::string&, xercesc::XMLStringPool* const, xercesc::XercesNamespaceResolver* const, const unsigned int)>(&XercesXPath_fromstring<std::string>)))
			.def("__eq__", &xercesc::XercesXPath::operator ==)
			.def("__ne__", &xercesc::XercesXPath::operator !=)
			.def("getLocationPaths", &xercesc::XercesXPath::getLocationPaths, boost::python::return_value_policy<boost::python::reference_existing_object>())
			PyDECL_XSERIALIZABLE(XercesXPath)
			.def("getExpression", &xercesc::XercesXPath::getExpression, boost::python::return_value_policy<boost::python::return_by_value>())
			.setattr("EXPRTOKEN_OPEN_PAREN", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPEN_PAREN))
			.setattr("EXPRTOKEN_CLOSE_PAREN", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_CLOSE_PAREN))
			.setattr("EXPRTOKEN_OPEN_BRACKET", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPEN_BRACKET))
			.setattr("EXPRTOKEN_CLOSE_BRACKET", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_CLOSE_BRACKET))
			.setattr("EXPRTOKEN_PERIOD", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_PERIOD))
			.setattr("EXPRTOKEN_DOUBLE_PERIOD", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_DOUBLE_PERIOD))
			.setattr("EXPRTOKEN_ATSIGN", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_ATSIGN))
			.setattr("EXPRTOKEN_COMMA", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_COMMA))
			.setattr("EXPRTOKEN_DOUBLE_COLON", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_DOUBLE_COLON))
			.setattr("EXPRTOKEN_NAMETEST_ANY", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NAMETEST_ANY))
			.setattr("EXPRTOKEN_NAMETEST_NAMESPACE", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NAMETEST_NAMESPACE))
			.setattr("EXPRTOKEN_NAMETEST_QNAME", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NAMETEST_QNAME))
			.setattr("EXPRTOKEN_NODETYPE_COMMENT", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NODETYPE_COMMENT))
			.setattr("EXPRTOKEN_NODETYPE_TEXT", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NODETYPE_TEXT))
			.setattr("EXPRTOKEN_NODETYPE_PI", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NODETYPE_PI))
			.setattr("EXPRTOKEN_NODETYPE_NODE", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NODETYPE_NODE))
			.setattr("EXPRTOKEN_OPERATOR_AND", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_AND))
			.setattr("EXPRTOKEN_OPERATOR_OR", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_OR))
			.setattr("EXPRTOKEN_OPERATOR_MOD", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_MOD))
			.setattr("EXPRTOKEN_OPERATOR_DIV", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_DIV))
			.setattr("EXPRTOKEN_OPERATOR_MULT", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_MULT))
			.setattr("EXPRTOKEN_OPERATOR_SLASH", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_SLASH))
			.setattr("EXPRTOKEN_OPERATOR_DOUBLE_SLASH", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_DOUBLE_SLASH))
			.setattr("EXPRTOKEN_OPERATOR_UNION", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_UNION))
			.setattr("EXPRTOKEN_OPERATOR_PLUS", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_PLUS))
			.setattr("EXPRTOKEN_OPERATOR_MINUS", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_MINUS))
			.setattr("EXPRTOKEN_OPERATOR_EQUAL", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_EQUAL))
			.setattr("EXPRTOKEN_OPERATOR_NOT_EQUAL", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_NOT_EQUAL))
			.setattr("EXPRTOKEN_OPERATOR_LESS", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_LESS))
			.setattr("EXPRTOKEN_OPERATOR_LESS_EQUAL", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_LESS_EQUAL))
			.setattr("EXPRTOKEN_OPERATOR_GREATER", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_GREATER))
			.setattr("EXPRTOKEN_OPERATOR_GREATER_EQUAL", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_OPERATOR_GREATER_EQUAL))
			.setattr("EXPRTOKEN_FUNCTION_NAME", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_FUNCTION_NAME))
			.setattr("EXPRTOKEN_AXISNAME_ANCESTOR", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_ANCESTOR))
			.setattr("EXPRTOKEN_AXISNAME_ANCESTOR_OR_SELF", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_ANCESTOR_OR_SELF))
			.setattr("EXPRTOKEN_AXISNAME_ATTRIBUTE", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_ATTRIBUTE))
			.setattr("EXPRTOKEN_AXISNAME_CHILD", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_CHILD))
			.setattr("EXPRTOKEN_AXISNAME_DESCENDANT", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_DESCENDANT))
			.setattr("EXPRTOKEN_AXISNAME_DESCENDANT_OR_SELF", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_DESCENDANT_OR_SELF))
			.setattr("EXPRTOKEN_AXISNAME_FOLLOWING", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_FOLLOWING))
			.setattr("EXPRTOKEN_AXISNAME_FOLLOWING_SIBLING", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_FOLLOWING_SIBLING))
			.setattr("EXPRTOKEN_AXISNAME_NAMESPACE", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_NAMESPACE))
			.setattr("EXPRTOKEN_AXISNAME_PARENT", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_PARENT))
			.setattr("EXPRTOKEN_AXISNAME_PRECEDING", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_PRECEDING))
			.setattr("EXPRTOKEN_AXISNAME_PRECEDING_SIBLING", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_PRECEDING_SIBLING))
			.setattr("EXPRTOKEN_AXISNAME_SELF", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_AXISNAME_SELF))
			.setattr("EXPRTOKEN_LITERAL", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_LITERAL))
			.setattr("EXPRTOKEN_NUMBER", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_NUMBER))
			.setattr("EXPRTOKEN_VARIABLE_REFERENCE", static_cast<int>(xercesc::XercesXPath::EXPRTOKEN_VARIABLE_REFERENCE))
			;
	//! xercesc::XPathScanner
	boost::python::class_<xercesc::XPathScanner, boost::noncopyable>("XPathScanner", boost::python::init<xercesc::XMLStringPool* const>())
			.def(XPathScannerDefVisitor<XMLString>())
			.def(XPathScannerDefVisitor<std::string>())
			.def("scanExpression", &xercesc::XPathScanner::scanExpression)
			.setattr("CHARTYPE_INVALID", static_cast<int>(xercesc::XPathScanner::CHARTYPE_INVALID))
			.setattr("CHARTYPE_OTHER", static_cast<int>(xercesc::XPathScanner::CHARTYPE_OTHER))
			.setattr("CHARTYPE_WHITESPACE", static_cast<int>(xercesc::XPathScanner::CHARTYPE_WHITESPACE))
			.setattr("CHARTYPE_EXCLAMATION", static_cast<int>(xercesc::XPathScanner::CHARTYPE_EXCLAMATION))
			.setattr("CHARTYPE_QUOTE", static_cast<int>(xercesc::XPathScanner::CHARTYPE_QUOTE))
			.setattr("CHARTYPE_DOLLAR", static_cast<int>(xercesc::XPathScanner::CHARTYPE_DOLLAR))
			.setattr("CHARTYPE_OPEN_PAREN", static_cast<int>(xercesc::XPathScanner::CHARTYPE_OPEN_PAREN))
			.setattr("CHARTYPE_CLOSE_PAREN", static_cast<int>(xercesc::XPathScanner::CHARTYPE_CLOSE_PAREN))
			.setattr("CHARTYPE_STAR", static_cast<int>(xercesc::XPathScanner::CHARTYPE_STAR))
			.setattr("CHARTYPE_PLUS", static_cast<int>(xercesc::XPathScanner::CHARTYPE_PLUS))
			.setattr("CHARTYPE_COMMA", static_cast<int>(xercesc::XPathScanner::CHARTYPE_COMMA))
			.setattr("CHARTYPE_MINUS", static_cast<int>(xercesc::XPathScanner::CHARTYPE_MINUS))
			.setattr("CHARTYPE_PERIOD", static_cast<int>(xercesc::XPathScanner::CHARTYPE_PERIOD))
			.setattr("CHARTYPE_SLASH", static_cast<int>(xercesc::XPathScanner::CHARTYPE_SLASH))
			.setattr("CHARTYPE_DIGIT", static_cast<int>(xercesc::XPathScanner::CHARTYPE_DIGIT))
			.setattr("CHARTYPE_COLON", static_cast<int>(xercesc::XPathScanner::CHARTYPE_COLON))
			.setattr("CHARTYPE_LESS", static_cast<int>(xercesc::XPathScanner::CHARTYPE_LESS))
			.setattr("CHARTYPE_EQUAL", static_cast<int>(xercesc::XPathScanner::CHARTYPE_EQUAL))
			.setattr("CHARTYPE_GREATER", static_cast<int>(xercesc::XPathScanner::CHARTYPE_GREATER))
			.setattr("CHARTYPE_ATSIGN", static_cast<int>(xercesc::XPathScanner::CHARTYPE_ATSIGN))
			.setattr("CHARTYPE_LETTER", static_cast<int>(xercesc::XPathScanner::CHARTYPE_LETTER))
			.setattr("CHARTYPE_OPEN_BRACKET", static_cast<int>(xercesc::XPathScanner::CHARTYPE_OPEN_BRACKET))
			.setattr("CHARTYPE_CLOSE_BRACKET", static_cast<int>(xercesc::XPathScanner::CHARTYPE_CLOSE_BRACKET))
			.setattr("CHARTYPE_UNDERSCORE", static_cast<int>(xercesc::XPathScanner::CHARTYPE_UNDERSCORE))
			.setattr("CHARTYPE_UNION", static_cast<int>(xercesc::XPathScanner::CHARTYPE_UNION))
			.setattr("CHARTYPE_NONASCII", static_cast<int>(xercesc::XPathScanner::CHARTYPE_NONASCII))
			;
	//! xercesc::XPathScannerForSchema
	boost::python::class_<xercesc::XPathScannerForSchema, boost::noncopyable, boost::python::bases<xercesc::XPathScanner> >("XPathScannerForSchema", boost::python::init<xercesc::XMLStringPool* const>())
			;

	boost::python::scope XercesNodeTestScope = XercesNodeTest;
	//! xercesc::XercesNodeTest::NodeType
	boost::python::enum_<xercesc::XercesNodeTest::NodeType>("NodeType")
			.value("NodeType_QNAME", xercesc::XercesNodeTest::NodeType_QNAME)
			.value("NodeType_WILDCARD", xercesc::XercesNodeTest::NodeType_WILDCARD)
			.value("NodeType_NODE", xercesc::XercesNodeTest::NodeType_NODE)
			.value("NodeType_NAMESPACE", xercesc::XercesNodeTest::NodeType_NAMESPACE)
			.value("NodeType_UNKNOWN", xercesc::XercesNodeTest::NodeType_UNKNOWN)
			.export_values()
			;
	boost::python::scope XercesStepScope = XercesStep;
	//! xercesc::XercesStep::AxisType
	boost::python::enum_<xercesc::XercesStep::AxisType>("AxisType")
			.value("AxisType_CHILD", xercesc::XercesStep::AxisType_CHILD)
			.value("AxisType_ATTRIBUTE", xercesc::XercesStep::AxisType_ATTRIBUTE)
			.value("AxisType_SELF", xercesc::XercesStep::AxisType_SELF)
			.value("AxisType_DESCENDANT", xercesc::XercesStep::AxisType_DESCENDANT)
			.value("AxisType_UNKNOWN", xercesc::XercesStep::AxisType_UNKNOWN)
			.export_values()
			;
}

} /* namespace pyxerces */
