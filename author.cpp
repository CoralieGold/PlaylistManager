#include "author.h"

std::string Author::getName() const
{
    return name;
}

void Author::setName(const std::string &value)
{
    name = value;
}

void Author::setAuthor(const std::string &name) {
    setName(name);
}

Author::Author(std::string name)
{
    setAuthor(name);
}

Author::Author()
{
}

std::string Author::print() {
    return name;
}

bool Author::operator==(Author const& b) {
    if (name == b.getName()) return true;
    else return false;
}
