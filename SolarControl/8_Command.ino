
bool sendLdrData = true;
bool sendPowerData = false;

//Command Parser and Reader for BT(yes i know i should prob make it separately but i dont give enough F)
void readCommandBT(){
   if (BTSerial.available()) {
    String command;
    command = BTSerial.readStringUntil('\n');
    command.toLowerCase();
    int space = command.indexOf(" ");
    String cmd = command.substring(0, space);
    String arg = command.substring(space + 1);
    Serial.print("Received: "); Serial.print(cmd); Serial.print(" "); Serial.println(arg);

    if (cmd == "s") {
      if(servoBTControl){
        servoWrite(arg.toInt());
        Serial.print("servo moved to "); Serial.println(arg);
      }
    }
    else if (cmd == "m"){
      servoBTControl = arg.toInt();
      Serial.print("servoBT = "); Serial.println(arg);
    }
    else if (cmd == "e"){
      if (arg == "all"){
        ebDump();
      }
      else if (arg.toInt() < EBUFF_MAX){
        byte n = arg.toInt();
        struct powerStruct pwr = ebGet(n);
        sendLog(pwr);
      }
    }
    else if (cmd == "screen"){
      if (arg == "0"){
        sendLdrData = true;
        sendPowerData = false;
      }
      else if (arg == "1"){
        sendLdrData = false;
        sendPowerData = true;
      }
    }
    else if (cmd == "p"){
      sendPowerData = arg.toInt();
    }
 }
 BTSerial.flush();   
}

//Command Parser and Reader for Serial
void readCommandSerial(){
   if (Serial.available()) {
    String command;
    command = Serial.readStringUntil('\n');
    command.toLowerCase();
    int space = command.indexOf(" ");
    String cmd = command.substring(0, space);
    String arg = command.substring(space + 1);
    Serial.print("Received: "); Serial.print(cmd); Serial.print(" "); Serial.println(arg);

    if (cmd == "s") {
      if(servoBTControl){
        servoWrite(arg.toInt());
        Serial.print("servo moved to "); Serial.println(arg);
      }
    }
    else if (cmd == "m"){
      servoBTControl = arg.toInt();
      Serial.print("servoBT = "); Serial.println(arg);
    }
    else if (cmd == "e"){
      if (arg == "all"){
        ebDump();
      }
      else if (arg.toInt() < EBUFF_MAX){
        byte n = arg.toInt();
        struct powerStruct pwr = ebGet(n);
        sendLog(pwr);
      }
    }
    else if (cmd == "screen"){
      if (arg == "0"){
        sendLdrData = true;
        sendPowerData = false;
      }
      else if (arg == "1"){
        sendLdrData = false;
        sendPowerData = true;
      }
    }
 }
 Serial.flush();   
}
