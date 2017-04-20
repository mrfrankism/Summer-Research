#include <Wire.h>
byte sample[3500];

#define sensorPin 16
#define interruptPin 8
#define myAddress 10

void setup() {
  // put your setup code here, to run once:
Wire.begin(myAddress);
Wire.onRequest(send_Data);
pinMode(interruptPin, INPUT);
attachInterrupt(interruptPin, takeSample, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void send_Data(){
Wire.write(sample, sizeof(sample));
}

void takeSample(){
  for(int i =0; i < sizeof(samples); i++){
    sample[i] = analogRead(sensorPin);
  }
}

