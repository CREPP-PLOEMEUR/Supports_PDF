// Entête déclarative

#include <LiquidCrystal.h>  // inclusion de la librairie LCD

// déclaration des broches de l'afficheur
const int RS=2;    // broche RS
const int E=3;     // broche E
const int D4=4;    // broche D4
const int D5=5;    // broche D5
const int D6=6;    // broche D6
const int D7=7;   // broche D7

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);  // déclaration objet représentant lcd

// la fonction setup(): exécutée une fois et en une seule fois
void setup() {
  
  lcd.begin(16,2);  // initialise LCD colones x 2
  
  lcd.clear();      // efface LCD + se place en 0,0
  lcd.print("Papy est un Chef");  // affiche le message
  
}  // fin de la fonction setup()

// la fonction loop(): exécutée en boucle sans fin
void loop() {
  
  lcd.display();  // active l'affichage LCD ( sans modifier le message )
  delay(1000);  // pause
 
  lcd.noDisplay();  // désactive l'affichage LCD ( sans modifier le message )
  delay(1000);    // pause
 
}    // fin de la fonction loop() 


