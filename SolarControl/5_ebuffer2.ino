//======== Macros ==========
#define ROM_MAX 1024

#define TAIL_EMPTY 255

#define SIZE_DATA 3*2

#define EBUFF_MAX (ROM_MAX/SIZE_DATA) //170

#define ADDR_TO_WRITE 1023

#define ADDR_TAIL_FLAG 1020


//========== Var Declaration ===========

void ebInit(){
  EEPROM.put(ADDR_TO_WRITE, 0);
  EEPROM.put(ADDR_TAIL_FLAG, TAIL_EMPTY);
}

byte ebGetWriteAddr(){
  byte addressToWrite;
  EEPROM.get(ADDR_TO_WRITE, addressToWrite);
  return addressToWrite;
}

bool ebPut(struct powerStruct &data) {
  bool rtn = true;
  byte addr = ebGetWriteAddr();

  // taruh datanya di head, apapun kondisinya
  EEPROM.put(SIZE_DATA * addr, data);

  addr = addr % EBUFF_MAX + SIZE_DATA;

  EEPROM.put(ADDR_TO_WRITE, addr);
  return rtn;
}

struct powerStruct ebGet(byte n){
  struct powerStruct pwr;
  EEPROM.get(SIZE_DATA * n, pwr);
  return pwr;
}
