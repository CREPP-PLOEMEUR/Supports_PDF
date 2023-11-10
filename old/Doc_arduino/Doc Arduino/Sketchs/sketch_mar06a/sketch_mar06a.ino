const int LED[1] = {2};
int vitesse=1000;

void setup() {
  pinMode(LED[1], OUTPUT);
  
}

void loop() {
  digitalWrite(LED[1], HIGH);
  delay(vitesse);
  digitalWrite(LED[1], LOW);
  delay(vitesse);

}
