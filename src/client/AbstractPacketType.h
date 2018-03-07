/*
 * AbstractPacketType.h
 *
 *  Created on: Mar 6, 2018
 *      Author: hephaestus
 */

#ifndef ABSTRACTPACKETTYPE
#define ABSTRACTPACKETTYPE
#include <stdint.h>
#include "IPacketResponseEvent.h"
#include <limits.h>
class AbstractPacketType {

public:
	IPacketResponseEvent * responseListener=NULL;

	int packetSize;
	uint8_t * downstream;
	uint8_t * upstream;
	long runCount=0;
	long runDivisor=1;
	long maxRuns = LONG_MAX;
	AbstractPacketType(int id, int size) {
		packetSize = size;
		downstream = new uint8_t[size];
		upstream = new uint8_t[size];
		getDownstreamIdPointer()[0] = id;

	}
	virtual ~AbstractPacketType();
	/**
	 * Return the number of bytes per value
	 */
	virtual int numberOfBytesPerValue()=0;
	/**
	 * Return the number  of parsed values in the packet
	 */
	int numberValues() {
		return ((packetSize - 4) / numberOfBytesPerValue());
	}
	uint32_t * getUpstreamIdPointer() {
		return (uint32_t *) upstream;
	}
	uint32_t * getDownstreamIdPointer() {
		return (uint32_t *) downstream;
	}
	uint32_t  getId() {
		return getDownstreamIdPointer()[0];
	}
	uint8_t * getUpstreamBytes() {
		return (uint8_t *) (upstream + 4);
	}
	uint8_t * getDownstreamBytes() {
		return (uint8_t *) (downstream + 4);
	}
	float * getUpstreamFloats(){
		return (float *)(upstream+4);
	}
	float * getDownstreamFloats(){
		return (float *)(downstream+4);
	}
	/**
	 * Set the listening event object
	 */
	void setResponseListener(IPacketResponseEvent * newresponseListener){
		responseListener=newresponseListener;
	}
};

#endif /* LIBRARIES_SIMPLEPACKETCOMS_SRC_CLIENT_ABSTRACTPACKETTYPE_H_ */
