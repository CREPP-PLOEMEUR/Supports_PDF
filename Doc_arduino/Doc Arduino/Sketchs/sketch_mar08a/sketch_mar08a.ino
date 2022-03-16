const int LED[4] = {2,3,4,5}; // tableau de constantes

int vitesse=250; // variable fixant la durée de la pause

void setup() {
                // met les 4 broches en sortie
  for (int i=0; i<4; i++){  // répète 4 fois le code
     pinMode(LED[i], OUTPUT);  // met la broche en sortie
  }  // fin de for
}    // fin de la fonction setup()

void loop() {
  
  for (int numLED=0; numLED<4; numLED++) {  // défile les 4 LEDs
    
        // allume la LED voulue
     for (int i=0; i<4; i++) { // allume 4 fois le code
        if (i==numLED) {      // si la LED est la LED courante
          digitalWrite(LED[i], HIGH);  // allume la LED
        }
        else {  // sinon
          digitalWrite(LED[i], LOW);   // éteint la LED
        }
  }  // fin de for i
  
      delay(vitesse);
      
  }   // fin for numLED
      
}


     
  
