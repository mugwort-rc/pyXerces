/*
 * XMLFormatter.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLFormatter.h"

#include <boost/python.hpp>
#include <xercesc/util/TransService.hpp>		//!< for forward declaration
#include <xercesc/framework/XMLFormatter.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

//! XMLFormatter
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLFormatterFormatBufOverloads, formatBuf, 2, 4)

class XMLFormatterDefVisitor
: public boost::python::def_visitor<XMLFormatterDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const XMLString&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags)>(&XMLFormatterDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const std::string&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags)>(&XMLFormatterDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const XMLString&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags)>(&XMLFormatterDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const std::string&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags)>(&XMLFormatterDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const XMLString&, const XMLSize_t)>(&XMLFormatterDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const std::string&, const XMLSize_t)>(&XMLFormatterDefVisitor::formatBuf))
	.def("writeBOM", static_cast<void(*)(xercesc::XMLFormatter&, const std::string&, const XMLSize_t)>(&XMLFormatterDefVisitor::writeBOM))
	;
}

static void formatBuf(xercesc::XMLFormatter& self, const XMLString& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags, const xercesc::XMLFormatter::UnRepFlags unrepFlags) {
	self.formatBuf(toFormat.ptr(), count, escapeFlags, unrepFlags);
}

static void formatBuf(xercesc::XMLFormatter& self, const std::string& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags, const xercesc::XMLFormatter::UnRepFlags unrepFlags) {
	XMLString buff(toFormat);
	XMLFormatterDefVisitor::formatBuf(self, buff, count, escapeFlags, unrepFlags);
}

static void formatBuf(xercesc::XMLFormatter& self, const XMLString& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags) {
	self.formatBuf(toFormat.ptr(), count, escapeFlags, xercesc::XMLFormatter::DefaultUnRep);
}

static void formatBuf(xercesc::XMLFormatter& self, const std::string& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags) {
	XMLString buff(toFormat);
	XMLFormatterDefVisitor::formatBuf(self, buff, count, escapeFlags);
}

static void formatBuf(xercesc::XMLFormatter& self, const XMLString& toFormat, const XMLSize_t count) {
	self.formatBuf(toFormat.ptr(), count, xercesc::XMLFormatter::DefaultEscape, xercesc::XMLFormatter::DefaultUnRep);
}

static void formatBuf(xercesc::XMLFormatter& self, const std::string& toFormat, const XMLSize_t count) {
	XMLString buff(toFormat);
	XMLFormatterDefVisitor::formatBuf(self, buff, count);
}

static void writeBOM(xercesc::XMLFormatter& self, const std::string& toFormat, const XMLSize_t count) {
	self.writeBOM(reinterpret_cast<const unsigned char*>(toFormat.c_str()), count);
}

};

void XMLFormatter_init(void) {
	//! xercesc::XMLFormatter
	auto XMLFormatter = boost::python::class_<xercesc::XMLFormatter, boost::noncopyable>("XMLFormatter", boost::python::init<const XMLCh* const, const XMLCh* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(XMLFormatterDefVisitor())
			.def(boost::python::init<const char* const, const char* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def("formatBuf", &xercesc::XMLFormatter::formatBuf, XMLFormatterFormatBufOverloads())
			.def("writeBOM", &xercesc::XMLFormatter::writeBOM)
			.def("getEncodingName", &xercesc::XMLFormatter::getEncodingName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getTranscoder", static_cast<xercesc::XMLTranscoder*(xercesc::XMLFormatter::*)(void)>(&xercesc::XMLFormatter::getTranscoder), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setEscapeFlags", &xercesc::XMLFormatter::setEscapeFlags)
			.def("setUnRepFlags", &xercesc::XMLFormatter::setUnRepFlags)
			.def("getEscapeFlags", &xercesc::XMLFormatter::getEscapeFlags)
			.def("getUnRepFlags", &xercesc::XMLFormatter::getUnRepFlags)
			;
	//! xercesc::XMLFormatTarget
	boost::python::class_<xercesc::XMLFormatTarget, boost::noncopyable>("XMLFormatTarget", boost::python::no_init)
			.def("writeChars", &xercesc::XMLFormatTarget::writeChars)
			.def("flush", &xercesc::XMLFormatTarget::flush)
			;
	boost::python::scope XMLFormatterScope = XMLFormatter;
	//! xercesc::XMLFormatter::EscapeFlags
	boost::python::enum_<xercesc::XMLFormatter::EscapeFlags>("EscapeFlags")
			.value("NoEscapes", xercesc::XMLFormatter::NoEscapes)
			.value("StdEscapes", xercesc::XMLFormatter::StdEscapes)
			.value("AttrEscapes", xercesc::XMLFormatter::AttrEscapes)
			.value("CharEscapes", xercesc::XMLFormatter::CharEscapes)
			.value("EscapeFlags_Count", xercesc::XMLFormatter::EscapeFlags_Count)
			.value("DefaultEscape", xercesc::XMLFormatter::DefaultEscape)
			.export_values()
			;
	//! xercesc::XMLFormatter::UnRepFlags
	boost::python::enum_<xercesc::XMLFormatter::UnRepFlags>("UnRepFlags")
			.value("UnRep_Fail", xercesc::XMLFormatter::UnRep_Fail)
			.value("UnRep_CharRef", xercesc::XMLFormatter::UnRep_CharRef)
			.value("UnRep_Replace", xercesc::XMLFormatter::UnRep_Replace)
			.value("DefaultUnRep", xercesc::XMLFormatter::DefaultUnRep)
			.export_values()
			;
}

} /* namespace pyxerces */
