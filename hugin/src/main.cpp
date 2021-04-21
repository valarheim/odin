#include <Arduino.h>
#include <WiFi.h>
#include <M5Core2.h>

const char* ssid = "";
const char* password = "";

WiFiServer wifiServer(80);

void wifi_setup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.setCursor(0, 20);
    M5.Lcd.printf("Connecting ...");
  }
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("Connected to:        ");
  M5.Lcd.setCursor(0, 45);
  M5.Lcd.printf(ssid);
  M5.Lcd.setCursor(0, 95);
  M5.Lcd.printf("IP address:          ");
  M5.Lcd.setCursor(0, 120);
  char localIP[50];
  WiFi.localIP().toString().toCharArray(localIP, 50);
  M5.Lcd.printf(localIP);
}

void setup(void) {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN , BLACK);
  M5.Lcd.setTextSize(2);
  wifi_setup();
  M5.Lcd.setCursor(0, 170);
  M5.Lcd.printf("Golem server started");
  wifiServer.begin();
}

void loop(void) {
  WiFiClient client = wifiServer.available();
  if (client) {
      while (client.connected()) {
        char out[50];
        String input = "";
        while (client.available()>0) {
          char inputChar = client.read();
          if(inputChar == ';') break;
          input += inputChar;
        }
      }
      client.stop();
  }
}
