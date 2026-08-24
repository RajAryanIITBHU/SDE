# 3. Builder Design Pattern (Creational)

## Intent
Separate the construction of a complex object from its representation so that the **same construction process can create different representations** using method chaining.

---

## 1. C++ Implementation

```cpp
#include <iostream>
#include <string>

using namespace std;

// Complex Product
class Computer {
public:
    string CPU;
    string RAM;
    string GPU;
    bool hasSSD = false;

    void display() const {
        cout << "Computer Config: CPU=" << CPU << ", RAM=" << RAM 
             << ", GPU=" << GPU << ", SSD=" << (hasSSD ? "Yes" : "No") << "\n";
    }
};

// Builder Class
class ComputerBuilder {
private:
    Computer computer;
public:
    ComputerBuilder& setCPU(const string& cpu) {
        computer.CPU = cpu;
        return *this;
    }
    ComputerBuilder& setRAM(const string& ram) {
        computer.RAM = ram;
        return *this;
    }
    ComputerBuilder& setGPU(const string& gpu) {
        computer.GPU = gpu;
        return *this;
    }
    ComputerBuilder& setSSD(bool ssd) {
        computer.hasSSD = ssd;
        return *this;
    }
    Computer build() {
        return computer;
    }
};

int main() {
    Computer gamingRig = ComputerBuilder()
                            .setCPU("Intel Core i9-14900K")
                            .setRAM("64GB DDR5")
                            .setGPU("NVIDIA RTX 4090")
                            .setSSD(true)
                            .build();

    gamingRig.display();
    return 0;
}
```

---

## 2. Python Implementation

```python
class Computer:
    def __init__(self):
        self.cpu = ""
        self.ram = ""
        self.gpu = ""
        self.has_ssd = False

    def __str__(self) -> str:
        return f"Computer Config: CPU={self.cpu}, RAM={self.ram}, GPU={self.gpu}, SSD={'Yes' if self.has_ssd else 'No'}"


class ComputerBuilder:
    def __init__(self):
        self._computer = Computer()

    def set_cpu(self, cpu: str) -> "ComputerBuilder":
        self._computer.cpu = cpu
        return self

    def set_ram(self, ram: str) -> "ComputerBuilder":
        self._computer.ram = ram
        return self

    def set_gpu(self, gpu: str) -> "ComputerBuilder":
        self._computer.gpu = gpu
        return self

    def set_ssd(self, ssd: bool) -> "ComputerBuilder":
        self._computer.has_ssd = ssd
        return self

    def build(self) -> Computer:
        return self._computer


if __name__ == "__main__":
    gaming_pc = (
        ComputerBuilder()
        .set_cpu("Intel Core i9-14900K")
        .set_ram("64GB DDR5")
        .set_gpu("NVIDIA RTX 4090")
        .set_ssd(True)
        .build()
    )
    print(gaming_pc)
```
