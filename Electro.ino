#include "Electro.h"
#include <Arduino.h>


Electromagnet::Electromagnet(int electromagnetPin, int statusLedPin) : pin(electromagnetPin), ledPin(statusLedPin) {
  pinMode(pin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void Electromagnet::activate() {
  digitalWrite(pin, HIGH); // Turn on the electromagnet
}

void Electromagnet::deactivate() {
  digitalWrite(pin, LOW); // Turn off the electromagnet
}


