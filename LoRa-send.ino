#include <SPI.h>
#include <LoRa.h>

int pin = A0;

String text = "ให้ LED ติด";

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
  int A = analogRead(pin);
  if (A==1023){
    LoRa.beginPacket();
    LoRa.print(text);
    LoRa.endPacket();

    Serial.print("Send '");
    Serial.print(text);
    Serial.println("'");
  }
}
