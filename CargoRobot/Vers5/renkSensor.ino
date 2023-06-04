void renkSensorPinTanimla(){
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(output, INPUT);

  //ESP32-Arduino için freq degeri ayarlama
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
}
void RenkSensorDebug()
{
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  red = pulseIn(output,LOW);
  Serial.print("Red: ");
  Serial.print(red);
  delay(50);

  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  green = pulseIn(output,LOW);
  Serial.print(", Yesil: ");
  Serial.print(green);
  delay(50);

  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  blue = pulseIn(output,LOW);
  Serial.print(", Mavi: ");
  Serial.println(blue);
  delay(50);
}


void Kalibrasyon(){
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  red = pulseIn(output,LOW);
  red = map(red, 74, 2200, 0, 100);
  delay(50);

  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  green = pulseIn(output,LOW);
  green = map(green, 79, 2400, 0, 100);
  delay(50);

  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  blue = pulseIn(output,LOW);
  blue = map(blue, 60, 2000, 0, 100);
  delay(50);
}

int FindColour(){
  Kalibrasyon();
  if(red<=12)
  {
    colour=1;
  }
  else if(green<=12)
  {
    colour=3;
  }  
  else if(blue<=12)
  {
    colour=2;
  }
  else
  {
    colour=0;
  }
  return colour;
}