int sensorValue;
int sensorHigh = 0;
int sensorLow = 1023;

const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  // calibrate instrument
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW); // calibration finished

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 1500, 3000);
  
  tone(8, pitch, 20);
  
  delay(10);

}
