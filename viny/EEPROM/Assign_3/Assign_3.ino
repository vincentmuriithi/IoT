#include <EEPROM.h>
void setup() 
{
  Serial.begin(9600);
}
int address;
int dataToWrite;

void loop() 
{
  String buffer = "";
  buffer = Serial.readString();
  if(buffer.startsWith("read")) {
    address = buffer.substring(buffer.indexOf(' ') +1).toInt();
    Serial.print("Data from the Address : ");
    Serial.print(address);
    Serial.println();
    Serial.println(EEPROM.read(address)); 
  } else if(buffer.startsWith("write")) {
    address = buffer.substring(12,8).toInt();
    dataToWrite = buffer.substring(9).toInt();
    Serial.print("Written ");
    Serial.print(dataToWrite);
    Serial.println();
    Serial.print("to the Address: ");
    Serial.print(address);
    Serial.println();
    EEPROM.write(address,dataToWrite); 
  }
}
