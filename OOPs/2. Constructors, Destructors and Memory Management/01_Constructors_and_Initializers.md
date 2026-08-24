# 1. Constructors and Initializers in C++ and Python

## What is a Constructor?
A **Constructor** is a special member function that is automatically invoked whenever a new instance/object of a class is created, primarily responsible for initializing the object's member variables.

---

## 1. C++ Constructors & Member Initializer Lists

C++ supports multiple overloaded constructor types:

```cpp
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    const int admissionYear; // Const members MUST be initialized via initializer list

public:
    // 1. Default Constructor
    Student() : name("Unknown"), rollNo(0), admissionYear(2026) {
        cout << "Default Constructor called\n";
    }

    // 2. Parameterized Constructor with Initializer List (Direct Initialization)
    Student(string n, int r, int year) 
        : name(n), rollNo(r), admissionYear(year) {
        cout << "Parameterized Constructor called for " << name << "\n";
    }

    void display() const {
        cout << "Student: " << name << ", Roll: " << rollNo << ", Year: " << admissionYear << "\n";
    }
};

int main() {
    Student s1; // Default
    Student s2("Alice", 101, 2026); // Parameterized
    s1.display();
    s2.display();
    return 0;
}
```

### Why use Member Initializer Lists in C++?
1. **Performance:** Initializes member variables directly, avoiding redundant default construction followed by assignment.
2. **Mandatory Cases:** Initializing `const` members, reference members (`int&`), or base class constructors with arguments.

---

## 2. Python: `__new__` vs. `__init__`

In Python, object creation is a 2-step process:
1. **`__new__(cls, ...)`:** The **actual Creator** method that allocates memory and returns the new instance.
2. **`__init__(self, ...)`:** The **Initializer** method that receives the created instance and sets attributes.

```python
class Student:
    # 1. __new__ creates the object in memory
    def __new__(cls, *args, **kwargs):
        print("1. __new__ allocated memory for Student instance")
        instance = super().__new__(cls)
        return instance

    # 2. __init__ initializes the instance's state
    def __init__(self, name: str = "Unknown", roll_no: int = 0, year: int = 2026):
        print(f"2. __init__ initializing state for {name}")
        self.name = name
        self.roll_no = roll_no
        self.year = year

    def display(self) -> None:
        print(f"Student: {self.name}, Roll: {self.roll_no}, Year: {self.year}")


if __name__ == "__main__":
    s1 = Student()
    s2 = Student("Alice", 101, 2026)
    s2.display()
```
