#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

#include <vector>
#include <string>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include "Frame.hpp"


class Animation {
private:
    const static int nbLines, lineSize;
    int nbFrames;
    int timePerFrame;
    std::vector<Frame> frames;
    Frame background, header;
    void loadAnimation(string path);
    bool background_set, header_set;
public:
    Animation();
    Animation(int _timePerFrame, string animationPath); // timePerFrame must be in microseconds
    void setBackground(Frame _frame) {
        background = _frame;
        background_set = true;
    }
    void addFrame(Frame frame);
    void addHeader(Frame frame);
    void addHeaderLine(string line);
    void printAnimation(int attackerLocation) const; // 0 left, 1 right
    ~Animation();

};


#endif // ANIMATION_HPP_INCLUDED
