# ☀️ Projet 6 : Le Tracker Solaire Photovoltaïque

Ce projet fait partie de mon catalogue de prototypes électroniques pour l'alternance. Il consiste à concevoir un système d'orientation dynamique pour panneau solaire (tracker de lumière mono-axe) capable de suivre la course du soleil en temps réel en comparant l'intensité lumineuse captée par deux photo-résistances (LDR) afin d'ajuster l'angle d'un servomoteur.

## 🎯 Objectifs Pédagogiques & Techniques
- Traiter et comparer des signaux analogiques différentiels en temps réel.
- Implémenter une zone morte informatique (seuil de tolérance) pour éviter les micro-oscillations mécaniques inutiles.
- Asservir un servomoteur de position en fonction d'un écart de variables d'entrée.

---

## ⚙️ Composants Utilisés

| Composant | Rôle |
| :--- | :--- |
| **Arduino Uno** | Microcontrôleur / Cerveau algorithmique du tracker |
| **2x Photo-résistances (LDR)** | Capteurs de luminosité (Gauches et Droite) pour cibler la source lumineuse |
| **2x Résistances 10kΩ** | Configurées en pont diviseur de tension pour la lecture analogique des LDR |
| **1x Servo-moteur** | Actionneur simulant le pivot d'orientation mécanique du panneau solaire |

---

## 🔌 Câblage Pas à Pas

Le schéma de connexion est configuré ainsi :

### 📡 Capteurs de lumière (LDR) :
- **LDR Gauche :** Une patte au **5V** | L'autre patte reliée à la broche analogique **A0** ET à une résistance de 10kΩ connectée au **GND**.
- **LDR Droite :** Une patte au **5V** | L'autre patte reliée à la broche analogique **A1** ET à une résistance de 10kΩ connectée au **GND**.

### 🦾 Servo-moteur :
- **Fil Rouge (VCC)** ➡️ Broche **5V** de l'Arduino
- **Fil Noir / Marron (GND)** ➡️ Broche **GND** de l'Arduino
- **Fil Orange / Jaune (Signal)** ➡️ Broche numérique **D9 (PWM)**

---

## 💻 Code Source (Arduino)

```cpp
#include <Servo.h>

Servo trackServo;
int positionServo = 90; // Position initiale au centre (90°)

void setup() {
  trackServo.attach(9); // Fixation du servo sur la broche D9
  trackServo.write(positionServo);
}

void loop() {
  // Lecture de l'intensité lumineuse (valeurs entre 0 et 1023)
  int ldrGauche = analogRead(A0);
  int ldrDroite = analogRead(A1);
  
  // Seuil de tolérance pour éviter les mouvements perpétuels et micro-oscillations
  int tolerance = 20; 
  
  // Comparaison des deux zones de luminosité
  if ((ldrGauche - ldrDroite) > tolerance) {
    if (positionServo > 0) positionServo -= 2; // Pivoter vers la gauche
  } 
  else if ((ldrDroite - ldrGauche) > tolerance) {
    if (positionServo < 180) positionServo += 2; // Pivoter vers la droite
  }
  
  // Envoi de la nouvelle consigne de position au servomoteur
  trackServo.write(positionServo);
  delay(50); // Pause de stabilité globale
}
```

---

## 🚀 Pistes d'Amélioration (Évolutions Industrielles)
Pour passer de ce prototype mono-axe à un système de qualité industrielle (ferme solaire connectée), voici les axes d'évolution :
1. **Tracker Double-Axe (Azimut & Élévation) :** Ajouter un second servomoteur et deux LDR supplémentaires (Haut et Bas) pour suivre parfaitement le soleil sur une trajectoire en 3D.
2. **Mode Économie d'Énergie / Mode Nuit :** Intégrer un algorithme qui repositionne le panneau à l'Est si la luminosité globale passe sous un seuil critique pendant une période prolongée (coucher du soleil), évitant la consommation inutile de courant la nuit.
3. **Télémesure (IoT) :** Mesurer la tension réelle générée par un mini-panneau solaire et envoyer la production en watts sur une application mobile via un module sans fil (WiFi/Bluetooth).

---

## 🛠️ Simulation
Ce projet a été modélisé, câblé et validé à 100% sur la plateforme de simulation en ligne **Wokwi** avec des composants nativement supportés.
