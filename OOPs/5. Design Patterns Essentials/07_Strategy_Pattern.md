# 7. Strategy Design Pattern (Behavioral)

## Intent
Define a family of algorithms, encapsulate each one as a separate class, and make them **interchangeable at runtime**. Strategy lets the algorithm vary independently from clients that use it.

---

## 1. C++ Implementation (Payment / Discount Strategy)

```cpp
#include <iostream>
#include <memory>

using namespace std;

// Strategy Interface
class DiscountStrategy {
public:
    virtual double applyDiscount(double rawAmount) const = 0;
    virtual ~DiscountStrategy() {}
};

// Concrete Strategy 1: Regular (No discount)
class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double rawAmount) const override { return rawAmount; }
};

// Concrete Strategy 2: Student Discount (20% off)
class StudentDiscount : public DiscountStrategy {
public:
    double applyDiscount(double rawAmount) const override { return rawAmount * 0.80; }
};

// Concrete Strategy 3: VIP Member Discount (40% off)
class VIPDiscount : public DiscountStrategy {
public:
    double applyDiscount(double rawAmount) const override { return rawAmount * 0.60; }
};

// Context Class
class ShoppingCart {
private:
    unique_ptr<DiscountStrategy> strategy;
    double totalAmount;

public:
    ShoppingCart(double amount) : totalAmount(amount), strategy(make_unique<NoDiscount>()) {}

    // Switch strategy dynamically at runtime!
    void setDiscountStrategy(unique_ptr<DiscountStrategy> newStrategy) {
        strategy = move(newStrategy);
    }

    double calculateFinalTotal() const {
        return strategy->applyDiscount(totalAmount);
    }
};

int main() {
    ShoppingCart cart(1000.0);
    cout << "Standard Total: $" << cart.calculateFinalTotal() << "\n";

    // Customer logs in as Student
    cart.setDiscountStrategy(make_unique<StudentDiscount>());
    cout << "Student Final Total: $" << cart.calculateFinalTotal() << "\n"; // $800

    // Customer upgrades to VIP
    cart.setDiscountStrategy(make_unique<VIPDiscount>());
    cout << "VIP Final Total: $" << cart.calculateFinalTotal() << "\n"; // $600
    return 0;
}
```

---

## 2. Python Implementation

```python
from abc import ABC, abstractmethod


# Strategy Interface
class DiscountStrategy(ABC):
    @abstractmethod
    def apply_discount(self, raw_amount: float) -> float:
        pass


class NoDiscount(DiscountStrategy):
    def apply_discount(self, raw_amount: float) -> float:
        return raw_amount


class StudentDiscount(DiscountStrategy):
    def apply_discount(self, raw_amount: float) -> float:
        return raw_amount * 0.80


class VIPDiscount(DiscountStrategy):
    def apply_discount(self, raw_amount: float) -> float:
        return raw_amount * 0.60


# Context
class ShoppingCart:
    def __init__(self, amount: float):
        self.amount = amount
        self._strategy: DiscountStrategy = NoDiscount()

    def set_discount_strategy(self, strategy: DiscountStrategy) -> None:
        self._strategy = strategy

    def calculate_final_total(self) -> float:
        return self._strategy.apply_discount(self.amount)


if __name__ == "__main__":
    cart = ShoppingCart(1000.0)
    print(f"Standard Total: ${cart.calculate_final_total():.2f}")

    cart.set_discount_strategy(StudentDiscount())
    print(f"Student Final Total: ${cart.calculate_final_total():.2f}")  # $800

    cart.set_discount_strategy(VIPDiscount())
    print(f"VIP Final Total: ${cart.calculate_final_total():.2f}")  # $600
```
