
byte interruptPin = 8;
String myAddress = "master"; //this is the master board controlling the others...

char samples [3500];
#define HWSerial Serial1
void setup() {
  Serial.begin(250000);
  HWSerial.begin(250000);
  pinMode(interruptPin, OUTPUT); //set the interrupt pin to output to trigger the slave boards
}

void loop() {
  if(HWSerial.available() > 0){
      String data = HWSerial.readStringUntil('\n');
      Serial.println(data);
  }
  if(Serial.available() > 0){
    String data = Serial.readStringUntil('\n');
    Serial.println("Read: " + data);
  }
}


void serialEvent(){


}
/*
void serialEvent(){
  while(HWSerial.available() > 0){
  //read the data from the serial1 port and dump it to the serial 
  port to the computer 
  }
   while(Serial.available() > 0){
    String addressCmd = Serial.readStringUntil('\n');
    Serial.print("Address read: ");
    Serial.println(addressCmd);
    Serial1.println(addressCmd);
    if(addressCmd.equals(myAddress)){
      Serial.println("Thats my address!");
    }else if(addressCmd.equals(myAddress + "giveData")){
      Serial1.println("hellogivedata");
      Serial1.readBytes(samples,3500);  
      //Serial.println(samples);
     for(int i = 0; i< sizeof(samples); i++){
        Serial.println(Serial1.read());
      }
    }else if (addressCmd.equals(myAddress + "startSamples")){
      digitalWrite(interruptPin, HIGH);
      delay(1000);
      digitalWrite(interruptPin, LOW);
      Serial.println("Started Samples");
    }else{
         Serial.println(addressCmd);
  }
}
}
*/


