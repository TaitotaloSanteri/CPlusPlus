#pragma once
#include<iostream>
class Human
{
public:
	// Kustomoitu konstruktori. Konstruktoria kutsutaan AINA kun luodaan uusi objekti jostakin luokasta.
	// Tässä tapauksessa haluamme ihmiselle nimen ja iän, joka kerta kun Human -tyyppinen objekti luodaan.
	Human(std::string _name, int _age);
	// Destruktori siihen kun objekti tuhotaan, eli sen muistiosoite poistuu käytöstä.
	~Human();
	void ShowNameAndAge();
	int GetAge();
	static void ShowHowManyHumans();
	virtual void Info();
protected:
	std::string name;
	int age;
private:
	static int howManyHumans;
};

