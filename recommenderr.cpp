#include "recommender.h"   
#include "book.h"
#include "library.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <vector>
#include <set>
#include <sstream>

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \"");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \"\r\n");
    return str.substr(first, (last - first + 1));
}

std::string getCSVField(std::stringstream &ss) {
    std::string result;
    if (ss.peek() == '"') {
        ss.get(); 
        std::getline(ss, result, '"');
        if (ss.peek() == ',') ss.get(); 
    } else {
        std::getline(ss, result, ',');
    }
    return trim(result);
}

std::vector<Book> loadBooks(const std::string& filename, std::set<std::string>& moods) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file.\n";
        return books;
    }

    std::string line;
    getline(file, line); 

    while (getline(file, line)) {
        std::stringstream ss(line);

        std::string id = getCSVField(ss);      
        std::string author = getCSVField(ss);
        std::string year = getCSVField(ss);     
        std::string title = getCSVField(ss);
       // std::string genre = getCSVField(ss);   
        std::string mood = getCSVField(ss);

        if (title.empty() || mood.empty()) continue;

        books.push_back({title, author, mood});
        moods.insert(mood);
    }

    file.close();
    return books;
}

void recommendByMood(const std::vector<Book>& books, const std::string& mood) {
    std::vector<Book> matching;
    for (const auto& book : books) {
        if (book.mood == mood) {
            matching.push_back(book);
        }
    }

    if (matching.empty()) {
        std::cout << "No books found for this mood.\n";
        return;
    }

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle(matching.begin(), matching.end(), rng);

    std::cout << "\nRecommended books for mood [" << mood << "]:\n";
    int count = std::min(10, static_cast<int>(matching.size()));
    for (int i = 0; i < count; ++i) {
        std::cout << "- " << matching[i].title << " by " << matching[i].author << "\n";
    }
}



     

