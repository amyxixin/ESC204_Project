#include <SPI.h>
#include <WiFi.h>
#include <elapsedMillis.h>
#include "esp_camera.h"

char ssid[] = ""; //network name
char pass[] = ""; //network password
const int serverPort = 23;
WifiClient = comp; //a single computer should be the only remote client
elapsedMillis timer //we will use this to control the rate at which the server operates

WiFiServer Server(serverPort);

void setup() {
  Server.begin();
}

void checkForConnections() {
  if (Server.hasClient()) {
    if (comp.connected()) {
      Serial.println("Connection rejected.");
      Server.available().stop();
    }
    else {
      Serial.println("Connection accepted.");
      RemoteClient = Server.available();
    }
  }
}

void sendPixelData() {
  camera_fb_t* fb = esp_camera_fb_get();
  uint8_t* buf = fb->buf;
  size_t len = fb->len;
  
  Server.write(buf, len);
}

void loop() {
  checkForConnections();

  if (timer > 1000) {
    sendPixelData();
    
    timer = 0;
  }
}
