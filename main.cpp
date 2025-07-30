#include "book.h"
#include "library.h"
#include "recommender.h"
#include "recommenderr.cpp"
#include "library.cpp"
#include "utils.cpp"
#include "utils.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void showMenu() {
    cout << "\nMood-Based Book Recommendation System\n";
    cout << "1. Add a Book\n";
    cout << "2. View Library\n";
    cout << "3. Get Recommendation by Mood\n";
    cout << "4. Sort Library\n";
    cout << "5. Search by Title\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void showMoodMenu(const vector<string>& moods) {
    cout << "\nMood Options:\n";
    for (size_t i = 0; i < moods.size(); ++i) {
        cout << i + 1 << ". " << moods[i] << "\n";
    }
    cout << moods.size() + 1 << ". Back to Main Menu\n";
    cout << "Choose an option: ";
}

void showSortMenu() {
    cout << "\nSort Library By:\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Mood\n";
    cout << "4. Back to Main Menu\n";
    cout << "Choose an option: ";
}

int main() {
    Library lib;
    int choice;

    vector<string> validMoods = {
        "Tense", "Magical", "Thoughtful", "Nostalgic", "Romantic",
        "Poignant", "Adventurous", "Dark", "Mysterious"
    };

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Book b;
            cout << "Enter title: ";
            getline(cin, b.title);
            cout << "Enter author: ";
            getline(cin, b.author);
            cout << "Enter genre: ";
            getline(cin, b.genre);
            cout << "Enter mood (choose one of the 9 moods): ";
            getline(cin, b.mood);
            lib.addBook(b);

        } else if (choice == 2) {
            lib.viewBooks();

        } else if (choice == 3) {
            int moodChoice;
            while (true) {
                showMoodMenu(validMoods);
                cin >> moodChoice;
                cin.ignore();

                if (moodChoice >= 1 && moodChoice <= validMoods.size()) {
                    recommendByMood(lib.getBooks(), validMoods[moodChoice - 1]);
                } else if (moodChoice == validMoods.size() + 1) {
                    break;
                } else {
                    cout << "Select a valid option!\n";
                }
            }

        } else if (choice == 4) {
            int sortChoice;
            while (true) {
                showSortMenu();
                cin >> sortChoice;
                cin.ignore();

                if (sortChoice == 1) {
                    lib.sortByTitle();
                    lib.viewBooks();
                } else if (sortChoice == 2) {
                    lib.sortByAuthor();
                    lib.viewBooks();
                } else if (sortChoice == 3) {
                    lib.sortByMood();
                    lib.viewBooks();
                } else if (sortChoice == 4) {
                    break;
                } else {
                    cout << "Select a valid option!\n";
                }
            }

        } else if (choice == 5) {
            string searchTitle;
            cout << "Enter book title to search: ";
            getline(cin, searchTitle);

            int index = lib.searchByTitle(searchTitle);
            if (index != -1) {
                Book& found = lib.getBooks()[index];
                cout << "Book found:\n";
                cout << "Title: " << found.title << "\n";
                cout << "Author: " << found.author << "\n";
                cout << "Genre: " << found.genre << "\n";
                cout << "Mood: " << found.mood << "\n";
            } else {
                cout << "Book not found.\n";
            }

        } else if (choice == 6) {
            cout << "Goodbye!\n";
            break;

        } else {
            cout << "Select a valid option!\n";
        }
    }
}
