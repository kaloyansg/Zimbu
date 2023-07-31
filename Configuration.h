#pragma once
#include "Component.h"
#include "Cpu.h"
#include "Memory.h"
#pragma warning (disable:4996)
class Configuration
{
private:
	Component** components;
	std::size_t numberOfComponents;

	Configuration()
	{
		components = new Component * [0];
		numberOfComponents = 0;
	}

	void insert(const Component* c)
	{
		for (size_t i = 0; i < numberOfComponents; i++)
		{
			if (strcmp(typeid(*components[i]).name(), typeid(*c).name()) == 0) throw "Component already in configuration!";
		}

		Component** newComponents = new Component * [numberOfComponents + 1];
		for (size_t i = 0; i < numberOfComponents; i++)
		{
			newComponents[i] = components[i];
		}
		newComponents[numberOfComponents] = (Component*)c;
		delete[] components;
		components = newComponents;
		numberOfComponents++;
	}

public:
	Configuration(Component** components, std::size_t numbeOfComponents) : numberOfComponents(numbeOfComponents)
	{
		for (size_t i = 0; i < numbeOfComponents-1; i++)
		{
			for (size_t j = i+1; j < numbeOfComponents; j++)
			{
				std::string a = typeid(*components[i]).name();
				std::string b = typeid(*components[j]).name();
				if (strcmp(typeid(*components[i]).name(), typeid(*components[j]).name()) == 0) 
					throw "Invalid list of components!";
			}
		}

		this->components = new Component * [numbeOfComponents];

		for (size_t i = 0; i < numbeOfComponents; i++)
		{
			this->components[i] = components[i];
		}
	}

	~Configuration()
	{
		for (size_t i = 0; i < numberOfComponents; i++)
		{
			delete components[i];
		}
		delete[] components;
	}

	Configuration(const Configuration&) = delete;
	Configuration& operator=(const Configuration&) = delete;

	double price() const
	{
		double result = 0;
		for (size_t i = 0; i < numberOfComponents; i++)
		{
			result += components[i]->price();
		}
		return result;
	}

	std::size_t size() const
	{
		return numberOfComponents;
	}

	const Component& operator[](std::size_t index) const
	{
		if (index<0 || index>numberOfComponents - 1) throw "Invalid index!";

		return *components[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Configuration& cof)
	{
		for (size_t i = 0; i < cof.numberOfComponents; i++)
		{
			cof.components[i]->output(os);
			os << std::endl;
		}

		double price = 0;
		for (size_t i = 0; i < cof.numberOfComponents; i++)
		{
			price += cof.components[i]->price();
		}
		os << price << std::endl;

		return os;
	}

	static Component* creatComponent();

	friend Configuration* createConfiguration();
};


Component* Configuration::creatComponent()
{
	std::cout << "Enter component type (cpu/memory): ";
	std::string type;
	std::cin >> type;

	try
	{
		if (strcmp(type.c_str(), "cpu") == 0)
		{
			std::cout << "Enter label: ";
			std::string label;
			std::cin >> label;
			unsigned short cores, clockSpeed;
			std::cout << "Enter number of cores: ";
			std::cin >> cores;
			std::cout << "Enter clock speed: ";
			std::cin >> clockSpeed;
			Component* result = new Cpu(label.c_str(), cores, clockSpeed);
			return result;
		}
		else if (strcmp(type.c_str(), "memory") == 0)
		{
			std::cout << "Enter label: ";
			std::string label;
			std::cin >> label;
			unsigned short capacity;
			std::cout << "Enter capacity: ";
			std::cin >> capacity;
			Component* result = new Memory(label.c_str(), capacity);
			return result;
		}
		else
		{
			throw "Invalid component type!";
		}
	}
	catch (const char* error)
	{
		std::cout << error;
		return nullptr;
	}
}

Configuration* createConfiguration()
{
	Configuration* conf = new Configuration();
	std::cout << "Number of cmponents: ";
	unsigned short numberOfComponents;
	std::cin >> numberOfComponents;

	for (size_t i = 0; i < numberOfComponents; i++)
	{
		try
		{
			Component* comp = Configuration::creatComponent();
			conf->insert(comp);
		}
		catch (const const char* err)
		{
			std::cout << err << std::endl;
		}
	}

	return conf;
}