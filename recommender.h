#ifndef BOOKRECOMMENDER_H
#define BOOKRECOMMENDER_H

#include <string>
#include <vector>
#include <set>
#include <sstream>

struct Book {
    std::string title;
    std::string author;
    std::string mood;
};

std::string trim(const std::string& str);

std::string getCSVField(std::stringstream &ss);

std::vector<Book> loadBooks(const std::string& filename, std::set<std::string>& moods);

void recommendBooks(const std::vector<Book>& books, const std::string& mood);

#endif 
