/*
 * XMLString.cpp
 *
 *  Created on: 2013/02/17
 *      Author: mugwort_rc
 */

#include "XMLString.h"

#include <xercesc/util/XMLString.hpp>

namespace pyxerces {

class XMLChManager {
public:
	/*!
	 * Constructor
	 */
	XMLChManager(XMLCh* ptr)
		: _ptr(ptr)
	{}
	/*!
	 * Constructor
	 */
	XMLChManager(const XMLCh* ptr)
		: _ptr(const_cast<XMLCh*>(ptr))
	{}
	/*!
	 * Destructor
	 */
	~XMLChManager(void)
	{
		if(this->_ptr != nullptr) {
			xercesc::XMLString::release(&this->_ptr);
		}
	}

	/*!
	 * Get raw pointer
	 * @return XMLCh*
	 */
	XMLCh* ptr(void) const {
		return this->_ptr;
	}

	/*!
	 * Transcode string
	 */
	static boost::shared_ptr<XMLChManager> transcode(const std::string& str) {
		return boost::shared_ptr<XMLChManager>(new XMLChManager(xercesc::XMLString::transcode(str.c_str())));
	}

	/*!
	 * Replicate string
	 */
	static boost::shared_ptr<XMLChManager> replicate(const XMLCh* ptr) {
		return boost::shared_ptr<XMLChManager>(new XMLChManager(xercesc::XMLString::replicate(ptr)));
	}

private:
	XMLChManager(const XMLChManager&);
	XMLChManager& operator =(const XMLChManager&);

private:
	XMLCh* _ptr;

};

// ==================================================

XMLString::XMLString(const std::string& str)
	: _ch(XMLChManager::transcode(str))
{}

XMLString::XMLString(const XMLCh* ptr)
	: _ch(XMLChManager::replicate(ptr))
{}

XMLString::XMLString(const XMLString& copy)
	: _ch(copy._ch)
{}

XMLString::~XMLString(void)
{}

XMLString& XMLString::operator =(const XMLString& rhs) {
	this->_ch = rhs._ch;
	return *this;
}

XMLCh* XMLString::ptr(void) const {
	if( ! this->_ch) {
		PyErr_SetString(PyExc_RuntimeError, "XMLCh Manager is fail");
		boost::python::throw_error_already_set();
	}
	return this->_ch->ptr();
}

XMLString::operator XMLCh*(void) const {
	return this->ptr();
}

bool XMLString::operator <(const XMLString& rhs) const {
	return 0 > xercesc::XMLString::compareString(this->ptr(), rhs.ptr());
}

bool XMLString::operator <=(const XMLString& rhs) const {
	return 0 >= xercesc::XMLString::compareString(this->ptr(), rhs.ptr());
}

bool XMLString::operator >(const XMLString& rhs) const {
	return 0 < xercesc::XMLString::compareString(this->ptr(), rhs.ptr());
}

bool XMLString::operator >=(const XMLString& rhs) const {
	return 0 <= xercesc::XMLString::compareString(this->ptr(), rhs.ptr());
}

bool XMLString::operator ==(const XMLString& rhs) const {
	return xercesc::XMLString::equals(this->ptr(), rhs.ptr());
}

bool XMLString::operator !=(const XMLString& rhs) const {
	return ! this->operator ==(rhs);
}

XMLSize_t XMLString::hash(const XMLSize_t modulus) const {
	return xercesc::XMLString::hash(this->ptr(), modulus);
}

int XMLString::indexOf(const XMLCh ch) const {
	return xercesc::XMLString::indexOf(this->ptr(), ch);
}

int XMLString::lastIndexOf(const XMLCh ch) const {
	return xercesc::XMLString::lastIndexOf(this->ptr(), ch);
}

XMLString XMLString::subString(const XMLSize_t start, const XMLSize_t end) const {
	XMLSize_t size = this->size();
	if(start >= end || start > size || end > size) {
		PyErr_SetString(PyExc_IndexError, "Index out of range");
		boost::python::throw_error_already_set();
	}
	XMLString result("");
	xercesc::XMLString::subString(result.ptr(), this->ptr(), start, end);
	return result;
}

bool XMLString::startsWith(const XMLString& prefix) const {
	return xercesc::XMLString::startsWith(this->ptr(), prefix.ptr());
}

bool XMLString::startsWith(const boost::python::tuple& prefixs) const {
	std::size_t size = boost::python::len(prefixs);
	for(std::size_t i = 0; i < size; ++i) {
		if( ! boost::python::extract<XMLString>(prefixs[i]).check()){
			continue;
		}
		if(this->startsWith(boost::python::extract<XMLString>(prefixs[i]))) {
			return true;
		}
	}
	return false;
}

bool XMLString::startsWithIn(const XMLString& prefix) const {
	return xercesc::XMLString::startsWithI(this->ptr(), prefix.ptr());
}

bool XMLString::startsWithIn(const boost::python::tuple& prefixs) const {
	std::size_t size = boost::python::len(prefixs);
	for(std::size_t i = 0; i < size; ++i) {
		if( ! boost::python::extract<XMLString>(prefixs[i]).check()){
			continue;
		}
		if(this->startsWithIn(boost::python::extract<XMLString>(prefixs[i]))) {
			return true;
		}
	}
	return false;
}

bool XMLString::endsWith(const XMLString& suffix) const {
	return xercesc::XMLString::endsWith(this->ptr(), suffix.ptr());
}

bool XMLString::endsWith(const boost::python::tuple& suffixs) const {
	std::size_t size = boost::python::len(suffixs);
	for(std::size_t i = 0; i < size; ++i) {
		if( ! boost::python::extract<XMLString>(suffixs[i]).check()){
			continue;
		}
		if(this->endsWith(boost::python::extract<XMLString>(suffixs[i]))) {
			return true;
		}
	}
	return false;
}

int XMLString::isMatch(const XMLString& pattern) const {
	return xercesc::XMLString::patternMatch(this->ptr(), pattern.ptr());
}

XMLSize_t XMLString::size(void) const {
	return xercesc::XMLString::stringLen(this->ptr());
}

bool XMLString::isValidNOTATION(void) const {
	return xercesc::XMLString::isValidNOTATION(this->ptr());
}

bool XMLString::isValidEncName(void) const {
	return xercesc::XMLString::isValidEncName(this->ptr());
}

bool XMLString::isAlpha(void) const {
	XMLCh*    ptr  = this->ptr();
	XMLSize_t size = this->size();
	for(XMLSize_t i = 0; i < size; ++i) {
		if( ! xercesc::XMLString::isAlpha(ptr[i])) {
			return false;
		}
	}
	return true;
}

bool XMLString::isDigit(void) const {
	XMLCh*    ptr  = this->ptr();
	XMLSize_t size = this->size();
	for(XMLSize_t i = 0; i < size; ++i) {
		if( ! xercesc::XMLString::isDigit(ptr[i])) {
			return false;
		}
	}
	return true;
}

bool XMLString::isAlphaNum(void) const {
	XMLCh*    ptr  = this->ptr();
	XMLSize_t size = this->size();
	for(XMLSize_t i = 0; i < size; ++i) {
		if( ! xercesc::XMLString::isAlphaNum(ptr[i])) {
			return false;
		}
	}
	return true;
}

bool XMLString::isHex(void) const {
	XMLCh*    ptr  = this->ptr();
	XMLSize_t size = this->size();
	for(XMLSize_t i = 0; i < size; ++i) {
		if( ! xercesc::XMLString::isHex(ptr[i])) {
			return false;
		}
	}
	return true;
}

bool XMLString::isLower(void) const {
	XMLString lower = this->lower();
	return this->operator ==(lower);
}

bool XMLString::isUpper(void) const {
	XMLString upper = this->upper();
	return this->operator ==(upper);
}

XMLString XMLString::strip(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::trim(result.ptr());
	return result;
}

XMLString XMLString::lower(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::lowerCase(result.ptr());
	return result;
}

XMLString XMLString::lowerASCII(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::lowerCaseASCII(result.ptr());
	return result;
}

XMLString XMLString::upper(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::upperCase(result.ptr());
	return result;
}

XMLString XMLString::upperASCII(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::upperCaseASCII(result.ptr());
	return result;
}

bool XMLString::isWSReplaced(void) const {
	return xercesc::XMLString::isWSReplaced(this->ptr());
}

bool XMLString::isWSCollapsed(void) const {
	return xercesc::XMLString::isWSCollapsed(this->ptr());
}

XMLString XMLString::replaceWS(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::replaceWS(result.ptr());
	return result;
}

XMLString XMLString::collapseWS(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::collapseWS(result.ptr());
	return result;
}

XMLString XMLString::removeWS(void) const {
	XMLString result = this->replicate();
	xercesc::XMLString::removeWS(result.ptr());
	return result;
}

XMLCh XMLString::at(const XMLSize_t i) const {
	if(i >= this->size()) {
		PyErr_SetString(PyExc_IndexError, "Index out of range");
		boost::python::throw_error_already_set();
		return 0;
	}
	return this->ptr()[i];
}

XMLString XMLString::makeUName(const XMLString& URI, const XMLString& name) {
	return XMLString(xercesc::XMLString::makeUName(URI.ptr(), name.ptr()));
}

XMLString XMLString::fixURI(const XMLString& str) {
	XMLString result("");
	xercesc::XMLString::fixURI(str.ptr(), result.ptr());
	return result;
}

std::string XMLString::toString(void) const {
	return XMLString::transcode(this->ptr());
}

std::string XMLString::reprString(void) const {
	boost::python::object global_ns = boost::python::import("__main__").attr("__dict__");
	global_ns["obj"] = this->toString();
	// pprint
	boost::python::exec("import pprint\n"
						"pp  = pprint.PrettyPrinter()\n"
						"__res = pp.pformat(obj)", global_ns, global_ns);
	return boost::python::extract<std::string>(global_ns["__res"]);
}

std::string XMLString::transcode(const XMLCh* ptr) {
	char* buff = xercesc::XMLString::transcode(ptr);
	if(buff == nullptr) {
		PyErr_SetString(PyExc_UnicodeTranslateError, "XMLString::transcode Error");
		boost::python::throw_error_already_set();
	}
	std::string result = buff;
	xercesc::XMLString::release(&buff);
	return result;
}

XMLString XMLString::replicate(void) const {
	assert(this->ptr() != nullptr);
	return XMLString(this->ptr());
}

// ==================================================

XMLString XMLChPtr::toString(void) const {
	return XMLString(this->ptr());
}

// ==================================================

unsigned char* unsigned_cast(char* ch) {
	return reinterpret_cast<unsigned char*>(ch);
}

char* signed_cast(unsigned char* ch) {
	return reinterpret_cast<char*>(ch);
}

// ==================================================

//! const XMLCh* -> XMLChPointerWrapper
class ConstXMLChToPythonConverter {
public:
	static PyObject* convert(const XMLCh* const ptr) {
		return boost::python::incref(boost::python::object(XMLString(ptr)).ptr());
	}
};

// ==================================================

void XMLString_init(void) {
	//! string <=> XMLCh*
	boost::python::class_<XMLString>("XMLString", boost::python::init<const std::string&>())
			.def(boost::python::init<const XMLCh*>())
			.def("__str__", &XMLString::toString)
			.def("__repr__", &XMLString::reprString)
			.def("__lt__", &XMLString::operator <)
			.def("__le__", &XMLString::operator <=)
			.def("__gt__", &XMLString::operator >)
			.def("__ge__", &XMLString::operator >=)
			.def("__eq__", &XMLString::operator ==)
			.def("__ne__", &XMLString::operator !=)
			.def("__len__", &XMLString::size)
			.def("__getitem__", &XMLString::at)
			.def("ptr", &XMLString::ptr, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("hash", &XMLString::hash)
			.def("indexOf", &XMLString::indexOf)
			.def("lastIndexOf", &XMLString::lastIndexOf)
			.def("subString", &XMLString::subString)
			// startswith/endswith start,end parameter unsupported.
			.def("startswith", static_cast<bool(XMLString::*)(const XMLString&) const>(&XMLString::startsWith))
			.def("startswith", static_cast<bool(XMLString::*)(const boost::python::tuple&) const>(&XMLString::startsWith))
			.def("startswithin", static_cast<bool(XMLString::*)(const XMLString&) const>(&XMLString::startsWithIn))
			.def("startswithin", static_cast<bool(XMLString::*)(const boost::python::tuple&) const>(&XMLString::startsWithIn))
			.def("endswith", static_cast<bool(XMLString::*)(const XMLString&) const>(&XMLString::endsWith))
			.def("endswith", static_cast<bool(XMLString::*)(const boost::python::tuple&) const>(&XMLString::endsWith))
			.def("isMatch", &XMLString::isMatch)
			.def("isValidNOTATION", &XMLString::isValidNOTATION)
			.def("isValidEncName", &XMLString::isValidEncName)
			.def("isalnum", &XMLString::isAlphaNum)
			.def("isalpha", &XMLString::isAlpha)
			.def("isdigit", &XMLString::isDigit)
			.def("ishex", &XMLString::isHex)
			.def("islower", &XMLString::isLower)
			.def("isupper", &XMLString::isUpper)
			.def("strip", &XMLString::strip)
			.def("lower", &XMLString::lower)
			.def("lowerASCII", &XMLString::lowerASCII)
			.def("upper", &XMLString::upper)
			.def("upperASCII", &XMLString::upperASCII)
			.def("isWSReplaced", &XMLString::isWSReplaced)
			.def("isWSCollapsed", &XMLString::isWSCollapsed)
			.def("replaceWS", &XMLString::replaceWS)
			.def("collapseWS", &XMLString::collapseWS)
			.def("removeWS", &XMLString::removeWS)
			.def("makeUName", &XMLString::makeUName)
			.def("fixURI", &XMLString::fixURI)
			.staticmethod("makeUName")
			.staticmethod("fixURI")
			;

	//! XMLCh pointer wrapper
	boost::python::class_<XMLChPtr>("XMLCh", boost::python::no_init)
			.def("ptr", &XMLChPtr::ptr, boost::python::return_value_policy<boost::python::return_opaque_pointer>())
			.def("toString", &XMLChPtr::toString)
			;

	//! char* -> unsigned char*
	boost::python::def("unsigned_cast", &pyxerces::unsigned_cast, boost::python::return_value_policy<boost::python::return_opaque_pointer>());
	//! unsigned char* -> char*
	boost::python::def("signed_cast", &pyxerces::signed_cast, boost::python::return_value_policy<boost::python::return_opaque_pointer>());

	//! const XMLCh* -> XMLString
	boost::python::to_python_converter<const XMLCh*, pyxerces::ConstXMLChToPythonConverter>();
}

} /* namespace pyxerces */
