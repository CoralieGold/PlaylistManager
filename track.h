#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <vector>
#include <string>
#include "author.h"

class Track
{
private:
    std::string title;
    Author author;
    std::string path;
public:
    std::string getTitle() const;
    Author getAuthor() const;
    std::string getPath() const;

    void setTitle(const std::string &value);
    void setPath(const std::string &value);
    void setAuthor(const Author &value);
    void setTrack(const std::string &title, const Author &author, const std::string &path);

    std::string print();

    Track(std::string title, Author author, std::string path);
    Track();

    bool operator==(Track const& b);
};

#endif // TRACK_H
