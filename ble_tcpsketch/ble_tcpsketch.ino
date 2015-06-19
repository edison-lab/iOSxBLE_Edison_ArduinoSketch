#include <WiFi.h>
#include <Servo.h>

WiFiServer server(3000);
Servo servo;

void setup() {
  
  Serial.begin(9600);
  
  servo.attach(3);
  server.begin();
  
  Serial.print("Connected to TCP. My address:");
  IPAddress myAddress(127,0,0,1);
  Serial.println(myAddress);
  
}

void loop() {  
   
  WiFiClient client = server.available();
  
  if (client.available() > 0) {
    byte servoAngle = client.read(); 
    servo.write(servoAngle);
  }
  
}

   

