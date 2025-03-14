#include <iostream>
#include "Zad4.h"

int main()
{
	Baloon baloon1(50, 2);
	Baloon baloon2(55, 3);
	Alchohol bottle1(250.5, "JackDaniels");
	Alchohol bottle2(350.5, "Beluga");
	Alchohol bottle3(450.5, "Moet");
	Narga narga1(35, "Habibi", 4);
	Narga narga2(35, "Habibi", 4);
	Narga narga3(35, "Habibi", 4);

	NightClub megami;
	/*megami.addBaloon(baloon1);
	megami.addBaloon(baloon2);
	megami.addAlchohol(bottle1);
	megami.addAlchohol(bottle2);
	megami.addAlchohol(bottle3);
	megami.addNarga(narga1);
	megami.addNarga(narga2);
	megami.addNarga(narga3);
	megami.printBaloonsArr();
	megami.printBottlesArr();
	megami.printNargasArr();
	megami.removeBaloonFromArr(baloon2);
	megami.removeAlchoholFromArr(bottle1);
	megami.removeNargaFromArr(narga1);
	megami.printBaloonsArr();
	megami.printBottlesArr();
	megami.printNargasArr();*/

	//std::ofstream file1("baloonFile");
	//std::ofstream file2("alchoholFile");
	//std::ofstream file3("nargaFile");

	//file1 << "green - 25.6";
	//file2 << "black_label-60";
	//file3 << "OS-queen-30";

	Baloon b1;
	b1.createBaloonFromFile("baloonFile");
	b1.printBaloon();
	Alchohol a1;
	a1.createAlchoholFromFile("alchoholFile");
	a1.printAlchohol();
	Narga n1;
	n1.createNargaFromFile("nargaFile");
	n1.printNarga();
}