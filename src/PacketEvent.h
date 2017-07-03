#ifndef  PacketEvent
#define PacketEvent
#include <stdint.h>
class PacketEventAbstract {
protected:
  // Unique id of the function being called
  uint32_t myId;
public:
  // Packet ID needs to be set
  PacketEventAbstract(uint32_t id);
  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back 
  virtual void event(float * buffer)=0;
  uint32_t getId(){return myId;}
};

#endif /* end of include guard: PacketEvent */
