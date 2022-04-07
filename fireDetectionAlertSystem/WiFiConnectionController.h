#include <WiFiNINA.h>

// wifi connection
int wifiStatus = WL_IDLE_STATUS;
char wifiSsid[] = WIFI_SSID;
char wifiPass[] = WIFI_PASS;
WiFiSSLClient wifiClient;
bool wifiConnected = false;

void scanWiFiNetworks() {
  Serial.println("** Scan Networks **");
  byte numSsid = WiFi.scanNetworks();

  // print the network number and name for each network found:
  for (int scannedNetworkId = 0; scannedNetworkId<numSsid; scannedNetworkId++) {
    Serial.print(scannedNetworkId);
    Serial.print(") Network: ");
    Serial.println(WiFi.SSID(scannedNetworkId));

    if (WiFi.SSID(scannedNetworkId) == String(wifiSsid)) {
      Serial.println("This is the one we were looking for.");
      break;
    }
  }
}

void connectToWiFi() {
  scanWiFiNetworks();

  // attempt to connect to Wifi network:
  while (wifiStatus != WL_CONNECTED) {
    Serial.print("Attempting to connect to Personal Hotspot network, SSID: ");
    Serial.println(wifiSsid);
    wifiStatus = WiFi.begin(wifiSsid, wifiPass);

    delay(500);
  }

  Serial.println("You're connected to the network");
}

void disconnectWiFi() {
  WiFi.disconnect();
  Serial.println("You're disconnected from the network");
}
