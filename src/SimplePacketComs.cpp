#include "SimplePacketComs.h"

SimplePacketComsAbstract::SimplePacketComsAbstract(){
  setNumberOfBytesInPacket(DEFAULT_PACKET_SIZE_SIMPLE_PACKET);
}
uint32_t SimplePacketComsAbstract::getNumberOfBytesInPacket(){
  return numberOfBytes;
}
void SimplePacketComsAbstract::setNumberOfBytesInPacket(uint32_t newNumberOfBytes){
  numberOfBytes=newNumberOfBytes;
  buffer = new uint8_t[numberOfBytes];
}
uint32_t SimplePacketComsAbstract::getNumberOfFloatsInPacket(){
  return (numberOfBytes/4)-1;
}

void SimplePacketComsAbstract::attach(PacketEventAbstract * eventImplementation){
  fmap[eventImplementation->getId()] = eventImplementation;
}
