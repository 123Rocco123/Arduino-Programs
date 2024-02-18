#include <TimeLib.h>

const int greenPin = 2;
const int yellowPin = 6;
const int redPin = 9;

int lightSequence = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  time_t startingTime = now();

  if (lightSequence == 0) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);

    digitalWrite(greenPin, HIGH);
  } else if (lightSequence == 1) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);

    digitalWrite(yellowPin, HIGH);
  } else {
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);

    digitalWrite(redPin, HIGH);
  }

  delay(5000); // Delay for 1 second

  if (lightSequence == 2) {
    lightSequence = 0;
  } else {
    lightSequence += 1;
  }
}
