#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 3

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int batasSuhu = 28, batasKelembaban = 70;

void printCenter(byte row, String text) {
  lcd.setCursor((16 - text.length()) / 2, row);
  lcd.print(text);
}

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(FAN_PIN, OUTPUT);

  Serial.begin(9600);

  printCenter(0, "Smart Monitor");
  printCenter(1, "by Fajar");
  delay(2000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();
    printCenter(0, "Sensor Error!");
    delay(2000);
    return;
  }

  digitalWrite(FAN_PIN, t > batasSuhu);

  String kondisi = "Santai";
  if (t > batasSuhu) kondisi = "Panas";
  else if (h > batasKelembaban) kondisi = "Tropis";


  lcd.clear();
  printCenter(0, String(t, 1) + (char)223 + "C RH:" + String((int)h) + "%");
  printCenter(1, "Terasa " + kondisi);


  Serial.print("Suhu:");
  Serial.print(t);
  Serial.print(",Kelembaban:");
  Serial.println(h);

  delay(30000);
}
