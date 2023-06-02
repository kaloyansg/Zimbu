#include "Cpu.h"

Cpu::Cpu(const char* label, unsigned short cores, unsigned short clockSpeed) :
	Component(label), cores(cores), clockSpeed(clockSpeed)
{
	if (cores < 1 || cores >8) throw "Invalid cores!";
}

//Component* Cpu::clone() const
//{
//	Component* result = new Cpu(*this);
//	return result;
//}

double Cpu::price() const
{
	return (double)cores * 29.99;
}

void Cpu::output(std::ostream& out) const
{
	this->Component::output(out);
	out << "; Cores - " << cores << "; Clock speed - " << clockSpeed << "; Price: " << this->price();
}
