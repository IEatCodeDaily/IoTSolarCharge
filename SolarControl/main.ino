//======== Macros ============

#define BT_STATE 12 //pin state HC05

#define PACKET_PERIOD 500 //interval to send LDR and ServoPos data
#define LDR_PERIOD 100  //interval to refresh ServoPos according to LDR
#define DATALOG_PERIOD 12*60*60*3600/EBUFF_MAX //interval between data logging to EEPROM

//========= Variable Declaration ========
interval itvPacketSend;
interval itvLdrUpdate;
interval itvDataLog;

//========= Funcs ===========

//Setup
void setup() {
  BTSerial.begin(BAUD);
  Serial.begin(BAUD);

  lcdinit();
  servoInit();
  ldrInit();
  sensor219.begin();
  intervalInit(itvPacketSend, PACKET_PERIOD);
  intervalInit(itvLdrUpdate, LDR_PERIOD);
  intervalInit(itvDataLog, DATALOG_PERIOD);
  
  pinMode(12, INPUT); //BT State
}

//Looo0o00o0o0o0oo0o0op
void loop(){
  readCommandBT();
  
  ldrData = ldrRead();
    
  powerData = powerRead();
    
  if (isTimeout(itvPacketSend)){
    prPowerLcd(powerData);
    //prPowerSerial(powerData);
    if(digitalRead(BT_STATE)){
      if(sendLdrData){
        sendData(ldrData);
      }
      if(sendPowerData){
        sendLog(powerData);
      }
    }
  }
  if (isTimeout(itvLdrUpdate)){
    if(!servoBTControl){
      taskKontrol(ldrData);
      //Serial.print(ldrData.ldr1);
      //Serial.println(ldrData.ldr2);
    }
  } 
}
  
