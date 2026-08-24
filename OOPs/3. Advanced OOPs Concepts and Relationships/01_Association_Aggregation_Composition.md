# 1. Association, Aggregation & Composition ("Has-A" vs. "Is-A")

In object-oriented design, relationships between classes are classified into two broad categories:
1. **"Is-A" Relationship:** Realized via **Inheritance** (e.g., A `Dog` is an `Animal`).
2. **"Has-A" Relationship:** Realized via **Object Composition / Association** (e.g., A `Car` has an `Engine`).

---

## The Hierarchy of "Has-A" Relationships

```
              ASSOCIATION (Weakest general relationship)
                           |
                           v
              AGGREGATION (Weak "Has-A", Independent Lifetimes)
                           |
                           v
              COMPOSITION (Strong "Has-A", Dependent Lifetimes)
```

---

## 1. Composition (Strong "Has-A" / "Part-Of")
- **Definition:** The container object **owns** the contained object.
- **Lifetime Dependency:** If the parent object is destroyed, **the child object is also destroyed**.
- **Analogy:** A `Human` and a `Heart` (a heart cannot exist independently if the human dies).

### C++ Example:
```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    void start() { cout << "Engine started!\n"; }
};

class Car {
private:
    Engine engine; // Composition: Engine is created and destroyed with the Car
public:
    void drive() {
        engine.start();
        cout << "Car is driving...\n";
    }
};
```

### Python Example:
```python
class Engine:
    def start(self):
        print("Engine started!")


class Car:
    def __init__(self):
        self.engine = Engine()  # Composition

    def drive(self):
        self.engine.start()
        print("Car is driving...")
```

---

## 2. Aggregation (Weak "Has-A")
- **Definition:** The container object references the contained object, but does **not own** its lifecycle.
- **Lifetime Dependency:** If the parent object is destroyed, **the child object continues to exist independently**.
- **Analogy:** A `Department` and a `Teacher` (if the department is closed, the teacher still exists).

### C++ Example:
```cpp
class Teacher {
public:
    string name;
    Teacher(string n) : name(n) {}
};

class Department {
private:
    Teacher* teacher; // Aggregation: Pointer reference; Teacher exists outside
public:
    Department(Teacher* t) : teacher(t) {}
};
```

### Python Example:
```python
class Teacher:
    def __init__(self, name: str):
        self.name = name


class Department:
    def __init__(self, teacher: Teacher):
        self.teacher = teacher  # Aggregation (Injected reference)
```
