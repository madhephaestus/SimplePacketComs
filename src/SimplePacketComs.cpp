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
  fmap.push_back(eventImplementation);
}

/**
* This runs the packet server and calls all events if a backet comes in
*/
void SimplePacketComsAbstract::server(){
  if(isPacketAvailible()){
    getPacket(buffer, numberOfBytes);
    uint32_t currentId = getIdPointer()[0];
    for (std::vector<PacketEventAbstract* >::iterator it = fmap.begin() ; it != fmap.end(); ++it){
       if((*it)->getId() == currentId){
        (*it)->event(getDataPointer());
        sendPacket(buffer, numberOfBytes);
        return;// packet is responded to, fast return
      }
    }
    printf("\nUnknown packet %i ",currentId);
    for(int i=0;i<numberOfBytes;i++){
      printf("\n\tbyte %i ",buffer[i]);
    }
  }
}
/**
* This pushes a packet upstream
*/
void SimplePacketComsAbstract::push(uint32_t id, float * bufferofFloats ){
  getIdPointer()[0]=id;
  float * outgoingBuff = getDataPointer();
  for(uint32_t i=0;i<getNumberOfFloatsInPacket();i++){
    outgoingBuff[i] = bufferofFloats[i];
  }
  sendPacket(buffer, numberOfBytes);
}
