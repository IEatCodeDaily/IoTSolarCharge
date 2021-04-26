
//construct packet to be sent and send the packet
void sendData(struct ldrStruct &ldr){
  String packet;
  packet = "D," + String(ldr.ldr1) + "," + String(ldr.ldr2) + "," + String(servo_pos); 
  sendPacket(packet);
}

void sendLog(struct powerStruct &pwr){
  String packet;
  packet = "L," +String(pwr.voltage) + "mV," + String(pwr.current) + "uA," + String(pwr.power) + "uW"; 
  sendPacket(packet);
}

//send packet to BT and Serial(for debug)
void sendPacket(String packet){
  BTSerial.println(packet);
  Serial.print("Sent: "); Serial.println(packet);
}
