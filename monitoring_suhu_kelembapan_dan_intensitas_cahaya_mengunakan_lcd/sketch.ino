#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 15  // Pin tempat DATA DHT22 terhubung
#define DHTTYPE DHT22  // Tipe sensor DHT

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

const int ldrPin = 34;  // Pin ADC tempat LDR terhubung

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();  
  lcd.backlight();
  pinMode(ldrPin, INPUT);

  // Menampilkan pesan awal di LCD
  lcd.setCursor(0, 0);
  lcd.print("Monitoring...");
  delay(2000);
}

void loop() {
  // Membaca suhu dan kelembapan dari DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Membaca data intensitas cahaya dari LDR
  int lightLevel = analogRead(ldrPin);

  // Menampilkan hasil pembacaan ke Serial Monitor dan LCD
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("DHT Error      ");
  } else {
    Serial.print("Suhu: ");
    Serial.print(temperature);
    Serial.println("°C");
    
    Serial.print("Kelembapan: ");
    Serial.print(humidity);
    Serial.println("%");

    // Menampilkan hasil ke LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C   ");
    
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print("%   ");
  }

  Serial.print("Intensitas Cahaya: ");
  Serial.println(lightLevel);

  // Menampilkan intensitas cahaya di serial monitor
  lcd.setCursor(10, 1);
  lcd.print("L:");
  lcd.print(lightLevel);

  delay(2000); // Tunggu 2 detik sebelum pembacaan berikutnya
}
