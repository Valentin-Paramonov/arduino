const int sensorPin = A0;
const float baselineTemperature = 20.0;

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 3; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  printSensorInfo(sensorValue);
  ligthUpLedsBasedOn(toTemperature(sensorValue));
  delay(1);
}

void printSensorInfo(int sensorValue) {
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Volts: ");
  Serial.println(toVolts(sensorValue));
  Serial.print("Degrees C: ");
  Serial.println(toTemperature(sensorValue));
}

float toVolts(int sensorValue) {
  return (sensorValue / 1024.0) * 5.0;
}

float toTemperature(int sensorValue) {
  return (toVolts(sensorValue) - 0.5) * 100;
}

void ligthUpLedsBasedOn(float temperature) {
  if (temperature < baselineTemperature) {
    turnOffLed(3);
    turnOffLed(4);
    turnOffLed(5);
  } else if (temperature >= baselineTemperature + 2 && temperature < baselineTemperature + 4) {
    turnOnLed(3);
    turnOffLed(4);
    turnOffLed(5);
  } else if (temperature >= baselineTemperature + 4 && temperature < baselineTemperature + 6) {
    turnOnLed(3);
    turnOnLed(4);
    turnOffLed(5);
  } else if (temperature >= baselineTemperature + 6) {
    turnOnLed(3);
    turnOnLed(4);
    turnOnLed(5);
  }
}

void turnOnLed(int ledNumber) {
  digitalWrite(ledNumber, HIGH);
}

void turnOffLed(int ledNumber) {
  digitalWrite(ledNumber, LOW);
}
