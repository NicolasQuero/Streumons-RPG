#ifndef TEXTOUTPUT_HPP_INCLUDED
#define TEXTOUTPUT_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct TextOutput {
private:
    static string textToShow;
public:
    TextOutput();
    TextOutput(string text);
    static void setText(string text) { textToShow = text; }
    static void addText(string text) { textToShow += text; }
    static void clearText() { textToShow = ""; }
    static string getText() { return textToShow; }
    static bool isEmpty() { return (textToShow == ""); }
    friend ostream &operator<<(ostream &out, const TextOutput text_output) {
        for (size_t i = 0; i < textToShow.length() + 1; i++) {
            out << "-";
        }
        out << endl << " " << textToShow;
        for (size_t i = 0; i < textToShow.length() + 1; i++) {
            out << "-";
        }
        out << endl;
        return out;
    }
};


#endif // TEXTOUTPUT_HPP_INCLUDED
