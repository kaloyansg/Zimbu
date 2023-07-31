#pragma once
#include "Component.h"
class Cpu : public Component
{
private:
	unsigned short cores;
	unsigned short clockSpeed;

public:
	Cpu(const char* label, unsigned short cores, unsigned short clockSpeed) 
		: Component(label), cores(cores), clockSpeed(clockSpeed)
	{
		if (cores < 1 || cores>8) throw "Invalid cores!";
	}

	double price() const override
	{
		return cores * 29.99;
	}

	Component* clone() const override
	{
		return new Cpu(*this);
	}
};

