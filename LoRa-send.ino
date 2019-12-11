#include <SPI.h>
#include <LoRa.h>

int pin = 3;

String text = "ให้ LED ติด";
String text1 = "ให้ LED ดับ";

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa-sender");
  pinMode(pin,INPUT);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while(1);
  }
}

void loop(){
  int A = digitalRead(pin);
  if (A==HIGH){
    LoRa.beginPacket();
    LoRa.print(text);
    LoRa.endPacket();

    Serial.print("Send '");
    Serial.print(text);
    Serial.println("'");
  }
  if (A==LOW){
    LoRa.beginPacket();
    LoRa.print(text1);
    LoRa.endPacket();

    Serial.print("Send '");
    Serial.print(text1);
    Serial.println("'");
    delay(2000);
  }
  
}
