# 3. Abstraction and Interfaces in C++ and Python

## What is Abstraction?
**Abstraction** means **hiding complex internal implementation details** and exposing only the essential features/interfaces to the user.

- **Analogy:** When you press the brake pedal in a car, you know the car will slow down. You do not need to understand hydraulic brake fluid pressure or caliper mechanics.

---

## Abstract Classes & Interfaces

- **Abstract Class:** A class that cannot be directly instantiated and contains at least one pure virtual/abstract method. It serves as a base contract for derived classes.
- **Interface:** A pure abstract class containing **only** method declarations without any implementation or state.

---

## 1. C++ Implementation (Pure Virtual Functions)

In C++, an abstract class contains at least one **Pure Virtual Function** (`virtual void func() = 0;`).

```cpp
#include <iostream>
#include <vector>

using namespace std;

// Abstract Class / Interface
class Shape {
public:
    // Pure Virtual Function
    virtual double area() const = 0;
    virtual void draw() const = 0;

    // Virtual Destructor (Crucial for proper cleanup)
    virtual ~Shape() {}
};

// Derived Concrete Class 1
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "Drawing Circle of radius " << radius << ", Area: " << area() << "\n";
    }
};

// Derived Concrete Class 2
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        cout << "Drawing Rectangle " << width << "x" << height << ", Area: " << area() << "\n";
    }
};

int main() {
    // Shape s; // COMPILE ERROR! Cannot instantiate abstract class

    // Polymorphic collection
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    for (Shape* s : shapes) {
        s->draw();
    }

    for (Shape* s : shapes) delete s;
    return 0;
}
```

---

## 2. Python Implementation (`abc.ABC` & `@abstractmethod`)

In Python, abstract base classes are defined by inheriting from `abc.ABC` and using the `@abstractmethod` decorator.

```python
from abc import ABC, abstractmethod
import math


# Abstract Base Class (Interface)
class Shape(ABC):
    @abstractmethod
    def area(self) -> float:
        """Calculate the area of the shape."""
        pass

    @abstractmethod
    def draw(self) -> None:
        """Render the shape."""
        pass


# Concrete Implementation 1
class Circle(Shape):
    def __init__(self, radius: float):
        self.radius = radius

    def area(self) -> float:
        return math.pi * self.radius ** 2

    def draw(self) -> None:
        print(f"Drawing Circle of radius {self.radius}, Area: {self.area():.2f}")


# Concrete Implementation 2
class Rectangle(Shape):
    def __init__(self, width: float, height: float):
        self.width = width
        self.height = height

    def area(self) -> float:
        return self.width * self.height

    def draw(self) -> None:
        print(f"Drawing Rectangle {self.width}x{self.height}, Area: {self.area():.2f}")


if __name__ == "__main__":
    # shape = Shape() # TypeError: Can't instantiate abstract class Shape with abstract methods

    shapes = [Circle(5.0), Rectangle(4.0, 6.0)]
    for shape in shapes:
        shape.draw()
```
