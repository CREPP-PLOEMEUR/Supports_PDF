//....inclusion de librairie
#include <Servo.h>  // inclut la librairie Servo

//...entête déclarative = variables et constantes globales

  const int neutre=1395;  // largeur impulsion arrêt
  const int maxAV=1695;  // largeur impulsion vitesse max avant
  const int maxAR=1095;  // largeur impulsion vitesse max AR
  
  const int brocheServo=2;  // broche du servomoteur
  int impulsServo=0;  // largeur impulsion servomoteur en µsecondes
  Servo servo;  // déclaration d'un objet servomoteur
  
  const int RVar=0;  // déclaration constante broche analogique
  int mesureBrute=0;  // variable pour acquisition résultat brute de la conversion analogique numérique
  
void setup() {  // la fonction setup(): exécutée au début et en 1 seule fois

  servo.attach(brocheServo);  // attache le servo moteur à la broche
  
}  // fin de la fonction setup()

void loop() {  // la fonction loop(): exécutée en boucle et sans fin

  // acquisition conversion analogique-numérique (CAN) sur la voie analogique
  
  mesureBrute=analogRead(RVar); 
  
  impulsServo=map(mesureBrute, 0, 1395, maxAR, maxAV);  // calcul largeur impulsion correspondante
  servo.writeMicroseconds(impulsServo);
  
}  // fin de la fonction loop()
