// ...entête déclarative
// = déclarer ici les variables et les constantes

const int LED[8] = {2,3,4,5,6,7,8,9}; // Tableau des constantes

int vitesse=1000; // variable fixant la durée de la pause

// ...la fonction setup(): éxécutée au début et une seule fois
void setup() {
  
  // ...met les 8 broches en sortie
    for(int i=0; i<8; i++) {  // répète 8 fois le code
       pinMode(LED[i], OUTPUT); // met la broche en sortie
    } // fin de for
  
} // fin de la fonction setup()

//...la fonction loop(): éxécutée ensuite en boucle sans fin
void loop() {
    
 // allume les 8 LEDs 
   for (int i=0; i<8; i++) { // répète 8 fois le code
      digitalWrite(LED[i], HIGH); // allume la LED
   } // fin de for 
  
    delay(vitesse); // pause de n millisecondes
    
// éteint les 8 LEDs    
    for (int i=0; i<8; i++) {  // boucle for répète 8 fois
       digitalWrite(LED[i], LOW);  // éteint la LED
    } // fin de for  
     
    delay(vitesse); // pause de n millisecondes
         
  } // fin de la fonction loop()
     

     
    
