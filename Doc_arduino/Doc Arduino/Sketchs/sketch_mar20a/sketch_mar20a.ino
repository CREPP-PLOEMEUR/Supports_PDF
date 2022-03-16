//....étape déclarative
const int LED[8] = {8,9,4,3,2,7,6,5};  //... tableau des constantes
 // ....ordre des broches a,b,c,d,e,f,g,pt
int vitesse = 200;  //...variable fixant la durée de la pause


void setup() {
  // put your setup code here, to run once:
  //...met les 8 broches en sortie
  for (int i=0; i<8; i++){  // ...répète 8 fois le code
    pinMode(LED[i], OUTPUT);  //...met la broche en sortie
  } //...fin de for

}  //...fin dela fonction setup()

void loop() {
  // put your main code here, to run repeatedly: 
  for (int i=0; i<8; i++) {  // ...répète 8 fois le code
     digitalWrite(LED[i], HIGH);  //...allume la LED en cours
     delay(vitesse);  //...temps de pose
     digitalWrite(LED[i], LOW);  //...éteint la LED en cours
    
  }  //  ....fin de for
  
}   //...fin de la fonction loop()
