#include "utils.h"


void merge(vector<Book>& books, int left, int mid, int right) {
    vector<Book> leftArr(books.begin() + left, books.begin() + mid + 1);
    vector<Book> rightArr(books.begin() + mid + 1, books.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i].title < rightArr[j].title) {
            books[k++] = leftArr[i++];
        } else {
            books[k++] = rightArr[j++];
        }
    }

    while (i < leftArr.size()) {
        books[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        books[k++] = rightArr[j++];
    }
}


void mergeSort(vector<Book>& books, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(books, left, mid);
        mergeSort(books, mid + 1, right);
        merge(books, left, mid, right);
    }
}


int binarySearch(const vector<Book>& books, const string& title) {
    int left = 0;
    int right = books.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid].title == title) {
            return mid;
        } else if (books[mid].title < title) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

