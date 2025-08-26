// Serial communication..Connecting two Arduinos
//MASTER CODE

char mystr[20]= "Hlo Tejashvi" ;

void setup()
{
  Serial.begin(115200); //baud rate
}

void loop()
{
  Serial.write(mystr,20);//write the serial data
  delay(1000); // Wait for 1000 millisecond(s)
}

// C++ code
//SLAVE Code

char mystr[20];

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.readBytes(mystr,20); //Read the serial data  store the value
  Serial.println(mystr); //print the serial data
  delay(1000); // Wait for 1000 millisecond(s)
}
