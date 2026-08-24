# 1. Classes and Objects in C++ and Python

## What is Object-Oriented Programming (OOP)?
**Object-Oriented Programming (OOP)** is a programming paradigm based on the concept of **"Objects"**, which contain:
1. **State / Attributes (Data fields)**
2. **Behavior / Methods (Functions operating on the data)**

---

## Class vs. Object

| Feature | Class | Object |
| :--- | :--- | :--- |
| **Definition** | A user-defined **blueprint / template** | An **instance** created from the class |
| **Memory Allocation** | Consumes **no memory** (except type metadata) | Consumes **actual memory in RAM** (Heap/Stack) |
| **Analogy** | Architectural blueprint of a house | The actual physical brick-and-mortar house |

---

## 1. C++ Implementation

In C++, classes are statically typed. Objects can be created on the **Stack** (automatically destroyed when out of scope) or on the **Heap** (via `new`, manually freed via `delete`).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    // State / Attributes
    string brand;
    int speed;

public:
    // Constructor
    Car(string b, int s) : brand(b), speed(s) {}

    // Behavior / Method
    void accelerate(int increase) {
        speed += increase;
        cout << brand << " accelerating to " << speed << " km/h\n";
    }

    void displayInfo() const {
        cout << "Car Brand: " << brand << ", Current Speed: " << speed << " km/h\n";
    }
};

int main() {
    // 1. Stack Allocation
    Car car1("Tesla", 80);
    car1.accelerate(20);
    car1.displayInfo();

    // 2. Heap Allocation
    Car* car2 = new Car("BMW", 100);
    car2->accelerate(30);
    car2->displayInfo();
    delete car2; // Clean up heap memory

    return 0;
}
```

---

## 2. Python Implementation

In Python, classes are dynamically typed, and everything is an object in heap memory. Methods explicitly take `self` as their first parameter.

```python
class Car:
    # State / Attributes initialized in __init__
    def __init__(self, brand: str, speed: int):
        self.brand = brand      # Instance variable
        self.speed = speed      # Instance variable

    # Behavior / Method
    def accelerate(self, increase: int) -> None:
        self.speed += increase
        print(f"{self.brand} accelerating to {self.speed} km/h")

    def display_info(self) -> None:
        print(f"Car Brand: {self.brand}, Current Speed: {self.speed} km/h")


# Instantiation
if __name__ == "__main__":
    car1 = Car("Tesla", 80)
    car1.accelerate(20)
    car1.display_info()

    car2 = Car("BMW", 100)
    car2.accelerate(30)
    car2.display_info()
```

---

## Key Differences: C++ vs. Python

| Feature | C++ | Python |
| :--- | :--- | :--- |
| **Object Instantiation** | Stack (`Car c;`) or Heap (`Car* c = new Car();`) | Always dynamically allocated on Heap |
| **`this` vs. `self`** | Implicit pointer `this->` | Explicit first argument `self` in methods |
| **Memory Cleanup** | Manual (`delete` / RAII / Smart Pointers) | Automatic Garbage Collection (Reference Counting + Cyclic GC) |
| **Class Size in Memory** | Sum of member sizes + alignment padding + `vptr` (if virtual) | Dynamic dictionary `__dict__` overhead |
