#ifndef FRAME_HPP_INCLUDED
#define FRAME_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Frame {
private:
    vector<string> frameStrings;
    int nbLines;
public:
    Frame();
    Frame(int lineSize, int nbLines);
    string &operator [](int i) {
        return frameStrings[i];
    }
    void addLine(string line) { frameStrings.push_back(line); nbLines ++; }
    void addCharBack(char c, int lineNb) { frameStrings[lineNb] += c; }
    string getLine(int i) const { return frameStrings[i]; }
    int getNbLines() const { return nbLines; }
    ~Frame();


};



#endif // FRAME_HPP_INCLUDED

