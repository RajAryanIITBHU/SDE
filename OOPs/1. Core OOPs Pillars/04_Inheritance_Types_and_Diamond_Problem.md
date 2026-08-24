# 4. Inheritance Types & The Diamond Problem

## What is Inheritance?
**Inheritance** is the mechanism where a **Derived (Child) Class** inherits attributes and methods from a **Base (Parent) Class**, promoting code reusability and establishing an **"Is-A" relationship**.

---

## 5 Types of Inheritance

```
1. SINGLE INHERITANCE:       2. MULTILEVEL INHERITANCE:    3. MULTIPLE INHERITANCE:
      [ Base A ]                   [ Base A ]               [ Base A ]   [ Base B ]
          |                            |                         \           /
          v                            v                          v         v
     [ Derived B ]                [ Class B ]                   [ Derived C ]
                                       |
                                       v
                                  [ Class C ]

4. HIERARCHICAL INHERITANCE:                             5. HYBRID / DIAMOND INHERITANCE:
          [ Base A ]                                              [ Base A ]
         /          \                                            /          \
        v            v                                          v            v
  [ Derived B ] [ Derived C ]                             [ Class B ]    [ Class C ]
                                                                 \          /
                                                                  v        v
                                                                 [ Class D ]
```

---

## The Diamond Problem

When class $D$ inherits from both $B$ and $C$, which both inherit from $A$, $D$ receives **two duplicate copies of $A$'s members**, leading to compiler ambiguity.

---

## 1. C++ Solution: Virtual Base Classes (`virtual public A`)

In C++, using `virtual` inheritance ensures only **one single shared instance of the base class $A$** exists in the derived class $D$.

```cpp
#include <iostream>

using namespace std;

class Animal {
public:
    int health;
    Animal() : health(100) { cout << "Animal Constructor\n"; }
    void breathe() { cout << "Breathing oxygen...\n"; }
};

// Virtual inheritance prevents duplicate copies of Animal in Amphibian
class TerrestrialAnimal : virtual public Animal {
public:
    TerrestrialAnimal() { cout << "TerrestrialAnimal Constructor\n"; }
};

class AquaticAnimal : virtual public Animal {
public:
    AquaticAnimal() { cout << "AquaticAnimal Constructor\n"; }
};

class Frog : public TerrestrialAnimal, public AquaticAnimal {
public:
    Frog() { cout << "Frog Constructor\n"; }
};

int main() {
    Frog frog;
    // Without 'virtual public Animal', the next line is ambiguous:
    frog.breathe(); // Works cleanly! Only 1 Animal instance.
    cout << "Frog health: " << frog.health << "\n";
    return 0;
}
```

---

## 2. Python Solution: Method Resolution Order (MRO) & C3 Linearization

Python resolves multiple inheritance and diamond conflicts deterministically using the **C3 Linearization Algorithm** and the `super()` method.

```python
class Animal:
    def __init__(self):
        print("Animal init")

    def breathe(self):
        print("Breathing oxygen...")


class TerrestrialAnimal(Animal):
    def __init__(self):
        super().__init__()
        print("TerrestrialAnimal init")


class AquaticAnimal(Animal):
    def __init__(self):
        super().__init__()
        print("AquaticAnimal init")


class Frog(TerrestrialAnimal, AquaticAnimal):
    def __init__(self):
        super().__init__()
        print("Frog init")


if __name__ == "__main__":
    frog = Frog()
    frog.breathe()

    # Inspect the exact Method Resolution Order (MRO)
    print("\nMRO Resolution Sequence:")
    for cls in Frog.mro():
        print(cls.__name__)
    # Output: Frog -> TerrestrialAnimal -> AquaticAnimal -> Animal -> object
```
