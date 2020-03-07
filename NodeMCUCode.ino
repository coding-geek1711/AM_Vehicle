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
      if (command == "F"){
        s.write(1);
      }
      else if (command == "B"){
        s.write(2);
      }
      else if (command == "L"){
        s.write(3);
      }
      else if (command == "R"){
        s.write(4);
      }
      else if(command == "S"){
        s.write(5);
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
