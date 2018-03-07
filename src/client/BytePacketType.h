/*
 * BytePacketType.h
 *
 *  Created on: Mar 6, 2018
 *      Author: hephaestus
 */

#ifndef BYTEPACKETTYPE
#define BYTEPACKETTYPE

#include "AbstractPacketType.h"

class BytePacketType: public AbstractPacketType {
public:
	BytePacketType(int id, int size);
	virtual ~BytePacketType();
	/**
	 * Return the number of bytes per value
	 */
	int numberOfBytesPerValue() {
		return 1;
	}

};

#endif /* LIBRARIES_SIMPLEPACKETCOMS_SRC_CLIENT_BYTEPACKETTYPE_H_ */
