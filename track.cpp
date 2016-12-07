#include "track.h"


Author Track::getAuthor() const
{
    return author;
}

void Track::setAuthor(const Author &value)
{
    author = value;
}

std::string Track::getTitle() const
{
    return title;
}

void Track::setPath(const std::string &value)
{
    path = value;
}

std::string Track::getPath() const
{
    return path;
}


void Track::setTitle(const std::string &value)
{
    title = value;
}

void Track::setTrack(const std::string &title, const Author &author, const std::string &path)
{
    setTitle(title);
    setAuthor(author);
    setPath(path);
}

Track::Track(std::string title, Author author, std::string path)
{
    setTrack(title, author, path);
}

Track::Track()
{

}

std::string Track::print() {
    return title + " - " + author.print() + " (" + path + ")";
}

bool Track::operator==(Track const& b) {
    if (title == b.getTitle() && author == b.getAuthor() && path == b.getPath()) return true;
    else return false;
}
