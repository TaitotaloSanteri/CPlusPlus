#pragma once
#include<iostream>
class Human
{
public:
	// Kustomoitu konstruktori. Konstruktoria kutsutaan AINA kun luodaan uusi objekti jostakin luokasta.
	// T�ss� tapauksessa haluamme ihmiselle nimen ja i�n, joka kerta kun Human -tyyppinen objekti luodaan.
	Human(std::string _name, int _age);
	// Destruktori siihen kun objekti tuhotaan, eli sen muistiosoite poistuu k�yt�st�.
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

