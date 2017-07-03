#ifndef SimplePacketComs
#define SimplePacketComs
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include "PacketEvent.h"
#define DEFAULT_PACKET_SIZE_SIMPLE_PACKET 64

class SimplePacketComsAbstract {
private:
   uint32_t numberOfBytes;
   uint8_t * buffer;
   std::vector<PacketEventAbstract*> fmap;
public:
  SimplePacketComsAbstract();
  /**
  * Non blocking function to check if a packet is availible from the physical layer
  */
  virtual bool isPacketAvailible()=0;
  /**
  * User function that fills the buffer from the data in the physical layer
  * this data should already be framed, checksummed and validated as a valid packet
  */
  virtual int32_t getPacket(uint8_t * buffer,uint32_t numberOfBytes)=0;
  /**
  * User function that sends the buffer to the physical layer
  * this data should already be framed, checksummed and validated as a valid packet
  */
  virtual int32_t sendPacket(uint8_t * buffer,uint32_t numberOfBytes)=0;
  /**
  Gets the numbetr of bytes the PHY uses to transfer information
  */
  uint32_t getNumberOfBytesInPacket();
  /**
  Allow the user to set the number of bytes to transfer by the phy
  */
  void setNumberOfBytesInPacket(uint32_t newNumberOfBytes);
  /**
  The number of data values the phy transfers in the data transaction
  */
  uint32_t getNumberOfFloatsInPacket();

  /**
  * Attach a function to a packet event
  */
  void attach(PacketEventAbstract * eventImplementation);
  /**
  * This runs the packet server and calls all events if a backet comes in
  */
  void server();
  /**
  * This pushes a packet upstream
  */
  void push(uint32_t id, float * buffer );

  uint32_t * getIdPointer(){
    return (uint32_t *)buffer;
  }
  float * getDataPointer(){
    return (float *)(buffer+4);
  }
  std::vector<PacketEventAbstract*> * getfMap(){ return &fmap;}

};
#endif /* end of include guard: SimplePacketComs
 */
