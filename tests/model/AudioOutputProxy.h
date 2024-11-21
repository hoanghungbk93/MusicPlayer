#ifndef AUDIO_OUTPUT_PROXY_H
#define AUDIO_OUTPUT_PROXY_H

#include "../../src/model/AudioOutputInterface.h"
#include <functional>

class AudioOutputProxy : public AudioOutputInterface {
public:
    /**
     * Constructor nhận vào một đối tượng AudioOutputInterface thực.
     * @param realOutput Đối tượng AudioOutputInterface thực sự.
     */
    explicit AudioOutputProxy(AudioOutputInterface* realOutput) 
        : realOutput(realOutput) {}

    /**
     * Khởi tạo thiết bị đầu ra âm thanh bằng cách sử dụng mock hoặc gọi đối tượng thực.
     * @return true nếu khởi tạo thành công, false nếu không.
     */
    bool initialize() override {
        if (mockInitialize) {
            return mockInitialize();
        }
        return realOutput->initialize();
    }

    /**
     * Phát âm thanh bằng cách sử dụng mock hoặc gọi đối tượng thực.
     * @param soundData Dữ liệu âm thanh cần phát.
     * @return true nếu phát thành công, false nếu không.
     */
    bool playSound(const std::string& soundData) override {
        if (mockPlaySound) {
            return mockPlaySound(soundData);
        }
        return realOutput->playSound(soundData);
    }

    /**
     * Dừng phát âm thanh bằng cách sử dụng mock hoặc gọi đối tượng thực.
     */
    void stop() override {
        if (mockStop) {
            mockStop();
        } else {
            realOutput->stop();
        }
    }

    /**
     * Cấu hình hành vi mock cho phương thức initialize.
     * @param func Hàm mock.
     */
    void setMockInitialize(std::function<bool()> func) {
        mockInitialize = func;
    }

    /**
     * Cấu hình hành vi mock cho phương thức playSound.
     * @param func Hàm mock.
     */
    void setMockPlaySound(std::function<bool(const std::string&)> func) {
        mockPlaySound = func;
    }

    /**
     * Cấu hình hành vi mock cho phương thức stop.
     * @param func Hàm mock.
     */
    void setMockStop(std::function<void()> func) {
        mockStop = func;
    }

private:
    AudioOutputInterface* realOutput; ///< Đối tượng AudioOutput thực.
    std::function<bool()> mockInitialize = nullptr; ///< Hàm mock cho initialize.
    std::function<bool(const std::string&)> mockPlaySound = nullptr; ///< Hàm mock cho playSound.
    std::function<void()> mockStop = nullptr; ///< Hàm mock cho stop.
};

#endif // AUDIO_OUTPUT_PROXY_H
