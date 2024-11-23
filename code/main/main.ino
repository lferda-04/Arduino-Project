#include "config.h"
#include "Ultrasonic.h"




void setup(){
  pinMode(pinMoteur1_avancer, OUTPUT);
  pinMode(pinMoteur1_reculer, OUTPUT);
  pinMode(pinMoteur2_avancer, OUTPUT);
  pinMode(pinMoteur2_reculer, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  slalom();

}