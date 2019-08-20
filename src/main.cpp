#include <Arduino.h>
#include <DHT.h>

#include <HomeAeroHobby.h>

HomeAeroHobby homeAero;

// DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
float temperature;
float humidity;

#define SOLENOID_PIN 3
#define WATER_LEVEL_PIN 0
#define WATER_PRESSURE_PIN 1
#define TEMPERATURE_LED 4
#define HUMIDITY_LED 5
#define WATER_LEVEL_LED 6
#define WATER_PRESSURE_LED 7

// Function definitions
void readDHT11();

void setup() {
  Serial.begin(9600);

  // Initialze DHT
  Serial.println("Initializing DHT11!");
  dht.begin();
  pinMode(TEMPERATURE_LED, OUTPUT);
  pinMode(HUMIDITY_LED, OUTPUT);

  Serial.println("Initializing HomeAero Hobby!");
  homeAero.Init(SOLENOID_PIN, WATER_LEVEL_PIN, WATER_PRESSURE_PIN, 
    WATER_LEVEL_LED, WATER_PRESSURE_LED);
}

void loop() {
  homeAero.SetCurrentTime(millis());

  // Read sensors
  if((homeAero.GetCurrentTime() - homeAero.GetSensorTime()) 
    >= homeAero.GetSensorInterval()) {
    
    readDHT11();
    homeAero.ReadSensors();
    homeAero.SetSensorTime(millis());
  }

  // Control the misters
  if(homeAero.ValveIsActive() 
    && ((homeAero.GetCurrentTime() - homeAero.GetActionTime())
    >= homeAero.GetActionInterval())) {

    homeAero.ActivateMisters(false);

  }
  else if(!homeAero.ValveIsActive() 
    && ((homeAero.GetCurrentTime() - homeAero.GetActionTime()) 
    >= homeAero.GetRestInterval())) {
    
    homeAero.SetActionTime(millis());
    homeAero.ActivateMisters(true);
  }
}

void readDHT11() {
  temperature = dht.readTemperature(true);
  humidity = dht.readHumidity();

  if(temperature < 75) {
    Serial.println("Temperature Low!");
    digitalWrite(TEMPERATURE_LED, 1);
  }
  else
    digitalWrite(TEMPERATURE_LED, 0);

  if(humidity < 50) {
    Serial.println("Humidity Low!");
    digitalWrite(HUMIDITY_LED, 1);
  }
  else
    digitalWrite(HUMIDITY_LED, 0);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" degrees F");
}