#ifndef MUSIC_PLAYER_CONTROLLER_H
#define MUSIC_PLAYER_CONTROLLER_H

#include "../model/FileManagerInterface.h"
#include "../model/AudioOutputInterface.h"
#include "../view/ConsoleView.h"
#include <string>

class MusicPlayerController {
public:
    MusicPlayerController(FileManagerInterface& fileManager, AudioOutputInterface& audioOutput, ConsoleView& consoleView)
        : fileManager(fileManager), audioOutput(audioOutput), consoleView(consoleView) {}

    void loadFile(const std::string& filePath);
    void play();
    void stop();

private:
    FileManagerInterface& fileManager;
    AudioOutputInterface& audioOutput;
    ConsoleView& consoleView;

    std::string currentFile;
    bool isPlaying = false;
};

#endif // MUSIC_PLAYER_CONTROLLER_H
