#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <Arduino.h>

class Led {
   public:
    Led(int pin);
    void setup();
    void on();
    void off();
    void alternate();

   private:
    int _pin;
    bool _on;
};

class Button {
   public:
    Button(int pin);
    void setup();
    void update();
    bool is_pressed();
    bool was_pressed();
    bool was_released();
    bool was_pressed_or_released();

   private:
    int _pin;
    int _state;
    int _oldState;
};

#endif  // COMPONENTS_H
