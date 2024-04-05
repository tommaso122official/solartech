#include <Servo.h>

Servo myservo1, myservo2;
int analogPin = A1;
int ser1 = 0;
int ser2 = 0;
int maxVoltage = 0;
int optimalPos1 = 0;
int optimalPos2 = 0;
void setup() {
  myservo1.attach(9);
  myservo2.attach(8);
  Serial.begin(9600);
}

void loop() {

  for (int pos1 = 0; pos1 <= 90; pos1++) {
    int elab1=pos1*3;
    myservo1.write(elab1);
    delay(100);  // Tempo utile per raggiungimento della posizione
    for (int pos2 = 0; pos2 <= 30; pos2++) {
      int elab2=pos2*3;
      myservo2.write(elab2);
      delay(100);  // Tempo utile per raggiungimento della posizione
      int voltage = analogRead(analogPin);
      if (voltage > maxVoltage) {
        maxVoltage = voltage;
        optimalPos1 = pos1;
        optimalPos2 = pos2;
      }
    }
  }

  myservo1.write(optimalPos1);
  myservo2.write(optimalPos2);

  Serial.print("Optimal Position 1: ");
  Serial.print(optimalPos1);
  Serial.print(", Optimal Position 2: ");
  Serial.print(optimalPos2);
  Serial.print(", Max Voltage: ");
  Serial.println(maxVoltage);

  delay(1200000);
}


