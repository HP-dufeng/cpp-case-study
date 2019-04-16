//
// Created by feng on 19-4-16.
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

int Customer::MaxCustomerId;

Customer::Customer() {}

Customer::Customer(const string &name, const string &address)
    :m_customerId(++MaxCustomerId),
     m_name(name),
     m_address(address){

}

void Customer::read(ifstream &inStream) {
    inStream.read((char*)&m_customerId, sizeof m_customerId);

    getline(inStream, m_name);
    getline(inStream, m_address);

    {
        int loanSetSize;
        inStream.read((char*)&loanSetSize, sizeof loanSetSize);

        for(int count=0; count<loanSetSize; ++count) {
            int bookId;
            inStream.read((char*)&bookId, sizeof bookId);
            m_loanSet.insert(bookId);
        }
    }

    {
        int reservationListSize;
        inStream.read((char*)&reservationListSize, sizeof reservationListSize);

        for(int count=0; count<reservationListSize; ++count) {
            int bookId;
            inStream.read((char*)&bookId, sizeof bookId);
            m_loanSet.insert(bookId);
        }
    }
}

void Customer::write(ofstream &outStream) const {
    outStream.write((char*)&m_customerId, sizeof m_customerId);
    outStream << m_name << endl;
    outStream << m_address << endl;

    {
        int loanSetSize = m_loanSet.size();
        outStream.write((char*)&loanSetSize, sizeof loanSetSize);

        for(int bookId : m_loanSet) {
            outStream.write((char*)&bookId, sizeof bookId);
        }
    }

    {
        int reservationListSize = m_reservationSet.size();
        outStream.write((char*)&reservationListSize, sizeof reservationListSize);

        for(int bookId : m_reservationSet) {
            outStream.write((char*)&bookId, sizeof bookId);
        }
    }
}

void Customer::borrowBook(int bookId) {
    m_loanSet.insert(bookId);
}

void Customer::reserveBook(int bookId) {
    m_reservationSet.insert(bookId);
}

void Customer::returnBook(int bookId) {
    m_loanSet.erase(bookId);
}

void Customer::unreserveBook(int bookId) {
    m_reservationSet.erase(bookId);
}

ostream &operator<<(ostream &outStream, const Customer& customer) {
    outStream << customer.m_customerId << "."
              << customer.m_name << ","
              << customer.m_address << ".";

    if(!customer.m_loanSet.empty()) {
        outStream << endl << "Borrowed books:";

        bool first = true;
        for(int bookId : customer.m_loanSet) {
            outStream << (first ? "" : ",")
                      << Library::s_bookMap[bookId].author();
            first = false;
        }
    }

    if(!customer.m_reservationSet.empty()) {
        outStream << endl << "Reserved books:";

        bool first = true;
        for(int bookId : customer.m_reservationSet) {
            outStream << (first ? "" : ",")
                      << Library::s_bookMap[bookId].title();
            first = false;
        }
    }

    return outStream;
}









































