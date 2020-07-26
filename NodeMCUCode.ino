/// WIFI TO NODEMCU AND NODEMCU TO NANO ///

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

String command;             //String to store app command state.

const char* ssid = "NodeMCU Car";
ESP8266WebServer server(80);
SoftwareSerial s(3, 1);

void setup() {
 
  Serial.begin(115200);
  s.begin(9600);
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void loop() {
    server.handleClient();
      command = server.arg("State");
      switch(command){
        case "F":
          s.write(1);
          break;
        case "B":
          s.write(1);
          break;
        case "L":
          s.write(1);
          break;
        case "R":
          s.write(1);
          break;
        case "S":
          s.write(1);
          break;
      }
      delay(30);
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
