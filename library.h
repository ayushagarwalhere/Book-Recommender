#ifndef library_h
#define library_h

#include "book.h"
#include <vector>

class Library{
    private:
        vector<Book> userBooks;

    public:
        void addBook(const Book& b);
        void viewBooks() const;
        vector<Book>& getBooks();

        void sortByTitle();
        void sortByAuthor();
        void sortByMood();
        int searchByTitle(const string& title);

};

#endif