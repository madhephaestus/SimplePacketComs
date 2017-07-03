#ifndef  PacketEvent
#define PacketEvent
#include <stdint.h>
class PacketEventAbstract {
private:
  uint32_t myId;
public:
  PacketEventAbstract(uint32_t id);
  virtual void event(float * buffer)=0;
  uint32_t getId(){return myId;}
};

#endif /* end of include guard: PacketEvent */
