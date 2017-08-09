#include <SerialRAM.h>


SerialRAM ram;

const uint8_t data[27] = "abcdefghijklmnopqrstuvwxyz";
const uint8_t data2[27];

void setup() {
  Serial.begin(115200);
  ram.begin();

  Serial.println("Start");

}

void loop() {

  //reset data2
  memset(data2, 0x00, 27);
  
  //write the entire 27 bytes of data, starting from address 0x00
  ram.write(0x0000, data, 27);

  //read 27 bytes from address 0x0000
  ram.read(0x0000, data2, 27);

  Serial.print("Wrote: ");
  Serial.print((char*)data);
  Serial.print(" - Read: ");
  Serial.print((char*)data2);
  if(strcmp(data, data2) == 0){
    Serial.println(" - OK!");
  }
  else{
    Serial.println(" - KO! Could not read back what was written. Check your pullup resistors and circuit!");
  }
  
  
  delay(1000);

}
