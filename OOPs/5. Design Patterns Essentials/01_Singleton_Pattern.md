# 1. Singleton Design Pattern (Creational)

## Intent
Ensure a class has **only one single instance** throughout the entire application lifecycle, and provide a **global point of access** to it (e.g., Database Connection Pool, Logger, Configuration Manager).

---

## 1. C++ Implementation (Thread-Safe Meyers' Singleton)

In C++11 and later, function-local static variables are guaranteed by the standard to be initialized in a **thread-safe manner** on first execution.

```cpp
#include <iostream>
#include <mutex>

using namespace std;

class DatabaseConnection {
private:
    // 1. Private Constructor prevents direct instantiation
    DatabaseConnection() {
        cout << "Database Connection Initialized (Expensive setup).\n";
    }

    // 2. Delete Copy Constructor and Assignment Operator
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;

public:
    // 3. Static access method
    static DatabaseConnection& getInstance() {
        static DatabaseConnection instance; // Thread-safe in C++11
        return instance;
    }

    void executeQuery(const string& query) {
        cout << "Executing: " << query << "\n";
    }
};

int main() {
    DatabaseConnection& db1 = DatabaseConnection::getInstance();
    DatabaseConnection& db2 = DatabaseConnection::getInstance();

    db1.executeQuery("SELECT * FROM users");

    cout << "db1 address: " << &db1 << "\n";
    cout << "db2 address: " << &db2 << "\n"; // Exact same memory address!
    return 0;
}
```

---

## 2. Python Implementation (`__new__` Singleton)

```python
class DatabaseConnection:
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            print("Database Connection Initialized (Expensive setup).")
            cls._instance = super().__new__(cls)
        return cls._instance

    def execute_query(self, query: str) -> None:
        print(f"Executing: {query}")


if __name__ == "__main__":
    db1 = DatabaseConnection()
    db2 = DatabaseConnection()

    db1.execute_query("SELECT * FROM users")

    print("Are db1 and db2 the exact same instance?", db1 is db2) # True
```
