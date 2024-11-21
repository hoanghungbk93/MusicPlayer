#ifndef AUDIO_OUTPUT_PROXY_H
#define AUDIO_OUTPUT_PROXY_H

#include <functional>
#include <string>
#include "MusicPlayer.h" // Tệp khách hàng gốc

class AudioOutputProxy {
public:
    explicit AudioOutputProxy(AudioOutput* realOutput) : realOutput(realOutput) {}

    // Proxy cho `initialize`
    bool initialize() {
        if (mockInitialize) {
            return mockInitialize();
        }
        return realOutput->initialize();
    }

    // Proxy cho `playSound`
    bool playSound(const std::string& soundData) {
        if (mockPlaySound) {
            return mockPlaySound(soundData);
        }
        return realOutput->playSound(soundData);
    }

    // Proxy cho `stop`
    void stop() {
        if (mockStop) {
            mockStop();
        } else {
            realOutput->stop();
        }
    }

    // Setter cho mock behavior
    void setMockInitialize(std::function<bool()> func) {
        mockInitialize = func;
    }

    void setMockPlaySound(std::function<bool(const std::string&)> func) {
        mockPlaySound = func;
    }

    void setMockStop(std::function<void()> func) {
        mockStop = func;
    }

private:
    AudioOutput* realOutput; // Lớp thật từ khách hàng
    std::function<bool()> mockInitialize = nullptr;
    std::function<bool(const std::string&)> mockPlaySound = nullptr;
    std::function<void()> mockStop = nullptr;
};

#endif // AUDIO_OUTPUT_PROXY_H
