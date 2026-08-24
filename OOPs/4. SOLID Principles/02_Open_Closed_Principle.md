# 2. Open / Closed Principle (OCP)

## Definition
> **"Software entities (classes, modules, functions) should be OPEN for extension, but CLOSED for modification."**  
> — Bertrand Meyer

You should be able to introduce new functionality without modifying existing, battle-tested source code (achieved using **Polymorphism and Interfaces**).

---

## 1. OCP Violation Example

```cpp
// BAD DESIGN: Modifying class whenever a new payment method arrives
class PaymentProcessorBad {
public:
    void pay(string type, double amount) {
        if (type == "CreditCard") { /* ... */ }
        else if (type == "PayPal") { /* ... */ }
        else if (type == "Crypto") { /* Had to modify existing code! */ }
    }
};
```

---

## 2. Refactored Solution (C++ & Python)

### C++:
```cpp
#include <iostream>
#include <memory>

using namespace std;

// 1. Interface open for extension
class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

// 2. Concrete Extensions (No modification of existing classes needed!)
class CreditCardPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processed $" << amount << " via Credit Card.\n";
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processed $" << amount << " via PayPal.\n";
    }
};

class CryptoPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processed $" << amount << " via Bitcoin / Crypto.\n";
    }
};

// 3. Payment Processor remains closed for modification
class PaymentService {
public:
    void execute(PaymentMethod* method, double amount) {
        method->processPayment(amount);
    }
};

int main() {
    PaymentService service;
    CreditCardPayment cc;
    CryptoPayment crypto;

    service.execute(&cc, 150.0);
    service.execute(&crypto, 500.0);
    return 0;
}
```

### Python:
```python
from abc import ABC, abstractmethod


class PaymentMethod(ABC):
    @abstractmethod
    def process_payment(self, amount: float) -> None:
        pass


class CreditCardPayment(PaymentMethod):
    def process_payment(self, amount: float) -> None:
        print(f"Processed ${amount} via Credit Card.")


class CryptoPayment(PaymentMethod):
    def process_payment(self, amount: float) -> None:
        print(f"Processed ${amount} via Crypto.")


class PaymentService:
    def execute(self, method: PaymentMethod, amount: float) -> None:
        method.process_payment(amount)


if __name__ == "__main__":
    service = PaymentService()
    service.execute(CreditCardPayment(), 150.0)
    service.execute(CryptoPayment(), 500.0)
```
