# 💡 Veilleuse Automatique Intelligente (Smart Nightlight)

Ce projet présente un prototype fonctionnel de **système d'éclairage ambiant autonome** développé sur la plateforme de simulation embarquée **Wokwi**. Il illustre les compétences fondamentales en électronique numérique et analogique, notamment l'acquisition de données capteur et la logique de commande à seuil.

---

## 🛠️ Présentation du Projet & Analogie

Pour comprendre le fonctionnement de ce circuit de manière simple, on peut utiliser **l'analogie de la plomberie** :
* **Le courant électrique** est comparable à de l'eau circulant dans des tuyaux.
* **La tension (5V)** représente la pression de l'eau.
* **Le microcontrôleur Arduino** agit comme le gestionnaire du réseau (le chef de chantier). Il analyse la pression reçue sur son entrée analogique (`A0`) et choisit d'ouvrir ou de fermer la vanne de sortie (`D13`) pour alimenter la lampe.
* **La résistance** sert d'étranglement pour freiner le débit de l'eau et éviter que la LED ne reçoive trop d'énergie et ne grille.

---

## 🔌 Liste du Matériel (100% Composants Natifs Wokwi)

* **1x** Carte microcontrôleur Arduino Uno
* **1x** Capteur de lumière / Photo-résistance (LDR)
* **1x** Diode Électroluminescente (LED) standard
* **1x** Résistance de $220\ \Omega$ (protection de la LED)
* **1x** Résistance de $10\ \text{k}\Omega$ (pont diviseur de tension pour le capteur)

---

## 📐 Guide de Câblage Étape par Étape

### 1. Circuit de l'Actionneur (La LED d'éclairage)
* **Patte longue (+)** de la LED ➡️ Résistance de $220\ \Omega$ ➡️ Broche numérique **D13** de l'Arduino.
* **Patte courte (-)** de la LED ➡️ Broche **GND** (Masse) de l'Arduino.

### 2. Circuit du Capteur (La Photo-résistance)
* **Première patte** de la LDR ➡️ Broche **5V** de l'Arduino (Alimentation en puissance).
* **Seconde patte** de la LDR ➡️ Broche analogique **A0** de l'Arduino (Point de mesure de la tension).
* **Pont de référence** : Depuis cette même broche **A0**, connectez la résistance de $10\ \text{k}\Omega$ vers la broche **GND** de l'Arduino.

---

## 💻 Code Source Commenté (Arduino C++)

Le programme est optimisé pour être lisible et auto-explicatif. La boucle principale mesure la luminosité ambiante et pilote la sortie de puissance selon un seuil d'obscurité défini.

```cpp
// Configuration des broches de l'Arduino
const int pinLDR = A0;  // Port d'entrée pour la mesure du capteur analogique
const int pinLED = 13;  // Port de sortie numérique pour piloter l'allumage de la LED

// Seuil de basculement algorithmique (Échelle de l'ADC : 0 à 1023)
const int seuilObscurite = 400; 

void setup() {
  // Définition de la direction des flux de signaux
  pinMode(pinLED, OUTPUT); // Le port 13 envoie de la puissance (Actionneur)
  pinMode(pinLDR, INPUT);  // Le port A0 reçoit l'information de tension (Capteur)
  
  // Ouverture de la liaison de communication série pour le monitoring en temps réel
  Serial.begin(9600);
}

void loop() {
  // Acquisition du signal analogique converti par le microcontrôleur
  int valeurLumiere = analogRead(pinLDR);
  
  // Envoi de la valeur brute vers le moniteur série à des fins de débogage
  Serial.print("Indice de luminosite ambiante : ");
  Serial.println(valeurLumiere);
  
  // Logique de décision à seuil
  if (valeurLumiere < seuilObscurite) { 
    // CONDITION REMPLIE : La luminosité est trop faible (Nuit)
    digitalWrite(pinLED, HIGH); // Commande d'allumage : injection de 5V sur le port D13
  } 
  else { 
    // CONDITION NON REMPLIE : La luminosité est suffisante (Jour)
    digitalWrite(pinLED, LOW);  // Commande d'extinction : passage à 0V sur le port D13
  }
  
  // Temporisation de 200ms pour stabiliser les cycles d'horloge du processeur
  delay(200); 
}
```

---

## 🎯 Compétences Validées (Valorisation Alternance)

Ce projet simple met en avant plusieurs compétences techniques indispensables pour un technicien ou ingénieur en systèmes embarqués :
1. **Traitement du Signal** : Compréhension et mise en œuvre d'un pont diviseur de tension pour transformer une variation de résistance physique en variation de tension mesurable.
2. **Programmation C++ Embarquée** : Utilisation des fonctions natives de l'IDE Arduino (`analogRead`, `digitalWrite`), gestion des types de données et mise en place d'une logique conditionnelle.
3. **Prototypage Virtuel** : Maîtrise de l'environnement Wokwi pour simuler un comportement matériel avant routage électronique ou câblage physique sur banc d'essai.

