#include <SPI.h>
#include <WiFi.h>
#include <elapsedMillis.h>
#include "esp_camera.h"

char ssid[] = "Hi"; //network name
char pass[] = "12345678"; //network password
const int serverPort = 23;
WiFiClient comp; //a single computer should be the only remote client
elapsedMillis timer; //we will use this to control the rate at which the server operates

WiFiServer camserver(serverPort);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  WiFi.setSleep(false);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("No connection");
    delay(300);
  }
  
  camserver.begin();
  Serial.println("Connected");
  IPAddress addr = WiFi.localIP();
  Serial.println(addr);
}

void checkForConnections() {
  if (camserver.hasClient()) {
    if (comp.connected()) {
      Serial.println("Connection rejected.");
      camserver.available().stop();
    }
    else {
      Serial.println("Connection accepted.");
      comp = camserver.available();
    }
  }
}

void sendPixelData() {
  camera_fb_t* fb = esp_camera_fb_get();
  uint8_t* buf = fb->buf;
  size_t len = fb->len;
  
  camserver.write(buf, len);
}

void loop() {
  checkForConnections();

//  if (timer > 1000) {
//    sendPixelData();
//    
//    timer = 0;
//  }
}
