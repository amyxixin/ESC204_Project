#include <WiFi.h>

const char* ssid = "Hi";
const char* password = "12345678";
const char* host = "192.168.43.195";
const uint8_t port = 23;

const int F = 0; //forward
const int B = 1; //backward
const int L = 2; //left
const int R = 3; //right
const int S = 4; //stop

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi.");
}

void loop() {
  int instr = 4;
  
  Serial.println("Connecting to host...");
  
  if (!client.connect(host, port)) {
      Serial.println("Connecion failed. Retrying...");
      delay(1000);
      return;
  }

  instr = client.read();
  Serial.println(instr);
}
