#ifndef MEDIA_H
#define MEDIA_H

#include "author.h"
#include "time.h"
#include <iostream>
#include <vector>

class Media
{ 
private:
    std::vector<Author> involved_author;
    std::vector<Author> album_author;
    std::string album;
    int year;
    int number;
    std::string kind;
    Time duration;

public:
    std::vector<Author> getInvolved_author() const;
    std::vector<Author> getAlbum_author() const;
    std::string getAlbum() const;
    int getYear() const;
    int getNumber() const;
    std::string getKind() const;
    Time getDuration() const;

    void setInvolved_author(const std::vector<Author> &value);
    void setAlbum_author(const std::vector<Author> &value);
    void setAlbum(const std::string &value);
    void setYear(int value);
    void setNumber(int value);
    void setKind(const std::string &value);
    void setDuration(const Time &value);
    void setMedia(const std::vector<Author> &involved_author, const std::vector<Author> &album_author, const std::string &album, const int &year, const int &number, const std::string &kind, const Time &duration);

    Media(std::vector<Author> involved_author, std::vector<Author> album_author, std::string album, int year, int number, std::string kind, Time duration);
    Media();
};

#endif // MEDIA_H
