/*
 * LocalFileInputSource.cpp
 *
 *  Created on: 2013/03/19
 *      Author: mugwort_rc
 */

#include "LocalFileInputSource.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/util/BinInputStream.hpp>

#include <xercesc/framework/LocalFileInputSource.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <typename STR>
class LocalFileInputSourceDefVisitor
: public boost::python::def_visitor<LocalFileInputSourceDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::LocalFileInputSource*(*)(const STR, const STR, xercesc::MemoryManager* const)>(&LocalFileInputSourceDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::LocalFileInputSource*(*)(const STR, const STR)>(&LocalFileInputSourceDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::LocalFileInputSource*(*)(const STR, xercesc::MemoryManager* const)>(&LocalFileInputSourceDefVisitor<STR>::fromstring)))
	.def("__init__", boost::python::make_constructor(static_cast<xercesc::LocalFileInputSource*(*)(const STR)>(&LocalFileInputSourceDefVisitor<STR>::fromstring)))
	;
}

static xercesc::LocalFileInputSource* fromstring(const STR basePath, const STR relativePath, xercesc::MemoryManager* const manager) {
	XMLString buff1(basePath), buff2(relativePath);
	return new xercesc::LocalFileInputSource(buff1.ptr(), buff2.ptr(), manager);
}

static xercesc::LocalFileInputSource* fromstring(const STR basePath, const STR relativePath) {
	return LocalFileInputSourceDefVisitor<STR>::fromstring(basePath, relativePath, xercesc::XMLPlatformUtils::fgMemoryManager);
}

static xercesc::LocalFileInputSource* fromstring(const STR filePath, xercesc::MemoryManager* const manager) {
	XMLString buff(filePath);
	return new xercesc::LocalFileInputSource(buff.ptr(), manager);
}

static xercesc::LocalFileInputSource* fromstring(const STR filePath) {
	return LocalFileInputSourceDefVisitor<STR>::fromstring(filePath, xercesc::XMLPlatformUtils::fgMemoryManager);
}

};

class LocalFileInputSourceWrapper
: public xercesc::LocalFileInputSource, public boost::python::wrapper<xercesc::LocalFileInputSource>
{
public:
LocalFileInputSourceWrapper(const XMLCh* const basePath, const XMLCh* const relativePath, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::LocalFileInputSource(basePath, relativePath, manager)
{}

LocalFileInputSourceWrapper(const XMLCh* const filePath, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager)
: xercesc::LocalFileInputSource(filePath, manager)
{}

xercesc::BinInputStream* makeStream() const {
	if(boost::python::override makeStream = this->get_override("makeStream")){
		return makeStream();
	}else{
		return xercesc::LocalFileInputSource::makeStream();
	}
}

};

void LocalFileInputSource_init(void) {
	//! xercesc::LocalFileInputSource
	boost::python::class_<LocalFileInputSourceWrapper, boost::noncopyable, boost::python::bases<xercesc::InputSource> >("LocalFileInputSource", boost::python::init<const XMLCh* const, const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(boost::python::init<const XMLCh* const, boost::python::optional<xercesc::MemoryManager* const> >())
			.def(LocalFileInputSourceDefVisitor<XMLString&>())
			.def(LocalFileInputSourceDefVisitor<char*>())
			.def("makeStream", &xercesc::LocalFileInputSource::makeStream, boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
}

} /* namespace pyxerces */
