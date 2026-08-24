# 2. Static Members & Methods: C++ vs. Python

## What are Static Members?
**Static Members (Variables and Methods)** belong to the **Class itself**, rather than to any individual object instance. They are shared across all instances of the class.

---

## 1. C++ Implementation (`static` variables & `static` methods)

- A `static` variable has only **one physical copy in memory**, stored in the static/global data segment.
- A `static` method can **only access static member variables** (it has no `this` pointer).

```cpp
#include <iostream>

using namespace std;

class User {
private:
    string username;
    static int userCount; // Declaration of static member variable

public:
    User(string name) : username(name) {
        userCount++;
    }

    ~User() {
        userCount--;
    }

    // Static Member Function
    static int getUserCount() {
        // username = "test"; // COMPILE ERROR! No 'this' pointer in static methods
        return userCount;
    }
};

// Definition and initialization of static variable outside the class
int User::userCount = 0;

int main() {
    cout << "Initial Users: " << User::getUserCount() << "\n";
    User u1("Alice");
    User u2("Bob");
    cout << "Active Users: " << User::getUserCount() << "\n"; // Output: 2
    return 0;
}
```

---

## 2. Python Implementation (`@staticmethod` vs. `@classmethod`)

Python distinguishes between **Class Methods** (receive `cls`) and **Static Methods** (independent utilities):

```python
class User:
    user_count = 0  # Class variable (shared across all instances)

    def __init__(self, username: str):
        self.username = username
        User.user_count += 1

    # 1. Class Method: Has access to class state via 'cls'
    @classmethod
    def get_user_count(cls) -> int:
        return cls.user_count

    # 2. Static Method: Pure utility function with no access to self or cls
    @staticmethod
    def is_valid_username(name: str) -> bool:
        return len(name) >= 3 and name.isalnum()


if __name__ == "__main__":
    print("Is 'al' valid?", User.is_valid_username("al"))       # False
    print("Is 'alice' valid?", User.is_valid_username("alice")) # True

    u1 = User("Alice")
    u2 = User("Bob")
    print("Total Active Users:", User.get_user_count())         # 2
```
