int counter;

void identificationSwitch() {
  //Serial.print("Identification Option: ");
  switch (RXBuf[2]) {
    case 0x80:
      //Serial.println("ECU Identification Data Table");
      break;
    case 0x81:
      //Serial.println("ECU Identification Scaling Table");
      break;
    case 0x86:
      //Serial.println("Vehicle Manufacturer Specific");
      break;
    case 0x87:
      //Serial.println("Vehicle Manufacturer Spare Part Number");
      break;
    case 0x88:
      //Serial.println("Vehicle Manufacturer ECU Software Number");
      break;
    case 0x89:
      //Serial.println("Vehicle Manufacturer ECU Software Version Number");
      break;
    case 0x8A:
      //Serial.println("System Supplier");
      break;  
    case 0x8B:
      //Serial.println("ECU Manufacturing Date");
      break;
    case 0x8C:
      //Serial.println("ECU Serial Number");
      break;
    case 0x90:
      //Serial.println("Vehicle Identification Number");
      break;
    case 0x91:
      //Serial.println("Vehicle Manufacturer ECU Hardware Number");
      break;
    case 0x92:
      //Serial.println("System Supplier ECU Hardware Number");
      break;  
    case 0x93:
      //Serial.println("System Supplier ECU Hardware Version Number");
      break;
    case 0x94:
      //Serial.println("System Supplier ECU Software Number");
      break;  
    case 0x95:
      //Serial.println("System Supplier ECU Software Version Number");
      break;
    case 0x96:
      //Serial.println("Exhaust Regulation Or Type Approval Number");
      break;  
    case 0x97:
      //Serial.println("System Name or Engine Type");
      break;
    case 0x98:
      //Serial.println("Repair Shop Code or Tester Serial Number");
      break;  
    case 0x99:
      //Serial.println("Programming Date");
      break;
    case 0x9B:
      //Serial.println("Calibration Date");
      break;  
    case 0x9C:
      //Serial.println("Calibration Equipment Software Number");
      break;
    case 0x9D:
      //Serial.println("ECU Installation Date");
      break;  
    default:
      //Serial.println("Code Error");
      break;  
  }
}

void commandSwitch() {
  switch(RXBuf[1]) {
    case 0x10:
      //Serial.println("Command: Start Diagnostic Session");
      if (RXBuf[2] == 0x86) {
        //Serial.println("Development Session");
        //Serial.println("changing Speed to 56000 kbps");
        //Serial1.end();
        //Serial1.begin(56000);
        highSpeed = 1;
       // Serial.print("Checksum = ");
       // Serial.println(RXBuf[(RXBuf[0] + 1)], HEX);
      }
      else {
        //Serial.println("Unknown Sub Command");
      }
      break;
    case 0x1A:
      //Serial.println("Command: Read ECU Identification");
      identificationSwitch();
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[3], HEX);
      break;
    case 0x23:
      //Serial.println("Command: Read Memory By Address");
      //Serial.print("Memory Address: 0x");
      //Serial.print(RXBuf[2], HEX);
      //Serial.print(RXBuf[3], HEX);
      //Serial.println(RXBuf[4], HEX);
      //Serial.print(RXBuf[5]);
      //Serial.println(" bytes");
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[6], HEX);
      break;
    case 0x3D:
      //Serial.println("Command: Write Memory By Address");
      //Serial.print("Memory Address: 0x");
      //Serial.print(RXBuf[2], HEX);
      //Serial.print(RXBuf[3], HEX);
      //Serial.println(RXBuf[4], HEX);
      //Serial.print(RXBuf[5], HEX);
      //Serial.println(" bytes");
      for (int t = 6; t < (RXBuf[5]+6); t++) {
        //Serial.print("Byte ");
        //Serial.print(t-5, HEX);
        //Serial.print(": 0x");
        //Serial.println(RXBuf[t], HEX);
      }
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[(RXBuf[0]+1)], HEX);
      break;
    case 0x3E:
      //Serial.println("Command: Tester Present");
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[2], HEX);
      break;
    case 0x50:
      //Serial.println("Positive Response to Start Diagnostic Session");
      if (RXBuf[2] == 0x86) {
        //Serial.println("Development Session");
        //Serial.println("56000 kbps Speed");
        //Serial.print("Checksum = ");
        //Serial.println(RXBuf[4], HEX);
        Serial1.end();
        Serial1.begin(56000);
      }
      break;
    case 0x5A:
      //Serial.println("Positive Response to Read ECU Identification");
      identificationSwitch();
      for (int t = 3; t < (RXBuf[0] + 1) ; t++) {
        //Serial.write(RXBuf[t]);
      }
      //Serial.println();
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[(RXBuf[0] + 1)], HEX);
      break;
    case 0x63:
      //Serial.println("Positive Response to Read Memory By Address");
      for(int t = 2; t < (RXBuf[0]+1); t++) {
        //Serial.print("Byte ");
        //Serial.print(t-1);
        //Serial.print(": 0x");
        //Serial.println(RXBuf[t], HEX);
      }
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[(RXBuf[0] + 1)], HEX);
      break;
    case 0x7D:
      //Serial.println("Positive Response to Write Memory By Address Command");
      //Serial.print("Written At 0x");
      //Serial.print(RXBuf[2], HEX);
      //Serial.print(RXBuf[3], HEX);
      //Serial.println(RXBuf[4], HEX);
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[5], HEX);
      break;
    case 0x83:
      //Serial.println("Command: Access Timing Parameters");
      if (RXBuf[2]== 0x03) { 
          //Serial.println("Set Timing Parameters to Given Values");
          //Serial.print("P2Min: ");
          //Serial.println(RXBuf[3]);
          //Serial.print("P2Max: ");
          //Serial.println(RXBuf[4]);
          //Serial.print("P3Min: ");
          //Serial.println(RXBuf[5]);
          //Serial.print("P3Max: ");
          //Serial.println(RXBuf[6]);
          //Serial.print("P4Min: ");
          //Serial.println(RXBuf[7]);
          //Serial.print("Checksum = ");
          //Serial.println(RXBuf[8], HEX);
      }
      else {
        //Serial.println("Subcommand Unknown");
      }
      break;
    case 0xB7:
      Serial.println("Logger Configuration Array");
      if (RXBuf[0] != 0x01) { 
        for (int t=2; t <(RXBuf[0] + 1); t++) {
          Serial.print("0x");
          Serial.print(RXBuf[t], HEX);
          Serial.print(", ");
          if(t == 0x13 || t==0x23 || t==0x33 || t==0x43 || t==0x53 || t==0x63 || t== 0x73) {
            Serial.println();
          }
        }
      }
      //Serial.println();
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[(RXBuf[0] + 1)], HEX);
      break;
        
    case 0xC3:
      //Serial.println("Positive Response to Access Timing Parameters");
      //Serial.print("Checksum = ");
      //Serial.println(RXBuf[3], HEX);
      break;
    default:
      //Serial.println("Unknown Command");
      break;
  }
}

