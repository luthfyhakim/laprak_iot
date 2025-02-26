#include <Arduino.h>

// put function declarations here:
#define RED_LED 23
#define YELLOW_LED 19
#define GREEN_LED 18

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // Red Light ON
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  Serial.println("RED LIGHT ON");
  delay(3000);

  // Yellow Light ON
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  Serial.println("YELLOW LIGHT ON");
  delay(3000);

  // Green Light ON
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  Serial.println("GREEN LIGHT ON");
  delay(3000);
}
