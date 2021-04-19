
#include <WiFi.h>
#include <WebServer.h>
#include "index.h"

WebServer server(80);
const char* ssid = "GIMhomes #6";
const char* password =  "likeyourhome";

void ConnectWiFi();
void sendWebPage();

void setup() {
  Serial.begin(115200);
  ConnectWiFi();
  server.on("/", sendWebPage);
  server.onNotFound ( sendWebPage );
  server.begin();
  Serial.println("Server Start");
}

void loop() {

}

void sendWebPage() {
  server.send(200, "text/html", webpage );
//  String message = "File Not Found\n\n";
//  message += "URI: ";
//  message += server.uri();
//  message += "\nMethod: ";
//  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
//  message += "\nArguments: ";
//  message += server.args();
//  message += "\n";
//  for ( uint8_t i = 0; i < server.args(); i++ ) {
//    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
//  }
//  server.send ( 404, "text/plain", message );
}

void ConnectWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(5000);
    Serial.print(".");
  }
  Serial.print("CONECTED SUCCESS ip:");
  Serial.println(WiFi.localIP());

}
