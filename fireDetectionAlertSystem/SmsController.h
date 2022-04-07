#include <ArduinoHttpClient.h>

// infobip api
char apiServer[] = API_SERVER;
int apiServerPort = 443;
String apiUser = API_USER;
String apiCredentials = API_PASS;
String apiSmsEndpoint = "/sms/1/text";
String apiSmsEndpointQueryParamBase = apiSmsEndpoint + "/query?username=" + apiUser + "&password=" + apiCredentials;

// sms delivery
String smsSender = SMS_SENDER;
String smsRecipient = SMS_RECIPIENT;

void sendSms(String from, String to, String textMessage) {
  HttpClient httpClient = HttpClient(wifiClient, apiServer, apiServerPort);
  httpClient.beginRequest();
  httpClient.get(apiSmsEndpointQueryParamBase + "&from=" + from + "&to=" + to + "&text=" + textMessage);
  httpClient.beginBody();
  httpClient.endRequest();

  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.println("Sending SMS...");
  Serial.println("Status code: " + String(statusCode));
  Serial.println("Response: " + response);

  if (statusCode == 200) {
    Serial.println("SMS Delivered");
  }
}

void sendFireAlertSMS() {
  sendSms(smsSender, smsRecipient, "Arduino%20detected%20fire!!!");
}

void sendNoFireUpdateSMS() {
  sendSms(smsSender, smsRecipient, "There%20is%20no%20more%20fire%20around%20your%20Arduino%20setup.");
}
