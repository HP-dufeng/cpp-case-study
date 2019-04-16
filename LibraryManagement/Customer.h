//
// Created by feng on 19-4-16.
//

#ifndef LIBRARYMANAGEMENT_CUSTOMER_H
#define LIBRARYMANAGEMENT_CUSTOMER_H

#endif //LIBRARYMANAGEMENT_CUSTOMER_H

#include <string>
#include <set>
using namespace std;

class Customer {
public:
    Customer();
    Customer(const string &name, const string &address);

    void read(ifstream &inStream);
    void write(ofstream &outStream) const;

    void borrowBook(int bookId);
    void reserveBook(int bookId);
    void returnBook(int bookId);
    void unreserveBook(int bookId);

    bool hasBorrowed() const {
        return !m_loanSet.empty();
    }

    const string &name() const {return m_name;}
    const string &address() const {return m_address;}
    int id() const {return m_customerId; }

    static int MaxCustomerId;

    friend ostream &operator<<(ostream &outStream, const Customer &customer);

private:
    int m_customerId;
    string m_name, m_address;
    set<int> m_loanSet, m_reservationSet;
};