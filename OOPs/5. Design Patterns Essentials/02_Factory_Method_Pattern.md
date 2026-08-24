# 2. Factory Method Design Pattern (Creational)

## Intent
Provide an interface for creating objects in a superclass, but allow subclasses or factory methods to alter the **exact type of objects that will be created at runtime**.

---

## 1. C++ Implementation

```cpp
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Product Interface
class Notification {
public:
    virtual void notifyUser() = 0;
    virtual ~Notification() {}
};

// Concrete Products
class EmailNotification : public Notification {
public:
    void notifyUser() override { cout << "[EMAIL] Sending email alert.\n"; }
};

class SMSNotification : public Notification {
public:
    void notifyUser() override { cout << "[SMS] Sending SMS verification code.\n"; }
};

class PushNotification : public Notification {
public:
    void notifyUser() override { cout << "[PUSH] Sending mobile push notification.\n"; }
};

// Factory Class
class NotificationFactory {
public:
    static unique_ptr<Notification> createNotification(const string& channel) {
        if (channel == "EMAIL") return make_unique<EmailNotification>();
        if (channel == "SMS") return make_unique<SMSNotification>();
        if (channel == "PUSH") return make_unique<PushNotification>();
        return nullptr;
    }
};

int main() {
    auto n1 = NotificationFactory::createNotification("EMAIL");
    auto n2 = NotificationFactory::createNotification("SMS");

    if (n1) n1->notifyUser();
    if (n2) n2->notifyUser();
    return 0;
}
```

---

## 2. Python Implementation

```python
from abc import ABC, abstractmethod


# Product Interface
class Notification(ABC):
    @abstractmethod
    def notify_user(self) -> None:
        pass


# Concrete Products
class EmailNotification(Notification):
    def notify_user(self) -> None:
        print("[EMAIL] Sending email alert.")


class SMSNotification(Notification):
    def notify_user(self) -> None:
        print("[SMS] Sending SMS verification code.")


class PushNotification(Notification):
    def notify_user(self) -> None:
        print("[PUSH] Sending mobile push notification.")


# Factory
class NotificationFactory:
    @staticmethod
    def create_notification(channel: str) -> Notification:
        channels = {
            "EMAIL": EmailNotification,
            "SMS": SMSNotification,
            "PUSH": PushNotification,
        }
        creator = channels.get(channel.upper())
        if creator:
            return creator()
        raise ValueError(f"Unknown notification channel: {channel}")


if __name__ == "__main__":
    n1 = NotificationFactory.create_notification("EMAIL")
    n2 = NotificationFactory.create_notification("SMS")

    n1.notify_user()
    n2.notify_user()
```
