#include <FiniteStateMachine.h>
#include "TanimlamalarDegiskenler.h";

State BASLA = State(basla);
State YUKTARA = State(yukTara);
State YUKEYAKLAS = State(yukeYaklas);
State RENKOKU = State(renkoku);
State YUKUAL = State(yukuAl);
State TOPLAMABOLGESIBUL = State(toplamaBolgesiBul)
State YUKUGOTUR = State(yukuGotur);
State ENGELIAS = State(engeliAs);
State YUKUBIRAK = State(yukuBirak);
State BITIR = State(bitir);
FSM Robot = FSM(BASLA);

enum motor_enum {ILERLE, DUR, DON, GERIGIT};
uint8_t motorState = DUR;

void setup(){
  motorPinTanimla();
  makaraPinTanimla();
  ultrasonikPinTanimla();
  miknatisTanimla();
  renkSensorPinTanimla();
 // Serial.begin(9600);
}

void loop(){
  
  // if(ultrasonikState == CALIS)
  //     ultrasonikAltSensorlerOku();
   //ultrasonikSensorOlcum4();
  // ultrasonikDebug();
  //makaraDebug();
  //motorDebug();
  Robot.update();
}
void basla(){
  delay(3000);
  Robot.transitionTo(YUKTARA);
}
void yukTara(){
  if(motorState != DON){
    //bir kere yapılacak islemler
    motorState = DON;
    motorDurdur();
    delay(stateArasiGecisDelay);
  }
  //******************UPDATE*******************************
  motorSagaDon();
  delay(taramaDonmeDelay);
  motorDurdur();


  ultrasonikAltSensorlerOku();
  if(distanceCm2>minYukMesafesi && distanceCm2 <maxYukMesafesi && distanceCm2>0){    //                   //distanceCm+distanceCm2+distanceCm3>3
    delay(taramadanYaklasmaArasiDelay);
    Robot.transitionTo(YUKEYAKLAS);
  }
  else if(distanceCm2>maxYukMesafesi && distanceCm<maxYukMesafesi && distanceCm>0){  //yuk sagda kaldı
    motorSagaDon();
    delay(taramadaYukSagdaMotorDelay);
    motorDurdur();
  }
  else if(distanceCm2>maxYukMesafesi && distanceCm3<maxYukMesafesi && distanceCm3>0){ //yuk solda kaldı
    motorSolaDon();
    delay(taramadaYukSoldaMotorDelay);
    motorDurdur();
  }
  else{
    taramaSayaci++;
    if(taramaSayaci>30)
    {
      Robot.transitionTo(BITIR);
    }
  }
  delay(taramaSensorDelay);
}

void bitir(){
  motorDurdur();
  miknatisDurdur();  
}

void yukeYaklas(){

  if(motorState != YUKEYAKLAS){
    motorState = YUKEYAKLAS;
    motorDurdur();
    delay(stateArasiGecisDelay);
  }

  //******************UPDATE*******************************
  motorIlerle();
  delay(ilerlemeArasiDelay);
  motorDurdur();

  ultrasonikAltSensorlerOku();
  if(distanceCm2<maxMotorDurdurmaMesafesi && distanceCm2>1){
    Robot.transitionTo(RENKOKU);
  }
  else if(distanceCm2>maxYukMesafesi && distanceCm<maxYukMesafesi && distanceCm>0){  //yuk sagda kaldı
    motorSagaDon();
    delay(ilerlemedeYukSagdaMotorDelay);
    motorDurdur();
  }
  else if(distanceCm2>maxYukMesafesi && distanceCm3<maxYukMesafesi && distanceCm3>0){ //yuk solda kaldı
    motorSolaDon();
    delay(ilerlemedeYukSoldaMotorDelay);
    motorDurdur();
  }

}

void renkoku(){
  if(motorState != DUR){
    motorState = DUR;
    motorDurdur();
  }
  delay(stateArasiGecisDelay);
  int color = FindColour();
  if(color == 1){
    kirmiziYukSayisi++;
    Robot.transitionTo(YUKUAL);
  }
  else if(color == 2){
    maviYukSayisi++;
    Robot.transitionTo(YUKUAL);
  }
  else if(color == 3){
    yesilYukSayisi++;
    Robot.transitionTo(YUKUAL);
  }
}

