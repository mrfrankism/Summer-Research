// Arrays to save our results in
// L - for Teensy LC 
byte board = 'L'; // Used to define proper variables and etc...
byte interruptPin = 8;
String myAddress = "hello";
byte analogReadPin = 0;

/* Board -------------------- Max Number of Samples 
 * Teensy -------------------    3500
 * Arduino UNO --------------    1500
 */
byte sample [3500]; 


  

#if (board == 'A') //only used to set the Arduino UNO's ADC to a higher speed
  // Define various ADC prescaler
  const unsigned char PS_16 = (1 << ADPS2);
  const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
  const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
  const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

      // set up the ADC
    ADCSRA &= ~PS_128;  // remove bits set by Arduino library
    // you can choose a prescaler from above.
    // PS_16, PS_32, PS_64 or PS_128
    ADCSRA |= PS_16;    // set our own prescaler to 64 
    
#endif


byte LED = 13;
void setup() {
  pinMode(LED, OUTPUT);
  Serial1.begin(250000);
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  attachInterrupt(interruptPin, takeSample, RISING);
}

void takeSample(){

  digitalWrite(LED, HIGH);
  delay(1000);
  for(int i = 0; i < sizeof(sample); i++){
    sample[i] = analogRead(analogReadPin);
  }
  digitalWrite(LED,LOW);

}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  Serial1.println("hello from over here");
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}

void serialEvent(){
  while(Serial1.available() > 0){
    String addressCmd = Serial1.readStringUntil('\n');
    Serial1.print("Address read: ");
    Serial1.println(addressCmd);
    if(addressCmd.equals(myAddress)){
      Serial1.println("Thats my address!");
    }else if(addressCmd.equals(myAddress + "givedata")){
      for(int i = 0; i<sizeof(sample); i++){
        Serial1.println(sample[i]); 
      }
  }
}
}

