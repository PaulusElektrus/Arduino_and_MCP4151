/*
With this script I controlled a SMPS by a MCP4151 with an Arduino UNO and the PC over Serial Communication.
*/

#include <Arduino.h>
#include "MCP4151.h"

#define CS     10
#define MOSI   11
#define MISO   12
#define SCK    13

int i = 255;
float u_in = 5.0;
float u;
float read_value;
String incomingString;

MCP4151 pot(CS, MOSI, MISO, SCK);
// MCP4151 pot(CS, MOSI, MISO, SCK, 4000000, 250000, SPI_MODE0);

void setup() {
  pot.writeValue(i); // turn the pot on
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0){
    incomingString = Serial.readString();

    if (incomingString.equals("u")){
        if (i <= 245){
        i += 10;}
        pot.writeValue(i);
    }
    if (incomingString.equals("d")){
        if (i >= 10){
        i -= 10;}
        pot.writeValue(i);
    }
        if (incomingString.equals("z")){
        pot.writeValue(0);
    }
        if (incomingString.equals("f")){
        pot.writeValue(255);
    }
    Serial.print("Pot: ");
    Serial.print(pot.getCurValue());
    read_value=0;
    delay(1000);
    for(int j = 0; j < 5; j++){
      read_value+=analogRead(A0);}
    read_value=read_value/5;
    u=(u_in/1023.0)*read_value;
    Serial.print(" - U: " );
    Serial.println(u);
  }

  delay(50);}