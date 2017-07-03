#include "SimplePacketComs.h"


uint32_t SimplePacketComsAbstract::getNumberOfBytesInPacket(){
  return numberOfBytes;
}
void SimplePacketComsAbstract::setNumberOfBytesInPacket(uint32_t newNumberOfBytes){
  numberOfBytes=newNumberOfBytes;
}
uint32_t SimplePacketComsAbstract::getNumberOfFloatsInPacket(){
  return (numberOfBytes/4)-1;
}
