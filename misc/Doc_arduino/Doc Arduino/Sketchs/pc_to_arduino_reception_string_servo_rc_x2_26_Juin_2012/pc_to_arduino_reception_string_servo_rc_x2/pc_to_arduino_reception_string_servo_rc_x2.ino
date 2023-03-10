
//--- Programme pour le controle de 2 servomoteurs à rotation continue
// par le Terminal Serie
// par X. HINAULT - Tous droits réservés - licence GPL v3 - www.mon-club-elec.fr

//--- entete déclarative = variables et constantes globales 

//---- inclusion de librairie
#include <Servo.h> // inclut la librairie Servo

//--- variables pour réception chaine sur port Série
int octetReception=0; // variable de réception octet
char caractereReception=0; // variable de réception caractère
String chaineReception=""; // déclare un objet String vide

//--- variables et constantes pour les servomoteurs
const int Droit=0; // servo Droit a l'indice 0
const int Gauche=1; // servo Droit a l'indice 1

const int neutre=1480; // largeur impulsion arret 
const int maxAV[2]={1730,1230}; // largeur impulsion vitesse max en avant
const int maxAR[2]={1230,1730}; // largeur impulsion vitesse max en arriere

const int brocheServo[2]={2,3}; // broches des servomoteur 

//int impulsServo=0; // largeur impulsion servomteur en µsecondes

Servo servo[2]; // déclaration d'un objet servomoteur



//--- la fonction setup() : exécutée au début et 1 seule fois
void setup() {

   Serial.begin(115200); // initialise la vitesse de la connexion série
   //-- utilise la meme vitesse dans le Terminal Série
  
   Serial.println("--- Instructions reconnues: ---"); 
   Serial.println("stop");  
   Serial.println("avantD");  
   Serial.println("avantG");  
   Serial.println("arriereD");  
   Serial.println("arriereD");  
   Serial.println("enAvant");  
   Serial.println("enArriere");  
   Serial.println("tourneD");  
   Serial.println("tourneG");  
   Serial.println("-------------------------------");  

  
} // fin de la fonction setup()


//--- la fonction loop() : exécutée en boucle sans fin 
void loop() {

  while (Serial.available()>0) { // si un caractère en réception
    
    octetReception=Serial.read(); // lit le 1er octet de la file d'attente    

    if (octetReception==10) { // si Octet reçu est le saut de ligne 
          Serial.print ("Saut de ligne recu : "); 
          Serial.println ("Chaine recue = "+chaineReception); // affiche la chaine recue
          
          //--- effectue action si la chaine attendue est reçue 
          if (chaineReception=="avantD") servoAvant(Droit, 100);

          if (chaineReception=="avantG") servoAvant(Gauche, 100);

          if (chaineReception=="arriereD") servoArriere(Droit, 100);

          if (chaineReception=="arriereG") servoArriere(Gauche, 100);

          if (chaineReception=="enAvant")  enAvant(100);                        
       
           if (chaineReception=="enArriere") enArriere(100);                        
          
          if (chaineReception=="tourneD") tourneDroite(100);              
                 
          if (chaineReception=="tourneG") tourneGauche(100);              
          
          if (chaineReception=="stop") servosStop(); 
   
          chaineReception=""; //RAZ le String de réception
          delay(100); // pause
          break; // sort de la boucle while
    } // fin if 
    
    else { // si le caractère reçu n'est pas un saut de ligne        
      caractereReception=char(octetReception); // récupere le caractere à partir du code Ascii
      chaineReception=chaineReception+caractereReception; // ajoute la caractère au String 
      delay(1); // laisse le temps au caractères d'arriver
    } // fin else 

    
  } // fin while - fin de réception de la chaine

  
} // fin de la fonction loop()


//-------- fonctions des mouvements de base des servomoteurs ------

//----- fonction de controle de la vitesse avant d'un servomoteur
void servoAvant(int indiceServo, int vitesseIn) {
// -- vitesse entre 10 et 100% --  
 
     int impulsServo; // variable locale 
     
     servo[indiceServo].attach(brocheServo[indiceServo]); // attache le servomoteur à la broche
     
     impulsServo=map(vitesseIn, 0, 100, neutre, maxAV[indiceServo]); // calcul largeur impulsion AV correspondante
     servo[indiceServo].writeMicroseconds(impulsServo); 
     delay(10); // pause 

  
} // fin servoAvant 


//----- fonction de controle de la vitesse arriere d'un servomoteur
void servoArriere(int indiceServo, int vitesseIn) {
// -- vitesse entre 10 et 100% --  
 
     int impulsServo; // variable locale 
     
     servo[indiceServo].attach(brocheServo[indiceServo]); // attache le servomoteur à la broche
     
     impulsServo=map(vitesseIn, 0, 100, neutre, maxAR[indiceServo]); // calcul largeur impulsion AV correspondante
     servo[indiceServo].writeMicroseconds(impulsServo); 
     delay(10); // pause 

  
} // fin servoArriere

//--- fonctions de mouvements synchrones des 2 moteurs 

void enAvant(int vitesseIn) { // met les 2 moteurs en avant
// vitesse entre 10 et 100%
  
  servoAvant(Droit, vitesseIn); // moteur Droit
  servoAvant(Gauche, vitesseIn); // moteur Gauche
  
} // fin en avant 

void enArriere(int vitesseIn) { // met les 2 moteurs en arriere
// vitesse entre 10 et 100%
  
  servoArriere(Droit, vitesseIn); // moteur Droit
  servoArriere(Gauche, vitesseIn); // moteur Gauche
  
} // fin en arriere

void tourneDroite(int vitesseIn) { // tourne à droite
// vitesse entre 10 et 100%
  
  servoArriere(Droit, vitesseIn); // moteur Droit
  servoAvant(Gauche, vitesseIn); // moteur Gauche
  
} // fin en tourne droite

void tourneGauche(int vitesseIn) { // tourne à gauche
// vitesse entre 10 et 100%
  
  servoAvant(Droit, vitesseIn); // moteur Droit
  servoArriere(Gauche, vitesseIn); // moteur Gauche
  
} // fin tourne gauche

void servosStop() { // arret des 2 moteurs 
   servo[Droit].detach(); // met le servomoteur à l'arret
   servo[Gauche].detach(); // met le servomoteur à l'arret 
}



// NB : les lignes précédées de // sont des commentaires
