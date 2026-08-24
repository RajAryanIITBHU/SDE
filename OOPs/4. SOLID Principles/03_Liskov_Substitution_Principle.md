# 3. Liskov Substitution Principle (LSP)

## Definition
> **"Subtypes must be substitutable for their base types without altering the correctness of the program."**  
> — Barbara Liskov

If class $B$ is a subtype of class $A$, then any instance of $A$ can be replaced with an instance of $B$ without breaking the application logic.

---

## 1. Classic LSP Violation: The Square-Rectangle Problem

In mathematics, a Square is a Rectangle. But in OOP:

```cpp
// BAD DESIGN: Square breaks Rectangle's behavioral contract!
class Rectangle {
protected:
    int width, height;
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    int getArea() const { return width * height; }
};

class Square : public Rectangle {
public:
    void setWidth(int w) override { width = height = w; } // Mutates height unexpectedly!
    void setHeight(int h) override { width = height = h; }
};

void testArea(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(4);
    // Expected: 5 * 4 = 20. But for Square: 4 * 4 = 16! FAILS LSP!
}
```

---

## 2. Refactored Solution (C++ & Python)

Make both inherit from an abstract `Shape` interface:

### C++:
```cpp
#include <iostream>

using namespace std;

class Shape {
public:
    virtual int getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int getArea() const override { return width * height; }
};

class Square : public Shape {
private:
    int side;
public:
    Square(int s) : side(s) {}
    int getArea() const override { return side * side; }
};

int main() {
    Rectangle rect(5, 4);
    Square sq(4);

    cout << "Rectangle Area: " << rect.getArea() << "\n"; // 20
    cout << "Square Area: " << sq.getArea() << "\n";       // 16
    return 0;
}
```

### Python:
```python
from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def get_area(self) -> int:
        pass


class Rectangle(Shape):
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

    def get_area(self) -> int:
        return self.width * self.height


class Square(Shape):
    def __init__(self, side: int):
        self.side = side

    def get_area(self) -> int:
        return self.side * self.side


if __name__ == "__main__":
    shapes = [Rectangle(5, 4), Square(4)]
    for shape in shapes:
        print(f"Area: {shape.get_area()}")
```
