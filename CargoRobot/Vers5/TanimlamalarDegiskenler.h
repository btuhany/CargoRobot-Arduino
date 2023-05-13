//************************************STATE PARAMETRELERİ********************************
//YUK TARA
float minYukMesafesi = 5;
float maxYukMesafesi = 60;
//YUKE ILERLE
float maxDurmaMesafesi = 7;
//------------------PINLER & SABITLER--------------------
//led gostergeler
const int led1 = 27;
const int led2 = 14;
const int led3 = 12;
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
const int tekerlekSagA = 32;
const int tekerlekSagB = 33;

const int tekerlekSolA = 25;
const int tekerlekSolB = 26;

const int tekerlekSagAnalogPin = 4;    //sag
const int tekerlekSolAnalogPin = 16;   // arka
