// décalage latéral de l'affichage entier d'un afficheur LCD

// entête déclarative
#include <LiquidCrystal.h>

// déclaration des broches de l'afficheur

const int RS=2;  // broche RS
const int E=3;  // broche E
const int D4=4;  // broche D4
const int D5=5;  // broche D5
const int D6=6;  // broche D6
const int D7=7;  // broche D7

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);  // déclaration objet représentant lcd

// la fonction setup(): s'exécute en premier une seule fois
void setup() {
  
  lcd.begin(16, 2);  // initialisation colonnes x lignes
  
  lcd.clear();  // efface LCD se place en 0,0
  delay(10);  // courte pause après clear()
  
  lcd.print("LCD OK !");  // affiche le message
  delay(1000);  //pause
  
  lcd.clear();  // efface LCD et se place en 0,0
  delay(10);  // courte pause après clear()
  
  //.....message initial....
  lcd.setCursor(2,0);  // positionne le curseur
  lcd.print("**Ateliers**");  // affiche le message
  lcd.setCursor(2,1);  // positionne le curseur
  lcd.print("**Arduino**");  // affiche le message
  
}  // fin de la fonction setup()

// la fonction loop (): exécutée ensuite en boucle sans fin
void loop() {
  
  for (int i=0; i<2; i++) {
    lcd.scrollDisplayLeft();  // décalage affichage entier vers la gauche
    delay(1000);
  }
  
  for (int i=0; i<4; i++) {
    lcd.scrollDisplayRight();  // décalage affichage entier vers la droite
    delay(1000);
  }
  
  for (int i=0; i<2; i++) {
    lcd.scrollDisplayLeft();  // décalage affichage entier vers la gauche
    delay(1000);
  }
  
}  // fin de la fonction loop()


