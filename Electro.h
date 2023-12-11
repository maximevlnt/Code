
#ifndef ELECTROAIMANT_H
#define ELECTROAIMANT_H

#include <Arduino.h>

class Electroaimant {
  private:
    int pin;

  public:
    Electroaimant(int electromagnetPin);
    void activate();
    void deactivate();
};

#endif
