#include <SoftwareSerial.h>
#include <SparkFunESP8266WiFi.h>

#define NETWORK_NAME "HKU"
#define NETWORK_PASSWORD "draadloos"

void setup() {
  Serial.begin(9600);
  
  setupESP8266();
}

void loop() {
  ESP8266Client client;

  int result = client.connect("studenthome.hku.nl", 80);
  if (result < 0) {
    Serial.println("Failed to connect to server.");
  } else {
    Serial.println("Send HTTP request...");
    client.println("GET /~bradley.langguth/Kernmodule_IXD4/Results.php HTTP/1.1\n"
                   "Host: studenthome.hku.nl\n"
                   "Connection: close\n");

    Serial.println("Response from server");
    Serial.println("-----");
    while (client.available()) {
      Serial.write(client.read());
    }
    Serial.println("-----");
  }

  if (client.connected()) {
    client.stop();
  }

  delay(4000);
}
