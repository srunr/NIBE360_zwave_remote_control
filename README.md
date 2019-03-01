# NIBE360_zwave_remote_control
This library contain documents and source code for setting up a z-uno zwave controller together with an Arduino uno 
and a relay board to remotely control the NIBE360 heater. See the details in the parts list document. 
Use this zwave enabled remote controller together with a zwave hub controller. See instruction on how to add a z-uno to a zwave 
hub at https://z-uno.z-wave.me/getting-started/. The source sketch for the Z-UNO Zwave controller in this application is based on
the sketch that was certified by the Z-Wave Alliance as one of the two reference Z-Uno sketches, modified for remote management 
of NIBE360 and using Arduino UNO as the shield for the relay board VMA 436. The Ardunio UNO are using digital input pull up 
pins 1 - 5 and drive output pins 8 - 12 with active LOW. 5 relay switches and 2 input alarms are defined based on the information 
in the manual http://www.nibeonline.com/pdf/411482-1.pdf page 17 and onwards. Tha parts list document also contain pictures of the wiring inside the NIBE360 as well as links to swedish online suppliers of the parts.

