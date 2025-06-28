#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "book.h"
using namespace std;

void merge(vector<Book> &books, int left, int mid, int right);
void mergeSort(vector<Book> &books, int left, int right);

int binarySearch(const vector<Book> &books, const string& title);

#endif