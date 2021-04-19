int sensePin= A0;
int sensorInput;
double temp;

void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  sensorInput = analogRead(sensePin);
  temp = (double) sensorInput/1024;
  temp = (double) ((temp*5)-0.5)*100;
  
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.println(" Celcius");  
}