#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>
#include <string>

class PhoneBook
{
private:
    Contact	contacts[8];
public:
    PhoneBook();
    void	setContact(int id, std::string name, std::string surname, std::string nickname,
						std::string phoneNumber, std::string darkestSecret);
	void	getContactInfo(int id);
	Contact	getContact(int id);
};

#endif