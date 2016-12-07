#include "description.h"


std::string Description::getTitle() const
{
    return title;
}

std::string Description::getSub_title() const
{
    return sub_title;
}

void Description::setTitle(const std::string &value)
{
    title = value;
}

void Description::setSub_title(const std::string &value)
{
    sub_title = value;
}

void Description::setDescription(const std::string &title, const std::string &sub_title)
{
    setTitle(title);
    setSub_title(sub_title);
}

Description::Description(std::string title, std::string sub_title)
{
    setDescription(title, sub_title);
}

Description::Description()
{

}
