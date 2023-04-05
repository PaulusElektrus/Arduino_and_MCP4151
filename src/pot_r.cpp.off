#include <Arduino.h>
#include "MCP4151.h"

#define CS     10
#define MOSI   11
#define MISO   12
#define SCK    13

float read_value;
float u_in = 5.0;
float u2;
float r;
float r1 = 509.0;

MCP4151 pot(CS, MOSI, MISO, SCK);
// MCP4151 pot(CS, MOSI, MISO, SCK, 4000000, 250000, SPI_MODE0);

void setup() {
  pot.writeValue(0); // turn the pot off
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    pot.writeValue(i);
    Serial.print("Pot: ");
    Serial.print(pot.getCurValue());
    Serial.print(" - A0: ");
    read_value=0;
    for(int j = 0; j < 5; j++){
      read_value+=analogRead(A0);}
    read_value=read_value/5;
    Serial.print(read_value);
    u2=(u_in/1023.0)*read_value;
    Serial.print(" - U: ");
    Serial.print(u2);
    r = r1*(u2/(u_in-u2));
    Serial.print(" - R: ");
    Serial.println(r);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    pot.writeValue(i);
    Serial.print("Pot: ");
    Serial.print(pot.getCurValue());
    Serial.print(" - A0: ");
    read_value=0;
    for(int j = 0; j < 5; j++){
      read_value+=analogRead(A0);}
    read_value=read_value/5;
    Serial.print(read_value);
    u2=(u_in/1023.0)*read_value;
    Serial.print(" - U: ");
    Serial.print(u2);
    r = r1*(u2/(u_in-u2));
    Serial.print(" - R: ");
    Serial.println(r);
    delay(10);
  }
  delay(60000);
}

