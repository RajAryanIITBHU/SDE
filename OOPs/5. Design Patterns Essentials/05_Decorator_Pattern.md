# 5. Decorator Design Pattern (Structural)

## Intent
Attach additional responsibilities and behaviors to an object **dynamically at runtime without altering its structure**, providing a flexible alternative to subclassing.

---

## 1. C++ Implementation (Classic Coffee / Toppings Example)

```cpp
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Component Interface
class Beverage {
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Beverage() {}
};

// Concrete Component
class SimpleCoffee : public Beverage {
public:
    string getDescription() const override { return "Simple Coffee"; }
    double getCost() const override { return 2.00; }
};

// Base Decorator
class BeverageDecorator : public Beverage {
protected:
    unique_ptr<Beverage> beverage;
public:
    BeverageDecorator(unique_ptr<Beverage> b) : beverage(move(b)) {}
};

// Concrete Decorator 1: Milk
class MilkDecorator : public BeverageDecorator {
public:
    MilkDecorator(unique_ptr<Beverage> b) : BeverageDecorator(move(b)) {}
    string getDescription() const override { return beverage->getDescription() + " + Milk"; }
    double getCost() const override { return beverage->getCost() + 0.50; }
};

// Concrete Decorator 2: Caramel
class CaramelDecorator : public BeverageDecorator {
public:
    CaramelDecorator(unique_ptr<Beverage> b) : BeverageDecorator(move(b)) {}
    string getDescription() const override { return beverage->getDescription() + " + Caramel"; }
    double getCost() const override { return beverage->getCost() + 0.75; }
};

int main() {
    // Dynamically wrap coffee with Milk and Caramel!
    unique_ptr<Beverage> myCoffee = make_unique<SimpleCoffee>();
    myCoffee = make_unique<MilkDecorator>(move(myCoffee));
    myCoffee = make_unique<CaramelDecorator>(move(myCoffee));

    cout << "Order: " << myCoffee->getDescription() << "\n";
    cout << "Total Cost: $" << myCoffee->getCost() << "\n"; // $3.25
    return 0;
}
```

---

## 2. Python Implementation

```python
from abc import ABC, abstractmethod


class Beverage(ABC):
    @abstractmethod
    def get_description(self) -> str:
        pass

    @abstractmethod
    def get_cost(self) -> float:
        pass


class SimpleCoffee(Beverage):
    def get_description(self) -> str:
        return "Simple Coffee"

    def get_cost(self) -> float:
        return 2.00


class BeverageDecorator(Beverage):
    def __init__(self, beverage: Beverage):
        self._beverage = beverage


class MilkDecorator(BeverageDecorator):
    def get_description(self) -> str:
        return self._beverage.get_description() + " + Milk"

    def get_cost(self) -> float:
        return self._beverage.get_cost() + 0.50


class CaramelDecorator(BeverageDecorator):
    def get_description(self) -> str:
        return self._beverage.get_description() + " + Caramel"

    def get_cost(self) -> float:
        return self._beverage.get_cost() + 0.75


if __name__ == "__main__":
    coffee = SimpleCoffee()
    coffee = MilkDecorator(coffee)
    coffee = CaramelDecorator(coffee)

    print("Order:", coffee.get_description())
    print(f"Total Cost: ${coffee.get_cost():.2f}")  # $3.25
```
