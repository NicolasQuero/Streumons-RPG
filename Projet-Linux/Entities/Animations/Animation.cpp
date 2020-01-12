#include "Animation.hpp"

using namespace std;

const int Animation::lineSize = 27;
const int Animation::nbLines = 10;

Animation::Animation() {};

Animation::Animation(int _timePerFrame, string animationPath) : timePerFrame(_timePerFrame), background_set(false) {
    frames = vector<Frame>();
    loadAnimation(animationPath);

}

void Animation::addFrame(Frame frame) {
    frames.push_back(frame);
    nbFrames ++;
}

void Animation::loadAnimation(string path) {
    ifstream file(path);
    if (file.is_open()) {
        cout << "FILE OPEN" << endl;
        string line;
        int frameNb = 0;
        Frame frame = Frame();
        while (getline(file, line)) {
            cout << line << endl;
            if (line[0] != '_') {
                frame.addLine(line);
                frameNb++;
            }
            else {
                frames.push_back(frame);
                frame = Frame();
                frameNb = 0;
            }
        }
        nbFrames = frameNb;
    }
}

void Animation::printAnimation() const {
    if (!background_set) {
        for (Frame frame : frames) {
            system("clear");
            for (int i = 0; i < nbLines; i++) {
                cout << frame.getLine(i) << endl;
            }
            usleep(timePerFrame);
        }
    }
    else {
        for (Frame frame : frames) {
            system("clear");
            for (int i = 0; i < nbLines; i++) {
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

Animation::~Animation() {
    frames.clear();
    frames.shrink_to_fit();
}
