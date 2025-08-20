// Digital clock for 6 common-cathode 7-segments (HH:MM:SS)
// Segment pins
const uint8_t segPins[7] = {11, 10, 7, 8, 9, 12, 13}; // a,b,c,d,e,f,g

// Digit cathode pins for each display
const uint8_t dispPins[6] = {2, 3, 4, 5, 6, A1}; // HH tens, HH units, MM tens, MM units, SS tens, SS units

// digit patterns for 0..9 (order: a,b,c,d,e,f,g) - 1 = ON for common cathode
const uint8_t digits[10][7] = {
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}  //9
};

// time variables
volatile int hours = 0;
volatile int minutes = 0;
volatile int seconds = 0;

// multiplex control
uint8_t currentDigit = 0;
unsigned long lastMux = 0;
const unsigned long muxInterval = 2; // ms per digit -> 6 * 2ms = 12ms refresh

// timekeeping
unsigned long lastSecond = 0;

void setup() {
  // Serial to allow manual time set (optional)
  Serial.begin(9600);
  Serial.println("Clock started. Send HH:MM:SS to set time.");

  // setup segment pins
  for (uint8_t i = 0; i < 7; ++i) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], LOW); // default off (LOW = off for common-cathode segments)
  }

  // setup digit pins (HIGH = off for common-cathode cathode pins)
  for (uint8_t i = 0; i < 6; ++i) {
    pinMode(dispPins[i], OUTPUT);
    digitalWrite(dispPins[i], HIGH); // disable initially
  }

  lastMux = millis();
  lastSecond = millis();
  // set an initial time if you want
  hours = 0; minutes = 0; seconds = 0;
}

void loop() {
  // multiplex refresh
  if (millis() - lastMux >= muxInterval) {
    lastMux += muxInterval;
    refreshNextDigit();
  }

  // time increment every 1000 ms
  if (millis() - lastSecond >= 1000) {
    lastSecond += 1000;
    tickSecond();
  }

  // Serial time set (send "HH:MM:SS" + newline)
  if (Serial.available()) {
    String s = Serial.readStringUntil('\n');
    s.trim();
    if (s.length() >= 7) {
      int h = s.substring(0,2).toInt();
      int m = s.substring(3,5).toInt();
      int sec = s.substring(6,8).toInt();
      if (h >= 0 && h < 24 && m >= 0 && m < 60 && sec >= 0 && sec < 60) {
        hours = h; minutes = m; seconds = sec;
        Serial.print("Time set to: ");
        Serial.print(hours); Serial.print(":");
        Serial.print(minutes); Serial.print(":");
        Serial.println(seconds);
      } else {
        Serial.println("Invalid time format or out of range");
      }
    }
  }
}

// increment seconds and handle rollovers
void tickSecond() {
  seconds++;
  if (seconds >= 60) {
    seconds = 0;
    minutes++;
    if (minutes >= 60) {
      minutes = 0;
      hours++;
      if (hours >= 24) hours = 0;
    }
  }
}

// draw one digit (multiplex)
void refreshNextDigit() {
  // disable all displays first (avoid ghosting)
  for (uint8_t i = 0; i < 6; ++i) digitalWrite(dispPins[i], HIGH);

  // determine which number to show on currentDigit
  uint8_t values[6];
  values[0] = hours / 10;
  values[1] = hours % 10;
  values[2] = minutes / 10;
  values[3] = minutes % 10;
  values[4] = seconds / 10;
  values[5] = seconds % 10;

  uint8_t val = values[currentDigit];

  // set segments
  for (uint8_t s = 0; s < 7; ++s) {
    if (digits[val][s]) digitalWrite(segPins[s], HIGH); // ON
    else digitalWrite(segPins[s], LOW);                // OFF
  }

  // enable current digit
  digitalWrite(dispPins[currentDigit], LOW);

  // advance to next digit
  currentDigit++;
  if (currentDigit >= 6) currentDigit = 0;
}
