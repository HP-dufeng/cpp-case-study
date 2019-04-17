//
// Created by feng on 19-4-17.
//
#include <set>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Book.h"
#include "Customer.h"
#include "Library.h"

Book::Book() {}

Book::Book(const string &author, const string &title)
    :m_author(author),
     m_title(title){

}

void Book::read(ifstream &inStream) {
    getline(inStream, m_author);
    getline(inStream, m_title);
}

void Book::write(ofstream &outStream) const {
    outStream << m_author << endl;
    outStream << m_title << endl;
}

int Book::reserveBook(Customer *customerPtr) {
    m_reservationPtrList.push_back(customerPtr);
    return m_reservationPtrList.size();
}

void Book::returnBook() {
    m_borrowerPtr = nullptr;
}

void Book::removeReservation(Customer *customerPtr) {
    m_reservationPtrList.remove(customerPtr);
}

ostream &operator<<(ostream &outStream, const Book &book) {
    outStream << "\"" << book.m_title << "\" by " << book.m_author;
    if(book.m_borrowerPtr != nullptr) {
        outStream << endl << " Borrowed by: " << book.m_borrowerPtr->name() << ".";
    }
    
    if(!book.m_reservationPtrList.empty()){
        outStream << endl << " Reserved by: ";
        bool first = true;
        for(Customer *customerPtr : book.m_reservationPtrList) {
            outStream << (first ? "" : ",") << customerPtr->name();
            first = false;
        }
        outStream << ".";
    }
    
    return outStream;
}


































