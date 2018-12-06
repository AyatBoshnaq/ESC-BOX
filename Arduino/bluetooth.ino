
#define ledPin 13  // //pin 13 built-in LED light
String val;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
   if(Serial.available()) //
  {
    val = Serial.readString();
    char* it = &val[0];
    while(*it != '\0') {
      if(*it >= 'a' && *it <= 'z') {
        *it = *it - 'a' + 'A';
      }
      it++;
    }
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    Serial.print(val);  //print on Serial debugging assistant on computer
     
  }
   
}
