#include "config.h"
#include "Ultrasonic.h"
#include "Servo.h"

Servo servo;


void declencher(){
  delay(1000);

  servo.write(100);
  

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