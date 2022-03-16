// déclaration de constante des broches

const int ROUGE_1 = 2;
const int ORANGE_1 = 3;
const int VERT_1 = 4;
const int ROUGE_2 = 5;
const int ORANGE_2 = 6;
const int VERT_2 = 7;

void setup() {
  
  pinMode(ROUGE_1, OUTPUT);
  pinMode(ORANGE_1, OUTPUT);
  pinMode(VERT_1, OUTPUT);
  pinMode(ROUGE_2, OUTPUT);
  pinMode(ORANGE_2, OUTPUT);
  pinMode(VERT_2, OUTPUT);
  
 
  // initialisation des LEDs au début: feu 1 au ROUGE, feu 2 au vert
  
  digitalWrite(ROUGE_1, HIGH);
  digitalWrite(ORANGE_1, LOW);
  digitalWrite(VERT_1, LOW);
  digitalWrite(ROUGE_2, LOW);
  digitalWrite(ORANGE_2, LOW);
  digitalWrite(VERT_2, HIGH);
  
   delay(5000);
   
}
   
void loop() {
   
  //....le feu 2 passe à l'orange
  
  digitalWrite(VERT_2, LOW);
  digitalWrite(ORANGE_2, HIGH);
  
   delay(2000);
   
  //...le feu 2 passe au rouge
  
  digitalWrite(ORANGE_2, LOW);
  digitalWrite(ROUGE_2, HIGH);
  
    delay(1000);
  
  //....le feu 1 passe au vert
  
  digitalWrite(ROUGE_1, LOW);
  digitalWrite(VERT_1, HIGH);
  
    delay(5000);
    
   // ....le feu 1 passe à l'orange
   
   digitalWrite(VERT_1, LOW);
   digitalWrite(ORANGE_1, HIGH);
   
     delay(2000);
     
    //...le feu 1 passe au rouge
    
    digitalWrite(ORANGE_1, LOW);
    digitalWrite(ROUGE_1, HIGH);
    
      delay(1000);
      
     // ...le feu 2 passe au vert
     
     digitalWrite(ROUGE_2, LOW);
     digitalWrite(VERT_2, HIGH);
     
       delay(5000);
       
}
