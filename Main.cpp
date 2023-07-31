#include <iostream>
#pragma warning (disable:4996)
#include "Component.h"
#include "Cpu.h"
#include "Memory.h"
#include "Configuration.h"

int main()
{
    std::cout << "Hello World!\n";

	Component* a = nullptr;
	Component* b = nullptr;
	try
	{
		a = new Cpu("processor", 5, 50);
		a->output(std::cout);
		std::cout<<std::endl;

		b = new Memory("memory", 25);
		b->output(std::cout);
		std::cout << std::endl;
	}
	catch (const char* error)
	{
		std::cout << error;
	}

	delete a;
	delete b;

	//Component* component = creatComponent();
	//if (component != nullptr) component->output(std::cout);

	/*Component** components = new Component*[1];
	components[0] = a;*/
	//components[1] = b;

	/*try
	{
		Configuration conf(components, 1);
		std::cout << conf;

	}
	catch (const char* err)
	{
		std::cout << err;
	}*/

	Configuration* conf = createConfiguration();
	std::cout << conf;
	delete conf;
}