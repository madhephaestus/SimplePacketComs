#include "PacketEvent.h"

PacketEventAbstract::PacketEventAbstract(uint32_t id) {
	myId = id;
}
uint32_t PacketEventAbstract::getId() {
	return myId;
}
