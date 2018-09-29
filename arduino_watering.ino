int threshold = 600; ///set moisture threshold
long duration = 20*1000L; ///set watering duration in ms
long waitTime = 60*60*1000L; ///set interval in ms
int PumpPin = 2; ///set pump pin number
int moist ;
void setup() {
  pinMode(PumpPin, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  Serial.print("Reading from sensor");
  digitalWrite(PumpPin, HIGH);
  digitalWrite(PumpPin, LOW);//a check to see if the water is flowing
  delay(1500);
  digitalWrite(PumpPin, HIGH);
  
}

void loop() {
  moist= analogRead(A0);
  Serial.print("\nmoisture is:");
  Serial.print(moist);
  if (moist>threshold){
    digitalWrite(PumpPin, LOW);
    Serial.print("\nwatering!");
    delay(duration);
    digitalWrite(PumpPin, HIGH);
  }
  delay(waitTime);
  

}
