#include <Wire.h>
byte sample[31];

#define LED 13
#define analogPin A3
#define interruptPin 8
#define myAddress 0x26

void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
  
Wire.begin(myAddress);
Wire.onRequest(send_Data);
pinMode(interruptPin, INPUT);
attachInterrupt(interruptPin, takeSample, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void send_Data(){
//for(int b =0; b<sizeof(sample)/32; i++){
  //Wire.write(sample, sizeof(sample)/32);
//}
     
   Wire.write(sample,31);
}

void takeSample(){
  digitalWrite(LED, HIGH);
  unsigned long startTime = micros();
  for(int i =0; i < 30; i++){
    sample[i] = analogRead(analogPin)/4;
   //sample[i] = 100/4;
  }
  unsigned long stopTime = micros();
  sample[30] = (stopTime-startTime)/4; //store the amount of time to take 30 samples
  //delay(1000);
  digitalWrite(LED, LOW);
}

