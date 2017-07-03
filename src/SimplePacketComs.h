#ifndef SimplePacketComs
#define SimplePacketComs
#include <stdint.h>
#include <stdio.h>
#include <map>
#include <iostream>
#include "PacketEvent.h"
#define DEFAULT_PACKET_SIZE_SIMPLE_PACKET 64

class SimplePacketComsAbstract {
private:
   uint32_t numberOfBytes;
   uint8_t * buffer;
   std::map <uint32_t, PacketEventAbstract *> fmap;
public:
  SimplePacketComsAbstract();
  virtual bool isPacketAvailible()=0;
  virtual int32_t getPacket(uint8_t * buffer)=0;
  virtual int32_t sendPacket(uint8_t * buffer)=0;
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


};
#endif /* end of include guard: SimplePacketComs
 */
