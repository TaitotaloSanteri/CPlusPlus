#pragma once
#include<iostream>
class Human
{
public:
	// Kustomoitu konstruktori. Konstruktoria kutsutaan AINA kun luodaan uusi objekti jostakin luokasta.
	// Tässä tapauksessa haluamme ihmiselle nimen ja iän, joka kerta kun Human -tyyppinen objekti luodaan.
	Human(std::string _name, int _age);
	void ShowNameAndAge();
	int GetAge();
private:
	std::string name;
	int age;
};

