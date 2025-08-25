// C++ code
//Slide_Switch_LEDs

int LED1=13;
int LED2=12;
int SW1=2;
int SW2=3;

void setup()
{
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  SW1=digitalRead(2);
  if(SW1){
    digitalWrite(LED1,HIGH);
    delay(1000); //Delay of 1sec to let LED blink for 1 sec
  }else{
    digitalWrite(LED1,LOW);
    delay(1000); //Delay of 1 sec to let Led off for 1 sec
  }  
  SW2=digitalRead(3);
  if(SW2){
    digitalWrite(LED2,HIGH);
    delay(1000);
  }else{
    digitalWrite(LED2,LOW);
    delay(1000);
  }  
}
