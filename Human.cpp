#include "Human.h"
int Human::howManyHumans = 0;

// Konstruktori
Human::Human(std::string _name, int _age)
{
	howManyHumans++;
	name = _name;
	age = _age;
	std::cout << name << " luotiin!" << std::endl;
}

Human::~Human()
{
	howManyHumans--;
	std::cout << name << " tuhottiin!" << std::endl;
}

void Human::ShowNameAndAge()
{
	std::cout << "Ihmisen nimi on " << name << ". Ja ik� on " << age << "." << std::endl;
}

int Human::GetAge()
{
	return age;
}

void Human::ShowHowManyHumans()
{
	std::cout << "Maailmassa on " << howManyHumans << " ihmist�.";
}

void Human::Info()
{
	std::cout << "Min� olen aikuinen ihminen." << std::endl;
}
