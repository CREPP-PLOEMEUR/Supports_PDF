// entête déclarative
// déclarer ici constantes et variables locales

const int LED=2; // constante désignant la broche
int vitesse=1000; // variable fixant la durée de la pause

//...la fonction setup() : exécutée au début et en une seule fois
void setup() {
  
  pinMode(LED, OUTPUT); // met la broche en sortie
  
} // fin de la fonction setup()
void loop() {
  
  digitalWrite(LED, HIGH); // allume la LED
  delay(vitesse); // pause de n millisecondes
  digitalWrite(LED, LOW); // éteint la LED
  delay(vitesse); // pause de n millisecondes
  
} // fin de la fonction loop
