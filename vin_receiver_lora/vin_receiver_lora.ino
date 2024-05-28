//#include <SPI.h>
#include <LoRa.h>

#define SS_PIN 53
#define RST_PIN 25
#define DIO0_PIN 27

unsigned long int previousTime = 0;
const unsigned long int interval = 2000;
struct Student{
  char jina[20];
  int namba;
  char school[20];
  char profession[20];
} typedef Student;
class Person{
  public:
  Person(){
    Serial.println("Lora-Tech...");
    LoRa.setPins(SS_PIN, RST_PIN, DIO0_PIN);
    LoRa.setSpreadingFactor(11);
    LoRa.setSignalBandwidth(50000);
    lora();
  }

  void lora(){
    if(!LoRa.begin(433E6)){
        Serial.println("failed");
        lora();
    }
    else
       Serial.println("connected");
    return;
  }
};

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Person();
  printer();
}

void loop(){
  //Serial.println("searching data...");
  unsigned long int currentTime = millis();
  LoRa.receive();
  Student *student = (Student*)malloc(sizeof(Student));
  int dataSize = sizeof(student->jina) + sizeof(student->namba) + sizeof(student->school) + sizeof(student->profession);
  if (currentTime - previousTime > interval){
int packetSize = LoRa.parsePacket();
if (packetSize > 0){
  while (LoRa.available()){
    for (int i = 0; i < dataSize; i++){
      *(reinterpret_cast<uint8_t*>(student) + i) = LoRa.read();
    }
  }

  Serial.println("Student name: " + String(student->jina));
  Serial.println("Student Id: " + String(student->namba));
  Serial.println("Student School: " + String(student->school));
  Serial.println("Student profession: " + String(student->profession));
  Serial.println("");
} 
previousTime = currentTime;
  }
  free(student);
}

void printer(){
Serial.println("vincent receiver"); 
}
