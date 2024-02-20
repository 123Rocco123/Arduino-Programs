const int ledZero = 8;
const int ledOne = 6;
const int ledTwo = 4;
const int ledFour = 2;

int oneState = 0;
int addState = 0;
int minusState = 0;
int equalsState = 0;

const int addOne = 13;
const int minus = 12;
const int plus = 11;
const int equals = 10;

int lightNumber = 0;

int previousNumber = 0;
int currentNumber = 0;
int minusOrAdd = 0;

// Function used to turn off the LEDS
void turnLEDSOff() {
  digitalWrite(ledZero, LOW);
  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, LOW);
  digitalWrite(ledFour, LOW);
}

// Function used to reset the LEDs to base where only the 0 LED is on
void resetLEDS() {
  digitalWrite(ledZero, HIGH);

  digitalWrite(ledOne, LOW);
  digitalWrite(ledTwo, LOW);
  digitalWrite(ledFour, LOW);
}

// Function used to check the current number that we've passed into the calculator
void checkNumber(int currentCalc) {
  // While loop used to check that while the number is less than 7, then we subtract from the value lighting up the LEDs with the values that add up the currentCalc variable
  while (currentCalc != 0 && currentCalc <= 7) {
    if (currentCalc >= 4) {
      digitalWrite(ledFour, HIGH);
      currentCalc -= 4;
    }
    if (currentCalc >= 2) {
      digitalWrite(ledTwo, HIGH);
      currentCalc -= 2;
    }
    if (currentCalc == 1) {
      digitalWrite(ledOne, HIGH);
      currentCalc -= 1;
    }
  }

  // If instead we have a value greater than we can display, then we turn all of the lights to signal it
  if (currentCalc > 7) {
    digitalWrite(ledZero, HIGH);
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, HIGH);
    digitalWrite(ledFour, HIGH);
  }
}

// Function used to check which button has been pressed
  // Parameters contain the state of the button 
void equationPressed(int minusState, int addState, int equalsState) {
   if (minusState == HIGH) {
    // Variable used to make it so that the program knows which operation has to be performed
    minusOrAdd = -1;

    // Delay used to make it so that we dont change the value multiple times in a very short time span
    delay(250);

    previousNumber = currentNumber;
    currentNumber = 0;
  } else if (addState == HIGH) {
    minusOrAdd = 1;

    delay(250);

    previousNumber = currentNumber;
    currentNumber = 0;
  } else if (equalsState == HIGH) {
    if (minusOrAdd == -1) {
      Serial.println(previousNumber - currentNumber);
      resetLEDS();

      delay(250);

      previousNumber = 0;
      currentNumber = 0;

    } else if (minusOrAdd == 1) {
      Serial.println(previousNumber + currentNumber);
      resetLEDS();

      delay(250);

      previousNumber = 0;
      currentNumber = 0;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(addOne, INPUT);
  pinMode(minus, INPUT);
  pinMode(plus, INPUT);
  pinMode(equals, INPUT);

  pinMode(ledZero, OUTPUT);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledFour, OUTPUT);

  // Used to initalize the monitor so we can output text to the terminal
  Serial.begin(9600);

  digitalWrite(ledZero, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  oneState = digitalRead(addOne);
  addState = digitalRead(plus);
  minusState = digitalRead(minus);
  equalsState = digitalRead(equals);

  // If condition used to check if we've increased the value of the currentNumber variable by one or not
  if (oneState == HIGH) {
    currentNumber += 1;
    digitalWrite(ledZero, LOW);

    delay(250);
  }

  equationPressed(minusState, addState, equalsState);

  if (currentNumber != 0) {
    turnLEDSOff();
    checkNumber(currentNumber);
  }
}
