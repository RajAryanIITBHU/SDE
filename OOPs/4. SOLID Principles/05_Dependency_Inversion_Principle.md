# 5. Dependency Inversion Principle (DIP)

## Definition
> **"1. High-level modules should not depend on low-level modules. Both should depend on abstractions."**  
> **"2. Abstractions should not depend on details. Details should depend on abstractions."**  
> — Robert C. Martin

Decouple tightly coupled components using **Dependency Injection** and interfaces.

---

## 1. DIP Violation Example

```cpp
// BAD DESIGN: Switch directly hardcodes a concrete LightBulb
class LightBulb {
public:
    void turnOn() { cout << "Bulb on\n"; }
};

class SwitchBad {
private:
    LightBulb bulb; // Tightly coupled! Cannot control a Fan or TV.
public:
    void toggle() { bulb.turnOn(); }
};
```

---

## 2. Refactored Solution (C++ & Python)

### C++:
```cpp
#include <iostream>

using namespace std;

// 1. Abstraction interface
class SwitchableDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~SwitchableDevice() {}
};

// 2. Low-level concrete implementations
class LightBulb : public SwitchableDevice {
public:
    void turnOn() override { cout << "LightBulb: Glowing bright!\n"; }
    void turnOff() override { cout << "LightBulb: Dark.\n"; }
};

class Fan : public SwitchableDevice {
public:
    void turnOn() override { cout << "Fan: Spinning fast!\n"; }
    void turnOff() override { cout << "Fan: Stopped.\n"; }
};

// 3. High-level module depends ONLY on abstraction (Dependency Injection)
class ElectricSwitch {
private:
    SwitchableDevice* device;
public:
    ElectricSwitch(SwitchableDevice* d) : device(d) {}
    void pressOn() { device->turnOn(); }
    void pressOff() { device->turnOff(); }
};

int main() {
    LightBulb bulb;
    Fan fan;

    ElectricSwitch switch1(&bulb);
    ElectricSwitch switch2(&fan);

    switch1.pressOn();
    switch2.pressOn();
    return 0;
}
```

### Python:
```python
from abc import ABC, abstractmethod


# Abstraction
class SwitchableDevice(ABC):
    @abstractmethod
    def turn_on(self) -> None:
        pass

    @abstractmethod
    def turn_off(self) -> None:
        pass


class LightBulb(SwitchableDevice):
    def turn_on(self) -> None:
        print("LightBulb: Glowing bright!")

    def turn_off(self) -> None:
        print("LightBulb: Dark.")


class Fan(SwitchableDevice):
    def turn_on(self) -> None:
        print("Fan: Spinning fast!")

    def turn_off(self) -> None:
        print("Fan: Stopped.")


# High-level module
class ElectricSwitch:
    def __init__(self, device: SwitchableDevice):
        self.device = device  # Injected dependency

    def press_on(self) -> None:
        self.device.turn_on()

    def press_off(self) -> None:
        self.device.turn_off()


if __name__ == "__main__":
    switch1 = ElectricSwitch(LightBulb())
    switch2 = ElectricSwitch(Fan())

    switch1.press_on()
    switch2.press_on()
```
