#pragma once
#include<iostream>
class Human
{
public:
	// Kustomoitu konstruktori. Konstruktoria kutsutaan AINA kun luodaan uusi objekti jostakin luokasta.
	// T�ss� tapauksessa haluamme ihmiselle nimen ja i�n, joka kerta kun Human -tyyppinen objekti luodaan.
	Human(std::string _name, int _age);
	void ShowNameAndAge();
	int GetAge();
private:
	std::string name;
	int age;
};

