//.. Entête déclarative
// ...déclarer ici les constantes et variables globales
const int LED[8] = {8,9,4,3,2,7,6,5};  // ...tableau des constantes
//... ordre des broches a,b,c,d,e,f,g,pt
int vitesse=1000;  // ... temps de pause

void setup() {
  // put your setup code here, to run once:
  // ...défile les broches 0 à 7
  for (int i=0; i<8; i++) {  //.. répète 8 fois le code
    pinMode(LED[i], OUTPUT);
  
  }   // ...fin de for

}    // ...fin de la fonction setup()

// ...la fonction loop() éxécutée ensuite en boucle sans fin

void loop(){
  //..défile les chiffres 0 à 9
  for(int chiffre=0; chiffre<=9; chiffre++) {
    //digit(chiffre,true); // chiffre + point
    //digit(chiffre,false); //chiffre sans le point
    digit(chiffre, chiffre % 2); // chiffre + le point allumé si impair (reste=1)
    delay(vitesse);  // pause
    
  }
  
   digit(-1, false); //éteint segments + point
   delay(vitesse);  // pause
   
}  // fin de la fonction loop()

// fonction qui reçoit ine valeur de type int non signée et ne renvoie aucune valeur

void allumeLED(unsigned int valeur) {  // fonction pour allumer/éteindre les LEDs voulues en fonction valeur 8 bits reçue

for (int i=0; i<=7; i++) {
  digitalWrite(LED[i], bitRead(valeur,7-1)); // met la broche LED[i] dans l'état du bit de rang i de la variable
  
} // fin de for
  
} // fin de la fonction allumeLED

// fonction qui reçoit le chiffre à afficher et boolean pour afficher le point
void digit(int chiffreIn, boolean pointIn) {

// ordre des broches a,b,c,d,e,f,g,pt

if (chiffreIn==0) allumeLED(B11111100); // nombre 0
if (chiffreIn==1) allumeLED(B01100000); // nombre 1
if (chiffreIn==2) allumeLED(B11011010); // nombre 2
if (chiffreIn==3) allumeLED(B11110010); // nombre 3
if (chiffreIn==4) allumeLED(B01100110); // nombre 4
if (chiffreIn==5) allumeLED(B10110110); // nombre 5
if (chiffreIn==6) allumeLED(B10111110); // nombre 6
if (chiffreIn==7) allumeLED(B11100000); // nombre 7
if (chiffreIn==8) allumeLED(B11111110); // nombre 8
if (chiffreIn==9) allumeLED(B11110110); // nombre 9

if (chiffreIn<0) allumeLED(B00000000); // éteint tout si chiffre négatif

if (chiffreIn==true) digitalWrite(LED[7], HIGH); // allume point sans modifier les autres
else digitalWrite(LED[7], LOW);  // sinon éteint le point

} // fin de la fonction digit
