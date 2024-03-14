#ifndef COMPONENTS_H
#define COMPONENTS_H

#define ANALOG_WRITE_THRESHOLD 100

#include <Arduino.h>

class Led {
public:
    Led(int pin);
    void setup();
    void on();
    void off();
    void toggle();
    void write(int val);

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
    int _prev_state;
};

class AnalogReader {
public:
    AnalogReader(int pin, int tol = 5);
    void setup();
    void update();
    bool increased();
    bool decreased();
    bool changed();
    int read();

private:
    int _pin;
    int _read;
    int _prev_read;
    int _tolerance;
};

#endif  // COMPONENTS_H
