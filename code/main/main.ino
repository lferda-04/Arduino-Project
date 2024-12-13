#include "config.h"
#include "Ultrasonic.h"
#include "Servo.h"

Servo servo;


void declencher(){
  #include <Servo.h>

// C++ code
//

Servo servo; //Création de l'objet "servo"

void setup()
{
  servo.attach(10); //Attache le servo au pin spécifié
  pinMode(A1,INPUT);
  Serial.begin(9600); //Ouvre le port série
}

void loop()
{
  int val = analogRead(A1); // Lit la valeur actuelle du potentiomètre
  
  Serial.println(val);
  
  if (val < 512) { servo.write(0);}//appuyé
  if (val > 512) { servo.write(55);}//relaché
  
  delay(100); // Attends 100 ms
}
  

}


void setup(){
  pinMode(pinMoteur1_avancer, OUTPUT);
  pinMode(pinMoteur1_reculer, OUTPUT);
  pinMode(pinMoteur2_avancer, OUTPUT);
  pinMode(pinMoteur2_reculer, OUTPUT);

  servo.attach(11);

  Serial.begin(9600);
}

void loop(){
  
  declencher();
}
