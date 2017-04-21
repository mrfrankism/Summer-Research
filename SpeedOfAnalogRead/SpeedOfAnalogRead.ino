
byte sample[3500];
#define analogPin A3
void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
takeSampleAndPrint();

}

void takeSampleAndPrint(){
  unsigned long startTime = micros();
  for(int i=0;i<sizeof(sample);i++){
    sample[i] = analogRead(analogPin)/4;
  }
  unsigned long totalTime = micros() - startTime;

    for(int i=0;i<sizeof(sample);i++){
    Serial.println(sample[i]);
  }

  Serial.print("Total time to take 3500 samples: ");
  Serial.print(totalTime);
  Serial.println(" us");

  
  Serial.print("Time per sample: ");
  Serial.print(totalTime/3500);
  Serial.println(" us");
}

