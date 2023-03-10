void setup() {

Serial.begin(115200); //initialise la communication série

}

void loop() {
  
  Serial.println("Hello World!"); //affiche le message
  
  delay(1000); //pause de 1 seconde
  
}
