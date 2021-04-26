/*
 * Handler I2C Devices
 * INA219 and I2C_LCD
 */


//========= Macros ===========
#define LCD_ADDR 0x27
#define LCD_ROW 2
#define LCD_COL 16

//========== Data Type ===========

struct powerStruct{
  int voltage;
  int current;
  int power;
};

//======== Variable Declaration ==========

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW); //LCD object
Adafruit_INA219 sensor219; // Declare and instance of INA219

struct powerStruct powerData;


//======== Funcs ===========


//Initialize LCD
void lcdinit(){ 
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("TUBES LTF II");
  lcd.setCursor(1,1);
  lcd.print("PV Berbasis IoT");
}

//Read INA219 and write it to a powerStruct Struct
struct powerStruct powerRead(){ 
  struct powerStruct pwr;
  float a;

  a = sensor219.getBusVoltage_V()*1000;
  pwr.voltage = a;
  a = sensor219.getCurrent_mA()*1000;
  pwr.current = a;
  a = pwr.voltage/1000*pwr.current;
  pwr.power = a; // Menghitung Power

  return pwr;
}

//Print power data to Serial (not BT)
void prPowerSerial(struct powerStruct &pwr){//
  float a;
  a = pwr.voltage/1000;
  Serial.print("Bus Voltage:   "); 
  Serial.print(pwr.voltage); 
  Serial.println(" mV");  

  a = pwr.current/1000;
  Serial.print("Current:       "); 
  Serial.print(pwr.current); 
  Serial.println(" uA");

  a = pwr.power;
  Serial.print("Power:         "); 
  Serial.print(pwr.power); 
  Serial.println(" uW");  
  
  Serial.println("");  
}

//Print voltage and current data to LCD
void prPowerLcd(struct powerStruct &pwr){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("V");
  lcd.print(" ");
  lcd.print(pwr.voltage);
  lcd.print("mV");


  lcd.setCursor(0,1);
  lcd.print("I");
  lcd.print(" ");
  lcd.print(pwr.current);
  lcd.print("uA");
}


/*
lcd.setCursor(0,0);
lcd.print("P=");
lcd.print(" ");
lcd.print(power);
lcd.print("W");
}*/
