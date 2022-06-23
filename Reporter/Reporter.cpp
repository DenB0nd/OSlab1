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

void addLine(std::ofstream& out, Employee nextEmployee, int salary)
{
	out << "Номер: " << nextEmployee.num;
	out << "Имя: " << nextEmployee.name;
	out << "Часы работы: " << nextEmployee.hours;
	out << "Зарплата: " << nextEmployee.hours * salary;

}

int main(int argc, char* args[])
{
	setlocale(LC_ALL, "rus");

	if (argc < 4)
	{
		std::cout << "Not enought arguments.\n";
		return 0;
	}

	std::ifstream binary(args[1], std::ios::binary);
	std::ofstream out(args[2]);
	out << "Отчет по файлу " << args[1] << "\n\n";
	int salary = atoi(args[3]);

	Employee nextEmployee = {};
	while (binary.is_open())
	{
		binary.read((char*)&nextEmployee, sizeof(Employee));
		addLine(out, nextEmployee, salary);
	}

	std::cout << "Programm finished successfully\n";
}