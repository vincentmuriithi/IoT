#include <SPI.h>
#include <LoRa.h>

#define RST_PIN 14
#define SS_PIN 5
#define DIO0_PIN 2

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");
  LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);
  LoRa.setSpreadingFactor(8);
  LoRa.setSignalBandwidth(125000);
 
  //LoRa.setSignalBandwidth(125E3);

  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    delay(250);
  }

  
  Serial.println("LoRa initialized successfully!");
 LoRa.receive();
 
}

void loop() {
int packetSize = LoRa.parsePacket(); // Check for available data
Serial.println("Waiting for data");
  if (packetSize > 0) {
    // Read and print each byte of the received packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println("Signal strength is: " + String(LoRa.packetRssi()));
    Serial.println("Signal-to-Noise-Ratio is: " + String(LoRa.packetSnr()));// Print a newline for better readability
  }

  // Your additional loop code here
  delay(500); // Add a delay or other logic if needed
}

void onReceive(int packetSize) {
  // received a packet
  
  //Serial.println("Received packet '");
 
  // read packet
  for (int i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }
}
