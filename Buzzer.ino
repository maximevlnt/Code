#include "Buzzer.h"
#include <Arduino.h>

Buzzer::Buzzer(int buzzerPin) : pin(buzzerPin) {
  pinMode(pin, OUTPUT);
}

void Buzzer::buzz(int frequency, int duration) {
  int period = 1000000L / frequency; // Calculate the period in microseconds
  int halfPeriod = period / 2; // Half the period for on/off intervals

  for (long i = 0; i < duration * 1000L; i += period * 2) {
    digitalWrite(pin, HIGH); // Turn buzzer on
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW); // Turn buzzer off
    delayMicroseconds(halfPeriod);
  }
}

void Buzzer::stop() {
  digitalWrite(pin, LOW); // Turn off the buzzer
}

void Buzzer::validationSound() {
  int melody[] = {262, 330, 392, 523, 392, 330}; // Melodie de validation
  int noteDurations[] = {200, 200, 200, 200, 200, 200}; // Durées de chaque note

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); ++i) {
    buzz(melody[i], noteDurations[i]);
    delay(50); // Pause entre les notes si nécessaire
  }
}

void Buzzer::refusalSound() {
  int melody[] = {330, 294, 262, 196, 262}; // Melodie de refus
  int noteDurations[] = {200, 200, 200, 200, 200}; // Durées de chaque note

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); ++i) {
    buzz(melody[i], noteDurations[i]);
    delay(50); // Pause entre les notes si nécessaire
  }
}
