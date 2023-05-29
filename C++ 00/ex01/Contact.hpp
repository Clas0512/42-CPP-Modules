#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
    int		index;
    std::string	name;
    std::string	surname;
    std::string	nickname;
    std::string	phoneNumber;
    std::string	darkestSecret;
public:
	void		setIndex(int index);
	void		setName(std::string name);
	void		setSurname(std::string surname);
	void		setNickname(std::string nickname);
	void		setPhoneNumber(std::string phoneNumber);
	void		setDarkestSecret(std::string darkestSecret);
	std::string	getIndex();
    std::string getName();
    std::string getSurname();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
};

#endif