#include<iostream> // #include vasta käytännössä samaa kuin Using on c# -kielessä. 
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
	// srand = seed random, käytetään tietokoneen sisäistä kellonaikaa joka vaikuttaa siltä, että numero arvottaisiin
	srand(time(NULL));
	return rand() % max;
}

// Funktio, jolla tarkistetaan, että onko käyttäjän syöte varmista numero.
bool IsNumber(std::string num)
{
	// Käydään jokainen syötteen kirjain / numero läpi, ja jos sieltä löytyy yksikin ei-numero
	// niin palautetaan false
	for (int i = 0; i < num.size(); i++)
	{
		if (!isdigit(num[i]))
		{
			return false;
		}
	}
	// Palautetaan true, jos syöte on numero
	return true;
}


// Ohjelman aloituspiste on aina main(). Eli kun käyttäjä suorittaa .exe tiedoston,
// tämä funktio suoritetaan ensimmäisenä.

void Perusteet1() {
	// setlocale funktiolla saadaan ääkköset näkymään oikein.
	ASETASUOMENKIELI;
	SHOWOS;
		// std on standard library. Sieltä löytyvällä cout kommennolla saadaan tekstiä konsolin ikkunalle.
		// endl komento vaihtaa riviä.
	LOG("Hello World");
	std::cout << "Mikä on nimesi: ";

	std::string answer;
	std::getline(std::cin, answer);
	std::cout << "Tervetuloa, " << answer << std::endl;
	
	int numero = RandomizeNumber(10);

	while (true)
	{
		std::cout << "Arvaa oikea numero (1-10): " << std::endl;
		std::getline(std::cin, answer);
	
		// Tarkistetaan omalla IsNumber -funktiolla, että käyttäjän syöte on varmasti numero.
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
			std::cout << "Ole hyvä ja syötä numero." << std::endl;
		}
	}
}

void VektoritJaLoopit() {
	Human newHuman("Jussi", 20);

	// Vector pitää sisällään montaa tietyn tyyppistä objektia. Hyvin samantyyppinen kuin C# -kielen List
	Humans humans;
	humans.push_back(newHuman);
	humans.push_back(Human("Laura", 29));
	humans.push_back(Human("Mikko", 58));

	// std::map on käytännössä sama kuin C# Dictionary.
	std::map<std::string, int> romanNumerals{
		{"M", 1000},
		{"C", 100},
		{"X", 10},
		{"V", 5},
		{"I", 1}
	};
	LOG(romanNumerals["M"]);
	LOG(romanNumerals["X"]);

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

void LuokanPerimisEsimerkki()
{
	//std::vector<Human> humans;
	//// Kun luodaan objekteja stack-muistissa vektoriin, kannattaa käyttä emplace_back metodia push_backin
	//// sijasta. Tämä välttää turhien objektien kopioiden tekemisen.
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
		// pointtereita (*) ja ne luodaan new avainsanaa käyttäen. Heap -muistiin luominen on hieman
		// hitaampaa kuin stack -muistiin luominen, mutta heap muistilla on käytössä käytännössä
		// koko vapaana oleva keskusmuisti

		// Smart Pointteri luo objektin heap -muistiin. Smart pointteria käyttäessä, sitä ei kuitenkaan
		// tarvitse poistaa (delete).
		auto smartHuman = std::make_shared<Human>("Niko", 50);

		Human* heapHuman = new Human("Jussi", 49);
		Human::ShowHowManyHumans();
		// Heap -muistiin luodut objektit pitää aina muistaa poistaa delete komennolla. Eli kaikki
		// objektit, mitkä on luotu new avainsanaa käyttäen, pitää manuaalisesti muistaa poistaa.
		delete heapHuman;
	}
	Human::ShowHowManyHumans();
	
	// & = referenssi
	// * = pointteri

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