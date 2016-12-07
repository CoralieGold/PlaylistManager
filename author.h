#ifndef AUTHOR
#define AUTHOR

#include <iostream>

class Author {
private:
    std::string name;

public:
    std::string getName() const;

    void setName(const std::string &value);
    void setAuthor(const std::string &name);

    Author(std::string name);
    Author();

    std::string print();

    bool operator==(Author const& b);
};

#endif // AUTHOR
