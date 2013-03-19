/*
 * PlatformUtils.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "PlatformUtils.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/XMLNetAccessor.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/util/Mutexes.hpp>
#include <xercesc/util/XMLMsgLoader.hpp>
#include <xercesc/framework/MemoryManager.hpp>

#include <xercesc/util/PlatformUtils.hpp>

namespace pyxerces {

//! XMLPlatformUtils
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsInitializeOverloads, xercesc::XMLPlatformUtils::Initialize, 0, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsInitializeXMLSizeOverloads, xercesc::XMLPlatformUtils::Initialize, 3, 7)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsCurFilePosOverloads, xercesc::XMLPlatformUtils::curFilePos, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsCloseFileOverloads, xercesc::XMLPlatformUtils::closeFile, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsFileSizeOverloads, xercesc::XMLPlatformUtils::fileSize, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsOpenFileOverloads, xercesc::XMLPlatformUtils::openFile, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsOpenFileToWriteOverloads, xercesc::XMLPlatformUtils::openFileToWrite, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsOpenStdInHandleOverloads, xercesc::XMLPlatformUtils::openStdInHandle, 0, 1)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsReadFileBufferOverloads, xercesc::XMLPlatformUtils::readFileBuffer, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsWriteBufferToFileOverloads, xercesc::XMLPlatformUtils::writeBufferToFile, 3, 4)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsResetFileOverloads, xercesc::XMLPlatformUtils::resetFile, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsGetFullPathOverloads, xercesc::XMLPlatformUtils::getFullPath, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsGetCurrentDirectoryOverloads, xercesc::XMLPlatformUtils::getCurrentDirectory, 0, 1)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsRemoveDotSlashOverloads, xercesc::XMLPlatformUtils::removeDotSlash, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsRemoveDotDotSlashOverloads, xercesc::XMLPlatformUtils::removeDotDotSlash, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsIsRelativeOverloads, xercesc::XMLPlatformUtils::isRelative, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsWeavePathsOverloads, xercesc::XMLPlatformUtils::weavePaths, 2, 3)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsCloseMutexOverloads, xercesc::XMLPlatformUtils::closeMutex, 1, 2)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsMakeMutexOverloads, xercesc::XMLPlatformUtils::makeMutex, 0, 1)
BOOST_PYTHON_FUNCTION_OVERLOADS(XMLPlatformUtilsRecognizeNELOverloads, xercesc::XMLPlatformUtils::recognizeNEL, 1, 2)

// ==================================================

void PlatformUtils_init(void) {
	//! xercesc::XMLPlatformUtils
	boost::python::class_<xercesc::XMLPlatformUtils, boost::noncopyable>("XMLPlatformUtils", boost::python::no_init)
			.def("Initialize", static_cast<void(*)(const char* const, const char* const, xercesc::PanicHandler* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::Initialize), XMLPlatformUtilsInitializeOverloads())
			.def("Initialize", static_cast<void(*)(XMLSize_t, XMLSize_t, XMLSize_t, const char* const, const char* const, xercesc::PanicHandler* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::Initialize), XMLPlatformUtilsInitializeXMLSizeOverloads())
			.def("Terminate", &xercesc::XMLPlatformUtils::Terminate)
			.def("panic", &xercesc::XMLPlatformUtils::panic)
			.def("makeFileMgr", &xercesc::XMLPlatformUtils::makeFileMgr, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("curFilePos", &xercesc::XMLPlatformUtils::curFilePos, XMLPlatformUtilsCurFilePosOverloads())
			.def("closeFile", &xercesc::XMLPlatformUtils::closeFile, XMLPlatformUtilsCloseFileOverloads())
			.def("fileSize", &xercesc::XMLPlatformUtils::fileSize, XMLPlatformUtilsFileSizeOverloads())
			.def("openFile", static_cast<xercesc::FileHandle(*)(const char* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::openFile), XMLPlatformUtilsOpenFileOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])  //!< void*
			.def("openFile", static_cast<xercesc::FileHandle(*)(const XMLCh* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::openFile), XMLPlatformUtilsOpenFileOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])  //!< void*
			.def("openFileToWrite", static_cast<xercesc::FileHandle(*)(const char* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::openFileToWrite), XMLPlatformUtilsOpenFileToWriteOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])  //!< void*
			.def("openFileToWrite", static_cast<xercesc::FileHandle(*)(const XMLCh* const, xercesc::MemoryManager* const)>(&xercesc::XMLPlatformUtils::openFileToWrite), XMLPlatformUtilsOpenFileToWriteOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])  //!< void*
			.def("openStdInHandle", &xercesc::XMLPlatformUtils::openStdInHandle, XMLPlatformUtilsOpenStdInHandleOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])  //!< void*
			.def("readFileBuffer", &xercesc::XMLPlatformUtils::readFileBuffer, XMLPlatformUtilsReadFileBufferOverloads())
			.def("writeBufferToFile", &xercesc::XMLPlatformUtils::writeBufferToFile, XMLPlatformUtilsWriteBufferToFileOverloads())
			.def("resetFile", &xercesc::XMLPlatformUtils::resetFile, XMLPlatformUtilsResetFileOverloads())
			.def("getFullPath", &xercesc::XMLPlatformUtils::getFullPath, XMLPlatformUtilsGetFullPathOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("getCurrentDirectory", &xercesc::XMLPlatformUtils::getCurrentDirectory, XMLPlatformUtilsGetCurrentDirectoryOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			//.def("isAnySlash", &xercesc::XMLPlatformUtils::isAnySlash)
			.def("removeDotSlash", &xercesc::XMLPlatformUtils::removeDotSlash, XMLPlatformUtilsRemoveDotSlashOverloads())
			.def("removeDotDotSlash", &xercesc::XMLPlatformUtils::removeDotDotSlash, XMLPlatformUtilsRemoveDotDotSlashOverloads())
			.def("isRelative", &xercesc::XMLPlatformUtils::isRelative, XMLPlatformUtilsIsRelativeOverloads())
			.def("weavePaths", &xercesc::XMLPlatformUtils::weavePaths, XMLPlatformUtilsWeavePathsOverloads()[boost::python::return_value_policy<boost::python::return_by_value>()])
			.def("getCurrentMillis", &xercesc::XMLPlatformUtils::getCurrentMillis)
			.def("makeMutexMgr", &xercesc::XMLPlatformUtils::makeMutexMgr, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("closeMutex", &xercesc::XMLPlatformUtils::closeMutex, XMLPlatformUtilsCloseMutexOverloads())
			.def("lockMutex", &xercesc::XMLPlatformUtils::lockMutex)
			.def("makeMutex", &xercesc::XMLPlatformUtils::makeMutex, XMLPlatformUtilsMakeMutexOverloads()[boost::python::return_value_policy<boost::python::return_opaque_pointer>()])
			.def("unlockMutex", &xercesc::XMLPlatformUtils::unlockMutex)
			.def("loadMsgSet", &xercesc::XMLPlatformUtils::loadMsgSet, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("recognizeNEL", &xercesc::XMLPlatformUtils::recognizeNEL, XMLPlatformUtilsRecognizeNELOverloads())
			.def("isNELRecognized", &xercesc::XMLPlatformUtils::isNELRecognized)
			.def("strictIANAEncoding", &xercesc::XMLPlatformUtils::strictIANAEncoding)
			.def("isStrictIANAEncoding", &xercesc::XMLPlatformUtils::isStrictIANAEncoding)
			.def("alignPointerForNewBlockAllocation", &xercesc::XMLPlatformUtils::alignPointerForNewBlockAllocation)
			.staticmethod("Initialize")
			.staticmethod("Terminate")
			.staticmethod("panic")
			.staticmethod("makeFileMgr")
			.staticmethod("curFilePos")
			.staticmethod("closeFile")
			.staticmethod("fileSize")
			.staticmethod("openFile")
			.staticmethod("openFileToWrite")
			.staticmethod("openStdInHandle")
			.staticmethod("readFileBuffer")
			.staticmethod("writeBufferToFile")
			.staticmethod("resetFile")
			.staticmethod("getFullPath")
			.staticmethod("getCurrentDirectory")
			//.staticmethod("isAnySlash")
			.staticmethod("removeDotSlash")
			.staticmethod("removeDotDotSlash")
			.staticmethod("isRelative")
			.staticmethod("weavePaths")
			.staticmethod("getCurrentMillis")
			.staticmethod("makeMutexMgr")
			.staticmethod("closeMutex")
			.staticmethod("lockMutex")
			.staticmethod("makeMutex")
			.staticmethod("unlockMutex")
			.staticmethod("loadMsgSet")
			.staticmethod("recognizeNEL")
			.staticmethod("isNELRecognized")
			.staticmethod("strictIANAEncoding")
			.staticmethod("isStrictIANAEncoding")
			.staticmethod("alignPointerForNewBlockAllocation")
			.add_static_property("fgNetAccessor", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgNetAccessor, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgTransService", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgTransService, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgUserPanicHandler", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgUserPanicHandler, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgDefaultPanicHandler", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgDefaultPanicHandler, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgMemoryManager", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgFileMgr", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgFileMgr, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgMutexMgr", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgMutexMgr, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgAtomicMutex", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgAtomicMutex, boost::python::return_value_policy<boost::python::reference_existing_object>()))
			.add_static_property("fgXMLChBigEndian", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgXMLChBigEndian))
			.add_static_property("fgSSE2ok", boost::python::make_getter(&xercesc::XMLPlatformUtils::fgSSE2ok))
			;
}

} /* namespace pyxerces */
