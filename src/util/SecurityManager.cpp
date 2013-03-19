/*
 * SecurityManager.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "SecurityManager.h"

#include <boost/python.hpp>
#include <xercesc/util/SecurityManager.hpp>

namespace pyxerces {

class SecurityManagerWrapper
: public xercesc::SecurityManager, public boost::python::wrapper<xercesc::SecurityManager>
{
public:
void setEntityExpansionLimit(XMLSize_t newLimit) {
	if(boost::python::override setEntityExpansionLimit = this->get_override("setEntityExpansionLimit")){
		setEntityExpansionLimit(newLimit);
	}else{
		xercesc::SecurityManager::setEntityExpansionLimit(newLimit);
	}
}

XMLSize_t getEntityExpansionLimit() const {
	if(boost::python::override getEntityExpansionLimit = this->get_override("getEntityExpansionLimit")){
		return getEntityExpansionLimit();
	}else{
		return xercesc::SecurityManager::getEntityExpansionLimit();
	}
}

};

void SecurityManager_init(void) {
	//! xercesc::SecurityManager
	boost::python::class_<SecurityManagerWrapper, boost::noncopyable>("SecurityManager")
			.def("setEntityExpansionLimit", &xercesc::SecurityManager::setEntityExpansionLimit)
			.def("getEntityExpansionLimit", &xercesc::SecurityManager::getEntityExpansionLimit)
			;
}

} /* namespace pyxerces */
