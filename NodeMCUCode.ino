/// WIFI TO NODEMCU AND NODEMCU TO NANO ///

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

String command, mode;             //String to store app command state.
int Speed;               // int to store speed specified

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
    mode = server.arg("Mode");
    command = server.arg("State");
    speed = server.arg("Speed").toInt();
    // if(mode == "Manual"){
    //   s.write(9998);
    //   switch(command){
    //   case "F":
    //     s.write(joinSpeedCommand(1, speed));
    //     break;
    //   case "B":
    //     s.write(joinSpeedCommand(2, speed));
    //     break;
    //   case "L":
    //     s.write(joinSpeedCommand(3, speed));
    //     break;
    //   case "R":
    //     s.write(joinSpeedCommand(4, speed));
    //     break;
    //   case "S":
    //     s.write(joinSpeedCommand(5, speed));
    //     break;
    //   }
    // }
    // else if(mode == "Auto"){
    //   s.write(9999);       // Assign 9999 to being convert to auto for arduino
    // }
    
    delay(30);
}

void HTTP_handleRoot(void) {

  if( server.hasArg("State") ){
         Serial.println(server.arg("State"));
    }
  if(server.hasArg("Speed")){
         Serial.println(server.arg("Speed"));
  }
  if(server.hasArg("Mode")){
    Serial.print("===========");
    Serial.print("%s", server.arg("Mode"));
    Serial.print("===========\n");
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}

// int joinSpeedCommand(int command, int speed){
//   int convertedCommand;
//   convertedCommand = speed*100 + command;
//   return convertedCommand;
// }
