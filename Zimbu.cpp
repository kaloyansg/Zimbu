#include <iostream>
#include "Component.h"
#include "Cpu.h";
#include "Memory.h"
#include "Configurations.h"
#include <fstream>

Component* Configurations::create_component()
{
    std::cout << "Enter componen type: CPU / Memory" << std::endl;
    char type[7];

	try
	{
		std::cin >> type;

		if (strcmp(type, "CPU") == 0)
		{
			std::cout << "Enter: label, cores and clock speed" << std::endl;
			char label[1024];

			std::cin >> label;
			unsigned short cores;
			std::cin >> cores;
			unsigned short clockSpeed;
			std::cin >> clockSpeed;

			Component* component = new Cpu(label, cores, clockSpeed);
			return component;
		}

		else if (strcmp(type, "Memory") == 0)
		{
			std::cout << "Enter: label and capacity" << std::endl;
			char label[1024];
			std::cin >> label;
			unsigned short capacity;
			std::cin >> capacity;

			Component* component = new Memory(label, capacity);
			return component;
		}
		else
		{
			std::cout << "Invalid command!";
			return nullptr;
		}
	}
	catch (const char* error)
	{
		std::cout << error << std::endl;
		return nullptr;
	}
	catch (std::bad_alloc& err)
	{
		std::cout << "Not enough memory!";
		return nullptr;
	}
}

int main()
{
	Component* component = Configurations::create_component();
	if (component != nullptr)
		component->output(std::cout);
	std::cout << std::endl;

	Component* purvi = new Cpu("Cpu", 5, 5);
	Component* vtori = new Memory("Memory", 5);

	Component** componenti = new Component * [2];

	componenti[0] = purvi;
	componenti[1] = vtori;

	Configurations komp(componenti, 2);

	Component const* a = &komp[0];
	a->output(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << komp;

	for (size_t i = 0; i < 2; i++)
	{
		delete componenti[i];
	}
	delete[] componenti;

	std::cout << std::endl;
		Configurations* b = nullptr;
	try
	{
		b = create_configuration();
	}
	catch (const char* error)
	{
		std::cerr << error;
	}
	std::cout << *b;

	std::cout << "Enter file name: ";
	char buff[64];
	std::cin >> buff;
	strcat(buff, ".txt");
	std::ofstream fileWriter(buff);
	if (!fileWriter) std::cerr << "File not opened!";
	else fileWriter << *b;
}