#include <FiniteStateMachine.h>
#include "TanimlamalarDegiskenler.h";
// State YUKEYAKLAS = State(yukYaklas);
// State YUKUAL = State(yukAl);
// State YUKUGOTUR = State(yukGotur);
// State YUKUBIRAK = State(yukBirak);
State BASLA = State(basla);
State YUKTARA = State(yukTara);
State BEKLE = State(bekle);
State TILERLE = State(tilerle);
State TDUR = State(tdur);
// State UZAKLAS = State(uzaklas);
FSM Robot = FSM(BASLA);


enum motor_enum {ILERLE, DUR, DON, GERIGIT};
enum ultrasonik_enum{BEKLET,CALIS};
uint8_t motorState = DUR;
uint8_t ultrasonikState = CALIS;


void setup() {
  pinMode(23,OUTPUT);
  motorPinTanimla();
  ultrasonikPinTanimla();
  Serial.begin(9600);
}

void loop() {
  
  // if(ultrasonikState == CALIS)
  //   ultrasonikSensorOku();
  

 
      

  Robot.update();
}
void basla()
{
  delay(3000);
  Robot.transitionTo(YUKTARA);
}
void yukTara()
{
  if(motorState != YUKTARA)
  {
    motorState = YUKTARA;
    motorDurdur();
    motorSagaDon();
  }

  ultrasonikSensorOku();
  if(distanceCm>minYukMesafesi && distanceCm <maxYukMesafesi && distanceCm>0)   //distanceCm+distanceCm2+distanceCm3>3
  {
    digitalWrite(23,HIGH);
    Robot.transitionTo(TILERLE);
  }
  else
  {
    digitalWrite(23,LOW);
  }

}

void bekle()
{
  if(distanceCm>10 && distanceCm <90 &&distanceCm+distanceCm2+distanceCm3>1)
  {
    digitalWrite(23,HIGH);
    Robot.transitionTo(TILERLE);
  }
  else
  {
    digitalWrite(23,LOW);
  }
  
}
void tilerle()
{
  if(motorState != ILERLE)
  {
    motorState = ILERLE;
    motorDurdur();
    motorIlerle();
  }
  // if(distanceCm2<20)
  // {
    
  //   Robot.transitionTo(TDUR);
  // }
  if(distanceCm2 <10 || distanceCm3 <10 && distanceCm+distanceCm2+distanceCm3>1)
  {
      digitalWrite(23,LOW);
      Robot.transitionTo(TDON);
  }
  else if(distanceCm<10)
  {
     Robot.transitionTo(BEKLE);
  }
}
void tdur()
{
  if(motorState != DUR)
  {
    motorState = DUR;
    motorDurdur();
  }
  //         if(distanceCm2<60 && distanceCm2 >15 && distanceCm2 != 0)
  //         {
  //           digitalWrite(23,HIGH);
  //           Robot.transitionTo(TILERLE);
  //         }
  
}









