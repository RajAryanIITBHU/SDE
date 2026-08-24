# 6. Observer Design Pattern (Behavioral)

## Intent
Define a **one-to-many dependency** between objects so that when one object (Subject / Observable) changes state, all its dependents (Observers / Subscribers) are **automatically notified and updated**.

---

## 1. C++ Implementation (YouTube Channel Subscriber Example)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Observer Interface
class ISubscriber {
public:
    virtual void update(const string& videoTitle) = 0;
    virtual ~ISubscriber() {}
};

// Subject / Publisher Interface
class YouTubeChannel {
private:
    vector<ISubscriber*> subscribers;
    string channelName;

public:
    YouTubeChannel(string name) : channelName(name) {}

    void subscribe(ISubscriber* sub) { subscribers.push_back(sub); }
    void unsubscribe(ISubscriber* sub) {
        subscribers.erase(remove(subscribers.begin(), subscribers.end(), sub), subscribers.end());
    }

    void uploadVideo(const string& title) {
        cout << "\n[" << channelName << "] Uploaded new video: " << title << "\n";
        notifySubscribers(title);
    }

private:
    void notifySubscribers(const string& title) {
        for (ISubscriber* sub : subscribers) {
            sub->update(title);
        }
    }
};

// Concrete Observer
class UserSubscriber : public ISubscriber {
private:
    string username;
public:
    UserSubscriber(string name) : username(name) {}

    void update(const string& videoTitle) override {
        cout << " -> Notification for " << username << ": New video '" << videoTitle << "' is live!\n";
    }
};

int main() {
    YouTubeChannel channel("CodeStoryWithMik");
    UserSubscriber user1("Alice");
    UserSubscriber user2("Bob");

    channel.subscribe(&user1);
    channel.subscribe(&user2);

    channel.uploadVideo("Master Dynamic Programming in C++");

    channel.unsubscribe(&user2);
    channel.uploadVideo("Graphs BFS/DFS Deep Dive");
    return 0;
}
```

---

## 2. Python Implementation

```python
from abc import ABC, abstractmethod


# Observer Interface
class ISubscriber(ABC):
    @abstractmethod
    def update(self, video_title: str) -> None:
        pass


# Concrete Observer
class UserSubscriber(ISubscriber):
    def __init__(self, username: str):
        self.username = username

    def update(self, video_title: str) -> None:
        print(f" -> Notification for {self.username}: New video '{video_title}' is live!")


# Subject / Publisher
class YouTubeChannel:
    def __init__(self, channel_name: str):
        self.channel_name = channel_name
        self._subscribers = []

    def subscribe(self, subscriber: ISubscriber) -> None:
        self._subscribers.append(subscriber)

    def unsubscribe(self, subscriber: ISubscriber) -> None:
        self._subscribers.remove(subscriber)

    def upload_video(self, title: str) -> None:
        print(f"\n[{self.channel_name}] Uploaded new video: {title}")
        for sub in self._subscribers:
            sub.update(title)


if __name__ == "__main__":
    channel = YouTubeChannel("CodeStoryWithMik")
    u1 = UserSubscriber("Alice")
    u2 = UserSubscriber("Bob")

    channel.subscribe(u1)
    channel.subscribe(u2)

    channel.upload_video("Master Dynamic Programming in Python")

    channel.unsubscribe(u2)
    channel.upload_video("Graphs BFS/DFS Deep Dive")
```
