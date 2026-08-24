# 2. Encapsulation and Access Modifiers

## What is Encapsulation?
**Encapsulation** is the bundling of data (attributes) and the methods that operate on that data into a **single unit (Class)**, while **restricting direct outside access** to the internal state (**Data Hiding**).

---

## 3 Standard Access Modifiers

| Access Modifier | Within Same Class | Derived (Child) Class | Outside World / Main |
| :--- | :---: | :---: | :---: |
| **`public`** | ✅ Accessible | ✅ Accessible | ✅ Accessible |
| **`protected`** | ✅ Accessible | ✅ Accessible | ❌ Hidden |
| **`private`** | ✅ Accessible | ❌ Hidden | ❌ Hidden |

---

## 1. C++ Implementation

In C++, access specifiers are strictly enforced by the compiler.

```cpp
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    // Data Hiding: Cannot be accessed or modified directly from outside
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    // Getter (Read-Only access)
    double getBalance() const {
        return balance;
    }

    // Setter with Business Validation Rules
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << ", New Balance: $" << balance << "\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << ", Remaining Balance: $" << balance << "\n";
            return true;
        }
        cout << "Insufficient funds or invalid withdrawal amount!\n";
        return false;
    }
};

int main() {
    BankAccount account("ACC-12345", 1000.0);
    // account.balance = 50000; // COMPILE ERROR! balance is private
    account.deposit(500.0);
    account.withdraw(300.0);
    cout << "Current Balance: $" << account.getBalance() << "\n";
    return 0;
}
```

---

## 2. Python Implementation & Name Mangling

Python does not have strict keyword-based access modifiers. Instead, it uses naming conventions:
- `var` $\to$ **Public**
- `_var` $\to$ **Protected** (Convention indicating internal use only)
- `__var` $\to$ **Private** (**Name Mangling:** Python internally renames `__var` to `_ClassName__var` to prevent accidental overwrites).

```python
class BankAccount:
    def __init__(self, account_number: str, initial_balance: float):
        self._account_number = account_number  # Protected
        self.__balance = initial_balance if initial_balance >= 0 else 0.0  # Private (Name Mangled)

    # Getter using @property decorator
    @property
    def balance(self) -> float:
        return self.__balance

    # Controlled deposit method
    def deposit(self, amount: float) -> None:
        if amount > 0:
            self.__balance += amount
            print(f"Deposited: ${amount}, New Balance: ${self.__balance}")
        else:
            print("Invalid deposit amount!")

    # Controlled withdrawal method
    def withdraw(self, amount: float) -> bool:
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            print(f"Withdrew: ${amount}, Remaining Balance: ${self.__balance}")
            return True
        print("Insufficient funds or invalid amount!")
        return False


if __name__ == "__main__":
    account = BankAccount("ACC-12345", 1000.0)

    # print(account.__balance) # Raises AttributeError: 'BankAccount' object has no attribute '__balance'
    
    # Access via property getter
    print("Balance via getter:", account.balance)

    # Name mangling inspection (Python allows accessing via _BankAccount__balance)
    print("Name mangled internal access:", account._BankAccount__balance)

    account.deposit(500.0)
    account.withdraw(300.0)
```
