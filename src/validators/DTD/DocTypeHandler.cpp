/*
 * DocTypeHandler.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "DocTypeHandler.h"

#include <boost/python.hpp>
#include <xercesc/validators/DTD/DocTypeHandler.hpp>

namespace pyxerces {

class DocTypeHandlerWrapper
: public xercesc::DocTypeHandler, public boost::python::wrapper<xercesc::DocTypeHandler>
{
public:
void attDef
(
    const   xercesc::DTDElementDecl&     elemDecl
    , const xercesc::DTDAttDef&          attDef
    , const bool                ignoring
) {
	this->get_override("attDef")(elemDecl, attDef);
}

void doctypeComment
(
    const   XMLCh* const    comment
) {
	this->get_override("doctypeComment")(comment);
}

void doctypeDecl
(
    const   xercesc::DTDElementDecl& elemDecl
    , const XMLCh* const    publicId
    , const XMLCh* const    systemId
    , const bool            hasIntSubset
    , const bool            hasExtSubset = false
) {
	this->get_override("doctypeDecl")(elemDecl, publicId, systemId, hasIntSubset, hasExtSubset);
}

void doctypePI
(
    const   XMLCh* const    target
    , const XMLCh* const    data
) {
	this->get_override("doctypePI")(target, data);
}

void doctypeWhitespace
(
    const   XMLCh* const    chars
    , const XMLSize_t       length
) {
	this->get_override("doctypeWhitespace")(chars, length);
}

void elementDecl
(
    const   xercesc::DTDElementDecl& decl
    , const bool            isIgnored
) {
	this->get_override("elementDecl")(decl, isIgnored);
}

void endAttList
(
    const   xercesc::DTDElementDecl& elemDecl
) {
	this->get_override("endAttList")(elemDecl);
}

void endIntSubset() {
	this->get_override("endIntSubset")();
}

virtual void endExtSubset() {
	this->get_override("endExtSubset")();
}

virtual void entityDecl
(
    const   xercesc::DTDEntityDecl&  entityDecl
    , const bool            isPEDecl
    , const bool            isIgnored
) {
	this->get_override("entityDecl")(entityDecl, isPEDecl, isIgnored);
}

void resetDocType() {
	this->get_override("resetDocType")();
}

void notationDecl
(
    const   xercesc::XMLNotationDecl&    notDecl
    , const bool                isIgnored
) {
	this->get_override("notationDecl")(notDecl, isIgnored);
}

void startAttList
(
    const   xercesc::DTDElementDecl& elemDecl
) {
	this->get_override("startAttList")(elemDecl);
}

void startIntSubset() {
	this->get_override("startIntSubset")();
}

void startExtSubset() {
	this->get_override("startExtSubset")();
}

void TextDecl
(
    const   XMLCh* const    versionStr
    , const XMLCh* const    encodingStr
) {
	this->get_override("TextDecl")(versionStr, encodingStr);
}

};

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DocTypeHandlerDoctypeDeclOverloads, doctypeDecl, 4, 5)

void DocTypeHandler_init(void) {
	//! xercesc::DocTypeHandler
	boost::python::class_<DocTypeHandlerWrapper, boost::noncopyable>("DocTypeHandler")
			.def("attDef", &xercesc::DocTypeHandler::attDef)
			.def("doctypeComment", &xercesc::DocTypeHandler::doctypeComment)
			.def("doctypeDecl", &xercesc::DocTypeHandler::doctypeDecl, DocTypeHandlerDoctypeDeclOverloads())
			.def("doctypePI", &xercesc::DocTypeHandler::doctypePI)
			.def("doctypeWhitespace", &xercesc::DocTypeHandler::doctypeWhitespace)
			.def("elementDecl", &xercesc::DocTypeHandler::elementDecl)
			.def("endAttList", &xercesc::DocTypeHandler::endAttList)
			.def("endIntSubset", &xercesc::DocTypeHandler::endIntSubset)
			.def("endExtSubset", &xercesc::DocTypeHandler::endExtSubset)
			.def("entityDecl", &xercesc::DocTypeHandler::entityDecl)
			.def("resetDocType", &xercesc::DocTypeHandler::resetDocType)
			.def("notationDecl", &xercesc::DocTypeHandler::notationDecl)
			.def("startAttList", &xercesc::DocTypeHandler::startAttList)
			.def("startIntSubset", &xercesc::DocTypeHandler::startIntSubset)
			.def("startExtSubset", &xercesc::DocTypeHandler::startExtSubset)
			.def("TextDecl", &xercesc::DocTypeHandler::TextDecl)
			;
}

} /* namespace pyxerces */
