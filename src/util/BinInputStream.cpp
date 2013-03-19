/*
 * BinInputStream.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "BinInputStream.h"

#include <string>
#include <boost/scoped_ptr.hpp>
#include <boost/python.hpp>
#include <xercesc/util/BinInputStream.hpp>

namespace pyxerces {

class BinInputStreamDefVisitor
: public boost::python::def_visitor<BinInputStreamDefVisitor>
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("readBytes", &BinInputStreamDefVisitor::readBytes)
	.def("readAll", &BinInputStreamDefVisitor::readAll)
	;
}

static boost::python::tuple readBytes(xercesc::BinInputStream& self, const XMLSize_t maxToRead) {
	boost::scoped_ptr<XMLByte> buffer(new XMLByte[maxToRead]);
	XMLSize_t size = self.readBytes(buffer.get(), maxToRead);
	std::string readed(reinterpret_cast<char*>(buffer.get()), size);
	return boost::python::make_tuple(readed, size);
}

static std::string readAll(xercesc::BinInputStream& self) {
	boost::scoped_ptr<XMLByte> buffer(new XMLByte[1024]);
	std::string result;
	while(XMLSize_t size = self.readBytes(buffer.get(), 1024)){
		result.append(reinterpret_cast<char*>(buffer.get()), size);
	}
	return result;
}

};

class BinInputStreamWrapper
: public xercesc::BinInputStream, public boost::python::wrapper<xercesc::BinInputStream>
{
public:
XMLFilePos curPos() const {
	return this->get_override("curPos")();
}

XMLSize_t readBytes(XMLByte* const toFill, const XMLSize_t maxToRead) {
	boost::python::tuple result = this->get_override("curPos")(maxToRead);
	std::string buffer = boost::python::extract<std::string>(result[0]);
	XMLSize_t   size   = boost::python::extract<XMLSize_t>(result[1]);
	memcpy(toFill, buffer.c_str(), size);
	return size;
}

const XMLCh* getContentType() const {
	return this->get_override("curPos")();
}

};

void BinInputStream_init(void) {
	//! xercesc::BinInputStream
	boost::python::class_<BinInputStreamWrapper, boost::noncopyable>("BinInputStream")
			.def(BinInputStreamDefVisitor())
			.def("curPos", boost::python::pure_virtual(&xercesc::BinInputStream::curPos))
			.def("readBytes", boost::python::pure_virtual(&xercesc::BinInputStream::readBytes))
			.def("getContentType", boost::python::pure_virtual(&xercesc::BinInputStream::getContentType), boost::python::return_value_policy<boost::python::return_by_value>())
			;
}

} /* namespace pyxerces */
