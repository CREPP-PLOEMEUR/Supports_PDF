const int PIEZO=2;
int millis0=0;

void setup(){
  pinMode (PIEZO, OUTPUT);
  millis0=millis();  //...mémorise millis
  
}

void loop() {
  //... boucle de defilement croissant de la frequence
  for (int frequence=500; frequence<=1000; frequence++) {
    tone(PIEZO, frequence); // genere un son de frequence voulue
    delay(1);  // courte pause
  }
  
  // ...boucle de defilement décroissant de la frequence
  for (int frequence=1000; frequence>=500; frequence--) {
     tone(PIEZO, frequence);
     delay(1);
  }
  
  if (millis()-millis0>10000) {  // après 10 secondes
    noTone(PIEZO);
    while(1);  //... stope loop
  }
    
  }  //... fin de la fonction loop ()
