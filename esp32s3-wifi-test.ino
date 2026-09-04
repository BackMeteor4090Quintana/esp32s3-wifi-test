#include <Arduino.h>
#include <WiFi.h>

const char* SSID = "Totalplay-2.4G-4ef8";
const char* PASS = "Jm7cbUXMQXPBFZA2";

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println();
  Serial.println("====================================");
  Serial.println(" ESP32-S3 - TEST WIFI LIMPIO");
  Serial.println("====================================");

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);

  Serial.printf("SSID: %s\n", SSID);
  WiFi.begin(SSID, PASS);
}

void loop() {
  static wl_status_t anterior = (wl_status_t)255;
  static unsigned long ultimo = 0;

  wl_status_t estado = WiFi.status();

  if (estado != anterior) {
    anterior = estado;
    Serial.printf("[WIFI] status=%d | t=%lu ms\n",
                  (int)estado, (unsigned long)millis());
  }

  if (estado == WL_CONNECTED && millis() - ultimo >= 3000) {
    ultimo = millis();
    Serial.printf("[WIFI] CONECTADO | IP=%s | RSSI=%d dBm | CH=%d\n",
                  WiFi.localIP().toString().c_str(),
                  WiFi.RSSI(),
                  WiFi.channel());
  }

  delay(100);
}
