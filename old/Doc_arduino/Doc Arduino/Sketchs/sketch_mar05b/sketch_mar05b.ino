// entête déclarative
//....déclare ici les constantes et variables globales
 
 const int LED[4] = {2,3,4,5}; // Tableau de constantes
 
 int vitesse(1000); // variable fixant la durée de la pause
 // ....la fonction setup() : éxécutée au début et en une seule fois
 
 void setup() {
    pinMode(LED[0], OUTPUT); // met la broche en sortie
    pinMode(LED[1], OUTPUT); // met la broche en sortie
    pinMode(LED[2], OUTPUT); // met la broche en sortie
    pinMode(LED[3], OUTPUT); // met la broche en sortie
    
 } // fin de la fonction setup()
 
 void loop() {
   digitalWrite(LED[0], HIGH); // allume la LED1
   digitalWrite(LED[1], HIGH); // allume la LED2
   digitalWrite(LED[2], HIGH); // allume la LED3
   digitalWrite(LED[3], HIGH); // allume la LED4
   
   delay(vitesse); // pause de n milliseconde
   
   digitalWrite(LED[0], LOW); // éteint la LED1
   digitalWrite(LED[1], LOW); // éteint la LED2
   digitalWrite(LED[2], LOW); // éteint la LED3
   digitalWrite(LED[3], LOW); // éteint la LED4
   
   delay(vitesse); // pause de n millisecondes
   
 } // fin de la fonction loop()
