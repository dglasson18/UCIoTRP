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
  for (int packetBuffer = 0; packetBuffer < 5; packetBuffer++)
  {
    packet = "XPacket " + String(counter);
    packet = packet + "Y";
    packets[packetBuffer] = packet;
    delay(500);
    counter++;
  }
  LoRa.beginPacket();
  LoRa.print(packets[0]);
  LoRa.print(packets[1]);
  LoRa.print(packets[2]);
  LoRa.print(packets[3]);
  LoRa.print(packets[4]);
  LoRa.endPacket();
}
