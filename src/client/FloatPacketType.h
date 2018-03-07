/*
 * FloatPacketType.h
 *
 *  Created on: Mar 6, 2018
 *      Author: hephaestus
 */

#ifndef FLOATTYPE
#define FLOATTYPE

#include "AbstractPacketType.h"

class FloatPacketType: public AbstractPacketType {
public:
	FloatPacketType(int id, int size);
	virtual ~FloatPacketType();
	/**
	 * Return the number of bytes per value
	 */
	int numberOfBytesPerValue() {
		return 4;
	}
};

#endif /* LIBRARIES_SIMPLEPACKETCOMS_SRC_CLIENT_BYTEPACKETTYPE_H_ */
