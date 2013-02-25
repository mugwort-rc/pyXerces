/*
 * TransService.cpp
 *
 *  Created on: 2013/02/26
 *      Author: mugwort_rc
 */

#include "TransService.h"

#include <boost/python.hpp>
#include <xercesc/util/TransENameMap.hpp>	//!< for forward declaration
#include <xercesc/util/TransService.hpp>

namespace pyxerces {

//! XMLTransService
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLTransServiceMakeNewTranscoderForOverloads, makeNewTranscoderFor, 3, 4)
//! XMLLCPTranscoder
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(XMLLCPTranscoderTranscodeOverloads, transcode, 1, 2)

void TransService_init(void) {
	//! xercesc::XMLTransService
	auto XMLTransService = boost::python::class_<xercesc::XMLTransService, boost::noncopyable>("XMLTransService", boost::python::no_init)
			.def("makeNewTranscoderFor", static_cast<xercesc::XMLTranscoder*(xercesc::XMLTransService::*)(const XMLCh* const, xercesc::XMLTransService::Codes&, const XMLSize_t, xercesc::MemoryManager* const)>(&xercesc::XMLTransService::makeNewTranscoderFor), XMLTransServiceMakeNewTranscoderForOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("makeNewTranscoderFor", static_cast<xercesc::XMLTranscoder*(xercesc::XMLTransService::*)(const char* const, xercesc::XMLTransService::Codes&, const XMLSize_t, xercesc::MemoryManager* const)>(&xercesc::XMLTransService::makeNewTranscoderFor), XMLTransServiceMakeNewTranscoderForOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("makeNewTranscoderFor", static_cast<xercesc::XMLTranscoder*(xercesc::XMLTransService::*)(const xercesc::XMLRecognizer::Encodings, xercesc::XMLTransService::Codes&, const XMLSize_t, xercesc::MemoryManager* const)>(&xercesc::XMLTransService::makeNewTranscoderFor), XMLTransServiceMakeNewTranscoderForOverloads()[boost::python::return_value_policy<boost::python::reference_existing_object>()])
			.def("compareIString", &xercesc::XMLTransService::compareIString)
			.def("compareNIString", &xercesc::XMLTransService::compareNIString)
			.def("getId", &xercesc::XMLTransService::getId, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("makeNewLCPTranscoder", &xercesc::XMLTransService::makeNewLCPTranscoder, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("supportsSrcOfs", &xercesc::XMLTransService::supportsSrcOfs)
			.def("upperCase", &xercesc::XMLTransService::upperCase)
			.def("lowerCase", &xercesc::XMLTransService::lowerCase)
			.def("addEncoding", &xercesc::XMLTransService::addEncoding)
			.staticmethod("addEncoding")
			;
	//! xercesc::XMLTranscoder
	auto XMLTranscoder = boost::python::class_<xercesc::XMLTranscoder, boost::noncopyable>("XMLTranscoder", boost::python::no_init)
			.def("transcodeFrom", &xercesc::XMLTranscoder::transcodeFrom)
			.def("transcodeTo", &xercesc::XMLTranscoder::transcodeTo)
			.def("canTranscodeTo", &xercesc::XMLTranscoder::canTranscodeTo)
			.def("getBlockSize", &xercesc::XMLTranscoder::getBlockSize)
			.def("getEncodingName", &xercesc::XMLTranscoder::getEncodingName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getMemoryManager", &xercesc::XMLTranscoder::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	//! xercesc::XMLLCPTranscoder
	boost::python::class_<xercesc::XMLLCPTranscoder, boost::noncopyable>("XMLLCPTranscoder", boost::python::no_init)
			.def("transcode", static_cast<char*(xercesc::XMLLCPTranscoder::*)(const XMLCh* const, xercesc::MemoryManager* const)>(&xercesc::XMLLCPTranscoder::transcode), XMLLCPTranscoderTranscodeOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("transcode", static_cast<XMLCh*(xercesc::XMLLCPTranscoder::*)(const char* const, xercesc::MemoryManager* const)>(&xercesc::XMLLCPTranscoder::transcode), XMLLCPTranscoderTranscodeOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			;
	//! xercesc::TranscodeToStr
	boost::python::class_<xercesc::TranscodeToStr, boost::noncopyable>("TranscodeToStr", boost::python::init<const XMLCh*, const char*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh*, XMLSize_t, const char*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh*, xercesc::XMLTranscoder*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh*, XMLSize_t, xercesc::XMLTranscoder*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("str", &xercesc::TranscodeToStr::str, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("adopt", &xercesc::TranscodeToStr::adopt, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("length", &xercesc::TranscodeToStr::length)
			;
	//! xercesc::TranscodeFromStr
	boost::python::class_<xercesc::TranscodeFromStr, boost::noncopyable>("TranscodeFromStr", boost::python::init<const XMLByte*, XMLSize_t, const char*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLByte*, XMLSize_t, xercesc::XMLTranscoder*, boost::python::optional<xercesc::MemoryManager* const> >())
			.def("str", &xercesc::TranscodeFromStr::str, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("adopt", &xercesc::TranscodeFromStr::adopt, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("length", &xercesc::TranscodeFromStr::length)
			;
	boost::python::scope XMLTransServiceScope = XMLTransService;
	//! xercesc::XMLTransService::Codes
	boost::python::enum_<xercesc::XMLTransService::Codes>("Codes")
			.value("Ok", xercesc::XMLTransService::Ok)
			.value("UnsupportedEncoding", xercesc::XMLTransService::UnsupportedEncoding)
			.value("InternalFailure", xercesc::XMLTransService::InternalFailure)
			.value("SupportFilesNotFound", xercesc::XMLTransService::SupportFilesNotFound)
			.export_values()
			;
	//! xercesc::XMLTransService::TransRec
	boost::python::class_<xercesc::XMLTransService::TransRec, boost::noncopyable>("TransRec", boost::python::no_init)
			.def_readwrite("", &xercesc::XMLTransService::TransRec::intCh)
			.def_readwrite("", &xercesc::XMLTransService::TransRec::extCh)
			;
	boost::python::scope XMLTranscoderScope = XMLTranscoder;
	//! xercesc::XMLTranscoder::UnRepOpts
	boost::python::enum_<xercesc::XMLTranscoder::UnRepOpts>("UnRepOpts")
			.value("UnRep_Throw", xercesc::XMLTranscoder::UnRep_Throw)
			.value("UnRep_RepChar", xercesc::XMLTranscoder::UnRep_RepChar)
			;
}

} /* namespace pyxerces */
