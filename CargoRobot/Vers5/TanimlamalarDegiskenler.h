//************************************STATE PARAMETRELERİ********************************
//STATE
const float stateArasiGecisDelay = 200;
//YUK TARA
const float taramaDonmeDelay = 300;
const float taramaSensorDelay = 20;
const float taramadanYaklasmaArasiDelay = 1000;
const float taramadaYukSagdaMotorDelay = 150;
const float taramadaYukSoldaMotorDelay = 150;
const float minYukMesafesi = 90;
const float maxYukMesafesi = 5;
int taramaSayaci = 0;
//YUKE ILERLE
const float ilerlemeArasiDelay = 300;
const float ilerlemedeYukSagdaMotorDelay = 100;
const float ilerlemedeYukSoldaMotorDelay = 100;
const float maxMotorDurdurmaMesafesi = 5;
const float maxDurmaMesafesi = 7;
//RENKOKU
const int kirmiziYukSayisi = 0;
const int maviYukSayisi = 0;
const int yesilYukSayisi = 0;
//MIKNATIS MAKARA
const float makaraIndirmeDelay = 400; //*******************************************************************************
const float makaraOrtalamaDelay = 1000;
const float makaraOrtadanIndirmeDelay = 200; 
const float makaraToplamaDelay = 1300;
const float yukAlmaDelay = 1000;
const float minYukSensorMesafesi = 6;
//YUKGOTURME
const float maxToplamaBolgesiMesafesi = 70;
const float minToplamaBolgesiMesafesi = 6;
//YUKGOTURURKEN ENGEL
const float minEngelMesafesi = 15;
const float maxEngelMesafesi = 23;
const float engeldenDonmeDelay = 500;
const float engeldenGeriGitmeDelay = 500;
//YUKUBIRAK
const float geriGitDelay = 500;
//DUVAR KONTROL
const float minDuvarMesafesi = 30;
//------------------PINLER & SABITLER--------------------
//led gostergeler
// const int led1 = 27;
// const int led2 = 14;
// const int led3 = 12;
//ultrasonik
const int trigPin = 15;
const int trigPin2 = 27;
const int echoPin  = 36;
const int echoPin2  = 39;
const int echoPin3  = 34;
const int echoPin4  = 5;
const int echoPin5  = 17;
//elektromiknatis
const int makaraIpA  = 14;
const int makaraIpB  = 12;
const int makaraAnalog = 13;
const int elektromiknatisOn = 0;
//renksensor
const int s0 = 23;
const int s1 = 22;
const int s2 = 21;
const int s3 = 19;
const int output = 18;

unsigned long duration;
float distanceCm;

unsigned long duration2;
float distanceCm2;

unsigned long duration3;
float distanceCm3;

unsigned long duration4;
float distanceCm4;

unsigned long duration5;
float distanceCm5;

#define SOUND_SPEED 0.034  //cm


//motorlar
const int tekerlekSagA = 32;
const int tekerlekSagB = 33;

const int tekerlekSolA = 25;
const int tekerlekSolB = 26;

const int tekerlekSagAnalogPin = 4;    //sag
const int tekerlekSolAnalogPin = 16;   // arka
