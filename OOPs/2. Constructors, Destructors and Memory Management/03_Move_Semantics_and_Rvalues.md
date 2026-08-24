# 3. Move Semantics & Rvalues (C++11 Optimization)

## Why Move Semantics?
In C++98, returning large objects (e.g., `vector<int>` with 10 million elements) from a function resulted in an **expensive deep copy** to a temporary object, followed by destroying the original.

**Move Semantics (introduced in C++11)** allows an object to **steal / transfer ownership of resources** from a temporary object (**Rvalue**) without copying any underlying memory buffers.

---

## Lvalues vs. Rvalues

| Value Category | Definition | Example |
| :--- | :--- | :--- |
| **Lvalue (Left Value)** | Has an identifiable memory address; persists beyond a single expression. | `int x = 10;`, `str` |
| **Rvalue (Right Value)** | Temporary, transient value with no persistent name; destroyed at expression end. | `10`, `x + y`, `StringHolder("temp")` |

- **Lvalue Reference:** `Type&` (binds to lvalues)
- **Rvalue Reference:** `Type&&` (binds specifically to temporary rvalues)

---

## C++ Implementation: Move Constructor & Move Assignment

```cpp
#include <iostream>
#include <vector>
#include <utility> // For std::move

using namespace std;

class DynamicBuffer {
private:
    int* data;
    size_t size;

public:
    // Parameterized Constructor
    DynamicBuffer(size_t s) : size(s), data(new int[s]) {
        cout << "Allocated buffer of size " << size << "\n";
    }

    // Move Constructor (Steals resource from temporary other)
    DynamicBuffer(DynamicBuffer&& other) noexcept 
        : data(other.data), size(other.size) {
        // Leave the source object in a valid, empty state
        other.data = nullptr;
        other.size = 0;
        cout << "Move Constructor executed (0 bytes copied!)\n";
    }

    // Move Assignment Operator
    DynamicBuffer& operator=(DynamicBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data; // Free existing memory

            // Steal ownership
            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
            cout << "Move Assignment executed\n";
        }
        return *this;
    }

    // Destructor
    ~DynamicBuffer() {
        delete[] data; // Safe to delete nullptr
    }
};

int main() {
    DynamicBuffer buf1(1000000); // Heap allocation

    // std::move casts buf1 (lvalue) to an rvalue reference
    DynamicBuffer buf2 = std::move(buf1); // Invokes Move Constructor!

    return 0;
}
```

---

## Python Equivalent: Memory Views and References
*(Python does not require explicit move semantics because Python natively operates with pointer reference assignments and garbage collection).*
