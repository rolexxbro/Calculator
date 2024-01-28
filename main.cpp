#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>


class Menu
{
private:
    std::string punkt_1  = "1. #####";
    std::string punkt_2  = "2. #####";
    std::string print_punkt;
public:
    void List_print()
    {
        std::cout << punkt_1 << "\n" << punkt_2 << std::endl;
    }
    Menu(int num_punkt)
    {
        switch(num_punkt)
        {
            case 1:
            {
                print_punkt = punkt_1;
                break;
            }
            case 2:
            {
                print_punkt = punkt_2;
                break;
            }
        }
    }
    void Print_Menu()
    {
        std::cout << "You enter: " << print_punkt << std::endl;
    }
};

class User
{
private:
    std::string user_name;
    std::string user_surname;
public:
/*    User(std::string void_name, std::string void_surname)
    {
        user_name = void_name;
        user_surname = void_surname;
    }
    void Print_user()
    {
        std::cout << user_name << " " << user_surname << std::endl;
    } */
    User(std::string name, std::string surname): user_name{name}, user_surname{surname} {}
    std::string getName() const {return user_name;}
    std::string getSurname() const {return user_surname;}
    void setNameSurname(std::string in_name, std::string in_surname)
    {
        in_name = user_name;
        in_surname  = user_surname;
    }

};

std::ostream& operator << (std::ostream &os, const User &person)
{
    return os << person.getName() << " " << person.getSurname();
}

int main()
{
    int void_num_menu;
    std::cout << "Please Enter num Menu: ";
    std::cin >> void_num_menu;

    Menu m(void_num_menu);
    m.List_print();
    m.Print_Menu();
    std::cout << std::endl;

    std::string name;
    std::string surname;
    std::cout << "Enter Name: ";
    std::cin >> name;
    std::cout << "Enter Surname: ";
    std::cin >> surname;
    User user(name, surname);
    //user.Print_user();

    std::vector<User> people = { User{name, surname} };
    std::ofstream out("people.txt");
    if (out.is_open())
    {
        for (const User& person: people)
        {
            out << person << std::endl;
        }
    }
    out.close();

    system("pause");
}