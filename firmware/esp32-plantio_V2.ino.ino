#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>


//Deinindo Pinagem do sensor DHT11
#define DHT_SENSOR_PIN  14 // ESP32 pin GIOP21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

// GPIO where the DS18B20 is connected to
const int oneWireBus = 21;
const int SOIL_MOISTURE_SENSOR_PIN = 34;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

int pool_delay = 200;

// unsigned long period = 5000;
// unsigned long time_now = 0;

void setup() {
  Serial.begin(921600);
  pinMode(SOIL_MOISTURE_SENSOR_PIN, INPUT);

  Serial.println("DevTITANS Plant.io initialized.");
  sensors.begin();
}

void loop() {
  String serialCommand;

  // if(millis() >= time_now + period) {
  //   time_now += period;
  //   //Serial.println("analog" + String(analogRead(SOIL_MOISTURE_SENSOR_PIN)));
  //   Serial.println("Soil Moisture(%): " + String(smGetValue(),2)+"%");
  // }

  while (Serial.available() > 0) {
    char serialChar = Serial.read();
    serialCommand += serialChar; 

    if (serialChar == '\n') {
        processCommand(serialCommand);
        serialCommand = "";
    }
  }

  delay(pool_delay);
}

void processCommand(String command) {
  command.trim();
  command.toUpperCase();
  //Umidade do Solo
  if (command == "GET_SM") {
    Serial.println("RES GET_SM " + String(smGetValue(),2));
  }//Temperatura
  else if (command == "GET_ST") {
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    Serial.print("RES GET_ST ");
    Serial.println(temperatureC);
    //Serial.println("ºC");
  }//Umidade Ambiente
  else if(command == "GET_AM"){
    float humi  = dht_sensor.readHumidity();
    Serial.print("RES GET_AM");
    Serial.println(humi);
  }//Temperatura Ambiente
  else if(command == "GET_AT"){
    float tempC = dht_sensor.readTemperature();
    Serial.print("RES GET_AT");
    Serial.println(tempC);
  }
  else if (command.startsWith("POLL_DELAY")) {
    int poll_value = command.substring(11).toInt();

    if (poll_value >= 100) {
        pool_delay = poll_value;
        Serial.printf("RES POLL_DELAY %d\n", poll_value);
    }
    else {
        Serial.printf("RES POLL_DELAY -1\n");
    }
  }
  else {
    Serial.println("ERR Unknown command.");
  }
}

float smGetValue() {
  return (map(analogRead(SOIL_MOISTURE_SENSOR_PIN), 0, 4095, 10000, 0) / 100.0);
}