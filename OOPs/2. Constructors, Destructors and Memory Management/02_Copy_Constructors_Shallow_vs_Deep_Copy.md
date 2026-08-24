# 2. Copy Constructors: Shallow Copy vs. Deep Copy

## Shallow Copy vs. Deep Copy (High-Frequency Interview Question)

```
 SHALLOW COPY (Pointers Copied Directly)       DEEP COPY (New Heap Memory Allocated)
+-------------+                              +-------------+
| Object A    |                              | Object A    |
| data_ptr    | -----\                       | data_ptr    | ------> [ Heap Memory A (Data) ]
+-------------+       +--> [ Heap Memory ]   +-------------+
| Object B    | -----/     (Shared Buffer)   | Object B    |
| data_ptr    |                              | data_ptr    | ------> [ Heap Memory B (Data Copy) ]
+-------------+                              +-------------+
```

- **Shallow Copy:** Copies member values bit-by-bit. If members include pointers/references, both objects point to the **same physical memory block**.
  - **Danger (Double Free Error):** When both objects go out of scope, both destructors call `delete` on the same pointer, causing a crash!
- **Deep Copy:** Allocates a **new block of heap memory** and copies the actual contents into it.

---

## 1. C++ Implementation & Copy Constructor

```cpp
#include <iostream>
#include <cstring>

using namespace std;

class StringHolder {
private:
    char* str;

public:
    // Parameterized Constructor
    StringHolder(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Custom Deep Copy Constructor
    StringHolder(const StringHolder& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        cout << "Deep Copy Constructor executed\n";
    }

    // Custom Deep Copy Assignment Operator
    StringHolder& operator=(const StringHolder& other) {
        if (this != &other) { // Guard against self-assignment
            delete[] str;     // Free old memory
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void modify(char newChar) { str[0] = newChar; }
    void print() const { cout << "String: " << str << "\n"; }

    // Destructor
    ~StringHolder() {
        delete[] str;
    }
};

int main() {
    StringHolder s1("Microsoft");
    StringHolder s2 = s1; // Calls Deep Copy Constructor

    s2.modify('W');
    s1.print(); // String: Microsoft (Untouched!)
    s2.print(); // String: Wicrosoft
    return 0;
}
```

---

## 2. Python Implementation (`copy.copy` vs. `copy.deepcopy`)

```python
import copy


class Person:
    def __init__(self, name: str, hobbies: list):
        self.name = name
        self.hobbies = hobbies  # Mutable reference


if __name__ == "__main__":
    original = Person("Alice", ["Coding", "Chess"])

    # 1. Shallow Copy (Copies reference to list)
    shallow_obj = copy.copy(original)
    shallow_obj.hobbies.append("Gaming")

    print("Original hobbies after shallow copy mod:", original.hobbies)
    # Output: ['Coding', 'Chess', 'Gaming'] -> Corrupted!

    # 2. Deep Copy (Recursively creates a new list)
    deep_obj = copy.deepcopy(original)
    deep_obj.hobbies.append("Swimming")

    print("Original hobbies after deep copy mod:", original.hobbies)
    # Output: ['Coding', 'Chess', 'Gaming'] -> Safe!
    print("Deep object hobbies:", deep_obj.hobbies)
    # Output: ['Coding', 'Chess', 'Gaming', 'Swimming']
```
