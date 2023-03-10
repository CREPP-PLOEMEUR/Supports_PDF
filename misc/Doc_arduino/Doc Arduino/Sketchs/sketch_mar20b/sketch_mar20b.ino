// ... Entête déclarative
// ...on déclare ici les constantes et les variables globales

const int LED[8] = {8,9,4,3,2,7,6,5};

// ... ordre des broches a,b,c,d,e,f,g,pt

int vitesse = 1000;  //....variable fixant le temps de pause


void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<8; i++){  // ...répète 8 fois le code
    pinMode(LED[i], OUTPUT);  // met la broche en sortie
    
  }  // ....fin de la boucle for

}    // ...fin de la fonction setup()

void loop() {
  // put your main code here, to run repeatedly:
 //...ordre des broches a,b,c,d,e,f,g,pt
allumeLED(B11111100);  // nombre 0
allumeLED(B01100000);  // nombre 1
allumeLED(B11011010);  // nombre 2
allumeLED(B11110010);  // nombre 3
allumeLED(B00100110);  // nombre 4
allumeLED(B10110110);  // nombre 5
allumeLED(B00111110);  // nombre 6
allumeLED(B11100000);  // nombre 7
allumeLED(B11111110);  // nombre 8
allumeLED(B11100110);  // nombre 9

  
}  // ...fin de la fonction loop()
void allumeLED(unsigned int valeur) {
  for (int i=0; i<8; i++) {
    digitalWrite(LED[i], bitRead(valeur, 7-i));
  }
  delay(vitesse);
}
