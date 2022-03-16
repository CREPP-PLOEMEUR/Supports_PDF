//...entête déclarative
// déclaration des constantes et variables globales

const int ledR=3;  // déclaration constante de broche
const int ledV=5;  // déclaration constante de broche
const int ledB=6;  // déclaration constante de broche

int i=0;          // déclaration variable de boiucle

// la fonction setup() s'exécute une seule fois

void setup() {
  
  pinMode(ledR, OUTPUT);  // met la broche en sortie
  pinMode(ledV, OUTPUT);  // met la broche en sortie
  pinMode(ledB, OUTPUT);  // met la broche en sortie
  
}  // fin de la fonction setup()

void loop() {
  
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledR, i);  // génère des impulsions sur la broche de largeur i, la luminosité augmente
    delay(10);              // pause de 10 ms entre chaque cran
  } //fin de for
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledR, 255-i);  // génère des impulsions sur la broche de largeur i, la luminosité diminue
    delay(10);              // pause de 10 ms entre chaque cran
  } // fin de for
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledV, i);   // génère des impulsions sur la broche de largeur i, la luminosité augmente
    delay(10);              // pause de 10 ms entre chaque cran
  }  // fin de for
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledV, 255-i);  // génère des impulsions sur la broche de largeur i, la luminosité diminue
    delay(10);              // pause de 10 ms entre chaque cran
  } // fin de for
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledB, i);   // génère des impulsions sur la broche de largeur i, la luminosité augmente
    delay(10);              // pause de 10 ms entre chaque cran
  } // fin de for
  for (i=0; i<=255; i++) {  // boucle for qui compte de 0 à 255
    analogWrite(ledB, 255-i);  // génère des impulsions sur la broche de largeur i, la luminosité diminue
    delay(10);              // pause de 10 ms entre chaque cran
  } // fin de for
  
}  // fin de la fonction loop()
