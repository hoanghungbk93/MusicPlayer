#include "MusicPlayer.h"
#include <iostream>

int main() {
    FileManager fileManager;
    AudioOutput audioOutput;

    MusicPlayer player(fileManager, audioOutput);

    std::string filePath = "song.mp3";

    if (player.loadFile(filePath)) {
        std::cout << "Loaded file: " << player.getCurrentFile() << "\n";
        if (player.play()) {
            std::cout << "Playing...\n";
            player.stop();
            std::cout << "Stopped.\n";
        } else {
            std::cerr << "Failed to play the file.\n";
        }
    } else {
        std::cerr << "Invalid file: " << filePath << "\n";
    }

    return 0;
}
