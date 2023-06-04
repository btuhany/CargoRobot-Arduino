void makaraPinTanimla()
{
  pinMode(makaraIpA, OUTPUT);
  pinMode(makaraIpB, OUTPUT);
  pinMode(makaraAnalog, OUTPUT);
}
void miknatisTanimla()
{
  pinMode(elektromiknatisOn, OUTPUT);
  digitalWrite(elektromiknatisOn, LOW);
}
void makaraDebug()
{
  analogWrite(makaraAnalog, 127);

  digitalWrite(makaraIpA,LOW);
  digitalWrite(makaraIpB,HIGH);
  delay(700);
  digitalWrite(makaraIpA,LOW);
  digitalWrite(makaraIpB,LOW);
  delay(2000);
  digitalWrite(makaraIpA,HIGH);
  digitalWrite(makaraIpB,LOW);
  delay(2500);
}
void makaraIndir()
{

}
void makarayiTopla()
{

}
void makaraDurdur()
{
  digitalWrite(makaraIpA,LOW);
  digitalWrite(makaraIpB,LOW);
}
void miknatisCalistir()
{
  digitalWrite(elektromiknatisOn, HIGH);
}
void miknatisDurdur()
{
  digitalWrite(elektromiknatisOn, LOW);
}
void elektromiknatisDebug()
{
  digitalWrite(elektromiknatisOn, HIGH);
  delay(3000);
  digitalWrite(elektromiknatisOn, LOW);
  delay(500);
}