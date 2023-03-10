const int PIEZO=2;
int LA3=440;


void setup() {
  // put your setup code here, to run once:
  pinMode(PIEZO, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly: 
  tone(PIEZO, LA3);
  delay(1000);
  noTone(PIEZO);
  delay(1000);
  
  
}
