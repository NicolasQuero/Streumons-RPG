#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Frame {
private:
    vector<string> frameStrings;
public:
    Frame();
    Frame(int lineSize, int nbLines);
    string &operator [](int i) {
        return frameStrings[i];
    }
    void addLine(string line) { frameStrings.push_back(line); }
    void addCharBack(char c, int lineNb) { frameStrings[lineNb] += c; }
    string getLine(int i) const { return frameStrings[i]; }
    ~Frame();


};



#endif // FRAME_HPP_INCLUDED

