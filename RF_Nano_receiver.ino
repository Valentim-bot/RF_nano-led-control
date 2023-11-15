#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define LED 3
RF24 radio(10, 9); // CE, CSN

const byte address[6] = "00001";

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    int nbr = 0;
    radio.read(&nbr, sizeof(nbr));
    digitalWrite(LED, HIGH);
    delay(nbr);
    digitalWrite(LED, LOW);
    delay(nbr);
    
    Serial.println(nbr);
  }
}