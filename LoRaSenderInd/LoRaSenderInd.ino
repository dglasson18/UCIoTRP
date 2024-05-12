#include <SPI.h>
#include <LoRa.h>

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  String packets[5];
  String packet;
  packet = "XPacket " + String(counter);
  packet = packet + "Y";
  LoRa.beginPacket();
  LoRa.print(packet);
  LoRa.endPacket();
  delay(500);
  counter++;
}
