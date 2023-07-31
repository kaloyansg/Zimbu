#pragma once
#include "Component.h"

class Memory : public Component
{
private:
	unsigned short capacity;
public:
	Memory(const char* label, unsigned short capacity) : Component(label), capacity(capacity)
	{
		if (capacity < 1 || capacity>10000) throw "Invalid capacity!";
	}

	double price() const override
	{
		return capacity * 89.99;
	}

	Component* clone() const override
	{
		return new Memory(*this);
	}
};

