#include "Memory.h"

Memory::Memory(const char* label, unsigned short capacity) 
	: Component(label), capacity(capacity)
{
	if (capacity < 1 || capacity>10000) throw"Invalid capacity!";
}

//Component* Memory::clone() const
//{
//	Component* resulnt = new Memory(*this);
//	return resulnt;
//}

double Memory::price() const
{
	return (double)capacity * 89.99;
}

void Memory::output(std::ostream& out) const
{
	this->Component::output(out);
	out << "; Capacity - " << capacity << "; Price: " << this->price();
}
