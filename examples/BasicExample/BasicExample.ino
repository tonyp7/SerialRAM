#include <SerialRAM.h>


SerialRAM ram;

void setup() {
  Serial.begin(115200);
  ram.begin();

}

void loop() {
  uint8_t buffer = 0x00;
  uint8_t randomByte = random(256);
  uint16_t randomAddress = random(0x0200);
  
  

  ram.write(randomAddress, randomByte);
  buffer = ram.read(randomAddress);

  Serial.print("Wrote byte: 0x");
  Serial.print(randomByte, HEX);
  Serial.print(" at address 0x");
  Serial.print(randomAddress, HEX);
  Serial.print(" - Read back value: 0x");
  Serial.print(buffer, HEX);

  if(randomByte == buffer){
    Serial.println(" - OK!");
  }
  else{
    Serial.println(" ERROR! Values do not match! Check your pullup resistors and wiring");
  }
  
  delay(1000);

}
