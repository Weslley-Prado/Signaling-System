// Defining the LED pins
const int ledPins[] = {2, 3, 4, 5, 6, 7};

// Defining the button pin
const int buttonPin = 8;

// Variable to store the button state
int buttonState = 0;

// Variable to store the current mode
int mode = 0;

void setup() {
  // Setting the LED pins as outputs
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Setting the button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Initializing serial communication (optional for debugging)
  Serial.begin(9600);
}

void loop() {
  // Reading the state of the button
  buttonState = digitalRead(buttonPin);

  // Changing the system functionality if the button is pressed
  if (buttonState == LOW) {
    mode = !mode; // Toggling between 0 and 1
    delay(300);   // Debounce to avoid multiple readings
  }

  // Executing the corresponding functionality
  if (mode == 0) {
    // 1st functionality: all LEDs blink every 1s
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(1000);
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(1000);
  } else {
    // 2nd functionality: alternating between even and odd LEDs
    // Turning on even LEDs
    for (int i = 0; i < 6; i++) {
      if (i % 2 == 0) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
    delay(1000);
    // Turning on odd LEDs
    for (int i = 0; i < 6; i++) {
      if (i % 2 != 0) {
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
    delay(1000);
  }
}
