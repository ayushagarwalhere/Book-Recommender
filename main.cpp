//#include "book.h"
//#include "library.h"
#include "recommender.h"
#include "utils.h"
#include <iostream>
#include <string>
using namespace std;



void showMenu() {
    cout << "\n Mood-Based Book Recommendation System \n";
    cout << "1. Add a Book\n";
    cout << "2. View Library\n";
    cout << "3. Get Recommendation\n";
    cout << "4. Sort Library\n";       
    cout << "5. Search by Title\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}
void showRecommendationMenu() {
    cout << "\n Recommendation Options \n";
    cout << "1. By Mood\n";
    cout << "2. By Character Type\n";
    cout << "3. By Plot\n";
    cout << "4. Back to Main Menu\n";
    cout << "Choose an option: ";
}
void showMoodMenu() {
    cout << "\n Mood Options \n";
    cout <<"1. Calm\n";
    cout <<"2. Romantic\n";
    cout <<"3. Funny\n";
    cout <<"4. Motivational\n";
    cout <<"5. Sad\n";
    cout <<"6. Lonely\n";
    cout <<"7. Back to Main Menu\n";
    cout <<"Choose an option: "; 
}
void showCharacterMenu() {
    cout <<"\n Character Type Options \n";
    cout <<"1. Underdog\n";
    cout <<"2. Anti-Hero\n";
    cout <<"3. Detective\n";
    cout <<"4. Romantic Lead\n";
    cout <<"5. Dark Protagonist\n";
    cout <<"6. Dreamer\n";
    cout <<"7. Back to Main Menu\n";
    cout <<"Choose an option: ";
}
void showPlotMenu() {
    cout <<"\n Plot Options \n";
    cout <<"1. Conflict \n";
    cout <<"2. Open\n";
    cout <<"3. Generations\n";
    cout <<"4. Lots Of Twists & Turns\n";
    cout <<"5. Success against the odds\n";
    cout <<"6. Quest\n";
    cout <<"7. Back to Main Menu\n";
    cout <<"Choose an option: ";
}
void showSortMenu() {
    cout << "\nSort By:\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Mood\n";
    cout << "4. Exit\n";
    cout << "Choose option: ";
}

int main(){
    Library lib;
    int choice;

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
            cout << "Enter mood: ";
            getline(cin, b.mood);
            lib.addBook(b);
            cout << "Enter character type: ";
            getline(cin, b.character);
            cout << "Enter plot: ";
            getline(cin, b.plot);

        } else if (choice == 2) {
            lib.viewBooks();
        } else if (choice == 3) {
            int recommend_choice;
            while (true) {
                showRecommendationMenu();
                cin >> recommend_choice;
                cin.ignore();

                if(recommend_choice == 1) {
                    int mood_choice;
                    while(true) {
                        showMoodMenu();
                        cin >> mood_choice;
                        cin.ignore();

                        if(mood_choice == 1){
                            recommendByMood(lib, "Calm");
                        }
                        if(mood_choice == 2){
                            recommendByMood(lib, "Romantic");
                        }
                        if(mood_choice == 3){
                            recommendByMood(lib, "Funny");
                        }
                        if(mood_choice == 4){
                            recommendByMood(lib, "Motivational");
                        }
                        if(mood_choice == 5){
                            recommendByMood(lib, "Sad");
                        }
                        if(mood_choice == 6){
                            recommendByMood(lib, "Lonely");
                        }
                        if(mood_choice == 7){
                            break;
                        }
                        else{
                            cout << "Select a valid option !!";
                        }
                    }
                }
                if(recommend_choice == 2){
                    int char_choice;
                    while(true){
                        showCharacterMenu();
                        cin >> char_choice;
                        cin.ignore();

                        if(char_choice == 1){
                            recommendByCharacter(lib, "Underdog");
                        }
                        if(char_choice == 2){
                            recommendByCharacter(lib, "Anti-Hero");
                        }
                        if(char_choice == 3){
                            recommendByCharacter(lib, "Detective");
                        }
                        if(char_choice == 4){
                            recommendByCharacter(lib, "Romantic Lead");
                        }
                        if(char_choice == 5){
                            recommendByCharacter(lib, "Dark Protagonist");
                        }
                        if(char_choice == 6){
                            recommendByCharacter(lib, "Dreamer");
                        }
                        if(char_choice == 7){
                            break;
                        }
                        else{
                            cout << "Select a valid option !!";
                        }

                    }
                }
                if(recommend_choice == 3){
                    int plot_choice;

                    while(true){
                        showPlotMenu();
                        cin >> plot_choice;
                        cin.ignore();

                        if(plot_choice == 1){
                            recommendByPlot(lib, "Conflict");
                        }
                        if(plot_choice == 2){
                            recommendByPlot(lib, "Open");
                        }
                        if(plot_choice == 3){
                            recommendByPlot(lib, "Generations");
                        }
                        if(plot_choice == 4){
                            recommendByPlot(lib, "Lots Of Twists & Turns");
                        }
                        if(plot_choice == 5){
                            recommendByPlot(lib, "Success against the odds");
                        }
                        if(plot_choice == 6){
                           recommendByPlot(lib, "Quest");
                        }
                        if(plot_choice == 7){
                            break;
                        }
                        else{
                            cout << "Select a valid option !!";
                        }
                    }
                }
                if(recommend_choice == 4){
                    break;
                }
            }
        }   else if(choice == 4){
                    int sort_choice;
                    
                    while(true){
                        showSortMenu();
                        cin >> sort_choice;
                        cin.ignore();

                        if(sort_choice == 1){
                            lib.sortByTitle();
                            lib.viewBooks();
                        }
                        if(sort_choice == 2){
                            lib.sortByAuthor();
                            lib.viewBooks();
                        }
                        if(sort_choice == 3){
                            lib.sortByMood();
                            lib.viewBooks();
                        }
                        if(sort_choice == 4){
                            break;
                        }
                        else{
                            cout << "Select a valid option !!";
                        }
                    }
            }else if (choice == 5) {
                    string searchTitle;
                    cout << "Enter book title to search: ";
                    getline(cin, searchTitle);

                    int index = lib.searchByTitle(searchTitle);
                    if (index != -1) {
                        Book& found = lib.getBooks()[index];
                        cout << "✅ Book found:\n";
                        cout << "Title: " << found.title << "\n";
                        cout << "Author: " << found.author << "\n";
                        cout << "Genre: " << found.genre << "\n";
                        cout << "Mood: " << found.mood << "\n";
                    } else {
                    cout << "❌ Book not found.\n";
                    }
            } else if(choice == 6){
                cout << "Goodbye !!";
                break;
            }
            else{
               cout << "Select a valid option !!";
            }   
        }
}
