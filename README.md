# SimplePacketComs
A simple packet coms library. This is the definition page and C++ implementation of SimplePacketComs. 

# Theory Of Opperation

SimplePacketComs is a protocol spec for transmitting data from one endpoint to another. The goal is to allow many different commands to be sent and recived on a single communication channel, with an easy to extend framework. The assumptions that we made is that the physical layer will send and recive alligned, checksummed packets of data. 

## Packet Structure

Packets consist of 4 bytes to define the command ID and N bytes (detected from the PHY) of data. The Command ID is parsed as a 32 bit unsigned int. The data can be sent as raw bytes or 32 bit floating point numbers. 

By convention a standard packet is 64 bytes. If both sides of an implementation change this, it does nto break spec, but for "Simplicity" this is not transmitted in packet data and must be agreed upon ahead of time by both sides of the command stack. 

### Byte Packets

An example byte packet from the Game Controller looks like this:

| |ID | byte 0 |byte 1 |byte 2 |byte 3 |byte 4 |byte 5 |byte 6 |byte 7 |byte 8 |byte 9 |byte 10 |byte 11 |byte 12 |byte 13 |byte 14 |byte 15 |byte 16 |byte 17 |byte 18 |byte 19 |
|--- |--- | --- |--- | --- |--- | --- | --- | --- |--- | --- |--- | --- | --- | --- |--- | --- |--- | --- | --- |--- |--- |
| downstream Bytes |4 | 1 | 1 | 1 | 1 | 1 | 1 |1 | 1 | 1 | 1 | 1 | 1 |1 | 1 | 1 | 1 | 1 | 1 |1|1|
| Contents downstream |1970 | Controller ID| JoyXLeft | JoyYLeft | JoyXRight | JoyYRight | TriggerLeft | TriggerRight |PadRight/PadLeft| PadDown/PadUp |--- |--- |ButtonX|ButtonY|ButtonA|ButtonB|ButtonMinus/getButtonPlus|ButtonHome|---|ButtonZLeft|ButtonZRight|
| upstream Bytes |4 | 60 |
| Contents upstream |1970 | Byte data to be printed by the game controller server|


### Float packets

An example float packet from the ware house robot looks like this:

| |ID | float |float |float |float |float |float |
|--- |--- | --- |--- | --- |--- | --- | --- |
| downstream Bytes |4 | 4 | 4 | 4 | 4 | 4 | 4 |
| Contents downstream |1936 | pickup area | pickup x | pickup z | drop off area | drop off  x | drop off  z |
| upstream Bytes |4 | 0 |
| Contents upstream |1936 | ---|



# Known Stack implementations

## Arduino

In Library Manager search for SimplePacketComs

## C++

https://github.com/madhephaestus/SimplePacketComs/

## Java

### Gradle 

```
repositories {
//com.neuronrobotics hosting point
maven { url 'https://oss.sonatype.org/content/repositories/staging/' }
}
dependencies {
compile "com.neuronrobotics:SimplePacketComsJava:0.3.0"
}
```
### Source

https://github.com/madhephaestus/SimplePacketComsJava

## Matlab (Experemental)

https://github.com/WPIRoboticsEngineering/RBE3001_Matlab

# Known Microcontroller Phy's

## MBED C++ USB HID (Example using Mbed HID)

https://github.com/WPIRoboticsEngineering/RBE3001_nucleo_firmware

## Arduino Teensy 3.2-6 HID

In Library Manager search for Teensy32SimplePacketComs

## Arduino ESP32 WiFi UDP

In Library Manager search for Esp32SimplePacketComs



