# NIBE360_zwave_remote_control
This library contain documents and source code for setting up a z-uno zwave controller together with an Arduino uno 
and a relay board to remotely control the NIBE360 heater. See the details in the parts list document. 
Use this zwave enabled remote controller together with a zwave hub controller. See instruction on how to add a z-uno to a zwave 
hub at https://z-uno.z-wave.me/getting-started/. The source sketch for the Z-UNO Zwave controller in this application is based on
the sketch that was certified by the Z-Wave Alliance as one of the two reference Z-Uno sketches and modified for remote management 
of NIBE360 and using Arduino UNO as the shield for the relay board VMA 436. The Ardunio UNO are using digital input pull up 
pins 1 - 5 and drive output pins 8 - 12 with active LOW. 5 relay switches and 2 input alarms are defined based on the information 
in the manual http://www.nibeonline.com/pdf/411482-1.pdf page 17 and onwards.

// Pins definitions
#define R1_TARIFF_A_PIN 9
#define R2_TARIFF_B_PIN 10
#define R3_SHUNT_PLUS5_PIN 11
#define I1_HP_ALARM_PIN 12 (not connected/used in this version of the controller)
#define I2_LP_ALARM_PIN 19 (not connected/used in this version of the controller)
#define R4_EXTRA_WARM_WATER_PIN 20
#define R5_FAN_SPEED_II_PIN 21


