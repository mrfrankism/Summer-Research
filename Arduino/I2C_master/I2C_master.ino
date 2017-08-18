#include <Wire.h>

byte sample[31];

byte addresses[] = {10}; //array to store all the addresses for the different slave boards
#define interruptPin 8


void setup() {
  // put your setup code here, to run once:

  pinMode(interruptPin, OUTPUT); //configure interrupt pin on master to be output
  Wire.begin();
  Serial.begin(250000);
}

void loop() {
  startSample();
  get30Samples();
  //delay(50);

}

void serialEvent(){
  while(Serial.available() > 0){
    
    String CMD = Serial.readStringUntil('\n');
    Serial.print("Address read: ");

    if(CMD.equals("getData")){
      get30Samples();
    }else if(CMD.equals("startSample")){
      startSample();
    }else{
        Serial.println(CMD + " is not a valid command");
  }
}

}

void startSample(){
        digitalWrite(interruptPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(interruptPin, LOW); 
}

void get30Samples(){
        Wire.requestFrom(0x26, 31);
      Serial.println("Getting data from slave");    
      
      int i = 0;
      while(Wire.available()){
        sample[i] = Wire.read();
        i++;
      }
      
      Serial.println("Printing data to PC Serial port");
      for(int i = 0; i<30; i++){ // write the data to serial port
        Serial.println(sample[i]);
      }
      Serial.print("Total time to sample: ");
      Serial.print(4*sample[30]);
      Serial.println(" us");
      Serial.print("Time taken per sample: ");
      unsigned long timePerSample = 4*sample[30]/30;
      Serial.print(timePerSample);
      Serial.println(" us");
}

