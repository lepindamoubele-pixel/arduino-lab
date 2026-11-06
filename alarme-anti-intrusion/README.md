# 🛡️ Projet 2 : Alarme Anti-Intrusions Domestique

Ce projet fait partie de mon catalogue de prototypes électroniques pour l'alternance. Il consiste à concevoir un système de sécurité résidentiel capable de détecter un mouvement physique dans une zone définie et de déclencher immédiatement une alerte sonore stridente et dissuasive.

## 🎯 Objectifs Pédagogiques & Techniques
- Maîtriser l'utilisation des capteurs de présence Tout-Ou-Rien (TOR).
- Générer des signaux sonores à fréquences variables (fréquences d'alerte) avec Arduino.
- Structurer un code propre et réactif (gestion des temporisations).

---

## ⚙️ Composants Utilisés

| Composant | Rôle |
| :--- | :--- |
| **Arduino Uno** | Microcontrôleur / Cerveau du système |
| **Capteur PIR (Motion Sensor)** | Détection de mouvement par infrarouge passif |
| **Buzzer** | Émission du signal d'alerte sonore |

---

## 🔌 Câblage Pas à Pas

Le schéma de connexion est configuré ainsi :

### 📡 Capteur PIR :
- **VCC** ➡️ Broche **5V** de l'Arduino
- **GND** ➡️ Broche **GND** de l'Arduino
- **OUT** (Signal) ➡️ Broche numérique **D2**

### 🔊 Buzzer :
- **Positif (+)** ➡️ Broche numérique **D8**
- **Négatif (-)** ➡️ Broche **GND** de l'Arduino

---

## 💻 Code Source (Arduino)

```cpp
const int pinPIR = 2;     // Capteur de mouvement sur D2
const int pinBuzzer = 8;  // Buzzer d'alerte sur D8

void setup() {
  pinMode(pinPIR, INPUT);     // Configuration du capteur en entrée
  pinMode(pinBuzzer, OUTPUT); // Configuration du buzzer en sortie
}

void loop() {
  int intrusion = digitalRead(pinPIR); // Lecture Tout-Ou-Rien (0 ou 1)

  if (intrusion == HIGH) {
    // Cycle d'alerte strident (bitonal)
    tone(pinBuzzer, 1000, 300); // Bip à 1000Hz pendant 300ms
    delay(400);
    tone(pinBuzzer, 800, 300);  // Bip à 800Hz pendant 300ms
    delay(400);
  } else {
    noTone(pinBuzzer); // Pas d'intrusion, silence
  }
}
```

---

## 🚀 Pistes d'Amélioration (Évolutions Futures)
Pour rendre le projet encore plus robuste et proche d'un produit industriel, voici les modules qui pourraient être ajoutés :
1. **Indicateur visuel :** Ajout d'une LED rouge clignotante synchronisée avec le buzzer lors d'une alerte.
2. **Système d'armement :** Intégration d'un bouton poussoir ou du clavier 4x4 (Projet 5) pour activer/désactiver l'alarme à l'aide d'un code.
3. **Connectivité (IoT) :** Utilisation d'un module ESP32 pour envoyer une notification d'alerte sur smartphone (via Blynk ou Telegram) en cas d'intrusion.

---

## 🛠️ Simulation
Ce projet a été développé et validé à 100% sur la plateforme de simulation en ligne **Wokwi** avec des composants natifs.
