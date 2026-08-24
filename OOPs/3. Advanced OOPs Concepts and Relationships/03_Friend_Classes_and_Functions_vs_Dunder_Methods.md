# 3. Friend Functions/Classes (C++) vs. Dunder Methods (Python)

## 1. C++: `friend` Functions and `friend` Classes

In C++, a **`friend`** function or class is granted **full access to private and protected members** of another class without being a member itself.

### Rules:
1. Friendship is **not mutual** (if A is a friend of B, B is not automatically a friend of A).
2. Friendship is **not inherited** (a child of a friend is not a friend).

```cpp
#include <iostream>

using namespace std;

class BankAccount {
private:
    double secretBalance;

public:
    BankAccount(double b) : secretBalance(b) {}

    // Friend Function declaration
    friend void auditorCheck(const BankAccount& account);

    // Friend Class declaration
    friend class TaxInspector;
};

void auditorCheck(const BankAccount& account) {
    // Direct access to private member secretBalance!
    cout << "[Auditor] Verified balance: $" << account.secretBalance << "\n";
}

class TaxInspector {
public:
    void inspect(const BankAccount& acc) {
        cout << "[Tax Inspector] Auditing secret balance: $" << acc.secretBalance << "\n";
    }
};

int main() {
    BankAccount myAccount(50000.0);
    auditorCheck(myAccount);

    TaxInspector inspector;
    inspector.inspect(myAccount);
    return 0;
}
```

---

## 2. Python: Magic / Dunder (Double Underscore) Methods

Python achieves internal hooks and customization through standardized **Dunder Methods**:

| Dunder Method | Operation / Purpose |
| :--- | :--- |
| `__str__(self)` | Human-readable string representation (`str(obj)`, `print(obj)`) |
| `__repr__(self)` | Unambiguous official representation for debugging (`repr(obj)`) |
| `__len__(self)` | Enables `len(obj)` |
| `__eq__(self, other)` | Enables `==` comparison |
| `__lt__(self, other)` | Enables `<` sorting / comparison |
| `__getitem__(self, key)` | Enables dictionary / list indexing `obj[key]` |

```python
class Book:
    def __init__(self, title: str, pages: int):
        self.title = title
        self.pages = pages

    def __str__(self) -> str:
        return f"'{self.title}' ({self.pages} pages)"

    def __len__(self) -> int:
        return self.pages

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Book):
            return self.title == other.title and self.pages == other.pages
        return False


if __name__ == "__main__":
    b1 = Book("Clean Code", 464)
    b2 = Book("Clean Code", 464)

    print(b1)               # Calls __str__: 'Clean Code' (464 pages)
    print("Page count:", len(b1)) # Calls __len__: 464
    print("Are equal?", b1 == b2) # Calls __eq__: True
```
