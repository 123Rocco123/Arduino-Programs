// Variable contains the digital pin number for the LED (Red)
const int ledPin = 7;
// Variable contains the digital pin number for the LED (Green)
const int ledPinGreen = 11;
// Variable contains the digital pin number for the Button
const int buttonPin = 3;

// Variable used to contain the state of the button press
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Used to turn the green light on
    // Makes it so that we always have it on
  digitalWrite(ledPinGreen, HIGH);

  // Used to initalize the monitor so we can output text to the terminal
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the button value
  buttonState = digitalRead(buttonPin);
  
  // If condition used to check that if the button has been pressed, then we turn the red light off and the green one on
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPinGreen, LOW);
  } 
  // Else condition used to set the red light off and the green one on if the button is not pressed
  else if (buttonState == LOW) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPinGreen, HIGH);
  }
}
