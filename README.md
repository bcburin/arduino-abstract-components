# Abstract Component Library for Arduino

The Abstract Component Library for Arduino provides a set of C++ classes designed to abstract the state management of Arduino components, offering simplified interfaces that adhere to object-oriented programming principles.

## Motivation

Consider the following example, which illustrates the control of an LED on pin 13 and a button on pin 2. The LED initializes in the off state. Whenever the button is released, the LED's state toggles, switching between on and off.

```cpp
// components
int led_pin = 13;
int button_pin = 2;

// state variables
int button_state = 0;
int last_button_state = 0;
int led_state = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {
  last_button_state = button_state;
  button_state = digitalRead(button_pin);

  if(last_button_state == LOW && button_state == HIGH) {
    if (led_state == 0) {
      digitalWrite(led_pin, HIGH);
      led_state = 1;
    } else {
      digitalWrite(led_pin, LOW);
      led_state = 0;
    }
  }

}
```

While functional, this code is somewhat verbose and requires manual management of both button and LED states. Utilizing the Abstract Component Library simplifies the code, providing a clearer and more concise solution, with the library managing state transitions.

```cpp
#include <Components.h>

Led led(13);
Button button(2);


void setup() {
  led.setup();
  button.setup();
}

void loop() {
  button.update();

  if(button.was_released()) {
    led.alternate();
  }

}

```

By leveraging the library, the code becomes more straightforward and easier to understand, as the library encapsulates the complexities of state management for the components.
