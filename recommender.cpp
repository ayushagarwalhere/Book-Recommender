#include "library.h"
#include <iostream>
#include <string>
using namespace std;

void recommendByMood(Library& lib, const string mood) {
    for (const auto& Book : lib.getBooks()) {
        if (Book.mood == mood) {
            cout << "Recommendation: " << Book.title << " by " << Book.author << " [" << Book.genre << "]\n";
            return;
        }
    }
    cout << "No book found for this mood !!";
}
void recommendByCharacter(Library& lib, const string character) {
    for(const auto& Book : lib.getBooks()) {
        if(Book.character == character) {
            cout << "Recommendation: " << Book.title << " by " << Book.author << " [" << Book.genre << "]\n";
            return;
        }
    }
    cout << "No book found for this character !!";
}
void recommendByPlot(Library& lib, const string plot) {
    for(const auto& Book : lib.getBooks()) {
        if(Book.plot == plot) {
            cout << "Recommendation: " << Book.title << " by " << Book.author << " [" << Book.genre << "]\n";
            return;
        }
    }
    cout << "No book found for this plot !!";
}