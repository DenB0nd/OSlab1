#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>


struct Employee
{
    int num;
    char name[10];
    double hours;
};


void addEmployee(std::ofstream& out)
{
    Employee employee = {};
    std::cout << "Number:";
    std::cin >> employee.num;
    std::cout << "Name:";
    std::cin >> employee.name;
    std::cout << "Hours:";
    std::cin >> employee.hours;

    out.write((char*)&employee, sizeof(employee));
}


int main(int argc, char* args[])
{
    if (argc < 3)
    {
        std::cout << "Not enough arguments.\n";
        return 0;
    }
    
    int lines = atoi(args[2]);
    std::ofstream out(args[1], std::ios::binary);

    if (!out)
    {
        std::cout << "File wasn't opened.\n";
    }

    for (int i = lines; i >= 0; i--)
    {
        addEmployee(out);
    }
    out.close();

    std::cout << "Programm finished successfully.\n";
    return 0;
}