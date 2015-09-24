#include <iostream>
#include "CommandManager.h"

CommandManager commandManager;

std::vector<std::string> split(std::string line);

int main() {
    std::string newLine;
    while (getline(std::cin, newLine)) {
        std::vector<std::string> words = split(newLine);
        if (words.empty()) {
            continue;
        }
        commandManager.runCommand(words);
//        std::cout << "here\n";
    }
    return 0;
}

std::vector<std::string> split(std::string line) {
    std::vector<std::string> words;
    words.clear();
    std::string tmp = "";
    for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' && tmp.size() > 0) {
            words.push_back(tmp);
            tmp.clear();
        } else {
            tmp += line.at(i);
        }
    }
    if (!tmp.empty()) {
        words.push_back(tmp);
    }
    return words;
}