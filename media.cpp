#include "media.h"


std::vector<Author> Media::getInvolved_author() const
{
    return involved_author;
}

std::vector<Author> Media::getAlbum_author() const
{
    return album_author;
}

std::string Media::getAlbum() const
{
    return album;
}

int Media::getYear() const
{
    return year;
}

int Media::getNumber() const
{
    return number;
}

std::string Media::getKind() const
{
    return kind;
}

Time Media::getDuration() const
{
    return duration;
}

void Media::setInvolved_author(const std::vector<Author> &value)
{
    involved_author = value;
}

void Media::setAlbum_author(const std::vector<Author> &value)
{
    album_author = value;
}

void Media::setAlbum(const std::string &value)
{
    album = value;
}

void Media::setYear(int value)
{
    year = value;
}

void Media::setNumber(int value)
{
    number = value;
}

void Media::setKind(const std::string &value)
{
    kind = value;
}

void Media::setDuration(const Time &value)
{
    duration = value;
}

void Media::setMedia(const std::vector<Author> &involved_author, const std::vector<Author> &album_author, const std::string &album, const int &year, const int &number, const std::string &kind, const Time &duration)
{
    setInvolved_author(involved_author);
    setAlbum_author(album_author);
    setAlbum(album);
    setYear(year);
    setNumber(number);
    setKind(kind);
    setDuration(duration);
}

Media::Media(std::vector<Author> involved_author, std::vector<Author> album_author, std::string album, int year, int number, std::string kind, Time duration)
{
    setMedia(involved_author, album_author, album, year, number, kind, duration);
}

Media::Media()
{

}
