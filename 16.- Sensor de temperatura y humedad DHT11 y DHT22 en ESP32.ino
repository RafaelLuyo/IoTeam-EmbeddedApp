#include <LiquidCrystal.h>
#include <DHTesp.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define NODE_ID 1
#define ENDPOINT_URL "https://thirstyseedapi-production.up.railway.app/api/v1/node/" + String(NODE_ID) + "/moisture"

// Inicializamos los pines conectados de la pantalla de cristal líquido al ESP32
LiquidCrystal lcd(22, 23, 5, 18, 19, 21);
DHTesp dht;
int pinDHT = 15;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Conectando a WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\nConectado a WiFi!");

    dht.setup(pinDHT, DHTesp::DHT22);
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("Iniciando...");
    delay(2000);
    lcd.clear();
}

void loop() {
    TempAndHumidity data = dht.getTempAndHumidity();
    Serial.println("Temperatura: " + String(data.temperature, 2) + "°C");
    Serial.println("Humedad: " + String(data.humidity, 1) + "%");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: " + String(data.temperature, 2) + "C");
    lcd.setCursor(0, 1);
    lcd.print("Humedad: " + String(data.humidity, 1) + "%");


    delay(10000); // Esperar diez segundos antes de la siguiente lectura
}
