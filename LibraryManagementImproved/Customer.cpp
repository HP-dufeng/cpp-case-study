//
// Created by feng on 19-4-17.
//

#include <set>
#include <map>
#include <list>
#include <string>
#include <fstream>
using namespace std;

#include "Book.h"
#include "Customer.h"
#include "Library.h"

Customer::Customer() {}

Customer::Customer(const string &name, const string &address)
    :m_name(name),
     m_address(address){

}

void Customer::read(ifstream &inStream) {
    getline(inStream, m_name);
    getline(inStream, m_address);
}

void Customer::write(ofstream &outStream) const {
    outStream << m_name << endl;
    outStream << m_address << endl;
}

void Customer::borrowBook(Book *bookPtr) {
    m_loanPtrSet.insert(bookPtr);
    m_reservationPtrSet.erase(bookPtr);
}

void Customer::reserveBook(Book *bookPtr) {
    m_reservationPtrSet.insert(bookPtr);
}

void Customer::returnBook(Book *bookPtr) {
    m_loanPtrSet.erase(bookPtr);
}

void Customer::unreserveBook(Book *bookPtr) {
    m_reservationPtrSet.erase(bookPtr);
}

ostream &operator<<(ostream &outStream, const Customer &customer) {
    outStream << customer.m_name << "," << customer.m_address << ".";

    if(!customer.m_loanPtrSet.empty()) {
        outStream << endl << "Borrowed books: ";
        bool first = true;
        for(const Book *bookPtr : customer.m_loanPtrSet) {
            outStream << (first ? "" : ",") << bookPtr->author();
            first = false;
        }
    }

    if(!customer.m_reservationPtrSet.empty()){
        outStream << endl << " Reserved books: ";
        bool first = true;
        for(Book *bookPtr : customer.m_reservationPtrSet) {
            outStream << (first ? "" : ",") << bookPtr->author();
            first = false;
        }
    }

    return outStream;
}





























