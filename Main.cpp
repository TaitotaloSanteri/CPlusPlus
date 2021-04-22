#include<iostream> // #include vasta käytännössä samaa kuin Using on c# -kielessä. 
#include<string>
#include<locale.h>
#include<vector>
#include"Human.h"

int RandomizeNumber(int max)
{
	// srand = seed random, käytetään tietokoneen sisäistä kellonaikaa joka vaikuttaa siltä, että numero arvottaisiin
	srand(time(NULL));
	return rand() % max;
}

// Ohjelman aloituspiste on aina main(). Eli kun käyttäjä suorittaa .exe tiedoston,
// tämä funktio suoritetaan ensimmäisenä.

void Perusteet1() {
	// setlocale funktiolla saadaan ääkköset näkymään oikein.
	std::setlocale(0, "fi-FI");

	// std on standard library. Sieltä löytyvällä cout kommennolla saadaan tekstiä konsolin ikkunalle.
	// endl komento vaihtaa riviä.
	std::cout << "Hello World!" << std::endl;
	std::cout << "Mikä on nimesi: ";

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

	// Vector pitää sisällään montaa tietyn tyyppistä objektia. Hyvin samantyyppinen kuin C# -kielen List
	std::vector<Human> humans;
	humans.push_back(newHuman);
	humans.push_back(Human("Laura", 29));
	humans.push_back(Human("Mikko", 58));

	// Perus indeksöity for -looppi. Täsmälleen saman näköinen kuin C# -kielessä.
	for (int i = 0; i < humans.size(); i++)
	{
		humans[i].ShowNameAndAge();
	}

	for (Human& human : humans)
	{
		human.ShowNameAndAge();
	}
}

// TuplaaNumero funktioon otetaan num -parametri int tyyppisenä. Tämä luo kopion funktioon lähetetystä
// muuttujasta, eli EI muuta siis itse lähetetyn muuttujan arvoa.
void TuplaaNumero(int num)
{
	num *= 2; // num = num * 2
}

// TuplaaNumeroReferenssi funktioon otetaan num -parametri int& tyyppsienä. Tämä muuttaa lähetetyn
// muuttujan arvoa. & = referenssi muuttujaan.
void TuplaaNumeroReferenssi(int& num)
{
	num *= 2; // num = num * 2
}


int main() {
	Perusteet1();
	//int numero = 5;
	//// Luodaan pointteri numero -muuttujalle. Pointteri on muuttuja, joka pitää sisällään jonkun toisen
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