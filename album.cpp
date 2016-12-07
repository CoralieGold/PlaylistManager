#include "album.h"

void Album::setAuthors(const std::vector<Author> &value)
{
    authors = value;
}

void Album::setTitle(const std::string &value)
{
    title = value;
}

void Album::setYear(int value)
{
    year = value;
}

std::vector<Author> Album::getAuthors() const
{
    return authors;
}

std::string Album::getTitle() const
{
    return title;
}

int Album::getYear() const
{
    return year;
}

Album::Album()
{
    
}

std::string Album::print() {
    return title << " - " << year;
}
