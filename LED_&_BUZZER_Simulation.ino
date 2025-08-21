// C++ code for LED & BUZZER Simulation
int Buzzer=7;
int Led1=10;
int Led2=9;
int Led3=8;

//Initilize
void setup()
{
  pinMode(Buzzer, OUTPUT);//initialize pin 7 as an output
  pinMode(Led1,OUTPUT);//initialize pin 10 as an output
  pinMode(Led2,OUTPUT);//initialize pin 9 as an output
  pinMode(Led3,OUTPUT);//initialize pin 8 as an output
}

void loop()
{
  //Red LED
  digitalWrite(Led1,HIGH);
  if(digitalRead(Led1)==HIGH){
    tone(Buzzer,100); //100Hz
  }
  delay(1000);//1 Sec
  digitalWrite(Led1,LOW);
  
    //Yellow LED
  digitalWrite(Led2,HIGH);
  if(digitalRead(Led2)==HIGH){
    tone(Buzzer,200); //200Hz
  }
  delay(1000);//1 Sec
  digitalWrite(Led2,LOW);
  
    //Green LED
  digitalWrite(Led3,HIGH);
  if(digitalRead(Led3)==HIGH){
    tone(Buzzer,300); //300Hz
  }
  delay(1000);//1 Sec
  digitalWrite(Led3,LOW);
}
