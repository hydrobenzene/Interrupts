/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/hydrobenzene/Downloads/SummerClass/Interrupt/Interrupt/src/Interrupt.ino"
  void setup();
void loop();
oled oledSetup();
void isr();
#line 1 "c:/Users/hydrobenzene/Downloads/SummerClass/Interrupt/Interrupt/src/Interrupt.ino"
SYSTEM_THREAD(ENABLED);
#include <Wire.h>
#include <blynk.h>
#include "oled-wing-adafruit.h"

int interruptCount = 0;
volatile bool interrupted = false;
OledWingAdafruit oled = oledSetup();

void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT_PULLUP);

  Serial.begin(9600);

  attachInterrupt(D2, isr, FALLING); 
  interrupts();

}

void loop() {
  oled.loop();
  if (digitalRead(D1) == 1 && !interrupted) counter++;
  Serial.println(digitalRead(D1));
  Serial.println(digitalRead(D2));
  printToDisplay((String) interruptCount);
}

oled oledSetup(){
  oled.setup(); // Initialize OLED
  oled.clearDisplay(); // Clear OLED Screen
  oled.setCursor(0,0); // Reset cursor
  oled.setTextSize(0); // Set text size to 0
	oled.display(); // Update OLED
}

void isr(){
  interrupted = !interrupted;
}