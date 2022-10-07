#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid     = "haus itu";
const char* password = "haus apa?";

void setup() {  
  Serial.begin(115200);
  Wire.begin(0, 2);
  delay(2000);

  lcd.init();
  lcd.backlight();

  // We start by connecting to a WiFi network
  Serial.println(" ");
  Serial.println(" ");
  Serial.print("Connecting to ");
  Serial.print(ssid);

  lcd.print("Connecting WiFi");
  delay(4000);

  Serial.print(" ");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int col = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (col > 15) {
      col = 0;
      lcd.clear();
      lcd.print("Connecting WiFi");
    }
    Serial.print(".");
    lcd.setCursor(col, 1);
    lcd.print(".");
    col++;
  }

  Serial.println(" ");
  Serial.print("WiFi connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(" ");

  lcd.clear();
  lcd.print("Wifi connected");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

  delay(8000);

  Serial.println("===> Data from weatherapi.com <===");
  Serial.println(" ");

}

void loop() {
  // wait for WiFi connection
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    //Set the target url
    String url = "http://api.weatherapi.com/v1/current.json?key=0576a9ab13044e1789f00455222206&q=denpasar&aqi=no";

    if (http.begin(client, url)) {  // HTTP

      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String getData = http.getString();
          sendDataToLcd(getData);

        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        // lcd.clear();
        // lcd.print("!Failed to GET!");
      }

      http.end();
    } else {
      Serial.printf("[HTTP] Unable to connect\n");
      lcd.clear();
      lcd.print("!CONNECTION!");
    }
  }

  Serial.println(" ");
  delay(10000);
}

void sendDataToLcd(String getData) {
  DynamicJsonDocument json(1536);
  // Parse JSON object
  DeserializationError error = deserializeJson(json, getData);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  JsonObject location = json["location"];
  const char* location_name = location["name"]; // "Denpasar"
  const char* location_region = location["region"]; // "Bali"
  String location_localtime = location["localtime"]; // "2022-05-25 5:40"
  JsonObject current = json["current"];
  int current_temp_c = current["temp_c"]; // 25
  int current_humidity = current["humidity"]; // 83

  Serial.print("Lokasi: ");
  Serial.print(location_name);
  Serial.print(", ");
  Serial.println(location_region);
  Serial.print("Waktu: ");
  Serial.println(location_localtime);
  Serial.print("Temperatur: ");
  Serial.print(current_temp_c);
  Serial.println(" C");
  Serial.print("Kelembaban: ");
  Serial.print(current_humidity);
  Serial.println(" %");

  lcd.clear();
  lcd.print(location_name);
  lcd.print(", ");
  lcd.print(location_region);
  lcd.setCursor(6, 1);
  location_localtime.remove(10, location_localtime.length() - 1);
  lcd.print(location_localtime);
  delay(15000);
  lcd.clear();
  lcd.print("Temperatur: ");
  lcd.print(current_temp_c);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Kelembapan: ");
  lcd.print(current_humidity);
  lcd.print(" %");

}
