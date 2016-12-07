#ifndef DESCRIPTION_H
#define DESCRIPTION_H

#include <iostream>

class Description
{
private:
    std::string title;
    std::string sub_title;

public:
    std::string getTitle() const;
    std::string getSub_title() const;

    void setTitle(const std::string &value);
    void setSub_title(const std::string &value);
    void setDescription(const std::string &title, const std::string &sub_title);

    Description(std::string title, std::string sub_title);
    Description();
};

#endif // DESCRIPTION_H
