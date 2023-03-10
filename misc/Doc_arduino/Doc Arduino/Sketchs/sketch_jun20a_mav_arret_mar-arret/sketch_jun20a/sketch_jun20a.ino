//.... inclusion de librairie
#include <Servo.h>  // inclut la librairie Servo

//... entête déclarative des constantes et variables globales

const int neutre=1395;  // largeur impulsion arrêt
const int maxAV=1695;  // largeur impulsion vitesse max en avant
const int maxAR=1095;  // largeur impulsion vitesse max arrière

const int brocheServo=2;  // broche du servomoteur

int impulsServo=0;        // largeur impulsion servomoteur en µsecondes

Servo servo;   // déclaration d'un objet servomoteur

void setup() {  // la fonction setup(): exécutée au début et en une seule fois

}  // fin de la fonction setup() exécutée au début et en une seule fois

void loop() {  // la fonction loop(): exécutée en boucle sans fin

  //...marche avant progressive
  servo.attach(brocheServo);  // attache le servomoteur à la broche
  
  for (int i=10; i<=100; i++) {  // progression en pourcentage %
  impulsServo=map(i, 0, 100, neutre, maxAV);  // calcul largeur impulsion AV correspondante en µsecondes
  servo.writeMicroseconds(impulsServo);
  delay(100);  // pause entre 2 changements
  
  }   // fin de for
  
  //...mise à l'arrêt réel du servomoteur
  servo.detach();   // détache le servomoteur de la broche = mise à l'arrêt
  delay(2000);  // pause
  
  //...marche arrière progressive
  servo.attach(brocheServo);  // attache le servomoteur à la broche
  
  for (int i=10; i<=100; i++) {  // progression en pourcentage %
  impulsServo=map(i, 0, 100, neutre, maxAR);  // calcul de largeur impulsion AR correspondante en µsecondes
  servo.writeMicroseconds(impulsServo);
  delay(100);  // pause entre 2 changements
  
  }  // fin de for
  
  // mise à l'arrêt réel du servomoteur
  servo.detach();  // détache le servomoteur de la broche = arrêt du servomoteur
  delay(2000);  // pause
  
}  // fin de la fonction loop()
