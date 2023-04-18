//************************************STATE PARAMETRELERİ********************************
//YUK TARA
float minYukMesafesi = 5;
float maxYukMesafesi = 60;
//------------------PINLER & SABITLER--------------------
//ultrasonik
const int trigPin = 15;
const int echoPin  = 36;
const int echoPin2  = 39;
const int echoPin3  = 34;

unsigned long duration;
float distanceCm;

unsigned long duration2;
float distanceCm2;

unsigned long duration3;
float distanceCm3;

#define SOUND_SPEED 0.034  //cm


//motorlar
const int tekerlekBirA = 13;
const int tekerlekBirB = 12;
const int tekerlekIkiA = 14;
const int tekerlekIkiB = 27;
const int tekerlekUcA = 26;
const int tekerlekUcB = 25;
const int tekerlekDortA = 33;
const int tekerlekDortB = 32;
const int tekerlekAnalogPin1 = 4;    //sag
const int tekerlekAnalogPin2 = 16;   // arka
const int tekerlekAnalogPin3 = 2;  // sol
const int tekerlekAnalogPin4 = 0;  