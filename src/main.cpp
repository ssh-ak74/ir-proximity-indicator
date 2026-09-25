#include <Arduino.h>

#define IR_PIN 27
#define GREEN_LED 25
#define RED_LED 26

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  if (digitalRead(IR_PIN) == LOW) {
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RED_LED, HIGH);
    Serial.println("OBSTACLE");
    delay(150);

    digitalWrite(RED_LED, LOW);
    delay(150);
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    Serial.println("CLEAR");
    delay(100);
  }
}
