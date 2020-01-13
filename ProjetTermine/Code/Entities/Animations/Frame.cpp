#include "Frame.hpp"

Frame::Frame() : frameStrings(), nbLines(0) {

}

Frame::Frame(int nbLines, int lineSize) : nbLines(nbLines) {
    frameStrings = vector<string>();
    string line = "";
    for (int j = 0; j < lineSize; j++) {
        line += ' ';
    }
    for (int i = 0; i < nbLines; i++) {
        frameStrings.push_back(line);
    }
}

void Frame::printFrame() const {
    for (string line : frameStrings) {
        cout << line << endl;
    }
}

Frame::~Frame() {
    frameStrings.clear();
    frameStrings.shrink_to_fit();
}
