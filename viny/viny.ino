void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int k = 0;
 k++;
while( k<5){
  
  break;
  Serial.print("Hello World\n");
  
  if(k==3){
    Serial.print("Hello World\n");
    break;
  }
}
 
}
