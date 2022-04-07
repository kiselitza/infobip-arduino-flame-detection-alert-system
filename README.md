# infobip-arduino-flame-detection-alert-system
A SHOWCASE solution for fire detection and audio, visual, and SMS alerting.
Do NOT replace your home security with this. 😁

## Quickstart
In order to run this solution you will first need the following:
- Arduino IDE from their official [website](https://www.arduino.cc/en/software)
- Infobip Account, create a free one [here](https://www.infobip.com/signup?signup_source=InfobipArduinoGithub)
- All of the listed [components](/README.md##components)
- Wiring as on the photo in [setup](/README.md##setup) section
- Replace `ArduinoSecrets.h` empty variables with your own values, check [this](/README.md##variables) section for extra explanation

## Setup
![Setup used for this solution](https://i.ibb.co/D1pQWYH/infobip-arduino-setup.png "Setup used for this solution")

## Variables
Within `ArduinoSecrets.h` file you'll find the following:

```cpp
  #define WIFI_SSID "" // SSID of the WiFi connection
  #define WIFI_PASS "" // Password for the WiFi connection
  #define API_SERVER "" // Infobip API Server, available at your account homepage
  #define API_USER "" // Your infobip account username
  #define API_PASS "" // Your infobip account password
  #define SMS_SENDER "InfoSMS"
  #define SMS_RECIPIENT "" // Your infobip-verified phone number
```

## Used Components
- Arduino IDE
- Arduino UNO WiFi REV 2
- Flame Sensor
- Buzzer
- 🟢 & 🔴 LEDs
- Wires
- Breadboard
- Voltage (via MacBook)
- A match/lighter
- Infobip SMS API

## Encontered Issues
If you happen to got any questions or issues regarding the solutions feel free to reach out.

## DISCLAIMER
I'd prefer using a proper `POST` request, but for some reason the request body is not reaching the server backend.
