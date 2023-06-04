void ultrasonikPinTanimla()
{
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin4, INPUT);
  pinMode(echoPin5, INPUT);
}
void ultrasonikAltSensorlerOku()
{
    delay(50);
    ultrasonikSensorOlcum1();
    delay(50);
    ultrasonikSensorOlcum2();
    delay(50);
    ultrasonikSensorOlcum3();
    // delay(50);
    // ultrasonikSensorOlcum4();
    // delay(100);
    // ultrasonikSensorOlcum5();
}
void ultrasonikSensorOlcum1()
{
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH,30000ul);
      distanceCm = duration * SOUND_SPEED/2;   
}
void ultrasonikSensorOlcum2()
{
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration2 = pulseIn(echoPin2, HIGH,30000ul);
      distanceCm2 = duration2 * SOUND_SPEED/2;   
}
void ultrasonikSensorOlcum3()
{
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration3 = pulseIn(echoPin3, HIGH,30000ul);
      distanceCm3 = duration3 * SOUND_SPEED/2;  
}
void ultrasonikSensorOlcum4()
{
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      duration4 = pulseIn(echoPin4, HIGH,30000ul);
      distanceCm4 = duration4 * SOUND_SPEED/2;  
}
void ultrasonikSensorOlcum5()
{
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      duration5 = pulseIn(echoPin5, HIGH,30000ul);
      distanceCm5 = duration5 * SOUND_SPEED/2;  
}
void ultrasonikDebug()
{
  Serial.print("Birinci sensor: ");
  Serial.println(distanceCm);
  Serial.print("İkinci sensor: ");
  Serial.println(distanceCm2);
  Serial.print("Ucuncu sensor: ");
  Serial.println(distanceCm3);
  Serial.print("Dorduncu sensor: ");
  Serial.println(distanceCm4);
  Serial.print("Besinci sensor: ");
  Serial.println(distanceCm5);
}