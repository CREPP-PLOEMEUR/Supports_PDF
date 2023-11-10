#include <SimpleCDbot.h>
#include <Utils.h>
#include <Servo.h>       

// variables pour réception  chaines sur port série

// int octetReception=0; // variable de reception octet
// char caractereReception=0; // variable de reception caractère

String chaineReception=""; // déclare un objet String vide

// variables et constantes pour les servomoteurs

const int Droit=0;    // servo Droit à l'indice 0
const int Gauche=1;   // servo Gauche à l'indice 1

const int neutre=1420;  // largeur impulsion arrêt
const int maxAV[2]={1220,1620};  // largeur impulsion vitesse max avant
const int maxAR[2]={1620,1220};  // largeur impulsion vitesse max arrière

const int brocheServo[2]={14,15}; // broches des servomoteurs

// pour le GP2D12

const int GP2D12=A2;  // déclaration constante de broche analogique

// déclaration des variables globales

int mesure_brute=0; // variable pour acquisition résultats bruts de conversion analogique numérique
float mesuref=0.0;  // variable pour calcul décimal de conversion analogique numérique

int distance;  // dstance référence

// tableau de valeurs en millivolts pour distance de 5 en 5 cm de 10 à 80 cm pour le capteur GP2D12

// première valeur à l'index 0
int calibrage[]={  // valeurs en mV
2370,  // 10 cm - index 0
1700,  // 15 cm - index 1
1300,  // 20 cm - index 2
1100,  // 25 cm - index 3
950,   // 30 cm - index 4
830,   // 35 cm - index 5
720,   // 40 cm - index 6
650,   // 45 cm - index 7
580,   // 50 cm - index 8
540,   // 55 cm - index 9
500,   // 60 cm - index 10
480,   // 65 cm - index 11
450,   // 70 cm - index 12
430,   // 75 cm - index 13
410,   // 80 cm - index 14
400,   // au delà de 80 cm - index 15
}; // fin du tableau

// int impulsServo=0; // largeur de l'impulsion du servomoteur en µsecondes
Servo servo[2]; // déclaration d'un objet servomoteur

Utils utils;

SimpleCDbot robot(brocheServo[Droit], maxAR[Droit], maxAV[Droit], brocheServo[Gauche], maxAR[Gauche], maxAV[Gauche], neutre);

boolean debug=true;
boolean etatMoteurs=false;    // témoin état moteur
boolean detectOstacle=false;  // témoin état obstacle

// fonction setup(): exécutée au début et en une seule fois
void setup() {
  
  Serial.begin(115200);  // initialise la vitese de la connexion série
                         // utilise la même vitesse dans le Terminal série
  robot.infosAnalyseChaine();  // info sur les chaines reconnues par analyseChaine()
  
} // fin de la fonction setup()

// la fonction loop(): s'exécute en boucle sans fin
void loop() {
  // réception de la chaine sur le port série et analyse de la chaine
  
  chaineReception=utils.waitingString(true);  // appelle la fonction de réception sur le port série
  
  // if (chaineReception!="") analyseChaine(chineReception); // appalle la fonction d'analyse de la chaine de réception
  // if (chaineReception!="") robot.analyseChaine(chaineReception);  // appelle la fonction d'analyse de la chaine de réception
  // la fonction analyse chaine "décode" la chaine et appelle la fonction de la librairie RobotCCx2 voulue si la chaine est valide
  
  if (chaineReception!=""); robot.analyseChaine(chaineReception);  // appelle la fonction d'analyse de la chaine en réception
  
  mesuref=moyenneMesure(30, GP2D12);  // réalise la moyenne de 30 mesure analogiques sur la voie GP2D12
  distance=distanceGP2D12(mesuref);   // renvoie la valeur de la distance correspondante à la valeur tension
  
  //....affichage du résultat
  
  if (distance==0) {  // si la valeur ne correspond pas au calibrage
     if (debug) Serial.println("Distance hors plage de mesure");
       
     if ( (etatMoteurs==false) || (detectObstacle==true) ) {  //allume moteurs
        robot.enAvant(100);
        etatMoteurs=true;
        detectObstacle=false;
     } // fin de if etatMoteurs
     
  } // fin de if distance
  else  {    // si valeur distance calculée
    if (debug) Serial.print("Distance comprise entre"), Serial.print(distance), Serial.print("cm et ");
    if (debug) Serial.print(distance+5), Serial.print(" cm");
    if (distance <20) {
      
      if (etatMoteurs==true) {  // si moteur allumé
      robot.arret(1000);
      robot.enArriere(50, 1000);  // recule 1 seconde
      // etatMoteurs=false; // on laisse à true jusqu'à distance sur 30 suivante
      detectObstacle=true;
      } // fin de if moteurs true
      
    } // fin de if < 30
    else  if (distance >=20) {
      
          if (detectObstacle==true) { // si moteurs allumés = si gestion distance < à 30 toujours en cours
          robot.tourneDroite(50, 1000);
          etatMoteurs=false;
          detectObstacle=false;
          } // fin de if
            
            if (etatMoteur==false); { // allume moteurs
            robot.enAvant(100);
            etatMoteur=true; 
            } // fin de if moteurs false
            
    } //fin de else if distance
    
  } // fin de else
  
  delay(250);  // pause entre 2 mesures
  
} // fin de la fonction loop()



