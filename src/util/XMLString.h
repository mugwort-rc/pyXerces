/*
 * XMLString.h
 *
 *  Created on: 2013/02/17
 *      Author: mugwort_rc
 */

#ifndef XMLSTRING_H_
#define XMLSTRING_H_

#include <string>
#include <boost/python.hpp>
#include <xercesc/framework/MemoryManager.hpp>
#include <xercesc/util/PlatformUtils.hpp>

namespace pyxerces {

void XMLString_init(void);

class XMLChManager;	//!< forward declaration

class XMLString {
public:
/*!
 * Default Constructor
 */
XMLString(void);
/*!
 * Constructor
 * @param [in]		str		convert string
 * @type str: const char*
 */
XMLString(const char* str);
/*!
 * Constructor
 * @param [in]		ptr		raw XMLCh*
 * @type ptr: XMLCh*
 */
XMLString(const XMLCh* ptr);
/*!
 * Constructor
 * @param [in]		initializeList	initialize XMLCh value list
 * @type initializeList: boost::python::list
 */
XMLString(const boost::python::list& initializeList);
/*!
 * Copy constructor
 * @param [in]		copy	copy value
 */
XMLString(const XMLString& copy);
/*!
 * Destructor
 */
~XMLString(void);

/*!
 * Copy operator
 * @param [in]		rhs		right parameter
 *
 */
XMLString& operator =(const XMLString& rhs);

/*!
 * Get raw pointer
 * @return real pointer
 */
XMLCh* ptr(void) const;

/*!
 * Cast operator
 */
operator const XMLCh*(void) const;

/*!
 * operator +
 */
XMLString operator +(const XMLString& rhs) const;
/*!
 * operator +=
 */
XMLString& operator +=(const XMLString& rhs);

/*!
 * operator <
 */
bool operator <(const XMLString& rhs) const;
/*!
 * operator <=
 */
bool operator <=(const XMLString& rhs) const;
/*!
 * operator >
 */
bool operator >(const XMLString& rhs) const;
/*!
 * operator >=
 */
bool operator >=(const XMLString& rhs) const;
/*!
 * operator ==
 */
bool operator ==(const XMLString& rhs) const;
/*!
 * operator !=
 */
bool operator !=(const XMLString& rhs) const;

/*!
 * Hash
 */
XMLSize_t hash(const XMLSize_t modulus) const;

/*!
 * indexOf character data
 * @param [in]		ch	character data
 * @return index pos
 * @sa XMLString::at()
 */
int indexOf(const XMLCh ch) const;
/*!
 * lastIndexOf character data
 * @param [in]		ch	character data
 * @return index pos
 * @sa XMLString::at()
 */
int lastIndexOf(const XMLCh ch) const;

/*!
 * subString
 */
XMLString subString(const XMLSize_t start, const XMLSize_t end) const;

/*!
 * startsWith
 */
bool startsWith(const XMLString& prefix) const;
/*!
 * startsWith Python tuple
 */
bool startsWith(const boost::python::tuple& prefixs) const;
/*!
 * startsWithIn
 */
bool startsWithIn(const XMLString& prefix) const;
/*!
 * startsWithIn Python tuple
 */
bool startsWithIn(const boost::python::tuple& prefixs) const;
/*!
 * endsWith
 */
bool endsWith(const XMLString& suffix) const;
/*!
 * endsWith
 */
bool endsWith(const boost::python::tuple& suffixs) const;

/*!
 * pattern matching
 */
int isMatch(const XMLString& pattern) const;

/*!
 * Size
 * @return string size
 */
XMLSize_t size(void) const;

/*!
 * isValidNOTATION
 */
bool isValidNOTATION(void) const;
/*!
 * isValidEncName
 */
bool isValidEncName(void) const;
/*!
 * is Alpha
 */
bool isAlpha(void) const;
/*!
 * is Digit
 */
bool isDigit(void) const;
/*!
 * is AlphaNum
 */
bool isAlphaNum(void) const;
/*!
 * is Hex
 */
bool isHex(void) const;
/*!
 * is Upper
 */
bool isUpper(void) const;
/*!
 * is Lower
 */
bool isLower(void) const;

/*!
 * Trim string.
 */
XMLString strip(void) const;

/*!
 * Lower string
 */
XMLString lower(void) const;

/*!
 * Lower ASCII string
 */
XMLString lowerASCII(void) const;

/*!
 * Upper string
 */
XMLString upper(void) const;

/*!
 * Upper ASCII string
 */
XMLString upperASCII(void) const;

/*!
 * is WhiteSpace Replaced
 */
bool isWSReplaced(void) const;
/*!
 * is WhiteSpace Collapsed
 */
bool isWSCollapsed(void) const;

/*!
 * replace WhiteSpace
 */
XMLString replaceWS(void) const;
/*!
 * collapse WhiteSpace
 */
XMLString collapseWS(void) const;
/*!
 * remove WhiteSpace
 */
XMLString removeWS(void) const;

/*!
 * XMLString getitem
 * @param [in]		i	index
 * @return character string
 */
XMLCh at(const XMLSize_t i) const;

/*!
 * makeUName
 * @sa xercesc::XMLString::makeUName()
 */
static XMLString makeUName(const XMLString& URI, const XMLString& name);
/*!
 * fixURI
 * @sa xercesc::XMLString::fixURI()
 */
static XMLString fixURI(const XMLString& str);

public:
/*!
 * size to Text
 */
static XMLString sizeToText(const unsigned int toFormat, const unsigned int radix, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager);
/*!
 * bin to Text
 */
static XMLString binToText(const unsigned int toFormat, const unsigned int radix, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager);

public:
/*!
 * To string
 * @return transcoded string
 */
std::string toString(void) const;
/*!
 * Python __repr__ format string
 */
std::string reprString(void) const;

private:
/*!
 * Replicate string
 * @return new managed string
 */
XMLString replicate(void) const;
/*!
 * XMLCh* to string convert
 * @return converted string
 */
static std::string transcode(const XMLCh* ptr);

private:
boost::shared_ptr<XMLChManager> _ch;

};

// ==================================================

class XMLChPtr {
public:
XMLChPtr(const XMLCh* ptr)
	: _ptr(const_cast<XMLCh*>(ptr))
{}
XMLChPtr(const XMLChPtr& copy)
	: _ptr(copy._ptr)
{}
~XMLChPtr()
{}

XMLChPtr& operator =(const XMLChPtr& rhs) {
	this->_ptr = rhs._ptr;
	return *this;
}

XMLString operator +(const XMLChPtr& rhs) {
	XMLString buff1(this->_ptr), buff2(rhs._ptr);
	return buff1 + buff2;
}

XMLString operator +(const XMLString& rhs) {
	XMLString buff(this->_ptr);
	return buff + rhs;
}

XMLCh* ptr(void) const {
	return this->_ptr;
}

XMLSize_t size(void) const {
	return XMLString(this->_ptr).size();
}

XMLString toString(void) const{
	return XMLString(this->_ptr);
}

private:
XMLCh* _ptr;

};

} /* namespace pyxerces */
#endif /* XMLSTRING_H_ */
