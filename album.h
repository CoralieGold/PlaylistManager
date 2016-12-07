#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <vector>
#include <string>
#include "author.h"

class Album
{
private:
    std::vector<Author> authors;
    std::string title;
    int year;
public:
    Album();

    void setAuthors(const std::vector<Author> &value);
    void setTitle(const std::string &value);
    void setYear(int value);
    std::vector<Author> getAuthors() const;
    std::string getTitle() const;
    int getYear() const;

    std::string print();
};

#endif // ALBUM_H
