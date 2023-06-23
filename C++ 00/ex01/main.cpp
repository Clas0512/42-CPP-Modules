#include "PhoneBook.hpp"
#include "Contact.hpp"

void    table(PhoneBook phoneBook)
{
    std::cout << "\e[47m" << " ------------------------------------------- " << std::endl;
    std::cout << "\e[47m" << "|   index  |   name   |  surname | nickname |" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "\e[47m" << "|----------|----------|----------|----------|" << std::endl;
        if (!(phoneBook.getContact(i).getName() == ""))
        {
            std::cout << "\e[47m" << "|" << std::setw(10) << i + 1 << "|";
            if (phoneBook.getContact(i).getName().length() > 10)
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getName().substr(0, 9) + "." << "|";
            else
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getName() << "|";
            if (phoneBook.getContact(i).getSurname().length() > 10)
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getSurname().substr(0, 9) + "." << "|";
            else
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getSurname() << "|";
            if (phoneBook.getContact(i).getNickname().length() > 10)
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getNickname().substr(0, 9) + "." << "|" << std::endl;
            else
                std::cout << "\e[47m" << std::setw(10) << phoneBook.getContact(i).getNickname() << "|" << std::endl;
        }
        else
        {
            std::cout << "|" << std::setw(10) << i + 1 << "|";
            std::cout << std::setw(10) << phoneBook.getContact(i).getName() << "|";
            std::cout << std::setw(10) << phoneBook.getContact(i).getSurname() << "|";
            std::cout << std::setw(10) << phoneBook.getContact(i).getNickname() << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;
}

int checkSlots(PhoneBook &phoneBook, int &firstId)
{
    for (int i = 0; i < 8; i++)
    {
        if (phoneBook.getContact(i).getName().length() < 1)
            return (i);
    }
    if (firstId == 8)
        firstId = 0;
	return (0);
}

int isInt(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void    addMenu(PhoneBook &phoneBook, int &firstId)
{
    std::string name;
    std::string surname;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    std::cout << "Please enter a name: " << std::endl;
    getline(std::cin, name);
    while (name == "")
    {
        std::cout << "Name can't be empty" << std::endl;
        std::cout << "Please enter a name: " << std::endl;
        getline(std::cin, name);
    }
    std::cout << "Please enter a surname: " << std::endl;
    getline(std::cin, surname);
    while (surname == "")
    {
        std::cout << "Surname can't be empty" << std::endl;
        std::cout << "Please enter a surname: " << std::endl;
        getline(std::cin, surname);
    }
    std::cout << "Please enter a nickname: " << std::endl;
    getline(std::cin, nickname);
    while (nickname == "")
    {
        std::cout << "Nickname can't be empty" << std::endl;
        std::cout << "Please enter a nickname: " << std::endl;
        getline(std::cin, nickname);
    }
    std::cout << "Please enter a phone number: " << std::endl;
    getline(std::cin, phoneNumber);
    while (!isInt(phoneNumber))
    {
        std::cout << "A phone number cannot include alphabetical characters" << std::endl;
        getline(std::cin, phoneNumber);
    }
    while (phoneNumber == "")
    {
        std::cout << "Phone number can't be empty" << std::endl;
        std::cout << "Please enter a phone number: " << std::endl;
        getline(std::cin, phoneNumber);
        while (!isInt(phoneNumber))
        {
            std::cout << "A phone number cannot include alphabetical characters" << std::endl;
            getline(std::cin, phoneNumber);
        }
    }
    std::cout << "Please enter a darkest secret: " << std::endl;
    getline(std::cin, darkestSecret);
    while (darkestSecret == "")
    {
        std::cout << "Darkest secret can't be empty" << std::endl;
        std::cout << "Please enter a dark secret: " << std::endl;
        getline(std::cin, darkestSecret);
    }
	checkSlots(phoneBook, firstId);
    phoneBook.setContact(firstId, name, surname, nickname, phoneNumber, darkestSecret);
    firstId++;
    std::cout << "Contact added" << std::endl;
}

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
	int firstId;
    PhoneBook phoneBook;
    std::string choose;
    std::string chooseId;
	firstId = 0;
    std::cout << "Welcome the PhoneBook" << std::endl;
    while (true)
    {
        std::cout << "Please enter a command\n(ADD, SEARCH or EXIT): " << std::endl;
        std::getline(std::cin, choose);
        if (std::cin.eof() == 1)
        {
            std::cout << "You entered EOF.\nExiting...";
            return 1;
        }
        else if (choose == "ADD")
        {
            table(phoneBook);
            addMenu(phoneBook, firstId);
            continue;
        }
        else if (choose == "SEARCH")
        {
            table(phoneBook);
            int id;
            std::cout << "Please enter contact id for see a contact informations: " << std::endl;
            std::cout << "Enter index : ";
            getline(std::cin, chooseId);
            std::cout << std::endl;
            while (!isInt(chooseId))
            {
                std::cout << "Please enter number: " << std::endl;
                getline(std::cin, chooseId);
            }
            while (std::stoi(chooseId) - 1 > 7 || std::stoi(chooseId) - 1 < 0)
            {
                std::cout << "Error: Invalid id" << std::endl;
                std::cout << "Please enter contact id for see a contact informations: " << std::endl;
                getline(std::cin, chooseId);
            }
            id = std::stoi(chooseId) - 1;
            phoneBook.getContactInfo(id);
            continue;
        }
        else if (choose == "EXIT")
            return (0);
        else
        {
            std::cout << "\nError: Invalid command\n" << std::endl;
            continue;
        }
    }
}
