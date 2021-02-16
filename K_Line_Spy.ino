int RXBuf[150];
unsigned long int oldmillis;
unsigned long int timing;
bool InitStarted;
bool InitComplete;
bool pin0;
byte data;
bool pin0old;
int ByteCount;
bool master;
bool highSpeed;
#include "parsing.h"


void parseMessage() {
  commandSwitch();
}

void recieveData(int ByteCount) {
  for ( int t = 0; t<ByteCount; ) {
    if(Serial1.available()) {
      RXBuf[t] = Serial1.read();
      Serial.print(RXBuf[t], HEX);
      Serial.print(" ");
      t++;  
    }
  }
  Serial.println();
  master=!master;
}

void recieveDataWithHeader() {
  for ( int t = 1; t<(RXBuf[0]+2) ; ) {
    if(Serial1.available()) {
      RXBuf[t] = Serial1.read();
      t++;  
    }
  }
  for ( int t = 0; t<(RXBuf[0]+2) ; ) {
    Serial.print(RXBuf[t], HEX);
    Serial.print(" ");
    t++;  
  }
  Serial.println();
  parseMessage();
  master = !master;
}

void setup() {
  Serial.begin(10400);
  Serial.println("System Connected");
  pinMode(0, INPUT);
  InitStarted = 0;
  InitComplete = 0;
  Serial1.begin(10400);
  pin0old = 1;
  master = 1;
  highSpeed = 0;
  counter = 1;
}

void loop() {
  if(!InitStarted) {
    InitComplete = 0;
    for (int i = 0; i < 4 ; ) {
      if (Serial1.available()) {
        data = Serial1.read();
        Serial.print(data, HEX);
        Serial.print(" ");
        if (data == 0xAA && ((i == 0) || (i == 2))) {
          i++;
        }
        if (data == 0x55 && ((i == 1) || (i == 3))) {
          i++;
        }
      }
    }
    Serial.println();
    oldmillis = millis();
    Serial1.end();
    pinMode(0, INPUT);
    for(int r = 0 ; r<11; ) {
      delay(200);
      pin0=digitalRead(0);
      Serial.print(pin0);
      r++;
    }
    Serial1.begin(10400);
    Serial.println();
    Serial.println("Slow init complete");
    InitStarted = 1;
  }
  
  if(InitStarted && !InitComplete) {
    //oldmillis = millis();
      master = 0;
      Serial.print("Connection Confirmation: ");
      recieveData(3);
      Serial.print("Connection Response: ");
      recieveData(1);
      Serial.print("Positive Response: ");
      recieveData(1);
      InitComplete = 1;
  }
   
  
  if(InitStarted&&InitComplete) {  
    if(Serial1.available()) {
      if (master) {
        Serial.print("Out: ");
      }
      else {
        Serial.print("In:  ");
      }
      RXBuf[0] = Serial1.read();
      if (RXBuf[0] == 0x00) {
        recieveArray();
      }
      else {
        recieveDataWithHeader();
        //parseMessage();
      }
      Serial.println();    
    }
  }
}
