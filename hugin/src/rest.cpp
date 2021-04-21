/*
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <M5Core2.h>
#include "api.h"

const char* ssid = "";
const char* password = "";

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
  MDNS.begin("esp32");
}


void setup(void) {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN , BLACK);
  M5.Lcd.setTextSize(2);
  wifi_setup();
  golem_api_setup();
  M5.Lcd.setCursor(0, 170);
  M5.Lcd.printf("Golem server started");
}

void loop(void) {
  golem_server.handleClient();
  M5.Lcd.setCursor(0, 190);
  M5.Lcd.printf("Position: %.02f %.02f %.02f", golem.position.x, golem.position.y, golem.position.z);
}
*/