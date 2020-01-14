#include "Animation.hpp"
#include <string>
using namespace std;

const int Animation::lineSize = 27;
const int Animation::nbLines = 10;

Animation::Animation() {};

Animation::Animation(int _timePerFrame, string animationPath) : timePerFrame(_timePerFrame), frames(), background_set(false), header_set(false) {
    loadAnimation(animationPath);

}

void Animation::addFrame(Frame frame) {
    frames.push_back(frame);
    nbFrames ++;
}

void Animation::addHeader(Frame frame) {
    header = frame;
    header_set = true;
}

void Animation::addHeaderLine(string line) {
    header.addLine(line);
    header_set = true;
}

void Animation::loadAnimation(string path) {
    ifstream file(path);
    if (file.is_open()) {
        cout << "FILE OPEN" << endl;
        string line = "";
        int frameNb = 0;
        Frame frame = Frame();
        while (getline(file, line)) {
            if (line[0] != '_') {
                frame.addLine(line);
            }
            else {
                frames.push_back(frame);
                frame = Frame();
                frameNb++;
            }
        }
        nbFrames = frameNb;
    }
    else
        cout << " FILE COULD NOT OPEN" << endl;
}

void Animation::printAnimation(int attackerLocation) const {
    if (attackerLocation == 0) {
        if (background_set) {
            for (Frame frame : frames) {
                system("clear");
                if (header_set) {
                    for (int i = 0; i < header.getNbLines(); i++) {
                        cout << header.getLine(i) << endl;
                    }
                }
                for (int i = 0; i < frame.getNbLines(); i++) {
                    for (int j = 0; j < lineSize; j++) {
                        if (frame.getLine(i)[j] == ' ')
                            cout << background.getLine(i)[j];
                        else
                            cout << frame.getLine(i)[j];
                    }
                    cout << endl;
                }
                usleep(timePerFrame);
            }
        }
    }
    else if (attackerLocation == 1) {
        if (background_set) {
            for (Frame frame : frames) {
                system("clear");
                if (header_set) {
                    for (int i = 0; i < header.getNbLines(); i++) {
                        cout << header.getLine(i) << endl;
                    }
                }
                for (int i = 0; i < frame.getNbLines(); i++) {
                    string output = "  ";
                    for (int j = lineSize - 1; j > 0; j--) {
                        if (frame.getLine(i)[j+1] == ' ' && background.getNbLines() >= i)
                            output += background.getLine(i)[lineSize - j];
                        else
                            output += frame.getLine(i)[j+1];
                    }
                    cout << output << endl;
                }
                usleep(timePerFrame);
            }
        }
    }
}

Animation::~Animation() {
    frames.clear();
    frames.shrink_to_fit();
}
