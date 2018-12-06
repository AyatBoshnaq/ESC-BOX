
const int sensorPin=A0;
const int ledPin= 13;
const int threshold= 5;

void setup()
{
pinMode(ledPin, OUTPUT);
}

void loop()
{
int val= analogRead(sensorPin);
//digitalWrite(ledPin, HIGH);
if (val >= threshold)
{
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
}
else 
  digitalWrite(ledPin, LOW);
} 
