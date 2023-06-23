#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; i++)
    {
        this->contacts[i].setIndex(i);
        this->contacts[i].setName("");
        this->contacts[i].setSurname("");
        this->contacts[i].setNickname("");
        this->contacts[i].setPhoneNumber("");
        this->contacts[i].setDarkestSecret("");
    }
}

void    PhoneBook::setContact(int id, std::string name, std::string surname,
                std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    this->contacts[id].setIndex(id);
    this->contacts[id].setName(name);
    this->contacts[id].setSurname(surname);
    this->contacts[id].setNickname(nickname);
    this->contacts[id].setPhoneNumber(phoneNumber);
    this->contacts[id].setDarkestSecret(darkestSecret);
}

void    PhoneBook::getContactInfo(int id)
{
    std::cout << "Index         : " << 1 + contacts[id].getIndex() << std::endl;
    std::cout << "Name          : " << contacts[id].getName() << std::endl;
    std::cout << "Surname       : " << contacts[id].getSurname() << std::endl;
    std::cout << "Nickname      : " << contacts[id].getNickname() << std::endl;
    std::cout << "Phone Number  : " << contacts[id].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[id].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}

Contact PhoneBook::getContact(int id)
{
    return (this->contacts[id]);
}
