// déclaration des constantes utiles
const int R=1;
const int V=1;
const int B=1;

const int ledRVB;
// déclaration des constantes de broches E/S numériques
const int ledRouge=3;
const int ledVert=5;
const int ledBleu=6;


void setup() {
  // mise en sortie des broches numériques
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVert, OUTPUT);
  pinMode(ledBleu, OUTPUT);
 
} // fin de la fonction setup()

void loop() {
  digitalWrite(ledRouge, HIGH);
  delay(1000);
  digitalWrite(ledRouge, LOW);
  delay(1000);
  
  digitalWrite(ledVert, HIGH);
  delay(1000);
  digitalWrite(ledVert, LOW);
  delay(1000);
  
  digitalWrite(ledBleu, HIGH);
  delay(1000);
  digitalWrite(ledBleu, LOW);
  delay(1000);
  
  // test des couleurs au format RVB
  ledRVB(R,0,B);
  delay(1000);
  ledRVB(0,0,0);
  delay(1000);
  
  ledRVB(R,V,0);
  delay(1000);
  ledRVB(0,0,0);
  delay(1000);
  
  ledRVB(0,V,B);
  delay(1000);
  ledRVB(0,0,0);
  delay(1000);
  
  ledRVB(R,V,B,);
  delay(1000);
  ledRVB(0,0,0);
  delay(1000);
  
  
  // variation de couleurs
  // variation de rouge
  for (int i=0; i<=255; i++) {  // défile les valeurs de 0 à 255
  
  }
  
}

  

