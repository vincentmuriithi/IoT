/*
 * This code is a test code to control a motor shield in this case (L298N) but any other motor
 * shield could be used.
 * Author: Vincent M Karimi
 */

#define TRIG 10
#define ECHO 9
#define MOTOR1A 7
#define MOTOR1B 8
#define MOTOR2A 2
#define MOTOR2B 4
#define MAX_DISTANCE 400
int long duration, distance;
void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, LOW);
Serial.println("Loading....");
}

void loop() {
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  delayMicroseconds(15);
  digitalWrite(TRIG, HIGH);

  duration = pulseIn(ECHO, HIGH);
  distance = (duration * 0.034) / 2;
  
//Trying to ensure that distance does not exceed a distance of 400 cm 
 if (distance <= MAX_DISTANCE)
  {
    if (distance <= 15)
    {
  digitalWrite(MOTOR1A, HIGH);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, HIGH);
  digitalWrite(MOTOR2B, LOW);
    }
    else if (distance >= 15 && distance <= 45)
    {
      digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, HIGH);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, HIGH);
    }
    else{
digitalWrite(MOTOR1A, LOW);
 digitalWrite(MOTOR1B, LOW);
digitalWrite(MOTOR2A, LOW);
 digitalWrite(MOTOR2B, LOW);
    }
  }
delay(2000);

}
