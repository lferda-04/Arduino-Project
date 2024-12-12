#include "config.h"
#include "Ultrasonic.h"
#include "Servo.h"

Servo servo;

int bouton = 13;
int etatBouton = 0;




void declencher(){
etatBouton=digitalRead(bouton); 
  if(etatBouton==HIGH){
    servo.write(90);
    delay(5000);
    servo.write(0);
    delay(1500);
  }
}



void setup(){
  pinMode(pinMoteur1_avancer, OUTPUT);
  pinMode(pinMoteur1_reculer, OUTPUT);
  pinMode(pinMoteur2_avancer, OUTPUT);
  pinMode(pinMoteur2_reculer, OUTPUT);
   
  pinMode(bouton, INPUT);
  servo.attach(10);
  Serial.begin(9600);
}

void loop(){
  
  declencher();
}
