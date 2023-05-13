
void motorPinTanimla()
{
  pinMode(tekerlekSagA, OUTPUT);
  pinMode(tekerlekSagB, OUTPUT);

  pinMode(tekerlekSolA, OUTPUT);
  pinMode(tekerlekSolB, OUTPUT);

  pinMode(tekerlekSolAnalogPin, OUTPUT);
  pinMode(tekerlekSagAnalogPin, OUTPUT);
}
void motorDurdur()
{
  digitalWrite(tekerlekSagA, LOW);
  digitalWrite(tekerlekSagB, LOW);

  digitalWrite(tekerlekSolA, LOW);
  digitalWrite(tekerlekSolB, LOW);
}
void motorIlerle()
{
  analogWrite(tekerlekSolAnalogPin, 180);
   analogWrite(tekerlekSagAnalogPin, 180);

  digitalWrite(tekerlekSagA,HIGH);   //saat yonu
  digitalWrite(tekerlekSagB,LOW);

  digitalWrite(tekerlekSolB,HIGH);  // saat yonu tersi
  digitalWrite(tekerlekSolA, LOW);

}
void motorGeriGit()
{
  analogWrite(tekerlekSolAnalogPin, 255);
  analogWrite(tekerlekSagAnalogPin, 255);

  digitalWrite(tekerlekSagA,LOW);
  digitalWrite(tekerlekSagB,HIGH);

  digitalWrite(tekerlekSolB,LOW);
  digitalWrite(tekerlekSolA, HIGH);

}
void motorSolaDon()
{
  analogWrite(tekerlekSolAnalogPin, 230);
  analogWrite(tekerlekSagAnalogPin, 230);

  digitalWrite(tekerlekSagA,HIGH);
  digitalWrite(tekerlekSagB,LOW);

  digitalWrite(tekerlekSolB,LOW);
  digitalWrite(tekerlekSolA, HIGH);
}
void motorSagaDon()
{
  analogWrite(tekerlekSolAnalogPin, 230);
  analogWrite(tekerlekSagAnalogPin, 230);

  digitalWrite(tekerlekSagA,LOW);
  digitalWrite(tekerlekSagB,HIGH);

  digitalWrite(tekerlekSolB,HIGH);
  digitalWrite(tekerlekSolA, LOW);
}
void motorDebug()
{
  delay(1500);
  motorDurdur();
  motorIlerle();
  delay(2000);
  motorDurdur();
  motorSagaDon();
  delay(2000);
  motorDurdur();
  motorSolaDon();
  delay(2000);
  motorDurdur();
  motorGeriGit();
  delay(2000);
}