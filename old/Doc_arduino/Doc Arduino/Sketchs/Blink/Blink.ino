/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
const int LED=3;
int vitesse=20;
int largeur=0;  // largeur d'impulsion
void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
 
  pinMode(LED, OUTPUT);     
}

void loop() {
  for (int i=100;i>=0; i--){
    largeur=map(i,0,100,0,255);
    analogWrite(LED, largeur);
    delay(vitesse);
  }
 
}
