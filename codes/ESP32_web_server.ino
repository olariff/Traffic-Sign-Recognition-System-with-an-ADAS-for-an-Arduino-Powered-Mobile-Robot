#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Ready");
}

void handleGet() {
  if (server.hasArg("data")) {
    String data = server.arg("data");
    Serial.println("Data: " + data);
  }
  server.send(200, "text/plain", "Data Received");
}

void handlePost() {
  server.send(200, "text/plain", "Processing Data");
}

void handleUpload() {
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    Serial.println("Receiving data:");
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    Serial.write(upload.buf, upload.currentSize);
  } else if (upload.status == UPLOAD_FILE_END) {
    server.send(200, "text/plain", "Data: ");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP("ESP32");
  server.on("/", handleRoot);
  server.on("/get", HTTP_GET, handleGet);
  server.on("/post", HTTP_POST, handlePost, handleUpload);
  server.begin();
}

void loop() {
  server.handleClient();
}
//#define led 2
//
//void setup(){
//  pinMode(led, OUTPUT);
//  //Serial.begin(921600);
//  //Serial.println("Hello from the setup");
//}
//
//void loop(){
//  delay(1000);
//  digitalWrite(led, HIGH);
//  //Serial.println("Hello from the loop");
//  delay(1000);
//  digitalWrite(led, LOW);
//}
