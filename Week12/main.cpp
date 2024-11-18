#include <iostream>
#include "Book.h"
using namespace std;
using namespace seneca;


void swap(Book& A, Book& B);
void sort(Book* arr[], int n);
void deallocate(LibraryItem* item);
void display(LibraryItem* item, int row);
int main() {
    const int SIZE = 5;
    int i{};
    LibraryItem* libraryItems[SIZE] = {
        new LibraryItem("The Great Gatsby", 1925),
        new LibraryItem("To Kill a Mockingbird", 1960),
        new LibraryItem("1984", 1949),
        new LibraryItem("Brave New World", 1932),
        new LibraryItem("The Catcher in the Rye", 1951)
    };
    Book* books[SIZE] = {
        new Book("The Catcher in the Rye", 1951, "J.D. Salinger"),
        new Book("The Hobbit", 1937, "J.R.R. Tolkien"),
        new Book("Pride and Prejudice", 1813, "Jane Austen"),
        new Book("1984", 1949, "George Orwell"),
        new Book("The Great Gatsby", 1925, "F. Scott Fitzgerald")
    };

    cout << "Library Items:" << endl;
    cout << "***********************************************" << endl;
    for (i = 0; i < SIZE; i++) {
        display(libraryItems[i], i + 1);
    }
    cout << "\nBooks:" << endl;
    cout << "***********************************************" << endl;

    for (i = 0; i < SIZE; i++) {
        display(books[i], i + 1);
    }

    cout << endl
        << "Testing Copy Assignment and copy constructor" << endl;
    cout << "***********************************************" << endl;
    cout << "Books sorted by publication year:" << endl;

    sort(books, SIZE);

    for (i = 0; i < SIZE; i++) {
        display(books[i], i + 1);
    }

    for (int i = 0; i < SIZE; i++) {
        deallocate(libraryItems[i]);
        deallocate(books[i]);
    }
    return 0;
}

void deallocate(LibraryItem* item) {
    delete item;
}

void display(LibraryItem* item, int row) {
   cout << row << ">" << endl;
    item->display() << endl;
    cout << "===============================================" << endl;
}


void swap(Book& A, Book& B) {
    Book T = A;
    A = B;
    B = T;
}
void sort(Book* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                swap(*arr[j], *arr[j + 1]);
            }
        }
    }
}
