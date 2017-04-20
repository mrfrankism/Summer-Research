#include <Wire.h>

byte sample[3500];

byte addresses[] = {10}; //array to store all the addresses for the different slave boards
#define interruptPin 8


void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent1(){
  while(Serial.available() > 0){
    
    String CMD = Serial.readStringUntil('\n');
    Serial.print("Address read: ");

    if(CMD.equals("getData")){
      for(int i = 0; i<sizeof(sample); i++){
        String data = "" + sample[i];
        Serial.println("Im here"); 
      }
    }else if(CMD.else{
    Serial.println(CMD + " is not a valid command");
  }
}
}
