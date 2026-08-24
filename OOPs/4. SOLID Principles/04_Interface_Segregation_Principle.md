# 4. Interface Segregation Principle (ISP)

## Definition
> **"Clients should not be forced to depend upon interfaces that they do not use."**  
> — Robert C. Martin

Prefer **many small, role-specific interfaces** over one single bloated "fat" interface.

---

## 1. ISP Violation Example

```cpp
// BAD DESIGN: Fat interface forces Robot to implement eat()!
class WorkerBad {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class RobotWorker : public WorkerBad {
public:
    void work() override { cout << "Robot working...\n"; }
    void eat() override { /* Robots don't eat! Forced to write dummy code! */ }
};
```

---

## 2. Refactored Solution (C++ & Python)

Segregate into two lean interfaces: `Workable` and `Eatable`.

### C++:
```cpp
#include <iostream>

using namespace std;

// Segregated Interface 1
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

// Segregated Interface 2
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

// Human implements both
class HumanWorker : public Workable, public Eatable {
public:
    void work() override { cout << "Human working...\n"; }
    void eat() override { cout << "Human eating lunch...\n"; }
};

// Robot implements only Workable
class RobotWorker : public Workable {
public:
    void work() override { cout << "Robot working 24/7 without eating!\n"; }
};

int main() {
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();

    robot.work();
    return 0;
}
```

### Python:
```python
from abc import ABC, abstractmethod


class Workable(ABC):
    @abstractmethod
    def work(self) -> None:
        pass


class Eatable(ABC):
    @abstractmethod
    def eat(self) -> None:
        pass


class HumanWorker(Workable, Eatable):
    def work(self) -> None:
        print("Human working...")

    def eat(self) -> None:
        print("Human eating lunch...")


class RobotWorker(Workable):
    def work(self) -> None:
        print("Robot working 24/7 without eating!")


if __name__ == "__main__":
    human = HumanWorker()
    robot = RobotWorker()

    human.work()
    human.eat()
    robot.work()
```
