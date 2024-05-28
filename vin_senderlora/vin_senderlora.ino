#include <SPI.h>
#include <LoRa.h>

#define NSS 53
#define RST 24
#define DI00_PIN 22

unsigned long previousTime = 0;
const unsigned long interval = 1000;
bool ledStatus = true;
struct Student{
  char jina[20];
  int namba;
  char school[20];
  char profession[20];
} typedef Student;
Student student;
Student *req_data = &student;

void initialize(){
  if (!LoRa.begin(433E6)){
     //Serial.println("Lora Initialization failed");
     initialize();
  }
  else
      return;
    //Serial.println("LoRa Initialization was succesful");  
}
//void printer(){
//Serial.println("vincent"); 
//}
void setup(){
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  //while(!Serial);
  //printer();
  LoRa.setPins(NSS, RST, DI00_PIN);
  LoRa.setTxPower(20);
  LoRa.setSpreadingFactor(12);
  LoRa.setSignalBandwidth(50000);
  initialize();
  strncpy(req_data->jina, "Eng Vincent", sizeof(req_data->jina) - 1);
  req_data->jina[sizeof(req_data->jina) - 1] = '\0';
  req_data->namba = 1235;
  strncpy(req_data->school, "TUM", sizeof(req_data->school) - 1);
  req_data->jina[sizeof(req_data->school) - 1] = '\0';
  strncpy(req_data->profession, "Engineering", sizeof(req_data->profession) -1);
  req_data->profession[sizeof(req_data->profession) - 1] = '\0';
  //digitalWrite(LED_BUILTIN, ledStatus);
}
void loop(){
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= interval){
LoRa.beginPacket();
LoRa.write(reinterpret_cast<uint8_t*>(req_data), sizeof(Student));
//Serial.println("transmitting data...");
LoRa.endPacket();
if (ledStatus){
  ledStatus = false;
  digitalWrite(LED_BUILTIN, ledStatus);
}
else{
  ledStatus = true;
  digitalWrite(LED_BUILTIN, ledStatus);
}
previousTime = currentTime;
  }  
}
