#include "Configurations.h"

Configurations::Configurations()
{
	components = new Component*[0];
	numberOfComponents = 0;
}

bool Configurations::checkConfiguration(const Component* c)
{
	for (size_t i = 0; i < numberOfComponents; i++)
	{
		if (strcmp(typeid(components[i]).name(), typeid(c).name()) == 0)
			return true;
	}
	return false;
}

void Configurations::insert(const Component* c)
{
	if (checkConfiguration(c))
	{
		throw "This component is already in the configuration!";
	}
	Component** temp = new Component * [numberOfComponents + 1];
	for (size_t i = 0; i < numberOfComponents; i++)
	{
		temp[i] = components[i];
	}
	temp[numberOfComponents] = const_cast<Component*>(c);
	delete[] components;
	components = temp;
	numberOfComponents++;
}

Configurations::Configurations(Component** components, unsigned numberOfComponents)
{
	this->components = new Component * [numberOfComponents];
	for (size_t i = 0; i < numberOfComponents; i++)
	{
		this->components[i] = components[i];//->clone();
	}
	this->numberOfComponents = numberOfComponents;
}


//Configurations::Configurations(const Configurations& other)
//{
//	this->components = new Component * [other.numberOfComponents];
//
//	for (size_t i = 0; i < other.numberOfComponents; i++)
//	{
//		this->components[i] = other.components[i];//->clone();
//	}
//
//	this->numberOfComponents = other.numberOfComponents;
//}
//
//Configurations& Configurations::operator=(const Configurations& other)
//{
//	if (this == &other) return *this;
//
//	Component** tempComponents = new Component * [other.numberOfComponents];
//
//	for (size_t i = 0; i < other.numberOfComponents; i++)
//	{
//		tempComponents[i] = other.components[i]; // ->clone();
//	}
//
//	//for (size_t i = 0; i < this->numberOfComponents; i++)
//	//{
//	//	delete this->components[i];
//	//}
//	delete[] this->components;
//	this->components = tempComponents;
//	this->numberOfComponents = other.numberOfComponents;
//	return *this;
//}


Configurations::~Configurations()
{
	//for (size_t i = 0; i < numberOfComponents; i++)
	//{
	//	delete components[i];
	//}
	delete[] components;
}

double Configurations::price() const
{
	double result = 0;

	for (size_t i = 0; i < numberOfComponents; i++)
	{
		result += components[i]->price();
	}

	return result;
}

std::size_t Configurations::size() const
{
	return numberOfComponents;
}

const Component& Configurations::operator[](std::size_t index) const
{
	if (index<0 || index > numberOfComponents - 1) throw "Invalid index!";

	return *components[index];
}

std::ostream& operator<<(std::ostream& os, const Configurations& conf)
{
	for (size_t i = 0; i < conf.numberOfComponents; i++)
	{
		conf.components[i]->output(os);
		os << std::endl;
	}
	os << "Final price: " << conf.price();
	return os;
}

Configurations* create_configuration()
{
	std::cout << "Number of components: ";
	unsigned number;
	std::cin >> number;
	Configurations* configuration = new Configurations();
	for (size_t i = 0; i < number; i++)
	{
		configuration->insert(Configurations::create_component());
	}
	return configuration;
}