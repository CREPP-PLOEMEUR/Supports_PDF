const int LED [8] = {2,3,4,5,6,7,8,9}; // tableau de constantes

int vitesse=1000; // variable fixant la durée de la pause

void setup() {
  
  pinMode(LED[0], OUTPUT); // met la broche en sortie
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);
  pinMode(LED[6], OUTPUT);
  pinMode(LED[7], OUTPUT);
 
 
  
} // fin de la fonction setup()

void loop() {
  
  digitalWrite(LED[0], HIGH); // allume la LED
  digitalWrite(LED[1], HIGH);
  digitalWrite(LED[2], HIGH);
  digitalWrite(LED[3], HIGH);
  digitalWrite(LED[4], HIGH);
  digitalWrite(LED[5], HIGH);
  digitalWrite(LED[6], HIGH);
  digitalWrite(LED[7], HIGH);
  
  
  delay (vitesse); // pause de n millisecondes
  
  digitalWrite(LED[0], LOW); // éteint la LED
  digitalWrite(LED[1], LOW);
  digitalWrite(LED[2], LOW);
  digitalWrite(LED[3], LOW);
  digitalWrite(LED[4], LOW);
  digitalWrite(LED[5], LOW);
  digitalWrite(LED[6], LOW);
  digitalWrite(LED[7], LOW);
 
  
  delay (vitesse); // fin de la fonction loop()
  
}
