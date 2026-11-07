# 🤖 LogiSort 4.0 : Système de Tri Logistique (Bras Robotisé)

Ce projet fait partie de mon catalogue de prototypes électroniques pour l'alternance. Il simule un système d'automatisation industrielle (Industrie 4.0) capable de mesurer la distance d'approche d'un produit sur une ligne de convoyage et de déployer instantanément un bras mécanique pour l'éjecter ou le trier selon sa position.

## 🎯 Objectifs Pédagogiques & Techniques
- Utiliser et comprendre le fonctionnement d'un capteur de distance à ultrasons (principe du temps de vol).
- Piloter un actionneur mécanique (servomoteur) en position angulaire via un signal PWM.
- Implémenter une logique de décision en temps réel basée sur des seuils de tolérance physiques.

---

## ⚙️ Composants Utilisés

| Composant | Rôle |
| :--- | :--- |
| **Arduino Uno** | Microcontrôleur / Cerveau du système de tri |
| **Capteur Ultrason (HC-SR04)** | Mesure de distance en temps réel par ondes sonores |
| **Servo-moteur** | Actionneur simulant le bras articulé d'éjection |

---

## 🔌 Câblage Pas à Pas

Le schéma de connexion sur le prototype est configuré ainsi :

### 📡 Capteur Ultrason (HC-SR04) :
- **VCC** ➡️ Broche **5V** de l'Arduino
- **GND** ➡️ Broche **GND** de l'Arduino
- **Trig** (Déclencheur) ➡️ Broche numérique **D12**
- **Echo** (Réception) ➡️ Broche numérique **D11**

### 🦾 Servo-moteur :
- **Fil Rouge (VCC)** ➡️ Broche **5V** de l'Arduino
- **Fil Noir / Marron (GND)** ➡️ Broche **GND** de l'Arduino
- **Fil Orange / Jaune (Signal)** ➡️ Broche numérique **D9 (PWM)**

---

## 💻 Code Source (Arduino)

```cpp
#include <Servo.h>

Servo brasDeTri;
const int pinTrig = 12;
const int pinEcho = 11;

void setup() {
  brasDeTri.attach(9);        // Fixe le servo sur la broche D9
  pinMode(pinTrig, OUTPUT);   // Configuration du Trig en sortie
  pinMode(pinEcho, INPUT);    // Configuration de l'Echo en entrée
  brasDeTri.write(0);         // Position de repos initiale (0°)
}

void loop() {
  // Génération d'une impulsion propre de 10µs sur Trig pour lancer l'onde
  digitalWrite(pinTrig, LOW); 
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  // Mesure du temps de retour de l'onde (temps de vol en microsecondes)
  long duree = pulseIn(pinEcho, HIGH);
  
  // Calcul de la distance en cm (Vitesse du son = 0.034 cm/µs)
  int distance = duree * 0.034 / 2;
  
  // Logique industrielle : si un objet est détecté à moins de 10 cm
  if (distance > 0 && distance < 10) {
    brasDeTri.write(90);      // Déploiement du bras à 90° (Éjection)
    delay(2000);              // Maintien du bras pendant 2 secondes
    brasDeTri.write(0);       // Retour à la position de repos initiale
  }
  delay(100);                 // Pause de stabilité avant la mesure suivante
}
```

---

## 🚀 Pistes d'Amélioration (Évolutions Industrielles)
Pour adapter ce prototype à une véritable chaîne logistique de Smart Factory, voici les ajouts envisageables :
1. **Compteur de pièces :** Intégration d'un écran LCD 1602 I2C pour afficher la distance en direct et comptabiliser le nombre total de colis triés.
2. **Tri Multi-zones :** Remplacer le comportement binaire par plusieurs paliers angulaires pour aiguiller les objets vers différents bacs de tri selon leur taille ou distance.
3. **Contrôle Qualité Connecté :** Associer un capteur de couleur (TCS3200) pour rejeter uniquement les produits non conformes et envoyer les statistiques de production via une passerelle IoT.

---

## 🛠️ Simulation
Ce projet a été modélisé, câblé et validé à 100% sur le simulateur en ligne **Wokwi** avec des composants strictement natifs.
