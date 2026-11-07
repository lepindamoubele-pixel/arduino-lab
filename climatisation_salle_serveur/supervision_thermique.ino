#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT22);
const int pinAlerte = 13;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(pinAlerte, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Temp: "); 
  lcd.print(temp, 1); 
  lcd.print(" C");
  
  lcd.setCursor(0, 1); 
  lcd.print("Hum: "); 
  lcd.print(hum, 1); 
  lcd.print(" %");
  
  if (temp > 25.0) {
    digitalWrite(pinAlerte, HIGH); // Activer la LED rouge
  } else {
    digitalWrite(pinAlerte, LOW);  // Éteindre la LED rouge
  }                                // <-- Ajouté : Accolade du "else"

  delay(2000);                     // <-- Recommandé : Pause de 2 secondes pour stabiliser l'affichage et le DHT22
}                                  // <-- Ajouté : Accolade de la fonction loop()

