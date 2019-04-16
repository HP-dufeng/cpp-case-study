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
#include "Library.h"
#include "Customer.h"

int Book::MaxBookId = 0;

Book::Book() {}

Book::Book(const string &author, const string &title)
     :m_bookId(++MaxBookId),
      m_author(author),
      m_title(title){

}

void Book::write(ofstream &outStream) const {
    outStream.write((char*)&m_bookId, sizeof m_bookId);

    outStream << m_author << endl;
    outStream << m_title << endl;

    outStream.write((char*)&m_borrowed, sizeof m_borrowed);
    outStream.write((char*)&m_customerId, sizeof m_customerId);

    {
        int reserveListSize = m_reservationList.size();
        outStream.write((char*)&reserveListSize, sizeof reserveListSize);

        for(int customerId : m_reservationList) {
            outStream.write((char*)&customerId, sizeof customerId);
        }
    }
}

void Book::read(ifstream &inStream) {
    inStream.read((char*)&m_bookId, sizeof m_bookId);

    getline(inStream, m_author);
    getline(inStream, m_title);

    inStream.read((char*)&m_borrowed, sizeof m_borrowed);
    inStream.read((char*)&m_customerId, sizeof m_customerId);

    {
        int reservationListSize;
        inStream.read((char*)&reservationListSize, sizeof reservationListSize);

        for(int count=0; count<reservationListSize; ++count) {
            int customerId;
            inStream.read((char*)&customerId, sizeof customerId);
            m_reservationList.push_back(customerId);
        }
    }
}

void Book::borrowBook(int customerId) {
    m_borrowed = true;
    m_customerId = customerId;
}

int Book::reserveBook(int customerId) {
    m_reservationList.push_back(customerId);
    return m_reservationList.size();
}

void Book::returnBook() {
    m_borrowed = false;
}

void Book::unreserveBookation(int customerId) {
    m_reservationList.remove(customerId);
}

ostream& operator<<(ostream &outStream, const Book &book) {
    outStream << "\"" << book.m_title << "\"by" << book.m_author;

    if(book.m_borrowed) {
        outStream << endl << "Borrowed by:"
                  << Library::s_customerMap[book.m_customerId].name()
                  <<".";
    }

    if(!book.m_reservationList.empty()) {
        outStream << endl << "Reserved by:";
        bool first = true;
        for(int customerId : book.m_reservationList) {
            outStream << (first ? "" : ",")
                      << Library::s_customerMap[customerId].name();
            first = false;
        }

        outStream << ".";
    }

    return outStream;
}
