
byte interruptPin = 8;
String myAddress = "master"; //this is the master board controlling the others...

char samples [3500];
void setup() {
  Serial.begin(250000);
  Serial1.begin(250000);
  pinMode(interruptPin, OUTPUT); //set the interrupt pin to output to trigger the slave boards
}

void loop() {

}




void serialEvent(){
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
Serial.println(Serial1.read());
}

