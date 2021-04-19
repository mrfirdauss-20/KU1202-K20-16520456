const int pingPin=7; //pin yang digunakan sebagai input
  
void setup()
{
  Serial.begin(9600); //starting serial port
}

void loop()
{
  long duration, cm; //stating variabel
  
  pinMode(pingPin, OUTPUT); //set pin as output
  digitalWrite(pingPin, LOW); //beri sinyal awal low
  delayMicroseconds(2);
  digitalWrite (pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds/(29*2);
}

