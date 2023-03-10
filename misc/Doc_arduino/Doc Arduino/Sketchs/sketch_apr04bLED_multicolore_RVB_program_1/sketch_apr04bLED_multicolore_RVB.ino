// entête déclarative
// déclaration des constantes et variables globale

const int ledR=3;  // constante désignat la broche de la LED
const int ledV=5;  // constante désignant la broche de la LED
const int ledB=6;  // constante désignant la broche de la LED

const boolean R=true;  // constante binaire couleur R
const boolean V=true;  // constante binaire couleur V
const boolean B=true;  // constante binaire couleur B

int vitesse=1000;      // variable fixant la durée de la pause en ms

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledB, OUTPUT);
  
}

void loop() {
  // couleurs de base...
  
  ledRVB(R,0,0),ledRVB(0,0,0);  // rouge puis éteint
  ledRVB(0,V,0),ledRVB(0,0,0);  // vert puis éteint
  ledRVB(0,0,B),ledRVB(0,0,0);  // bleu puis éteint
  
  //....mix....
  ledRVB(R,V,0),ledRVB(0,0,0);  // rouge + vert = jaune puis éteint
  ledRVB(R,0,B),ledRVB(0,0,0);  // rouge + bleu = violet puis éteint
  ledRVB(0,V,B),ledRVB(0,0,0);  // vert + bleu = bleu clair puis éteint
  ledRVB(R,V,B),ledRVB(0,0,0);  // rouge + vert + bleu = blanc puis éteint
  
}  // fin de la fonction loop()

void ledRVB(boolean Rouge, boolean Vert, boolean Bleu) {
  if (Rouge==true)digitalWrite(ledR, HIGH);  // allume couleur
  else digitalWrite(ledR, LOW);              // éteint couleur
  
  if (Vert==true)digitalWrite(ledV, HIGH);    // allume couleur
  else digitalWrite(ledV, LOW);               // éteint couleur
  
  if (Bleu==true)digitalWrite(ledB, HIGH);    // allume couleur
  else digitalWrite(ledB, LOW);               // éteint couleur
  
  delay(vitesse);     // pause de n millisecondes
  
}




  

   
