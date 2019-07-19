#include <Servo.h>

Servo servo;   // Create a servo object to control the servo
int pos = 180;
int eLDRPin = A0;
int wLDRPin = A1;
int eastLDR = 0;
int westLDR = 0;
int dark = 100;
int light = 600;
int Servoset = 180;
int difference = 10;

void setup() {
  servo.attach(9);
  servo.write(pos);
  Serial.begin(9600);
}

void loop() {
  eastLDR = analogRead(eLDRPin);
  westLDR = analogRead(wLDRPin);
  delay(50);
  Serial.println(eastLDR);
   Serial.println(westLDR);
  if (eastLDR > westLDR + difference) {
     Servoset --;
    servo.write(Servoset);
  }
  else if (westLDR > eastLDR + difference) {
    Servoset ++;
    servo.write(Servoset);
  }

}
