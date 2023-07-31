#pragma once
#include <iostream>
class Component
{
private:
	const std::string label;

public:
	Component(const char* label) : label(label) {}
	virtual ~Component() = default;

	virtual double price() const = 0;
	virtual void output(std::ostream& os) const
	{
		os << this->label << " " << this->price();
	}
	virtual Component* clone() const = 0;
};