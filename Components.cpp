#include "Components.h"

#include "Arduino.h"

// Led Class

Led::Led(int pin) : _pin(pin) {}

void Led::setup() { pinMode(_pin, OUTPUT); }

void Led::on() {
    digitalWrite(_pin, HIGH);
    _on = true;
}

void Led::off() {
    digitalWrite(_pin, LOW);
    _on = false;
}

void Led::alternate() {
    if (_on)
        off();
    else
        on();
}

// Button Class

Button::Button(int pin) : _pin(pin), _state(0), _oldState(0) {}

void Button::setup() { pinMode(_pin, INPUT); }

void Button::update() {
    _oldState = _state;
    _state = digitalRead(_pin);
}

bool Button::is_pressed() { return _state == HIGH; }

bool Button::was_pressed() { return _oldState == LOW && _state == HIGH; }

bool Button::was_released() { return _oldState == HIGH && _state == LOW; }

bool Button::was_pressed_or_released() {
    return was_pressed() || was_released();
}