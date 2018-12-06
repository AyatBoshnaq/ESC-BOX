//Henry's Bench
//KY-031 Knock Sensor Tutorial

#define ledPin 13  // //pin 13 built-in LED light
int knockPin = 10; // Use Pin 10 as our Input
int knockVal = HIGH; // This is where we record our shock measurement
boolean bAlarm = false;

unsigned long lastKnockTime; // Record the time that we measured a shock


int knockAlarmTime = 500; // Number of milli seconds to keep the knock alarm high


void setup ()
{
  Serial.begin(9600);  
  pinMode (knockPin, INPUT) ; // input from the KY-031
}
void loop ()
{
  knockVal = digitalRead (knockPin) ; // read KY-031 Value
  
  if (knockVal == LOW) // If we see a knock
  {
  
    lastKnockTime = millis(); // record the time of the shock
    // The following is so you don't scroll on the output screen
    if (!bAlarm){
    digitalWrite(ledPin, HIGH);
    delay(500);
      bAlarm = true;
    }
  }
  else
  {
    if( (millis()-lastKnockTime) > knockAlarmTime  &&  bAlarm){
      Serial.println("no knocks");
    digitalWrite(ledPin, LOW);
    delay(500);
      bAlarm = false;
    }
  }
}
