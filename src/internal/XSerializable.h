/*
 * XSerializable.h
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#ifndef XSERIALIZABLE_H_
#define XSERIALIZABLE_H_

namespace pyxerces {

void XSerializable_init(void);

#define PyDECL_XSERIALIZABLE(class_name) \
		.def("createObject", &xercesc::class_name::createObject, boost::python::return_value_policy<boost::python::reference_existing_object>()) \
		.staticmethod("createObject") \
		.def("isSerializable", &xercesc::class_name::isSerializable) \
		.def("getProtoType", &xercesc::class_name::getProtoType, boost::python::return_value_policy<boost::python::reference_existing_object>()) \
		.def("serialize", &xercesc::class_name::serialize)
		// XXX
		//.setattr("classGrammar", &xercesc::Grammar::classGrammar)

} /* namespace pyxerces */
#endif /* XSERIALIZABLE_H_ */
