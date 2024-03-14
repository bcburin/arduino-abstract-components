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

void Led::toggle() {
    if (_on) {
        off();
    }
    else {
        on();
    }
}

void Led::write(int val) {
    analogWrite(_pin, val);
    _on = (val > ANALOG_WRITE_THRESHOLD);
}

// Button Class

Button::Button(int pin) : _pin(pin), _state(LOW), _prev_state(LOW) {}

void Button::setup() { pinMode(_pin, INPUT); }

void Button::update() {
    _prev_state = _state;
    _state = digitalRead(_pin);
}

bool Button::is_pressed() { return _state == HIGH; }

bool Button::was_pressed() { return _prev_state == LOW && _state == HIGH; }

bool Button::was_released() { return _prev_state == HIGH && _state == LOW; }

bool Button::was_pressed_or_released() {
    return was_pressed() || was_released();
}


// AnalogReader class

AnalogReader::AnalogReader(int pin, int tol) : _pin(pin), _tolerance(tol) {}

void AnalogReader::setup() { pinMode(_pin, INPUT); }

void AnalogReader::update() {
    _prev_read = _read;
    _read = analogRead(_pin);
}

bool AnalogReader::increased() { return _read > (_prev_read + _tolerance); }

bool AnalogReader::decreased() { return _read < (_prev_read - _tolerance); }

bool AnalogReader::changed() { return increased() || decreased(); }

int AnalogReader::read() { return _read; }