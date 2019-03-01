
/* 
 * This scretch was certified by the Z-Wave Alliance as one of the two reference Z-Uno sketches.
 * Modified for remote management of NIBE360 and using Arduino UNO as the shield for the relay board VMA 436
 * Program the UNO using digital input pull up pins 1 - 5 and drive output pins 8 - 12 with active LOW.
 * 5 relays switches R1-R5
 * 2 alarm digital inputs I1-I2
 */

// Pins definitions
#define R1_TARIFF_A_PIN 9
#define R2_TARIFF_B_PIN 10
#define R3_SHUNT_PLUS5_PIN 11
#define I1_HP_ALARM_PIN 12
#define I2_LP_ALARM_PIN 19
#define R4_EXTRA_WARM_WATER_PIN 20
#define R5_FAN_SPEED_II_PIN 21

// Global variables to store data reported via getters
byte switchTARIFF_A_VAL = 0;
byte switchTARIFF_B_VAL = 0;
byte switchSHUNT_PLUS5_VAL = 0;
byte switchEXTRA_WARM_WATER_VAL = 0;
byte switchFAN_SPEED_II_VAL = 0;
byte lastHP_ALARM_VAL = 0;
byte lastLP_ALARM_VAL = 0;

ZUNO_SETUP_SLEEPING_MODE(ZUNO_SLEEPING_MODE_ALWAYS_AWAKE);

ZUNO_SETUP_ASSOCIATIONS(ZUNO_ASSOCIATION_GROUP_SET_VALUE); // Send Basic Set to association group

// Set up 7 channels
ZUNO_SETUP_CHANNELS(
  ZUNO_SWITCH_BINARY(getterR1, setterR1),
  ZUNO_SWITCH_BINARY(getterR2, setterR2),
  ZUNO_SWITCH_BINARY(getterR3, setterR3),
  ZUNO_SWITCH_BINARY(getterR4, setterR4),
  ZUNO_SWITCH_BINARY(getterR5, setterR5),
  ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_GENERAL_PURPOSE, getterI1),
  ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_GENERAL_PURPOSE, getterI2)
);

void setup() {
  // set up I/O pins. 
  pinMode(R1_TARIFF_A_PIN, OUTPUT);
  digitalWrite(R1_TARIFF_A_PIN, HIGH); // Init High as the relay board is active LOW
  pinMode(R2_TARIFF_B_PIN, OUTPUT);
  digitalWrite(R2_TARIFF_B_PIN, HIGH); // Init High as the relay board is active LOW
  pinMode(R3_SHUNT_PLUS5_PIN, OUTPUT);
  digitalWrite(R3_SHUNT_PLUS5_PIN, HIGH); // Init High as the relay board is active LOW
  pinMode(R4_EXTRA_WARM_WATER_PIN, OUTPUT);
  digitalWrite(R4_EXTRA_WARM_WATER_PIN, HIGH); // Init High as the relay board is active LOW
  pinMode(R5_FAN_SPEED_II_PIN, OUTPUT); 
  digitalWrite(R5_FAN_SPEED_II_PIN, HIGH); // Init High as the relay board is active LOW
  pinMode(I1_HP_ALARM_PIN, INPUT_PULLUP);
  pinMode(I2_LP_ALARM_PIN, INPUT_PULLUP);
  delay(1000); //delay 1 s
}

// Getters and setters

void setterR1(byte value) {
  digitalWrite(R1_TARIFF_A_PIN, (value > 0) ?  LOW : HIGH);
  switchTARIFF_A_VAL = value;
}

byte getterR1(){
  return switchTARIFF_A_VAL;
}

 void setterR2(byte value) {
  digitalWrite(R2_TARIFF_B_PIN, (value > 0) ? LOW : HIGH);
  switchTARIFF_B_VAL = value;
}

byte getterR2(){
  return switchTARIFF_B_VAL;
}

void setterR3(byte value) {
  digitalWrite(R3_SHUNT_PLUS5_PIN, (value > 0) ? LOW : HIGH);
  switchSHUNT_PLUS5_VAL = value;
}

byte getterR3(){
  return switchSHUNT_PLUS5_VAL;
}
void setterR4(byte value) {
  digitalWrite(R4_EXTRA_WARM_WATER_PIN, (value > 0) ? LOW : HIGH);
  switchEXTRA_WARM_WATER_VAL = value;
}

byte getterR4(){
  return switchEXTRA_WARM_WATER_VAL;
}
void setterR5(byte value) {
  digitalWrite(R5_FAN_SPEED_II_PIN, (value > 0) ? LOW : HIGH);
  switchFAN_SPEED_II_VAL = value;
}

byte getterR5(){
  return switchFAN_SPEED_II_VAL;
}

byte getterI1(void) {
  return lastHP_ALARM_VAL ? 0xff : 0;
}

byte getterI2(void) {
  return lastLP_ALARM_VAL ? 0xff : 0;
}

void loop() {
  byte current_HP_ALARM_VAL;
  byte current_LP_ALARM_VAL;

  // NIBE360 Alarms
  current_HP_ALARM_VAL = digitalRead(I1_HP_ALARM_PIN); 
  if (current_HP_ALARM_VAL != lastHP_ALARM_VAL) { 
    lastHP_ALARM_VAL = current_HP_ALARM_VAL;
    zunoSendReport(6);
  }
  
  current_LP_ALARM_VAL = digitalRead(I2_LP_ALARM_PIN); 
  if (current_LP_ALARM_VAL != lastLP_ALARM_VAL) { 
    lastLP_ALARM_VAL = current_LP_ALARM_VAL;
    zunoSendReport(7);
  }
  delay(100);
}


