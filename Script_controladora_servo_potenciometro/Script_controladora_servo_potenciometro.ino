#include <Servo.h>

const int servoPin = 8;
const int analogInPin = A0;
const int analogOutPut = 6;

int sensorValue = 0;
int outputValue = 0;

Servo servo;

void setup() {
    Serial.begin(9600);
    servo.attach(servoPin);
}

void loop() {
  
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(analogOutPut, outputValue);
  
  int servoPos = map(sensorValue, 0, 1023, 0, 180);
  servo.write(servoPos);
  delay(15);

}
