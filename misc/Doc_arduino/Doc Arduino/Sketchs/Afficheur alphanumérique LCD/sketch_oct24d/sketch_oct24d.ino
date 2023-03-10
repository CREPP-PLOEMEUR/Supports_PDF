// Positionnement du curseur d'un afficheur LCD

// entête déclarative
#include <LiquidCrystal.h>  // inclusion de la librairie LCD

// déclaration des broches de l'afficheur

const int RS=2;  // broche RS
const int E=3;   // broche E
const int D4=4;  // broche D4
const int D5=5;  // broche D5
const int D6=6;  // broche D6
const int D7=7;  // broche D7

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);  //  déclaration d'un objet représentant LCD

// la fonction setup(): exécutée au début et en une seule fois
void setup() {
  
  lcd.begin(16,2);  // initialisation LCD colonne x lignes
  
  lcd.clear();  // efface LCD et se place en 0,0
  delay(10);  // courte pause après clear()
  
  lcd.print("LCD OK");  // affiche le message
  delay(1000);  // pause
  
  lcd.clear();  // efface LCD et se place en 0,0
  delay(10);  // courte pause après clear()
  
}    // fin de la fonction setup()

// la fonction loop(): exécutée ensuite en boucle sans fin
void loop() {
  
  lcd.blink();  // active le clignotement
  
  lcd.print("decalage texte");  // affiche le message
  delay(4000);  // pause
  
  lcd.home();  // retour en 0,0 sans modifier l'affichage
  lcd.setCursor(1-1, 2-1);  // se place en 1ère colonne 2ème ligne (-1 pour corriger l'indice )
  lcd.print("home");  // afiche message
  lcd.home();        // retour en 0,0 sans modifier l'affichage
  delay(4000);  // pause
  
  lcd.setCursor(6-1, 2-1);  // se palce en 11ème colonne 2ème ligne
  lcd.print("ici");  // affiche message
  delay(4000);  // pause
  
  lcd.setCursor(10-1, 2-1);  // se place en 5ème colonne2ème ligne
  lcd.print("et la");    // affiche message
  delay(4000);  // pause
  
  lcd.clear();  // efface écran et position en 0,0
  delay(4000);  // pause
  
}  // fin de la fonction loop()


