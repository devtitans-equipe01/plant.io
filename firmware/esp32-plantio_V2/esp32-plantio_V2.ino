#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

// Pinout

#define SOIL_MOISTURE_SENSOR_PIN 34 // SM
#define DALLAS_ONEWIRE_SENSOR_PIN 21 // ST
#define DHT_SENSOR_PIN 14 // AM, AT
#define LDR_SENSOR_PIN 36 // AL

// Config

#define DHT_SENSOR_TYPE DHT11
DHT DHT11Sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
// Configura uma instância OneWire para se comunicar com dispositivos OneWire
OneWire oneWire(DALLAS_ONEWIRE_SENSOR_PIN);
// Referência oneWire para o sensor de temperatura Dallas
DallasTemperature dallasSensor(&oneWire);

#define POLL_DELAY = 200;

void setup() {
  pinMode(SOIL_MOISTURE_SENSOR_PIN, INPUT);
  pinMode(LDR_SENSOR_PIN, INPUT);

  dallasSensor.begin();
  DHT11Sensor.begin();

  Serial.begin(9600);
  Serial.println("DevTITANS Plant.io inicializado.");
}

void loop() {
  String serialCommand;

  while (Serial.available() > 0) {
    char serialChar = Serial.read();
    serialCommand += serialChar;

    if (serialChar == '\n') {
      processCommand(serialCommand);
      serialCommand = "";
    }
  }

  delay(POLL_DELAY);
}

void processCommand(String command) {
  command.trim();
  command.toUpperCase();

  if (command == "GET_SM") {
    Serial.printf("RES GET_SM %d\n", smGetValue());
  }
  else if (command == "GET_ST") {
    dallasSensor.requestTemperatures();    
    Serial.printf("RES GET_ST %d\n", stGetValue());
  } 
  else if (command == "GET_AM") {
    Serial.printf("RES GET_AM %d\n", amGetValue());
  }
  else if (command == "GET_AT") {
    Serial.printf("RES GET_AT %d\n", atGetValue());
  }
  else if(command == "GET_AL") {
    Serial.printf("RES GET_AL %d\n", alGetValue());
  }
  else {
    Serial.println("ERR Unknown command.");
  }
}

int smGetValue() {
  return map(analogRead(SOIL_MOISTURE_SENSOR_PIN), 0, 4095, 10000, 0);
}

int stGetValue() {
  return (int)(dallasSensor.getTempCByIndex(0) * 100);
}

int amGetValue() {
  return (int)(DHT11Sensor.readHumidity() * 100);
}

int atGetValue() {
  return (int)(DHT11Sensor.readTemperature() * 100);
}

int alGetValue() {
  return map(analogRead(LDR_SENSOR_PIN), 0, 4095, 0, 10000);
}



