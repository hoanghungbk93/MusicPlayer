#include "MusicPlayer.h"
#include <algorithm>

bool FileManager::isFileValid(const std::string& filePath) {
    auto formats = getSupportedFormats();
    auto pos = filePath.find_last_of('.');
    if (pos == std::string::npos) return false;

    std::string ext = filePath.substr(pos + 1);
    return std::find(formats.begin(), formats.end(), ext) != formats.end();
}

std::vector<std::string> FileManager::getSupportedFormats() {
    return {"mp3", "wav", "ogg"};
}

bool AudioOutput::initialize() {
    // Simulate audio output initialization
    return true;
}

bool AudioOutput::playSound(const std::string& soundData) {
    // Simulate playing sound
    return !soundData.empty();
}

void AudioOutput::stop() {
    // Simulate stopping sound
}

MusicPlayer::MusicPlayer(FileManager& fm, AudioOutput& ao)
    : fileManager(fm), audioOutput(ao), isPlaying(false) {}

bool MusicPlayer::loadFile(const std::string& filePath) {
    if (fileManager.isFileValid(filePath)) {
        currentFile = filePath;
        return true;
    }
    return false;
}

bool MusicPlayer::play() {
    if (!currentFile.empty() && audioOutput.initialize()) {
        isPlaying = audioOutput.playSound(currentFile);
    }
    return isPlaying;
}

void MusicPlayer::stop() {
    if (isPlaying) {
        audioOutput.stop();
        isPlaying = false;
    }
}

std::string MusicPlayer::getCurrentFile() const {
    return currentFile;
}
