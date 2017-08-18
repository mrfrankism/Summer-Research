
//we have 3 serial ports being used...
//Serial is for computer to teensy communication
//Serial1 or HWSerial is to tell the other teensys to transmit their data
//Serial2 or HWSerial2 is to recieve data from the other teensys

byte interruptPin = 8;
String myAddress = "master"; //this is the master board controlling the others...

char samples [3500];
#define HWSerial Serial1
#define HWSerial2 Serial2
void setup() {
  Serial.begin(250000);
  HWSerial.begin(250000);
  HWSerial2.begin(250000);
  pinMode(interruptPin, OUTPUT); //set the interrupt pin to output to trigger the slave boards
}

void loop() {
startSample();
HWSerial.println("hellogivedata\n");
delay(100);
}


void serialEvent(){
   while(Serial.available() > 0){
    String addressCmd = Serial.readStringUntil('\n');
    //Serial1.println(addressCmd);
    if(addressCmd.equals(myAddress)){
      Serial.println("Thats my address!");
    }else if(addressCmd.equals(myAddress + "giveData")){
      //Serial.println("Writing command to hello");
      HWSerial.print("hellogivedata\n");
    }else if (addressCmd.equals(myAddress + "startSamples")){
      startSample();
      Serial.println("Started Samples");
    }else if(addressCmd.equals(myAddress + "ping")){
      HWSerial.print("hello\n");
    }else{
      Serial.println("Command not found");
       //Serial.print("Data read: ");
       //Serial.println(addressCmd);
       //Serial1.println(addressCmd); //else print to the other serial port
  }
   }
   }

   void startSample(){
      digitalWrite(interruptPin, HIGH);
      delay(10);
      digitalWrite(interruptPin, LOW);
   }



void serialEvent2(){
  while(HWSerial2.available()>0){
   Serial.println(HWSerial2.readStringUntil('\n'));
  }
}



