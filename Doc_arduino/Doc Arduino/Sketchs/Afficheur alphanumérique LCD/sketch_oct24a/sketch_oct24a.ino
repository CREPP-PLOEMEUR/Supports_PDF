
// Afiche message sur un afficheur LCD standard

// En tête déclarative
#include <LiquidCrystal.h>  // inclusion de la librairie LCD

// Déclaration des broches de l'afficheur
const int RS=2;  // broche RS
const int E=3;   // broche E
const int D4=4;  // broche D4
const int D5=5;  // broche D5
const int D6=6;  // broche D6
const int D7=7;  // broche D7

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);  // déclaration d'un objet représentant lcd

// la fonction setup(): exécutée au début et en une seule fois
void setup() {
  
  // écrire ici les instruction à exécuter au début
  lcd.begin(16,2);  // initialisation LCD colonnes x lignes
  lcd.clear();      // efface LCD  + se place en 0,0
  lcd.print("Hello World"); // affiche le message
  
}  // fin de la fonction setup ()

// la fonction loop(): exécutée en boucle sans fin
void loop() {
  // écrire ici les instructions à exécuter en boucle
  
 } // fin de la fonction loop()

