//...inclusion de librairie
#include <Servo.h>  // inclut la librairie Servo

//....entête déclarative = variables et constantes globales
int octetReception=0;  // variable de reception octet
long nombreReception=0;  //déclare variable long stoker nombre recu

const int brocheServo=2;  // broche du servomoteur

Servo servo;  // déclaration d'un objet servomoteur

void setup() {  // la fonction setup(): exécutée au début et en une seule fois

  Serial.begin(115200);  // initialise la vitesse de la connexion série
  // utilise la même vitesse que dans le Terminal Série
  servo.attach(brocheServo);  // attache le servomoteur à la broche

}  // fin de la fonction setup()

void loop() {  // la fonction loop(): exécutée en boucle sans fin

  while (Serial.available()>0) {  // si un caractère en réception
  
    octetReception=Serial.read();  // lit le 1er octet de la file d'attente
    
    if (octetReception==10) {  // si octet recu est le saut de ligne
        Serial.print ("Saut de ligne recu:");
        Serial.print ("Nombre recu=");  // affiche le nombre recu
        Serial.println (nombreReception);
        
        servo.writeMicroseconds(nombreReception);
        Serial.print ("Largeur impulsion servomoteur=");
        Serial.print (nombreReception);
        Serial.println ("microseconds");
        
        nombreReception=0;  // RAZ le String de réception
        delay(10);  // pause
        break;  // sort de la boucle while
    }  // fin de if
    
    else {  // si le caractère recu n'est pas un saut de ligne
    
        octetReception=octetReception-48;  // transforme la valeur ASCII en valeur décimale
        
        // calcul du nombre à partir des valeurs recues
      
        if ((octetReception>=0)&&(octetReception<=9)) nombreReception=(nombreReception*10)+octetReception;
        else Serial.println("La chaine n'est pas un nombre valide!");
        
        delay(1);  // laisse le temps au caractère d'arriver
        
    }  // fin de else
    
  }  // fin de while
 
}  // fin de la fonction loop() 
