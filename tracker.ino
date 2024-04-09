#include <Servo.h>
#define wait 100
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
  myservo1.write(0);
  delay(wait);  // Tempo utile per raggiungimento della posizione
  myservo2.write(0);
  delay(wait);  // Tempo utile per raggiungimento della posizione
  for (int pos1 = 0; pos1 <= 90; pos1++) {
    int elab1=pos1*3;
    myservo1.write(elab1);
    delay(wait);  // Tempo utile per raggiungimento della posizione
    for (int pos2 = 0; pos2 <= 30; pos2++) {
      int elab2=pos2*3;
      myservo2.write(elab2);
      delay(wait);  // Tempo utile per raggiungimento della posizione
      int voltage = analogRead(analogPin);
      Serial.println(" ");
      Serial.print("mV: ");
      Serial.print(voltage);
      Serial.print(" pos1: ");
      Serial.print(pos1);
      Serial.print(" pos2: ");
      Serial.print(pos2);
      if (voltage > maxVoltage) {
        maxVoltage = voltage;
        optimalPos1 = pos1;
        optimalPos2 = pos2;
      }
    }
  }

  myservo1.write(optimalPos1);
  myservo2.write(optimalPos2);
  Serial.println(" ");
  Serial.print("Optimal Position 1: ");
  Serial.print(optimalPos1);
  Serial.print(", Optimal Position 2: ");
  Serial.print(optimalPos2);
  Serial.print(", Max Voltage: ");
  Serial.println(maxVoltage);

  delay(1200000);
}
