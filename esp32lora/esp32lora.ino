#include <SPI.h>
#include <LoRa.h>

#define RST_PIN 14
#define SS_PIN 5
#define DIO0_PIN 2

void setup() {
 Serial.begin(9600);
  while (!Serial);
  }

  Serial.println("LoRa Sender");
  
  LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);
  LoRa.setTxPower(19);
  LoRa.setSpreadingFactor(8);
  LoRa.setSignalBandwidth(125000);
 
  

  while (!LoRa.begin(433E6)) {
    //Serial.println("LoRa init failed. Check your connections.");
    Serial.println("esp32lora init failed.Reconnecting...");
    delay(250);

 // LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);

  //Serial.println("LoRa initialized successfully!");
}

void loop() {
  //Serial.println("Sending packet...");
  Serial.println("esp32lora connected");   // turn the LED on (HIGH is the voltage level)  
  LoRa.beginPacket();
  LoRa.print("Hello, LoRa! by Vincent");
  LoRa.println("");
  LoRa.endPacket();               
  delay(1000);  
}
