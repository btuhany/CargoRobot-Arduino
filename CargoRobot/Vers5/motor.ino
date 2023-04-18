
void motorPinTanimla()
{
  pinMode(tekerlekBirA, OUTPUT);
  pinMode(tekerlekBirB, OUTPUT);

  pinMode(tekerlekIkiA, OUTPUT);
  pinMode(tekerlekIkiB, OUTPUT);

  pinMode(tekerlekUcA, OUTPUT);
  pinMode(tekerlekUcB, OUTPUT);

  pinMode(tekerlekDortA, OUTPUT);
  pinMode(tekerlekDortB, OUTPUT);

  pinMode(tekerlekAnalogPin1, OUTPUT);
  pinMode(tekerlekAnalogPin2, OUTPUT);
  pinMode(tekerlekAnalogPin3, OUTPUT);
  pinMode(tekerlekAnalogPin4, OUTPUT);
}
void motorDurdur()
{
  digitalWrite(tekerlekBirA, LOW);
  digitalWrite(tekerlekBirB, LOW);
   digitalWrite(tekerlekIkiA, LOW);
   digitalWrite(tekerlekIkiB, LOW);
   digitalWrite(tekerlekUcA, LOW);
   digitalWrite(tekerlekUcB, LOW);
  digitalWrite(tekerlekDortA, LOW);
  digitalWrite(tekerlekDortB, LOW);
}
void motorIlerle()
{
  analogWrite(tekerlekAnalogPin1, 180);
  //analogWrite(tekerlekAnalogPin2, 255);
   analogWrite(tekerlekAnalogPin3, 180);
  //analogWrite(tekerlekAnalogPin4, 255);

  digitalWrite(tekerlekBirA,HIGH);   //saat yonu
  digitalWrite(tekerlekBirB,LOW);
  // digitalWrite(tekerlekIkiA,HIGH);
  // digitalWrite(tekerlekIkiB, LOW);
  digitalWrite(tekerlekUcB,HIGH);  // saat yonu tersi
  digitalWrite(tekerlekUcA, LOW);
  // digitalWrite(tekerlekDortB,HIGH);
  // digitalWrite(tekerlekDortA, LOW);
}
void motorGeriGit()
{
  analogWrite(tekerlekAnalogPin1, 255);
  //analogWrite(tekerlekAnalogPin2, 255);
   analogWrite(tekerlekAnalogPin3, 255);
  //analogWrite(tekerlekAnalogPin4, 255);

  digitalWrite(tekerlekBirA,LOW);
  digitalWrite(tekerlekBirB,HIGH);
  // digitalWrite(tekerlekIkiA,HIGH);
  // digitalWrite(tekerlekIkiB, LOW);
  digitalWrite(tekerlekUcB,LOW);
  digitalWrite(tekerlekUcA, HIGH);
  // digitalWrite(tekerlekDortB,HIGH);
  // digitalWrite(tekerlekDortA, LOW);
}
void motorSolaDon()
{
  analogWrite(tekerlekAnalogPin1, 230);
  // analogWrite(tekerlekAnalogPin2, 230 );
  // analogWrite(tekerlekAnalogPin3, 230);
  analogWrite(tekerlekAnalogPin4, 230);

  digitalWrite(tekerlekBirA,HIGH);
  digitalWrite(tekerlekBirB,LOW);
  // digitalWrite(tekerlekIkiB,HIGH);
  // digitalWrite(tekerlekIkiA,LOW);
  digitalWrite(tekerlekUcB,LOW);
  digitalWrite(tekerlekUcA, HIGH);
  // digitalWrite(tekerlekDortB,HIGH);
  // digitalWrite(tekerlekDortA, LOW);
}
void motorSagaDon()
{
  analogWrite(tekerlekAnalogPin1, 230);
  // analogWrite(tekerlekAnalogPin2, 230 );
  // analogWrite(tekerlekAnalogPin3, 230);
  analogWrite(tekerlekAnalogPin4, 230);

  digitalWrite(tekerlekBirA,LOW);
  digitalWrite(tekerlekBirB,HIGH);
  // digitalWrite(tekerlekIkiB,HIGH);
  // digitalWrite(tekerlekIkiA,LOW);
  digitalWrite(tekerlekUcB,HIGH);
  digitalWrite(tekerlekUcA, LOW);
  // digitalWrite(tekerlekDortB,HIGH);
  // digitalWrite(tekerlekDortA, LOW);
}