#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <string>
#include <vector>

class FileManager {
public:
    bool isFileValid(const std::string& filePath);
    std::vector<std::string> getSupportedFormats();
};

class AudioOutput {
public:
    bool initialize();
    bool playSound(const std::string& soundData);
    void stop();
};

class MusicPlayer {
public:
    MusicPlayer(FileManager& fileManager, AudioOutput& audioOutput);

    bool loadFile(const std::string& filePath);
    bool play();
    void stop();

    std::string getCurrentFile() const;

private:
    FileManager& fileManager;
    AudioOutput& audioOutput;

    std::string currentFile;
    bool isPlaying;
};

#endif // MUSIC_PLAYER_H
