# 1. Single Responsibility Principle (SRP)

## Definition
> **"A class should have one, and only one, reason to change."**  
> — Robert C. Martin (Uncle Bob)

Every class must focus on a **single cohesive responsibility**.

---

## 1. SRP Violation Example

```cpp
// BAD DESIGN: Invoice class handles calculations, database persistence, and printing!
class InvoiceBad {
public:
    double calculateTotal() { /* ... */ return 100.0; }
    void saveToDatabase()   { /* ... DB logic ... */ }
    void printInvoice()     { /* ... Printer logic ... */ }
};
```
*If database schema changes or PDF printing format changes, `InvoiceBad` must be edited.*

---

## 2. Refactored Solution (C++ & Python)

### C++:
```cpp
#include <iostream>
#include <string>

using namespace std;

// Class 1: Responsible only for business calculations
class Invoice {
public:
    double amount;
    Invoice(double a) : amount(a) {}
    double calculateTotal() const { return amount * 1.18; } // with tax
};

// Class 2: Responsible only for printing / formatting
class InvoicePrinter {
public:
    void print(const Invoice& invoice) {
        cout << "[PRINT] Invoice Total: $" << invoice.calculateTotal() << "\n";
    }
};

// Class 3: Responsible only for database persistence
class InvoiceRepository {
public:
    void save(const Invoice& invoice) {
        cout << "[DATABASE] Saving invoice of $" << invoice.calculateTotal() << "\n";
    }
};

int main() {
    Invoice invoice(500.0);
    InvoicePrinter printer;
    InvoiceRepository repo;

    printer.print(invoice);
    repo.save(invoice);
    return 0;
}
```

### Python:
```python
class Invoice:
    def __init__(self, amount: float):
        self.amount = amount

    def calculate_total(self) -> float:
        return self.amount * 1.18


class InvoicePrinter:
    def print_invoice(self, invoice: Invoice) -> None:
        print(f"[PRINT] Invoice Total: ${invoice.calculate_total():.2f}")


class InvoiceRepository:
    def save(self, invoice: Invoice) -> None:
        print(f"[DATABASE] Saving invoice of ${invoice.calculate_total():.2f}")


if __name__ == "__main__":
    inv = Invoice(500.0)
    InvoicePrinter().print_invoice(inv)
    InvoiceRepository().save(inv)
```