void yukuAl(){
  if(motorState != DUR){
    motorState = DUR;
    motorDurdur();
  }
  //******************UPDATE*******************************
  miknatisCalistir();

  makaraIndir();
  delay(makaraIndirmeDelay);
  makaraDurdur();

  delay(yukAlmaDelay);

  makaraTopla();
  delay(makaraOrtalamaDelay);
  makaraDurdur();

  ultrasonikSensorOlcum4();

  if(distanceCm4>1 && distanceCm4<minYukSensorMesafesi){
    makaraTopla();
    delay(makaraToplamaDelay);
    makaraDurdur();
    Robot.transitionTo(TOPLAMABOLGESIBUL);
  }
  else{
    makaraTopla();
    delay(makaraToplamaDelay);
    makaraDurdur();
  }
}

void toplamaBolgesiBul(){

  if(motorState != DON){
    //bir kere yapılacak islemler
    motorState = DON;
    motorDurdur();
    delay(stateArasiGecisDelay);
  }
  //******************UPDATE*******************************
  motorSagaDon();
  delay(taramaDonmeDelay);
  motorDurdur();

  ultrasonikSensorOlcum4();

  if(distanceCm4>1 && distanceCm4<maxToplamaBolgesiMesafesi){
    Robot.transitionTo(TOPLAMABOLGESIBUL);
  }
}

void yukuGotur(){
  if(motorState != DUR){
    motorState = DUR;
    motorDurdur();
  }
  //******************UPDATE*******************************
  ultrasonikAltSensorlerOku();
  if(distanceCm2<maxEngelMesafesi && distanceCm2>minEngelMesafesi){
    Robot.transitionTo(ENGELIAS);
  }
  else if(distanceCm<maxEngelMesafesi && distanceCm>minEngelMesafesi){
    Robot.transitionTo(ENGELIAS);
  }
  else if(distanceCm3<maxEngelMesafesi && distanceCm3>minEngelMesafesi)
  {
    Robot.transitionTo(ENGELIAS);
  }
  
  ultrasonikSensorOlcum4();
  if(!(distanceCm4<maxToplamaBolgesiMesafesi && distanceCm4>1)){
    Robot.transitionTo(TOPLAMABOLGESIBUL);
  }
  if(distanceCm4<minToplamaBolgesiMesafesi && distanceCm4>1)){
    Robot.transitionTo(YUKUBIRAK);
  }

  motorIlerle();
  delay(ilerlemeArasiDelay);
  motorDurdur();
}

void engeliAs(){
  if(motorState != DON){
    motorState = DON;
    motorDurdur();
  }
  //******************UPDATE*******************************
  ultrasonikAltSensorlerOku();
  int sagdaEngelVar = 0;
  int soldaEngelVar = 0;
  int ortadaEngelVar = 0;
  if(distanceCm2<maxEngelMesafesi && distanceCm2>minEngelMesafesi){
    sagdaEngelVar=1;
  }
  if(distanceCm<maxEngelMesafesi && distanceCm>minEngelMesafesi){
    ortadaEngelVar = 1;
  }
  if(distanceCm3<maxEngelMesafesi && distanceCm3>minEngelMesafesi){
    soldaEngelVar=1
  }

  if(sagdaEngelVar==0 && soldaEngelVar =1){
    //saga dön
    motorSagaDon();
    delay(engeldenDonmeDelay);
    motorDurdur();
  }
  else if(sagdaEngelVar==1 && soldaEngelVar =0){
    //sola dön
    motorSolaDon();
    delay(engeldenDonmeDelay);
    motorDurdur();
  }
  else if(ortadaEngelVar==1 || (sagdaEngelVar + soldaEngelVar == 2)){
    //geri git
    motorGeriGit();
    delay(engeldenGeriGitmeDelay);
    motorDurdur();
    delay(50);
    //saga don
    motorSagaDon();
    delay(engeldenDonmeDelay);
    motorDurdur();
  }
  else if(ortadaEngelVar + sagdaEngelVar + soldaEngelVar == 0){
    Robot.transitionTo(YUKUGOTUR);
  }
}

void yukuBirak(){
  if(motorState != DUR){
    motorState = DUR;
    motorDurdur();
  }
  miknatisDurdur(); 
  delay(50);
  motorGeriGit();
  delay(geriGitDelay);
  delay(50);
  Robot.transitionTo(YUKTARA);
}
void duvarKontrol()
{
  ultrasonikSensorOlcum5();
  if(distanceCm5<minDuvarMesafesi)
  {
    Robot.transitionTo(BITIR);
  }
}








