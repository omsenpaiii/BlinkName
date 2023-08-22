// SIT210
int led1 = LED_BUILTIN;

int buttonPin = 2; // Push button for resetting the name
bool isButtonPressed = false;
bool isBlinking = true; // Flag to control blinking state
unsigned long lastButtonPressTime = 0; // To track the time of the last button press

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() 
{
  // Check for external reset button press
  checkButtonPress();

  if (isButtonPressed) {
    unsigned long currentTime = millis();
    // Check if it's been more than 1 second since the last button press
    if (currentTime - lastButtonPressTime >= 1000) {
      resetName();
      isButtonPressed = false;
      isBlinking = true; // Enable blinking after resetting
      lastButtonPressTime = currentTime;
    }
  }

  if (isBlinking) {
    // Your name in Morse code
    blinkDash(); delay(1000); // Blink 'O' dash
    blinkDash(); delay(3000); // Gap between letters

    blinkDash(); delay(1000); // Blink 'M' dash
    blinkDash(); delay(1000);
    blinkDash(); delay(1000);

    delay(3000); // Gap between words
  }
}

void blinkDot() {
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  delay(200);
}

void blinkDash() {
  digitalWrite(led1, HIGH);
  delay(600);
  digitalWrite(led1, LOW);
  delay(200);
}

void resetName() {
  // Reset the name display here
  digitalWrite(led1, LOW);
  delay(1000);
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
}

void checkButtonPress() {
  if (digitalRead(buttonPin) == LOW) {
    isButtonPressed = true;
  }
}
