#ifndef SimplePacketComs
#define SimplePacketComs
#include <stdint.h>
#include <stdio.h>
class SimplePacketComsAbstract {
private:
   uint32_t numberOfBytes;
public:
  virtual bool isPacketAvailible()=0;
  virtual int32_t getPacket(uint8_t * buffer)=0;
  virtual int32_t sendPacket(uint8_t * buffer)=0;
  uint32_t getNumberOfBytesInPacket();
  void setNumberOfBytesInPacket(uint32_t newNumberOfBytes);
  uint32_t getNumberOfFloatsInPacket();

};
#endif /* end of include guard: SimplePacketComs
 */
