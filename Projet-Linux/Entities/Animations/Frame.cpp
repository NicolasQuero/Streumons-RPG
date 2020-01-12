#include "Frame.hpp"

Frame::Frame() {
    frameStrings = vector<string>();
}

Frame::Frame(int nbLines, int lineSize) {
    frameStrings = vector<string>();
    string line = "";
    for (int j = 0; j < lineSize; j++) {
        line += ' ';
    }
    for (int i = 0; i < nbLines; i++) {
        frameStrings.push_back(line);
    }
}

Frame::~Frame() {
    frameStrings.clear();
    frameStrings.shrink_to_fit();
}
