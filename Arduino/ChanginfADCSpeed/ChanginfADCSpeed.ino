// Arrays to save our results in
unsigned long start_times[2];
unsigned long stop_times[2];
byte values[3500];


// Define various ADC prescaler
//const unsigned char PS_16 = (1 << ADPS2);
//const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
//const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
//const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

// Setup the serial port and pin 2
void setup() {
  Serial.begin(250000);
  //pinMode(2, INPUT);

  // set up the ADC
 // ADCSRA &= ~PS_128;  // remove bits set by Arduino library

  // you can choose a prescaler from above.
  // PS_16, PS_32, PS_64 or PS_128
 // ADCSRA |= PS_16;    // set our own prescaler to 64 

}


void loop() {
  Serial.println("HelloWorld");  
//  unsigned long startTime = micros();
//  for(byte x = 0; x <16; x++){
//    Serial.println(analogRead(x));
//  }
//  Serial.print("T: ");
//  Serial.println(micros() - startTime);
// readAndTransmitEachChannel();
 //readAllChannelsThenTransmitAllData();
  fillArrayandTransmit(0);
//timeToReadandStoreAChannel();
//readOneChannelFast(0);
//  // print out the results
//  Serial.println("\n\n--- Results ---"); 
//  for(i=0;i<100;i++) {
//    Serial.print(values[i]);
//    Serial.print(" elapse = ");
//    Serial.print(stop_times[0] - start_times[0]);
//    Serial.print(" us\n");
//  }
  delay(60000);
}

void timeToReadandStoreAChannel(){
      for(int i=0;i<16;i++) {
    start_times[i] = micros();
    values[i] = analogRead(i);
    stop_times[i] = micros();
    Serial.print(values[i]);
    Serial.print(" elapse = ");
    Serial.print(stop_times[i] - start_times[i]);
    Serial.print(" us\n");
  }
  int totalTime = 0;
  for(int i=0;i<16;i++) {
   totalTime = totalTime + (stop_times[i] - start_times[i]);
  }
  Serial.println("Total time elapsed = ");
  Serial.println(totalTime);
}
void readAndTransmitEachChannel(){//RETEST THIS FOR SWITCHING CHANNELS
  //Reads a channel and transmits the data over serial
  //then moves on to the next channel
  //delay between each reading 220us
  //total delay to transmit 16 channels 3608us
    for(int i=0;i<16;i++) {
    start_times[i] = micros();
    values[i] = analogRead(i);
    Serial.print(values[i]);
    stop_times[i] = micros();
    Serial.print(" elapse = ");
    Serial.print(stop_times[i] - start_times[i]);
    Serial.print(" us\n");
  }
  int totalTime = 0;
  for(int i=0;i<16;i++) {
   totalTime = totalTime + (stop_times[i] - start_times[i]);
  }
  Serial.println("Total time elapsed = ");
  Serial.println(totalTime);

}

void readAllChannelsThenTransmitAllData(){
  // capture the values to memory
  //time to record 16 values 516us
  //time to transmit data 3234us
      start_times[0] = micros(); // time to start reading channels
  for(int i=0;i<16;i++) {
    values[i] = analogRead(i);
  }
      stop_times[0] = micros(); //stop time for reading channels
      start_times[1] = micros(); //time to start transmitting data
  for(int i=0;i<16;i++){
    Serial.println(values[i]);
  }
      stop_times[1] = micros();//stop time for transmission
    Serial.print("Time to record 16 channels = ");
    Serial.print(stop_times[0] - start_times[0]);
    Serial.print("  Time to transmit data = ");
    Serial.print(stop_times[1] - start_times[1]);
    Serial.print(" us\n");
    Serial.print("Total time elapsed = ");
    Serial.println((stop_times[0] - start_times[0])+(stop_times[1] - start_times[1]));
}

void fillArrayandTransmit(byte channel){
   // capture the values to memory
 // boolean stopped = false;
  start_times[0] = micros(); // time to start reading channels
    for(int x = 0; x<sizeof(values); x++){  
       values[x] = analogRead(channel)>>2; //fill a 6400 array of readings
      //delay(20);
//      if(values[i*16+x] == 0) {
//        zeroCounter ++;
//      }
  }
   
  stop_times[0] = micros(); //stop time for reading channels
  start_times[1] = micros(); //time to start transmitting data
  
  for(int i=0;i<sizeof(values);i++){
    Serial.print("I: "); //Next three lines show me the index for the values
    Serial.print(i);     // in the array
    Serial.print(" | ");
    Serial.println(values[i]);//print the 6400 values to serial
  }
    stop_times[1] = micros();//stop time for transmission
    
    Serial.print("Time to record 1300 readings = ");
    Serial.println(stop_times[0] - start_times[0]);
    Serial.print("  Time to transmit data = ");
    Serial.print(stop_times[1] - start_times[1]);
    Serial.print(" us\n");
    Serial.print("Total time elapsed = ");
    Serial.println((stop_times[0] - start_times[0])+(stop_times[1] - start_times[1]));
    
}

void readOneChannelFast(byte channel){
  for(int i = 0; i < 100; i++){
    values[i] = analogRead(channel);
  }

    for(int i = 0; i < 3200; i++){
    Serial.println(values[i]);
  }
  
}



