#pragma once
#include "Component.h"

class Cpu:public Component
{
private:
	const unsigned short cores;
	const unsigned short clockSpeed;

public:
	Cpu(const char* label, unsigned short cores, unsigned short clockSpeed);

	//Component* clone() const override;

	double price() const override;
	void output(std::ostream& out) const override;
};

