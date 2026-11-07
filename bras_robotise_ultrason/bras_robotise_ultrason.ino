#include <Servo.h>

Servo brasDeTri;
const int pinTrig = 12;
const int pinEcho = 11;

void setup() {
  brasDeTri.attach(9);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  brasDeTri.write(0); // Position repos
}

void loop() {
  digitalWrite(pinTrig, LOW); delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  long duree = pulseIn(pinEcho, HIGH);
  int distance = duree * 0.034 / 2;
  
  if (distance > 0 && distance < 10) {
    brasDeTri.write(90); // Éjection
    delay(2000);
    brasDeTri.write(0);  // Retour à la position repos
  }                      // <-- Ajouté : Fermeture du "if"
  
  delay(100);            // <-- Recommandé : Petite pause pour stabiliser le capteur
}                        // <-- Ajouté : Fermeture de la fonction "loop"
