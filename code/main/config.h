#ifndef CONFIG_H
#define CONFIG_H



extern int distance1;
extern int distance2;
//=======================================

extern int pinMoteur1_avancer;
extern int pinMoteur1_reculer;
//----------------------------
extern int pinMoteur2_avancer;
extern int pinMoteur2_reculer;
//========================================
extern bool ulrason1_detecte;
extern bool ultrason2_detecte;


//========================================
extern int avancer();
extern int tournergauche();
extern int tournerdroite();
extern void slalom();
extern void eviter();
extern void testultrason();
extern void testmouvement();


extern void slalom2();










#endif