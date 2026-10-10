void setup() {
  Serial.begin(9600);
}

void loop() {
  // read analog pin 0:
  const byte pin = 11;
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
 if ((sensorValue < 200) || (sensorValue > 800)) {
  digitalWrite(pin, HIGH);
  delay(50);
  digitalWrite(pin, LOW);
  delay(50);

  Serial.println("UNBALANCED");
 }

 else {
  int brightness = (sensorValue / 4);

  analogWrite(pin, brightness);

  Serial.print("ADC reading : ");
  Serial.print(sensorValue);
  Serial.print(" Analog Voltage : ");
  Serial.println(voltage);
  delay(1);
 }
}
