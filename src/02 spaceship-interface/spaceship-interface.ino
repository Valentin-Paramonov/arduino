void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int switchState = digitalRead(2);
  if (switchState == LOW) {
    greenLedOnlyOn();
  } else {
    redLedsOnlyOn();
  }
}

void greenLedOnlyOn() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void redLedsOnlyOn() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(250);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(250);  
}
