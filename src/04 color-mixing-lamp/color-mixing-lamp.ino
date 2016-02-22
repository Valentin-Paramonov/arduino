const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

const int redSensor = A0;
const int greenSensor = A1;
const int blueSensor = A2;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensor);
  delay(5);
  greenSensorValue = analogRead(greenSensor);
  delay(5);
  blueSensorValue = analogRead(blueSensor);
  printDebugInfo();
  analogWrite(redPin, redSensorValue / 4);
  analogWrite(greenPin, greenSensorValue / 4);
  analogWrite(bluePin, blueSensorValue / 4);
}

void printDebugInfo() {
//  Serial.println("Read:");
  printRgb(redSensorValue, greenSensorValue, blueSensorValue);
//  Serial.println("Mapped:");
  Serial.print(" -> ");
  printRgb(redSensorValue / 4, greenSensorValue / 4, blueSensorValue / 4);
  Serial.println();
}

void printRgb(int r, int g, int b) {
  Serial.print("R: ");
  Serial.print(r);
  Serial.print("\tG: ");
  Serial.print(g);
  Serial.print("\tB: ");
  Serial.print(b);
}
