#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int pingPin=A1;
long dur, cm=0;

void setup()
{
  lcd.begin(16,2);
  lcd.print("PING  Sensor");
}

void loop()
{
  cm = readSensor();
  
  lcd.setCursor(0, 0);	
  lcd.print("Jarak ");
  lcd.setCursor(6,1);
  lcd.print(cm);
  print_unit_cm(cm);
}

long readSensor()
{
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW); //beri sinyal awal low
  delayMicroseconds(2);
  digitalWrite (pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  dur = pulseIn(pingPin, HIGH);
  cm=dur/(29*2);
  if(cm>=2 && cm<=330){
    return cm;}
  else{ return 0;}
}

void print_unit_cm(long gas)
{
 int ROW =2;
  int ERR_Digit = 6;
  int digit=7;
  if(gas>=2 && gas<10){
  	lcd.setCursor(7, ROW);
    lcd.print("cm");
    print_blank(digit+2, ROW);
  }else if(gas>=10 && gas<100){
  	lcd.setCursor(digit+1, ROW);
    lcd.print("cm");
    print_blank(digit+3, ROW);
  }else if(gas>=100 && gas<=330){
  lcd.setCursor(digit+2, ROW);
    lcd.print("cm");
    print_blank(digit+4, ROW);
  }else{
    lcd.setCursor(digit-1, ROW);
    print_blank(digit-1, ROW);
  }
}     
void print_blank(int col, int row){
	int totalCol=16;
	for (int i=col; i<totalCol;i++){
	lcd.setCursor(i, row);
	lcd.print(" ");}
}



