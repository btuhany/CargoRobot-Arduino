void ultrasonikPinTanimla()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
}
void ultrasonikSensorOku()
{
    delay(50);
    ultrasonikSensorOlcum1();
    delay(50);
    ultrasonikSensorOlcum2();
    delay(50);
    ultrasonikSensorOlcum3();
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