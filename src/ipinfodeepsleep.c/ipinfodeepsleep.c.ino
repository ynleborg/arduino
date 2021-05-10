#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "xxx";
const char* password = "xxx";
void setup () {
  Serial.begin(74880);
  Serial.println("device is in Wake up mode");
  while (!Serial) { }
  WiFi.disconnect();
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");

  HTTPClient http;  //Declare an object of class HTTPClient
  http.begin("http://ipinfo.io/ip");  //Specify request destination
  int httpCode = http.GET();                                                                  //Send the request
  if (httpCode > 0) { //Check the returning code
    String payload = http.getString();   //Get the request response payload
    Serial.println(payload);                     //Print the response payload
  }
  http.end();   //Close connection

  Serial.println("deep sleep for 60 seconds");
  ESP.deepSleep(60e6);
}
void loop() {
}
