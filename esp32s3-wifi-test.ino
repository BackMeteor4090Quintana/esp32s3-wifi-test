#include <WiFi.h>

const char* WIFI_SSID = "PON_AQUI_TU_SSID";
const char* WIFI_PASS = "PON_AQUI_TU_PASSWORD";

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println();
  Serial.println("=== ESP32-S3 WIFI MINIMO + PLATFORM ANEMOIA ===");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true, true);
  delay(500);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  unsigned long inicio = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - inicio < 20000) {
    Serial.printf("[WIFI] status=%d\n", (int)WiFi.status());
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf(
      "[WIFI] CONECTADO | IP=%s | RSSI=%d dBm | CH=%d\n",
      WiFi.localIP().toString().c_str(),
      WiFi.RSSI(),
      WiFi.channel()
    );
  } else {
    Serial.printf("[WIFI] NO CONECTO | status final=%d\n", (int)WiFi.status());
  }
}

void loop() {
  static unsigned long ultimo = 0;

  if (millis() - ultimo >= 3000) {
    ultimo = millis();

    if (WiFi.status() == WL_CONNECTED) {
      Serial.printf(
        "[WIFI] CONECTADO | IP=%s | RSSI=%d dBm | CH=%d\n",
        WiFi.localIP().toString().c_str(),
        WiFi.RSSI(),
        WiFi.channel()
      );
    } else {
      Serial.printf("[WIFI] DESCONECTADO | status=%d\n", (int)WiFi.status());
    }
  }
}
