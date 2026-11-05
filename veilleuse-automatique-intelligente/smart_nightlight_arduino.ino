const int pinLDR = A0; // Capteur de lumière sur A0
const int pinLED = 13; // LED d'éclairage sur D13

void setup() {
  pinMode(pinLED, OUTPUT); // Broche 13 configurée en Sortie
  pinMode(pinLDR, INPUT);  // Broche A0 configurée en Entrée
  Serial.begin(9600);
}

void loop() {
  int valeurLumiere = analogRead(pinLDR); // Lecture du capteur (0 à 1023)
  
  // RÈGLE WOKWI : valeurLumiere > 600 signifie qu'il fait NOIR
  if (valeurLumiere > 600) {
    digitalWrite(pinLED, HIGH); // Allumer la LED dans l'obscurité
  } else {
    digitalWrite(pinLED, LOW);  // Éteindre la LED à la lumière
  }
  
  delay(200);
}
