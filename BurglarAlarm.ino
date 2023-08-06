const int VIBRATION_SENSOR = 36;
const int BUZZER_PIN = 32;
const int BUZZER_FREQUENCY = 3300;
const int BUZZER_INTERVAL = 250;
const int BUZZER_INTERVAL_THIEF = 100;
int buzzerCycle = 1000000/(2*BUZZER_FREQUENCY);
bool detected = false;
int pre_detect_time = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUZZER_PIN,OUTPUT);
}

void Warning() 
{
  pre_detect_time = millis();
  for(int j=0;j<3;j++) 
  {
    for(int i=0;i<1000;i++) 
    {
      digitalWrite(BUZZER_PIN,HIGH);
      delayMicroseconds(buzzerCycle);
      digitalWrite(BUZZER_PIN,LOW);
      delayMicroseconds(buzzerCycle);
    }
    delay(BUZZER_INTERVAL);
  }
  detected = false;
}

void BurglarAlarm() 
{
  pre_detect_time = millis();
  for(int j=0;j<30;j++) 
  {
    for(int i=0;i<500;i++) 
    {
      digitalWrite(BUZZER_PIN,HIGH);
      delayMicroseconds(buzzerCycle);
      digitalWrite(BUZZER_PIN,LOW);
      delayMicroseconds(buzzerCycle);
    }
    delay(BUZZER_INTERVAL_THIEF);
  }  
}
void loop() {
  int vibration_value = analogRead(VIBRATION_SENSOR);
  Serial.println(vibration_value);
  // Warning();
  // BurglarAlarm();
  if(vibration_value > 30) 
  {
    int present_time = millis();
    detected = true;
    if (present_time - pre_detect_time < 10000) 
    {
      BurglarAlarm();
    }
    else 
    {
      Warning();
    }
  }
  delay(100);
  // put your main code here, to run repeatedly:

}
