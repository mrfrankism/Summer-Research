
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

}


void serialEvent(){
   while(Serial.available() > 0){
    String addressCmd = Serial.readStringUntil('\n');
    Serial.print("Address read: ");
    Serial.println(addressCmd);
    //Serial1.println(addressCmd);
    if(addressCmd.equals(myAddress)){
      Serial.println("Thats my address!");
    }else if(addressCmd.equals(myAddress + "giveData")){
      //Serial.println("Writing command to hello");
      Serial1.println("hellogivedata");
    }else if (addressCmd.equals(myAddress + "startSamples")){
      digitalWrite(interruptPin, HIGH);
      delay(10);
      digitalWrite(interruptPin, LOW);
      Serial.println("Started Samples");
    }else if(addressCmd.equals(myAddress + "ping")){
      HWSerial.println("hello");
    }else{
         Serial.println(addressCmd);
  }
   }
   }
   void serialEvent1(){
      while(HWSerial.available() > 0){
  //read the data from the serial1 port and dump it to the serial 
  //port to the computer 
  //Serial.println("Reading data from HWSerial");
  Serial.println(HWSerial.readStringUntil('\n'));
  }
   }




