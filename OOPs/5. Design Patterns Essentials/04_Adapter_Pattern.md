# 4. Adapter Design Pattern (Structural)

## Intent
Convert the interface of a class into another interface that clients expect. Adapter lets classes work together that **could not otherwise because of incompatible interfaces**.

---

## 1. C++ Implementation

```cpp
#include <iostream>
#include <memory>

using namespace std;

// Target Interface expected by Modern Client
class ModernMediaPlayer {
public:
    virtual void playAudio(const string& filename) = 0;
    virtual ~ModernMediaPlayer() {}
};

// Adaptee (Incompatible 3rd-party legacy class)
class LegacyAudioEngine {
public:
    void streamWavFormat(const string& file) {
        cout << "[Legacy Engine] Streaming WAV raw bytes: " << file << "\n";
    }
};

// Adapter: Implements ModernMediaPlayer by wrapping LegacyAudioEngine
class AudioAdapter : public ModernMediaPlayer {
private:
    unique_ptr<LegacyAudioEngine> legacyEngine;
public:
    AudioAdapter() : legacyEngine(make_unique<LegacyAudioEngine>()) {}

    void playAudio(const string& filename) override {
        cout << "[Adapter] Converting audio format...\n";
        legacyEngine->streamWavFormat(filename);
    }
};

int main() {
    unique_ptr<ModernMediaPlayer> player = make_unique<AudioAdapter>();
    player->playAudio("song.mp3");
    return 0;
}
```

---

## 2. Python Implementation

```python
from abc import ABC, abstractmethod


# Target Interface
class ModernMediaPlayer(ABC):
    @abstractmethod
    def play_audio(self, filename: str) -> None:
        pass


# Adaptee (Legacy class)
class LegacyAudioEngine:
    def stream_wav_format(self, file: str) -> None:
        print(f"[Legacy Engine] Streaming WAV raw bytes: {file}")


# Adapter
class AudioAdapter(ModernMediaPlayer):
    def __init__(self):
        self._legacy_engine = LegacyAudioEngine()

    def play_audio(self, filename: str) -> None:
        print("[Adapter] Converting audio format...")
        self._legacy_engine.stream_wav_format(filename)


if __name__ == "__main__":
    player: ModernMediaPlayer = AudioAdapter()
    player.play_audio("song.mp3")
```
