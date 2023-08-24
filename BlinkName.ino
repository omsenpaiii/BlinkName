// SIT210 2.1P

// Pin number for the built-in LED
int led = LED_BUILTIN;

// Pin number where your button is connected
int buttonPin = 2;

// Variables to store the state of the button
bool buttonState = false;
bool lastButtonState = false;

// Setup function runs once at the beginning
void setup() {
  // Set the LED pin as an output
  pinMode(led, OUTPUT);

  // Set the button pin as an input with a pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);
}

// Main loop function
void loop() {
  // Read the current state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button was just pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button was pressed, read name from serial and blink it in Morse code
    String name = readNameFromSerial();
    blinkNameInMorse(name);
  }

  // Save the current button state for the next iteration
  lastButtonState = buttonState;
}

// Function to read a name from the Serial input
String readNameFromSerial() {
  String inputName = "";
  // Read characters from Serial until a newline character ('\n') is received
  while (Serial.available() > 0) {
    char c = Serial.read();
    Serial.println(c);
    if (c == '\n') {
      break; // Exit the loop when newline is received
    }
    inputName += c; // Append characters to the inputName string
  }
  return inputName;
}

// Function to blink a dot
void blinkDot() {
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(300);
}

// Function to blink a dash
void blinkDash() {
  digitalWrite(led, HIGH);
  delay(900);
  digitalWrite(led, LOW);
  delay(300);
}

// Function to blink a name in Morse code
void blinkNameInMorse(String name) {
  // Iterate through each character in the name
  for (int i = 0; i < name.length(); i++) {
    char c = tolower(name[i]); // Convert to lowercase for case-insensitivity
    // Translate characters to Morse code and blink accordingly
    switch (c) {
      // Cases for each letter
      case 'a':
        blinkDot(); delay(600); blinkDash(); delay(900);
        break;
      case 'b':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 'c':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 'd':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 'e':
        blinkDot(); delay(600);
        break;
      case 'f':
        blinkDot(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 'g':
        blinkDash(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 'h':
        blinkDot(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 'i':
        blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 'j':
        blinkDot(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600);
        break;
      case 'k':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600);
        break;
      case 'l':
        blinkDot(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 'm':
        blinkDash(); delay(600); blinkDash(); delay(600);
        break;
      case 'n':
        blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 'o':
        blinkDash(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600);
        break;
      case 'p':
        blinkDot(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 'q':
        blinkDash(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600);
        break;
      case 'r':
        blinkDot(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600);
        break;
      case 's':
        blinkDot(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      case 't':
        blinkDash(); delay(600);
        break;
      case 'u':
        blinkDot(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600);
        break;
      case 'v':
        blinkDot(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600);
        break;
      case 'w':
        blinkDot(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600);
        break;
      case 'x':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600);
        break;
      case 'y':
        blinkDash(); delay(600); blinkDot(); delay(600); blinkDash(); delay(600); blinkDash(); delay(600);
        break;
      case 'z':
        blinkDash(); delay(600); blinkDash(); delay(600); blinkDot(); delay(600); blinkDot(); delay(600);
        break;
      default:
        // For unsupported characters, just delay for a word gap
        delay(2100);
        break;
    }
    delay(300); // Gap between letters
  }
  delay(4200); // Gap between words
}
