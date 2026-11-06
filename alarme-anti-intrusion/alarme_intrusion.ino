const int pinPIR = 2; // Capteur de mouvement sur D2
const int pinBuzzer = 8; // Buzzer d'alerte sur D8

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  int intrusion = digitalRead(pinPIR); // Détection Tout-Ou-Rien (0 ou 1)
  
  if (intrusion == HIGH) {
    tone(pinBuzzer, 1000, 300); // Bip à 1000Hz pendant 300ms
    delay(400);
    tone(pinBuzzer, 800, 300);  // Bip à 800Hz pendant 300ms
    delay(400);
  } else {
    noTone(pinBuzzer);          // Arrête le son si aucun mouvement n'est détecté
  }                             // <-- L'accolade du "else"
}                               // <-- L'accolade manquante de la fonction loop()
