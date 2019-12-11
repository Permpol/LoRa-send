#include <SPI.h>
#include <LoRa.h>

int led = 3;
String text;

void setup(){
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa-received");
  pinMode(led,OUTPUT);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while(1);
  }
  digitalWrite(led,0);
}

void loop(){
  if (LoRa.parsePacket()) {
    String text = LoRa.readString();
    Serial.print("Receiver '");
    Serial.print(text);
    Serial.print("' RSSI is ");
    Serial.println(LoRa.packetRssi());
    
  }
  else{
    Serial.printIn("no data");
  }

  if(text == "ห้ LED ติด"){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
 

}