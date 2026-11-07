#include <Servo.h>

Servo trackServo;
int positionServo = 90;

void setup() {
  trackServo.attach(9);
  trackServo.write(positionServo);
  
  // Configuration des broches des capteurs de lumière
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  Serial.begin(9600); // Permet d'afficher les valeurs pour le réglage
}

void loop() {
  int ldrGauche = analogRead(A0); // Photorésistance Gauche
  int ldrDroite = analogRead(A1); // Photorésistance Droite
  
  int tolerance = 20; // Évite que le moteur ne tremble pour de toutes petites variations

  // SUR WOKWI : Plus la valeur lue est PETITE, plus il y a de LUMIÈRE.
  // Donc si (ldrGauche - ldrDroite) > tolerance, cela signifie que LDR_Droite a une valeur plus petite, 
  // donc LDR_Droite reçoit PLUS de lumière. Le moteur doit aller vers la DROITE.
  
  if ((ldrGauche - ldrDroite) > tolerance) {
    if (positionServo < 180) positionServo += 2; // Pivoter à droite (vers la lumière)
  } 
  else if ((ldrDroite - ldrGauche) > tolerance) {
    if (positionServo > 0) positionServo -= 2;   // Pivoter à gauche (vers la lumière)
  }

  trackServo.write(positionServo);
  
  delay(30); // CRUCIAL SUR WOKWI : Laisse le temps au servomoteur de se déplacer proprement
}
