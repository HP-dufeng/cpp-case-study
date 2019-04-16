//
// Created by feng on 19-4-16.
//

#ifndef LIBRARYMANAGEMENT_BOOK_H
#define LIBRARYMANAGEMENT_BOOK_H

#endif //LIBRARYMANAGEMENT_BOOK_H

#include <string>
#include <iostream>
#include <list>
using namespace std;

class Book{
public:
    Book();
    Book(const string &author, const string &title);

    const string &author() const { return m_author; }
    const string &title() const { return m_title; }

    void read(ifstream &inStream);
    void write(ofstream &outStream) const;

    void borrowBook(int customerId);
    int reserveBook(int customerId);
    void unreserveBookation(int customerId);
    void returnBook();

    int bookId() const { return m_bookId; }

    bool borrowed() const { return m_borrowed; }
    int customerId() const { return m_customerId; }

    list<int> &reservationList() { return m_reservationList; }

    static int MaxBookId;

    friend ostream& operator<<(ostream &outStream, const Book &book);

private:
    bool m_borrowed = false;
    int m_bookId;
    int m_customerId;
    string m_author;
    string m_title;
    list<int> m_reservationList;
};
