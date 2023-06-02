#pragma once
#include "Component.h"


class Configurations
{
private:
	Component** components;
	unsigned numberOfComponents;

	Configurations();

	bool checkConfiguration(const Component* c);
	void insert(const Component* c);

public:
	Configurations(Component** components, unsigned numberOfComponents);
	Configurations(const Configurations& other) = delete;
	Configurations& operator=(const Configurations& other) = delete;
	~Configurations();

	double price() const;
	std::size_t size() const;

	const Component& operator[](std::size_t index) const;
	friend std::ostream& operator<<(std::ostream&, const Configurations&);

	friend Configurations* create_configuration();
	static Component* create_component();
};

Configurations* create_configuration();