void SendMemoryByAddress() {
  //Serial.print("Message Length = 0x");
  //Serial.println(RXBuf[1], HEX);
  if(RXBuf[2] == 0x3D) {
      //Serial.println("Command: Write Memory By Address"); 
    }
  //Serial.print("Address is 0x");
  //Serial.print(RXBuf[3], HEX);
  //Serial.print(RXBuf[4], HEX);
  //Serial.println(RXBuf[5], HEX);
  //Serial.print("Length = ");
  //Serial.println(RXBuf[6], HEX);
  Serial.print("MemoryArray");
  Serial.print(counter);
  counter++;
  Serial.println();
  
  for (int t=7; t<(RXBuf[1] + 2); t++) {
    Serial.print("0x");
    Serial.print(RXBuf[t], HEX);
    if (RXBuf[t] < 0x10) {
      Serial.print("0");
    }
    if(t != (RXBuf[1] + 1)) {
       Serial.print(", ");
    }
    if(t == 0x16 || t==0x26 || t==0x36 || t==0x46 || t==0x56 || t==0x66 || t== 0x76) {
      Serial.println();
    }
  }
  //Serial.println();
  //Serial.print("Checksum = ");
  //Serial.println((RXBuf[(RXBuf[1]+2)]), HEX);
}

void ReadMemoryByAddress() {
  //Serial.print("Message Length = 0x");
  //Serial.println(RXBuf[1], HEX);
  if(RXBuf[2] == 0x63) {
      //Serial.println("Positive Response to Read Memory By Address"); 
    }
    //Serial.print("0x");
  for (int t=3; t<(RXBuf[1] + 2); t++) {
    //Serial.print(RXBuf[t], HEX);
    //Serial.print(", 0x");
    if(t == 0x13 || t==0x23 || t==0x33 || t==0x43 || t==0x53 || t==0x63 || t== 0x73) {
      //Serial.println();
    }
  }
  //Serial.println();
  //Serial.print("Checksum = ");
  //Serial.println((RXBuf[(RXBuf[1]+2)]), HEX);
}

void recieveArray() {
  for (int t=1; t<2;) {
    if(Serial1.available()) {
      RXBuf[1] = Serial1.read();
      master = !master;
      t++;
    }
  }
  for (int t=2; t<(RXBuf[1]+3) ; ) {
    if(Serial1.available()) {
      RXBuf[t] = Serial1.read();
      t++;
    }
  }
  for (int t = 0; t<(RXBuf[1]+3); t++) {
    //Serial.print(RXBuf[t], HEX);
    //Serial.print(" "); 
  }
  //Serial.println();
  switch(RXBuf[2]) {
    case 0x63:
      ReadMemoryByAddress();
      break;
    case 0x3D: 
      SendMemoryByAddress();
      break;
    default:
     // Serial.println("Unknown Command For Block");
      break;
  }
}
