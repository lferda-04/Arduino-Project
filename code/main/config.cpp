#include "config.h"
#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic1(8, 9);
Ultrasonic ultrasonic2(10, 11);

int distance1 = 0;
int distance2 = 0;
//=======================================

int pinMoteur1_reculer = 6;
int pinMoteur1_avancer = 5;
//----------------------------
int pinMoteur2_avancer = 4;
int pinMoteur2_reculer = 3;
//=======================================

/*bool ultrason1_detecte = false;
bool ultrason2_detecte = false;*/
bool obstacle_passed = false;

int avancer(int time){

  digitalWrite(pinMoteur1_avancer, HIGH);
  digitalWrite(pinMoteur2_avancer, HIGH);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

  delay(time);

  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

}

int tournerdroite(int time){

  digitalWrite(pinMoteur1_avancer, HIGH);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

  delay(time);

  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

}

int tournergauche(int time){
  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, HIGH);
  digitalWrite(pinMoteur2_reculer, LOW);

  delay(time);

  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

}

void eviter(){
    tournergauche(1000);
    avancer(500);
    tournerdroite(1000);
    avancer(500);
    tournerdroite(1000);
    avancer(600);
    tournergauche(1100);
}

void slalom(){
  //======= Get distance from ultrason1
  distance1 = ultrasonic1.read(CM);
  Serial.println(distance1);
  Serial.println("===================");

  /*if(distance1<=40){
    ultrason1_detecte = true;
  }else{
    ultrason1_detecte = false;
  }*/

  //------------------------------------------------------
  distance2 = ultrasonic2.read(CM);
  Serial.println(distance2);
  Serial.println("===================");

 /* if(distance2<=40){
    ultrason2_detecte = true;
  }else{
    ultrason2_detecte = false;
  }*/
  //------------------------------------------------------

  //======================================================

  if(distance1<=40 || distance2<=40){
    eviter();
  }else{
    avancer(50);
  }

}
void testultrason(){
  distance1 = ultrasonic1.read(CM);
  distance2 = ultrasonic2.read(CM);
  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println("======================");

  delay(500);
  
}

void testmouvement(){

}


















