
//rekam data ke EEPROM
void rekamData(struct powerStruct &pwr) {
  // tandai sdg rekam dengan manyalakan LED
  static boolean led=false;
  
  ebPut(pwr);

  led = !led;
  digitalWrite(13, led);
}

//too lazy to think about func declaration order
//void sendLog(long waktu, int volt, int current, int power);

//membaca seluruh isi EEPROM hingga flag tail  = -1 pada address 1022
void ebDump(){
  byte addr = ebGetWriteAddr();
  byte n = addr % EBUFF_MAX + 1;
  struct powerStruct pwr = ebGet(addr);
  sendPacket("eds"); //EEPROM Dumping Start
  sendLog(pwr);
  while (n != addr){
    pwr = ebGet(n);
    sendLog(pwr);
    n = addr % EBUFF_MAX + 1;
    }
  sendPacket("ede"); //EEPROM Dump End
}
