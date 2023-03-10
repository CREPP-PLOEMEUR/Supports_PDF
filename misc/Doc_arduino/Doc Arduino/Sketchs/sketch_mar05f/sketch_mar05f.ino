//....entête déclarative
// = déclarer ici variables et constances globales

const int LED[8] = {2,3,4,5,6,7,8,9}; // Tableau de constantes

int vitesse=250; // variable fixant la durée de la pause

//....la fonction setup(): éxécutée au début et en une seule fois
void setup() {
  
  // met les 8 broches en sortie
  for (int i=0; i<8; i++) {  // répète 8 fois le code
     pinMode(LED[i], OUTPUT); // met la broche en sortie
  } // fin de for
  
} // fin de la fonction setup()

// ...la fonction loop(): éxécutée ensuite en boucle sans fin
void loop() {
  
  for (int numLED=0; numLED<8; numLED++) { // défile les 8 LEDs
  
    // allume la LED voulue
    for (int i=0; i<8; i++) { // répète 8 fois le code
       if (i==numLED) {  // si la LED est la LED courante
         digitalWrite(LED[i], HIGH);  // allume la LED
       }
       else {  // sinon
         digitalWrite(LED[i], LOW);  // éteint la LED
       }
    }  // fin de for i
  
    delay(vitesse); // pause de n milliseconde
  
  } // fin de for numLED

} // fin de la fonction loop()  
