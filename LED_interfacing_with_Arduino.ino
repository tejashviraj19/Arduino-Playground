// C++ code
//LED interfacing with Arduino

int Red=7;
int Yellow=5;
int Green=3;
void setup()
{
  pinMode(o_LEDPin, OUTPUT);
}

void loop()
{
  digitalWrite(o_LEDPin, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(o_LEDPin, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
