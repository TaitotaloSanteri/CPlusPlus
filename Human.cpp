#include "Human.h"

// Konstruktori
Human::Human(std::string _name, int _age)
{
	name = _name;
	age = _age;
}

void Human::ShowNameAndAge()
{
	std::cout << "Ihmisen nimi on " << name << ". Ja ikä on " << age << "." << std::endl;
}

int Human::GetAge()
{
	return age;
}
