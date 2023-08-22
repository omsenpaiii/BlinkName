// SIT210 2.1P
int led = LED_BUILTIN;
int buttonPin = 2; // Change this to the pin where your button is connected
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button was pressed
    String name = readNameFromSerial();
    blinkNameInMorse(name);
  }

  lastButtonState = buttonState;
}

String readNameFromSerial() {
  String inputName = "";
  while (Serial.available() > 0) {
    char c = Serial.read();
    Serial.println(c);
    if (c == '\n') {
      break;
    }
    inputName += c;
  }
  return inputName;
}

void blinkDot() {
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(300);
}

void blinkDash() {
  digitalWrite(led, HIGH);
  delay(900);
  digitalWrite(led, LOW);
  delay(300);
}

void blinkNameInMorse(String name) {
  for (int i = 0; i < name.length(); i++) {
    char c = tolower(name[i]);
    switch (c) {
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
