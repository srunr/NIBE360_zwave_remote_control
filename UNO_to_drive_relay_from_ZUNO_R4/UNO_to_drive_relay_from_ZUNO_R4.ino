// Input pullup connected to the z-uno controller outputs to enable 
// conversion from 3.3V to 5V to drive the VMA436 board.
//Digital input PINS
int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;
int IN5 = 5;

// the digital output PINS
int OUT1 = 8;
int OUT2 = 9;
int OUT3 = 10;
int OUT4 = 11;
int OUT5 = 12;

byte readIN1 = HIGH;
byte currIN1 = HIGH;
byte readIN2 = HIGH;
byte currIN2 = HIGH;
byte readIN3 = HIGH;
byte currIN3 = HIGH;
byte readIN4 = HIGH;
byte currIN4 = HIGH;
byte readIN5 = HIGH;
byte currIN5 = HIGH;

void setup() 
{
  pinMode(IN1, INPUT_PULLUP); 
  pinMode(IN2, INPUT_PULLUP); 
  pinMode(IN3, INPUT_PULLUP); 
  pinMode(IN4, INPUT_PULLUP); 
  pinMode(IN5, INPUT_PULLUP); 

  pinMode(OUT1, OUTPUT); 
  pinMode(OUT2, OUTPUT); 
  pinMode(OUT3, OUTPUT); 
  pinMode(OUT4, OUTPUT); 
  pinMode(OUT5, OUTPUT); 

  // digitalWrite(OUT1,HIGH); // low = relay ON, high = relay OFF for velleman VMA436
  // digitalWrite(OUT2,HIGH); // Do not need to initialize !!!
  // digitalWrite(OUT3,HIGH); 
  // digitalWrite(OUT4,HIGH); 
  // digitalWrite(OUT5,HIGH); 
  delay(100);
}

void loop()
{
  delay(100);
  readIN1 = digitalRead(IN1);
  if (readIN1 != currIN1)
  {
    digitalWrite(OUT1,!readIN1); 
    currIN1 = readIN1;
    delay(10);
  }
  readIN2 = digitalRead(IN2);
  if(readIN2 != currIN2)
  {
    digitalWrite(OUT2,!readIN2); 
    currIN2 = readIN2;
    delay(10);
  }
  readIN3 = digitalRead(IN3);
  if(readIN3 != currIN3)
  {
    digitalWrite(OUT3,!readIN3); 
    currIN3 = readIN3;
    delay(10);
  }
  readIN4 = digitalRead(IN4);
  if(readIN4 != currIN4)
  {
    digitalWrite(OUT4,!readIN4); 
    currIN4 = readIN4;
    delay(10);
  }
  readIN5 = digitalRead(IN5);
  if(readIN5 != currIN5)
  {
    digitalWrite(OUT5,!readIN5); 
    currIN5 = readIN5;
    delay(10);
  }
 
}





