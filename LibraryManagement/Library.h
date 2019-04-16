//
// Created by feng on 19-4-16.
//

#ifndef LIBRARYMANAGEMENT_LIBRARY_H
#define LIBRARYMANAGEMENT_LIBRARY_H

#endif //LIBRARYMANAGEMENT_LIBRARY_H

class Library {
public:
    Library();

private:
    static string s_binaryPath;
    bool lookupBook(const string &author, const string &title, Book* bookPtr = nullptr)
};