#pragma once
#include <iostream>
#pragma warning (disable:4996)

class Component
{
private:
	const char* label;

public:
	Component(const char* label);
	
	Component(const Component& other);
	Component& operator=(const Component& other) = delete;

	//virtual Component* clone() const = 0;

	virtual double price() const = 0;
	virtual void output(std::ostream& out) const;

	virtual ~Component();
};

