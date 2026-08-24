# 4. Object Slicing and Type Casting

## 1. What is Object Slicing in C++?
**Object Slicing** happens in C++ when a **derived class object is assigned to a base class object by value** (instead of via a pointer or reference).

- **Result:** The derived-specific member variables are **"sliced off" (discarded)**, and only the base part of the object is copied into the base instance. Polymorphism is lost!

```cpp
#include <iostream>

using namespace std;

class Base {
public:
    int a = 10;
    virtual void print() { cout << "Base a: " << a << "\n"; }
};

class Derived : public Base {
public:
    int b = 20;
    void print() override { cout << "Derived a: " << a << ", b: " << b << "\n"; }
};

int main() {
    Derived d;

    // OBJECT SLICING OCCURS HERE:
    Base b = d; // 'd' is sliced! Derived member 'b' is completely lost.
    b.print();  // Calls Base::print() -> "Base a: 10"

    // HOW TO PREVENT SLICING: Use Pointers or References!
    Base& ref = d;
    ref.print(); // Calls Derived::print() -> "Derived a: 10, b: 20"
    return 0;
}
```

---

## 2. C++ Casting Operators

| Cast Operator | When to Use | Safety Check |
| :--- | :--- | :--- |
| **`static_cast<Type>`** | Standard compile-time conversions (e.g., `int` to `double`, upcasting derived to base pointer). | Compile-time check only. |
| **`dynamic_cast<Type>`** | Safe **downcasting** of polymorphic pointers/references at runtime (requires `vtable`). | Returns `nullptr` if cast fails. |
| **`const_cast<Type>`** | Casting away `const` or `volatile` qualifiers. | Unsafe if underlying object is truly const. |
| **`reinterpret_cast<Type>`** | Low-level bit reinterpretation (e.g., pointer to integer). | Completely unsafe. |

```cpp
Base* basePtr = new Derived();
// Safe dynamic downcasting
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr) {
    cout << "Downcast succeeded! b = " << derivedPtr->b << "\n";
}
delete basePtr;
```

---

## 3. Python: Dynamic Typing & `isinstance()`
Python has no object slicing because all variables are **references on the heap**:

```python
class Base:
    pass

class Derived(Base):
    def __init__(self):
        self.b = 20

d = Derived()
b = d # Both point to the exact same object on the heap (No slicing!)
print(isinstance(b, Base))    # True
print(isinstance(b, Derived)) # True
```
