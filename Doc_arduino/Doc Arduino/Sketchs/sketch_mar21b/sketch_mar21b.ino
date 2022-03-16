const int PIEZO=2;  // constante pour le broche du piezo
int demiPeriode=1000;  // variable de demi période en microsecondes


void setup() {
  // put your setup code here, to run once:
  pinMode(PIEZO, OUTPUT); // met la broche en sortie
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(PIEZO, HIGH);  // allume le Piezo
 delayMicroseconds(demiPeriode);  //pause en microsecondes
 digitalWrite(PIEZO, LOW);    // eteint la Piezo
 delayMicroseconds(demiPeriode); // pause en microsecondee
 
  
}  // fin de la fonction loop()
