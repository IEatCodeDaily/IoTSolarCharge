#define TITLE "Kontrol Servo Otomatis Dengan LDR dan Blynk"

#define BAUD 9600

//==========Library==========
//I2C
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal_I2C.h>

//Servo
#include <Servo.h>     

//EEPROM
#include <EEPROM.h>

//Software Serial for BT
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX


bool servoBTControl = false;
bool servoOverride = false;
