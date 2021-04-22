#include<iostream> // #include vasta k�yt�nn�ss� samaa kuin Using on c# -kieless�. 
#include<string>
#include<locale.h>
#include<vector>
#include"Human.h"

int RandomizeNumber(int max)
{
	// srand = seed random, k�ytet��n tietokoneen sis�ist� kellonaikaa joka vaikuttaa silt�, ett� numero arvottaisiin
	srand(time(NULL));
	return rand() % max;
}

// Ohjelman aloituspiste on aina main(). Eli kun k�ytt�j� suorittaa .exe tiedoston,
// t�m� funktio suoritetaan ensimm�isen�.

void Perusteet1() {
	// setlocale funktiolla saadaan ��kk�set n�kym��n oikein.
	std::setlocale(0, "fi-FI");

	// std on standard library. Sielt� l�ytyv�ll� cout kommennolla saadaan teksti� konsolin ikkunalle.
	// endl komento vaihtaa rivi�.
	std::cout << "Hello World!" << std::endl;
	std::cout << "Mik� on nimesi: ";

	std::string answer;
	std::getline(std::cin, answer);
	std::cout << "Tervetuloa, " << answer << std::endl;
	
	int numero = RandomizeNumber(10);

	while (true)
	{
		std::cout << "Arvaa oikea numero (1-10): " << std::endl;
		std::getline(std::cin, answer);
		// std::stoi on String TO Int, eli muuttaa string tyyppisen muuttujan int tyyppiseksi
		int arvaus = std::stoi(answer);

		if (arvaus == numero)
		{
			std::cout << "Arvasit oikein!";
			break;
		}
		else if (arvaus > numero)
		{
			std::cout << "Arvauksesi oli liian iso.";
		}
		else {
			std::cout << "Arvauksesi oli liian pieni.";
		}
	}
}

void VektoritJaLoopit() {
	Human newHuman("Jussi", 20);

	// Vector pit�� sis�ll��n montaa tietyn tyyppist� objektia. Hyvin samantyyppinen kuin C# -kielen List
	std::vector<Human> humans;
	humans.push_back(newHuman);
	humans.push_back(Human("Laura", 29));
	humans.push_back(Human("Mikko", 58));

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


int main() {
	Perusteet1();
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