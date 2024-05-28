#include <ESP8266WiFi.h>        // Include the Wi-Fi library
#include <ESP8266WiFiMulti.h>   // Include the Wi-Fi-Multi library

ESP8266WiFiMulti wifiMulti;  // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
WiFiClient client;
void setup() {
  Serial.begin(9600);         // Start the Serial communication to send messages to the computer
  delay(10);
  wifiMulti.addAP("WALTER", "njalo1994");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("Walter", "njalo1994");

  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(1000);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());  
  Serial.println(WiFi.RSSI());
}

void loop() { }
