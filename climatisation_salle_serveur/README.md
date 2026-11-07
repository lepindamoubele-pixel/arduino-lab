# 🌡️ Moniteur de Température pour Salles Serveurs

Ce projet fait partie de mon catalogue de prototypes électroniques pour l'alternance. Il consiste à concevoir un système de surveillance climatique autonome dédié aux infrastructures informatiques, capable de mesurer en temps réel la température et l'humidité, d'afficher ces données sur un écran LCD et de déclencher une alerte visuelle (LED) en cas de surchauffe critique.

## 🎯 Objectifs Pédagogiques & Techniques
- Interfacer et lire les données d'un capteur thermo-hygrométrique numérique (DHT22).
- Exploiter le bus de communication I2C pour piloter un afficheur LCD 1602 (gain de broches I/O).
- Mettre en place un système d'alerte à seuil pour la protection d'équipements sensibles.

---

## ⚙️ Composants Utilisés

| Composant | Rôle |
| :--- | :--- |
| **Arduino Uno** | Microcontrôleur / Cerveau du système |
| **Capteur DHT22** | Mesure haute précision de la température et de l'humidité |
| **Écran LCD 1602 (I2C)** | Affichage clair des données climatiques sur 2 lignes |
| **LED Rouge & Résistance 220Ω** | Indicateur visuel d'alerte en cas de surchauffe (> 25°C) |

---

## 🔌 Câblage Pas à Pas

Le schéma de connexion sur le prototype est configuré ainsi :

### 📟 Écran LCD 1602 (via module I2C) :
- **GND** ➡️ Broche **GND** de l'Arduino
- **VCC** ➡️ Broche **5V** de l'Arduino
- **SDA** (Données) ➡️ Broche analogique **A4**
- **SCL** (Horloge) ➡️ Broche analogique **A5**

### 📡 Capteur DHT22 :
- **VCC** ➡️ Broche **5V** de l'Arduino
- **GND** ➡️ Broche **GND** de l'Arduino
- **SDA / OUT** (Signal) ➡️ Broche numérique **D7**

### 🚨 LED d'Alerte :
- **Anode (+)** ➡️ Résistance 220Ω ➡️ Broche numérique **D13**
- **Cathode (-)** ➡️ Broche **GND** de l'Arduino

---

## 💻 Code Source (Arduino)

```cpp
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Initialisation de l'écran LCD à l'adresse 0x27 (16 colonnes, 2 lignes)
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Initialisation du capteur DHT22 sur la broche D7
DHT dht(7, DHT22);

const int pinAlerte = 13; // LED rouge sur D13

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(pinAlerte, OUTPUT);
}

void loop() {
  // Lecture des variables climatiques
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Mise à jour de l'affichage LCD
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Temp: "); lcd.print(temp, 1); lcd.print(" C");
  lcd.setCursor(0, 1); 
  lcd.print("Hum: ");  lcd.print(hum, 1);  lcd.print(" %");

  // Logique de sécurité : Seuil critique fixé à 25.0°C
  if (temp > 25.0) {
    digitalWrite(pinAlerte, HIGH); // Activer l'alerte visuelle (LED)
  } else {
    digitalWrite(pinAlerte, LOW);  // Température normale
  }

  delay(2000); // Rafraîchissement toutes les 2 secondes (spécificité du DHT22)
}
```

---

## 🚀 Pistes d'Amélioration (Évolutions IoT)
Pour transformer ce prototype en un outil de supervision de niveau industriel (Datacenter), voici les pistes d'évolution :
1. **Alerte Sonore :** Intégration d'un buzzer actif (comme le Projet 2) pour ajouter une alarme sonore stridente en cas de dépassement prolongé du seuil thermique.
2. **Supervision Centralisée (Scada/Datalogger) :** Envoi des données via le port Série vers un tableau de bord Node-RED ou enregistrement sur carte SD pour analyser l'historique des variations.
3. **Connectivité Réseau :** Remplacement de l'Arduino par un ESP32 pour envoyer des alertes automatiques par e-mail ou SMS (via protocole MQTT ou API Web) aux administrateurs systèmes.

---

## 🛠️ Simulation
Ce projet a été modélisé, câblé et validé à 100% sur le simulateur en ligne **Wokwi** avec des composants strictement natifs.
