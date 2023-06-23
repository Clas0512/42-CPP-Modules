#include "Contact.hpp"

void    Contact::setIndex(int index)
{
    this->index = index;
}

void    Contact::setName(std::string name)
{
    this->name = name;
}

void    Contact::setSurname(std::string surname)
{
    this->surname = surname;
}

void    Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void    Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

int Contact::getIndex()
{ 
    return (this->index);
}

std::string Contact::getName()
{
    return (this->name);
}

std::string Contact::getSurname()
{
    return (this->surname);
}

std::string Contact::getNickname()
{
    return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}
