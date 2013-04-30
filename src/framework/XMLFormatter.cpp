/*
 * XMLFormatter.cpp
 *
 *  Created on: 2013/02/25
 *      Author: mugwort_rc
 */

#include "XMLFormatter.h"

#include <boost/python.hpp>

//!< for forward declaration
#include <xercesc/util/TransService.hpp>

#include <xercesc/framework/XMLFormatter.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

class XMLFormatterDefVisitor
: public boost::python::def_visitor<XMLFormatterDefVisitor> {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("writeBOM", static_cast<void(*)(xercesc::XMLFormatter&, const std::string&, const XMLSize_t)>(&XMLFormatterDefVisitor::writeBOM))
	;
}

static void writeBOM(xercesc::XMLFormatter& self, const std::string& toFormat, const XMLSize_t count) {
	self.writeBOM(reinterpret_cast<const unsigned char*>(toFormat.c_str()), count);
}

};

template <class STR>
class XMLFormatterStringDefVisitor
: public boost::python::def_visitor<XMLFormatterStringDefVisitor<STR> > {
friend class def_visitor_access;

public:
template <class T>
void visit(T& class_) const {
	class_
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const STR&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags)>(&XMLFormatterStringDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const STR&, const XMLSize_t, const xercesc::XMLFormatter::EscapeFlags)>(&XMLFormatterStringDefVisitor::formatBuf))
	.def("formatBuf", static_cast<void(*)(xercesc::XMLFormatter&, const STR&, const XMLSize_t)>(&XMLFormatterStringDefVisitor::formatBuf))
	.def("__lshift__", &XMLFormatterStringDefVisitor::__lshift__, boost::python::return_internal_reference<>())
	;
}

static void formatBuf(xercesc::XMLFormatter& self, const STR& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags, const xercesc::XMLFormatter::UnRepFlags unrepFlags) {
	XMLString buff(toFormat);
	self.formatBuf(buff.ptr(), count, escapeFlags, unrepFlags);
}

static void formatBuf(xercesc::XMLFormatter& self, const STR& toFormat, const XMLSize_t count, const xercesc::XMLFormatter::EscapeFlags escapeFlags) {
	XMLString buff(toFormat);
	self.formatBuf(buff.ptr(), count, escapeFlags, xercesc::XMLFormatter::DefaultUnRep);
}

static void formatBuf(xercesc::XMLFormatter& self, const STR& toFormat, const XMLSize_t count) {
	XMLString buff(toFormat);
	self.formatBuf(buff.ptr(), count, xercesc::XMLFormatter::DefaultEscape, xercesc::XMLFormatter::DefaultUnRep);
}

static xercesc::XMLFormatter& __lshift__(xercesc::XMLFormatter& self, const STR& toFormat) {
	XMLString buff(toFormat);
	self << buff.ptr();
	return self;
}

};

class XMLFormatTargetWrapper
: public xercesc::XMLFormatTarget, public boost::python::wrapper<xercesc::XMLFormatTarget>
{
public:
void writeChars(const XMLByte* const toWrite, const XMLSize_t count, xercesc::XMLFormatter* const formatter) {
	this->get_override("writeChars")(std::string(reinterpret_cast<const char*>(toWrite)), count, boost::python::ptr(formatter));
}

void flush() {
	if(boost::python::override flush = this->get_override("flush")) {
		flush();
	}else{
		xercesc::XMLFormatTarget::flush();
	}
}

};

//! XMLFormatter
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLFormatterFormatBufOverloads, formatBuf, 2, 4)

void XMLFormatter_init(void) {
	//! xercesc::XMLFormatter
	auto XMLFormatter = boost::python::class_<xercesc::XMLFormatter, boost::noncopyable>("XMLFormatter", boost::python::init<const XMLCh* const, const XMLCh* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(XMLFormatterDefVisitor())
			.def(XMLFormatterStringDefVisitor<XMLString>())
			.def(XMLFormatterStringDefVisitor<std::string>())
			.def(boost::python::init<const char* const, const char* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def(boost::python::init<const char* const, xercesc::XMLFormatTarget* const, boost::python::optional<const xercesc::XMLFormatter::EscapeFlags, const xercesc::XMLFormatter::UnRepFlags, xercesc::MemoryManager* const> >())
			.def("__lshift__", static_cast<xercesc::XMLFormatter&(xercesc::XMLFormatter::*)(const XMLCh)>(&xercesc::XMLFormatter::operator <<), boost::python::return_internal_reference<>())
			.def("__lshift__", static_cast<xercesc::XMLFormatter&(xercesc::XMLFormatter::*)(const XMLCh*)>(&xercesc::XMLFormatter::operator <<), boost::python::return_internal_reference<>())
			.def("__lshift__", static_cast<xercesc::XMLFormatter&(xercesc::XMLFormatter::*)(const xercesc::XMLFormatter::EscapeFlags)>(&xercesc::XMLFormatter::operator <<), boost::python::return_internal_reference<>())
			.def("__lshift__", static_cast<xercesc::XMLFormatter&(xercesc::XMLFormatter::*)(const xercesc::XMLFormatter::UnRepFlags)>(&xercesc::XMLFormatter::operator <<), boost::python::return_internal_reference<>())
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
	boost::python::class_<XMLFormatTargetWrapper, boost::noncopyable>("XMLFormatTarget")
			.def("writeChars", boost::python::pure_virtual(&xercesc::XMLFormatTarget::writeChars))
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
