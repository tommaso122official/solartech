#include <Servo.h>
#define wait 50
Servo myservo1, myservo2;
int analogPin = A2;
/*int ser1 = 0;
int ser2 = 0;*/
int maxVoltage2 = 0;
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
  delay(100);  // Tempo utile per raggiungimento della posizione
  myservo2.write(22);
  delay(100);  // Tempo utile per raggiungimento della posizione
  for (int pos1 = 0; pos1 <= 270; pos1++) {
    myservo1.write(pos1);
    int voltage = analogRead(analogPin);
     if (voltage > maxVoltage) {
        maxVoltage = voltage;
        optimalPos1 = pos1;
      }
    delay(wait);
    }
    myservo1.write(optimalPos1);
    myservo2.write(0);
    delay(wait);
  for(int pos2=0;pos2<=45;pos2++)
  {
    myservo2.write(pos2);
    int voltage2 = analogRead(analogPin);
      Serial.print(voltage2);
      Serial.print(" ");
     if (voltage2 > maxVoltage2) {
        maxVoltage2 = voltage2;
        optimalPos2 = pos2;
      }
      delay(wait);
  }
  myservo2.write(optimalPos2);

  delay(1200000);
}
