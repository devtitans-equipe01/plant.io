#include <OneWire.h>
#include <DallasTemperature.h>

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

  if (command == "GET_SM") {
    Serial.println("RES GET_SM " + String(smGetValue(),2));
  }
  else if (command == "GET_TE") {
    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    Serial.print("RES GET_TE ");
    Serial.print(temperatureC);
    Serial.println("ºC");
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
