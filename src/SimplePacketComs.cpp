#include "SimplePacketComs.h"
#if defined(ARDUINO)
#include <Arduino.h>
#endif

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
#if defined(ARDUINO)
    Serial.println("Error! ID expected " +String(currentId)+" bytes "+String(buffer[0])+" "+String(buffer[1])+" "+String(buffer[2])+" "+String(buffer[3]));
    for (std::vector<PacketEventAbstract* >::iterator it = fmap.begin() ; it != fmap.end(); ++it){
    	uint32_t id = (*it)->getId();
        Serial.println("\t have: " +String(id));

       }
#endif
    //printf("\nUnknown packet %i ",currentId);
    for(int i=0;i<4;i++){
    	//copy the incoming missing ID into data
      buffer[i+4]=buffer[i];
    }
    //write in error ID
    buffer[0]=99;
    buffer[1]=0;
    buffer[2]=0;
    buffer[3]=0;//error packet
    // Zero out the rest of packet
    for(int i=8;i<numberOfBytes;i++){
	  buffer[i]=0;
	}

    sendPacket(buffer, numberOfBytes);
    return;
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
