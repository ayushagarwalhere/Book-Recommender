#include "library.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Library::addBook(const Book& b){
    userBooks.push_back(b);
}

void Library::viewBooks() const{
    if(userBooks.empty()){
        cout << "No books in library\n";
    }

    for (const auto& b : userBooks) {
        cout << "Title: " << b.title << ", Author: " << b.author << ", Genre: " << b.genre << ", Character: " << b.character << ", Plot: " <<b.plot << ", Mood: " << b.mood << "\n";
    }
}

vector<Book>& Library::getBooks(){
    return userBooks;
}

void Library::sortByTitle() {
    mergeSort(userBooks, 0, userBooks.size() - 1);
}

void Library::sortByAuthor() {
    sort(userBooks.begin(), userBooks.end(), [](const Book& a, const Book& b) {
        return a.author < b.author;
    });
}

void Library::sortByMood() {
    sort(userBooks.begin(), userBooks.end(), [](const Book& a, const Book& b) {
        return a.mood < b.mood;
    });
}

int Library::searchByTitle(const string& title) {
    return binarySearch(userBooks, title);
}
