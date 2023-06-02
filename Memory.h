#pragma once
#include "Component.h"
class Memory : public Component
{
private:
	const unsigned short capacity;
public:
	Memory(const char* label, unsigned short capacity);

	//Component* clone() const override;

	double price() const override;
	void output(std::ostream& out) const override;
};

