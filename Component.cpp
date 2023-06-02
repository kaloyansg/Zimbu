#include "Component.h"

Component::Component(const char* label)
{
	this->label = new char[strlen(label) + 1];
	strcpy((char*)this->label, label);
}

Component::Component(const Component& other)
{
	this->label = new char[strlen(other.label) + 1];
	strcpy((char*)this->label, other.label);
}

//Component& Component::operator=(const Component& other)
//{
//	if (this == &other) return *this;
//
//	char* tempName = new char[strlen(other.label) + 1];
//	delete[] this->label;
//	strcpy((char*)this->label, other.label);
//	
//	return *this;
//}

void Component::output(std::ostream& out) const
{
	out << label;
}

Component::~Component()
{
	delete[] label;
}
