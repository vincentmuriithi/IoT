#include <EEPROM.h>
int t;
int value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
value = EEPROM.read(t);
Serial.print(t);
Serial.print("\t");
Serial.print(value);
Serial.println();
t = t+1;
if(t==300){
  t=0;
  delay(500);
}


  

}
