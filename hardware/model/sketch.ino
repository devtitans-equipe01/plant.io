const int SOIL_MOISTURE_SENSOR_PIN = 34;

void setup() {
  Serial.begin(115200);
  pinMode(SOIL_MOISTURE_SENSOR_PIN, INPUT);
}

void loop() {
  int soilMoisture = map(analogRead(SOIL_MOISTURE_SENSOR_PIN), 0, 4095, 0, 10000);
  Serial.println("Soil Moisture(%): "+String(soilMoisture/100.0,2)+"%");
  delay(5000);
}