#include "BluetoothSerial.h"

BluetoothSerial serialBt;
char cmd;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  serialBt.begin("Esp32-BT");
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(serialBt.available())
  {
    cmd=serialBt.read();
  }
  if(cmd=='0')
  {
    Serial.println(cmd);
    digitalWrite(2,LOW);
  }
  if(cmd=='1')
    {
      Serial.println(cmd);
      digitalWrite(2,HIGH);
    }
    
}
