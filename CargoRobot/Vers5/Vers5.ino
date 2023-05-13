#include <FiniteStateMachine.h>
#include "TanimlamalarDegiskenler.h";
State YUKEYAKLAS = State(yukeYaklas);
// State YUKUAL = State(yukAl);
// State YUKUGOTUR = State(yukGotur);
// State YUKUBIRAK = State(yukBirak);
State BASLA = State(basla);
State YUKTARA = State(yukTara);
State BEKLE = State(bekle);

State TDUR = State(tdur);
// State UZAKLAS = State(uzaklas);
FSM Robot = FSM(BASLA);


enum motor_enum {ILERLE, DUR, DON, GERIGIT};
enum ultrasonik_enum{BEKLET,CALIS};
uint8_t motorState = DUR;
uint8_t ultrasonikState = CALIS;


void setup() {
  ledGostergeTanimla();
  motorPinTanimla();
  ultrasonikPinTanimla();
  Serial.begin(9600);
}

void loop() {
  
  // if(ultrasonikState == CALIS)
  //   ultrasonikSensorOku();
  
    ledDebug();  

  //Robot.update();
}
void basla()
{
  delay(3000);
  Robot.transitionTo(YUKTARA);
}
void yukTara()
{
  //bir kere yapılacak islemler
  if(motorState != DON)
  {
    motorState = DON;
    motorDurdur();
    motorSagaDon();
  }
  //update
  ultrasonikSensorOku();
  if(distanceCm>minYukMesafesi && distanceCm <maxYukMesafesi && distanceCm>0)   //distanceCm+distanceCm2+distanceCm3>3
  {
    //ledYak(0);
    motorDurdur();
    delay(1200);
    Robot.transitionTo(YUKEYAKLAS);
  }
  else
  {
    //ledSondur(0);
  }

}

void bekle()
{
  // if(distanceCm>10 && distanceCm <90 &&distanceCm+distanceCm2+distanceCm3>1)
  // {
  //   digitalWrite(23,HIGH);

  //   //Robot.transitionTo(TILERLE);
  // }
  // else
  // {
  //   digitalWrite(23,LOW);
  // }
  
}
void yukeYaklas(){

  //if(motorState != YUKEYAKLAS)
  // {
  //   motorState = YUKEYAKLAS;
  //   motorDurdur();
  //   motorIlerle();
  // }
  ultrasonikSensorOku();
  if(distanceCm2<20)
  {
    Robot.transitionTo(TDUR);
  }
  if((distanceCm2 <10 || distanceCm3 <10 )&& distanceCm2+distanceCm3>1)
  {
    motorDurdur();
    motorGeriGit();
    delay(2000);
    Robot.transitionTo(YUKTARA);
  }
}
// {
//  
//   //update


//   else if(distanceCm < maxDurmaMesafesi)
//   {
//      //renk sensoru calistir
//   }
// }
void tdur()
{
  if(motorState != DUR)
  {
    motorState = DUR;
    motorDurdur();
  }
  delay(5000);
    Robot.transitionTo(YUKTARA);
  //         if(distanceCm2<60 && distanceCm2 >15 && distanceCm2 != 0)
  //         {
  //           digitalWrite(23,HIGH);
  //           Robot.transitionTo(TILERLE);
  //         }
  
}









