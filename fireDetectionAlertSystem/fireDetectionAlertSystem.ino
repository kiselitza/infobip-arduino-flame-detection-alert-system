#include "ArduinoSecrets.h"
#include "WiFiConnectionController.h"
#include "SmsController.h"

// arduino components pins
int flameDetectionSensorPin = 7;
int buzzerPin = 8;
int greenLedPin = 12;
int redLedPin = 13;

// fire detection readings
int flame = LOW;
bool fireDetected = false;

// runs only once at the start
void setup() {
  // define the sensor input
  pinMode(flameDetectionSensorPin, INPUT);

  // define the outputs
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // sets the data rate in bits per second
  Serial.begin(9600);

  //connects to WiFi
  connectToWiFi();
}

// runs infinitelly in a loop
void loop() {
  // checking for fire readings
  flame = digitalRead(flameDetectionSensorPin);

  // no fire detected
  if(flame != LOW) {
    Serial.println("No fire detected");
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
    
    // checking PREVIOUS reading, IF fire was detected send an SMS that it got extinguished
    if (fireDetected) {
      sendNoFireUpdateSMS();
    }
    fireDetected = false;
  }

  // fire detected
  if(flame != HIGH) {
    Serial.println("Fire detected");
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
//    digitalWrite(buzzerPin, HIGH);

    // checking PREVIOUS reading, IF there was no fire send an SMS alert that there it is now detected
    if (!fireDetected) {
      sendFireAlertSMS();
    }
    fireDetected = true;
  }
  
  delay(1000);
}
