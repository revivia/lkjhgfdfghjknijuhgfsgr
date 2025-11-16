#define TRIG_PIN 4
#define ECHO_PIN 3
int potX = A0;
int joyX = A1;
int joyY = A2;
int buttonPin = 2;
int lastPot = -1;
int lastUltra = -1;
int lastJoyX = -1;
int lastJoyY = -1;
int lastButton = HIGH;
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(TRIG_PIN, LOW);
}
void sendCC(byte cc, byte value) {
  Serial.write(0xB0);
  Serial.write(cc);
  Serial.write(value);
}
void sendNoteOn(byte note) {
  Serial.write(0x90);
  Serial.write(note);
  Serial.write(127);
}
void sendNoteOff(byte note) {
  Serial.write(0x80);
  Serial.write(note);
  Serial.write(0);
}
void loop() {
  int potRaw = analogRead(potX);
  byte potVal = map(potRaw, 0, 1023, 0, 127);
  if (abs(potVal - lastPot) > 1) {
    sendCC(21, potVal);
    lastPot = potVal;
  }
  int joyRawX = analogRead(joyX);
  if (abs(joyRawX - 512) > 10) {
    byte joyValX = map(joyRawX, 0, 1023, 0, 127);
    if (abs(joyValX - lastJoyX) > 1) {
      sendCC(22, joyValX);
      lastJoyX = joyValX;
    }
  }
  int joyRawY = analogRead(joyY);
  if (abs(joyRawY - 512) > 10) {
    byte joyValY = map(joyRawY, 0, 1023, 0, 127);
    if (abs(joyValY - lastJoyY) > 1) {
      sendCC(23, joyValY);
      lastJoyY = joyValY;
    }
  }
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastButton) {
    if (buttonState == LOW) {
      sendNoteOn(60);
    } else {
      sendNoteOff(60);
    }
    lastButton = buttonState;
  }
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance_cm = duration * 0.034 / 2;
  if (distance_cm > 30) distance_cm = 30;
  if (distance_cm < 0) distance_cm = 0;
  byte ultraVal = map(distance_cm, 0, 30, 0, 127);
  if (abs(ultraVal - lastUltra) > 1) {
    sendCC(20, ultraVal);
    lastUltra = ultraVal;
  }
  delay(5);
}