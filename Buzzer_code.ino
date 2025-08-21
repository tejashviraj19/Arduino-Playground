//Buzzer Code
// C++ code

int Buzzer_pin=13;

//Initilize
void setup()
{
  pinMode(Buzzer_pin, OUTPUT);//initialize pin 13 as an output
}

void loop()
{
  tone(Buzzer_pin,100);//100Hz
  delay(100); // Wait for 1000 millisecond(s)
  tone(Buzzer_pin, 200); //200Hz
  delay(100); // Wait for 1000 millisecond(s)
  tone(Buzzer_pin,300);//100Hz
  delay(100);
  tone(Buzzer_pin, 400); //200Hz
  delay(100);
  tone(Buzzer_pin,500);//100Hz
  delay(100); // Wait for 1000 millisecond(s)
  tone(Buzzer_pin, 600); //200Hz
  delay(100);
  noTone(Buzzer_pin);//For turning off the Buzzer
  delay(2000);
}
