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
    User(std::string void_name, std::string void_surname)
    {
        user_name = void_name;
        user_surname = void_surname;
    }
    void Print_user()
    {
        std::cout << user_name << " " << user_surname << std::endl;
    }
};

struct TextFile
{
    TextFile(std::string file_name, std::string file_surname) : file_name{ file_name }, file_surname{ file_surname } {}
    std::string file_name;
    std::string file_surname;
};

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
    user.Print_user();

    std::vector<TextFile> text{TextFile{name, surname}};
    std::ofstream out("print_info.txt");
    if(out.is_open())
    {
        for(const TextFile& texts : text)
        {
            out << texts.file_name << " " << texts.file_surname;
        }
    }
    out.close();

    return 0;
}