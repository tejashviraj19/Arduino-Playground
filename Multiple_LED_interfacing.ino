//For Multiple LEDs

int timer=200;

void setup()
{
//loop for lowest pin to highest pin,,Ascending order
  for(int thisPin=3; thisPin<8; thisPin++){
    pinMode(thisPin,OUTPUT);
  }
  
}
void loop(){
  for(int thisPin=3; thisPin<8; thisPin++){
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin,LOW);
  }
}
//Descending Order
 for(int thisPin=8; thisPin>=3; thisPin--){
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin,LOW);
  }
}
