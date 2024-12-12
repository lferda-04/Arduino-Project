#include "config.h"
#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic1(6, 7);
Ultrasonic ultrasonic2(8, 9);
//=================================================


int distance1 = 0;
int distance2 = 0;
//=======================================

int pinMoteur1_reculer = 4;
int pinMoteur1_avancer = 5;
//----------------------------
int pinMoteur2_avancer = 4;
int pinMoteur2_reculer = 3;

int pwm1 = 9;
int pwm2 = 10;
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
  //analogWrite(pwm1, 200);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, HIGH);
  //analogWrite(pwm1, 150);
  //analogWrite(pwm2, 150);


  delay(time);

  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);

}

int tournergauche(int time){
  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, HIGH);
  digitalWrite(pinMoteur2_avancer, HIGH);
  //analogWrite(pwm2, 200);
  digitalWrite(pinMoteur2_reculer, LOW);
  //analogWrite(pwm1, 150);
  //analogWrite(pwm2, 150);

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
  //get distances
  distance1 = ultrasonic1.read(CM);
  distance2 = ultrasonic2.read(CM);

  //conditions
  if(distance1<40){
    avancer(500);
    tournergauche(600);
    avancer(1000);
  }else if(distance2<40){
    avancer(500);
    tournerdroite(600);
    avancer(1000);
  }else{
    avancer(100);
  }
  



}




















