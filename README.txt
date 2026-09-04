ESP32-S3 WIFI TEST - REPO INDEPENDIENTE

Este repo es totalmente independiente de COCODRILO OS.

NO usa:
- TFT_eSPI
- Anemoia
- librerías del repo de COCODRILO
- build_support/platform.txt
- particiones custom
- SD, audio, INA219, Telegram, NES

PASOS
1. Crea un repositorio nuevo en GitHub, por ejemplo: esp32s3-wifi-test
2. Sube TODO el contenido de este ZIP respetando carpetas.
3. Edita WifiTest.ino y cambia:
   PON_AQUI_TU_HOTSPOT
   PON_AQUI_TU_PASSWORD
4. Haz commit.
5. Ve a Actions.
6. Ejecuta "ESP32-S3 WiFi test limpio".
7. Descarga el artefacto "esp32s3-wifi-test".
8. Si aparece un archivo merged.bin, úsalo para flashear desde 0x0.

Este test instala Arduino ESP32 core 3.2.1 desde cero en GitHub Actions.
