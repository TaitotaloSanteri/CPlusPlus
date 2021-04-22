#include<iostream> // #include vasta k�yt�nn�ss� samaa kuin Using on c# -kieless�. 
#include<string>
#include<locale.h>
#include<vector>
#include"Human.h"
#include"Child.h"
#include"Macros.h"
#include<map>

using Humans = std::vector<Human>;

int RandomizeNumber(int max)
{
	// srand = seed random, k�ytet��n tietokoneen sis�ist� kellonaikaa joka vaikuttaa silt�, ett� numero arvottaisiin
	srand(time(NULL));
	return rand() % max;
}

// Funktio, jolla tarkistetaan, ett� onko k�ytt�j�n sy�te varmista numero.
bool IsNumber(std::string num)
{
	// K�yd��n jokainen sy�tteen kirjain / numero l�pi, ja jos sielt� l�ytyy yksikin ei-numero
	// niin palautetaan false
	for (int i = 0; i < num.size(); i++)
	{
		if (!isdigit(num[i]))
		{
			return false;
		}
	}
	// Palautetaan true, jos sy�te on numero
	return true;
}


// Ohjelman aloituspiste on aina main(). Eli kun k�ytt�j� suorittaa .exe tiedoston,
// t�m� funktio suoritetaan ensimm�isen�.

void Perusteet1() {
	// setlocale funktiolla saadaan ��kk�set n�kym��n oikein.
	ASETASUOMENKIELI;
	SHOWOS;
		// std on standard library. Sielt� l�ytyv�ll� cout kommennolla saadaan teksti� konsolin ikkunalle.
		// endl komento vaihtaa rivi�.
	LOG("Hello World");
	std::cout << "Mik� on nimesi: ";

	std::string answer;
	std::getline(std::cin, answer);
	std::cout << "Tervetuloa, " << answer << std::endl;
	
	int numero = RandomizeNumber(10);

	while (true)
	{
		std::cout << "Arvaa oikea numero (1-10): " << std::endl;
		std::getline(std::cin, answer);
	
		// Tarkistetaan omalla IsNumber -funktiolla, ett� k�ytt�j�n sy�te on varmasti numero.
		if (IsNumber(answer))
		{
			// std::stoi on String TO Int, eli muuttaa string tyyppisen muuttujan int tyyppiseksi
			int arvaus = std::stoi(answer);
			if (arvaus == numero)
			{
				LOG("Arvasit oikein!");
				break;
			}
			else if (arvaus > numero)
			{
				LOG("Arvauksesi oli liian iso.");
			}
			else {
				LOG("Arvauksesi oli liian pieni.");
			}
		}
		else {
			std::cout << "Ole hyv� ja sy�t� numero." << std::endl;
		}
	}
}

void VektoritJaLoopit() {
	Human newHuman("Jussi", 20);

	// Vector pit�� sis�ll��n montaa tietyn tyyppist� objektia. Hyvin samantyyppinen kuin C# -kielen List
	Humans humans;
	humans.push_back(newHuman);
	humans.push_back(Human("Laura", 29));
	humans.push_back(Human("Mikko", 58));

	// std::map on k�yt�nn�ss� sama kuin C# Dictionary.
	std::map<std::string, int> romanNumerals{
		{"M", 1000},
		{"C", 100},
		{"X", 10},
		{"V", 5},
		{"I", 1}
	};
	LOG(romanNumerals["M"]);
	LOG(romanNumerals["X"]);

	// Perus indeks�ity for -looppi. T�sm�lleen saman n�k�inen kuin C# -kieless�.
	for (int i = 0; i < humans.size(); i++)
	{
		humans[i].ShowNameAndAge();
	}

	for (Human& human : humans)
	{
		human.ShowNameAndAge();
	}
}

// TuplaaNumero funktioon otetaan num -parametri int tyyppisen�. T�m� luo kopion funktioon l�hetetyst�
// muuttujasta, eli EI muuta siis itse l�hetetyn muuttujan arvoa.
void TuplaaNumero(int num)
{
	num *= 2; // num = num * 2
}

// TuplaaNumeroReferenssi funktioon otetaan num -parametri int& tyyppsien�. T�m� muuttaa l�hetetyn
// muuttujan arvoa. & = referenssi muuttujaan.
void TuplaaNumeroReferenssi(int& num)
{
	num *= 2; // num = num * 2
}

void LuokanPerimisEsimerkki()
{
	//std::vector<Human> humans;
	//// Kun luodaan objekteja stack-muistissa vektoriin, kannattaa k�ytt� emplace_back metodia push_backin
	//// sijasta. T�m� v�ltt�� turhien objektien kopioiden tekemisen.
	//humans.emplace_back(Human("Jaakko", 30));
	//humans.emplace_back(Human("Liisa", 44));
	//humans.emplace_back(Child("Oskari", 11));

	//for (Human& human : humans)
	//{
	//	human.Info();
	//}

	std::vector<Human*> humans;
	humans.push_back(new Human("Jaakko", 30));
	humans.push_back(new Human("Liisa", 44));
	humans.push_back(new Child("Oskari", 11));

	for (Human* human : humans)
	{
		human->Info();
	}
	for (Human* human : humans)
	{
		delete human;
	}
}

int main() {
	//Perusteet1();
	LuokanPerimisEsimerkki();
	VektoritJaLoopit();
	{
		Human::ShowHowManyHumans();
		// Luodaan objekti ns. stack -muistiin. Stack -muistiin luominen on todella nopeata, mutta
		// Stack -muistia on avoinna ainostaan noin 1 megatavu.
		Human stackHuman("Eetu", 30);
		Human::ShowHowManyHumans();
		// Luodaan objekti ns. heap -muistiin. Heap muistiin objekteja luodessa, niiden aina olla 
		// pointtereita (*) ja ne luodaan new avainsanaa k�ytt�en. Heap -muistiin luominen on hieman
		// hitaampaa kuin stack -muistiin luominen, mutta heap muistilla on k�yt�ss� k�yt�nn�ss�
		// koko vapaana oleva keskusmuisti

		// Smart Pointteri luo objektin heap -muistiin. Smart pointteria k�ytt�ess�, sit� ei kuitenkaan
		// tarvitse poistaa (delete).
		auto smartHuman = std::make_shared<Human>("Niko", 50);

		Human* heapHuman = new Human("Jussi", 49);
		Human::ShowHowManyHumans();
		// Heap -muistiin luodut objektit pit�� aina muistaa poistaa delete komennolla. Eli kaikki
		// objektit, mitk� on luotu new avainsanaa k�ytt�en, pit�� manuaalisesti muistaa poistaa.
		delete heapHuman;
	}
	Human::ShowHowManyHumans();
	
	// & = referenssi
	// * = pointteri

	//int numero = 5;
	//// Luodaan pointteri numero -muuttujalle. Pointteri on muuttuja, joka pit�� sis�ll��n jonkun toisen
	//// muuttujan muistiosoitteen.
	//int* numeroPointteri = &numero;
	//*numeroPointteri = 10;
	//TuplaaNumeroReferenssi(*numeroPointteri);
	////TuplaaNumeroReferenssi(numero);
	//std::cout << numero << std::endl;
	//std::cout << numeroPointteri << std::endl;
	//

	return 0;
}