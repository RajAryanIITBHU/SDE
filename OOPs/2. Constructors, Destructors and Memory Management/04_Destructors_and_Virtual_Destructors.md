# 4. Destructors and Virtual Destructors

## What is a Destructor?
A **Destructor** is a member function automatically invoked when an object goes out of scope or is explicitly deleted, used to release acquired resources (heap memory, open files, network sockets).

---

## 1. Why Base Class Destructors MUST Be `virtual` in C++ (Top Interview Question!)

### The Scenario:
Suppose we create a derived object on the heap and store it in a **base class pointer**:

```cpp
Base* ptr = new Derived();
delete ptr; // DANGER if Base destructor is NOT virtual!
```

### What Happens Without `virtual` Destructor?
1. The compiler performs **Static Binding**.
2. Only `~Base()` executes!
3. **`~Derived()` is NEVER called**, causing a **severe memory/resource leak** for any memory allocated inside `Derived`!

### Code Example:
```cpp
#include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    // VIRTUAL DESTRUCTOR ensures derived destructor runs first
    virtual ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
private:
    int* buffer;
public:
    Derived() : buffer(new int[100]) { cout << "Derived Constructor (Allocated 100 ints)\n"; }
    ~Derived() override {
        delete[] buffer;
        cout << "Derived Destructor (Freed 100 ints)\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Properly calls: ~Derived() -> ~Base()
    return 0;
}
```

---

## 2. Python Destructors: `__del__` & Garbage Collection

Python uses **Reference Counting** supplemented by a **Cyclic Garbage Collector**:
- `__del__` is called when an object's reference count drops to `0`.

```python
class ResourceHolder:
    def __init__(self, name: str):
        self.name = name
        print(f"Resource '{self.name}' acquired.")

    def __del__(self):
        # Destructor / Finalizer
        print(f"Resource '{self.name}' released / destroyed.")


if __name__ == "__main__":
    res1 = ResourceHolder("DatabaseConnection")
    res2 = res1 # Reference count = 2
    del res1    # Reference count = 1 (Not destroyed yet)
    print("res1 deleted...")
    del res2    # Reference count = 0 -> __del__() triggered!
    print("res2 deleted...")
```
