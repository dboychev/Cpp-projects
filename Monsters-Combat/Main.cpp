#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "Demon.h"
#include "Ogre.h"
#include "Titan.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "Dragon.h"
#include "Phoenix.h"
#include "Cyclop.h"
#include "Chimera.h"

int main()
{
	srand(time(0));
	Vampire A("ASEN");
	Titan B;
	//A.Combat(B);
	Cyclop C;
	C.Attack(B);
	/*Dragon A;
	Phoenix B;
	A.Combat(B);
	/*Ogre Gosho;
	Demon Ivan;
	Phoenix Todor;
	Titan Angel;
	Chimera Petar;
	Vampire Ceco;
	Gosho.Combat(Petar);
	//Angel.print();
	//Todor.print();
	//Gosho.print();
	//Petar.print();
	//Ceco.print();
	/*cout << endl << Petar.get_Regen() << endl;
	cout << endl << Petar.get_DMGBuff() << endl;
	cout << endl << Ceco.get_Regen() << endl;
	/*cout << endl <<Todor.get_DMGBuff() << endl;
	cout << endl << Ivan.get_DMGBuff() << endl;
	cout << endl << Gosho.get_DMGBuff() << endl;*/
	
	//DEMO BATTLE
	/*while (Ceco.alive() != 0 && Gosho.alive() != 0)
	{
		Ceco.Attack(Petar);
		this_thread::sleep_for(chrono::seconds(1));
		if (Petar.alive() != 0)
		{
			Petar.Attack(Ceco);
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
	Ceco.print();
	Petar.print();*/

	/*Monster Ciklop("Gonzo", 300, 200, 0.5);
	Ciklop.print();
	Monster Govedo(Ciklop);
	Govedo.set_name("Govedo");
	Govedo.print();*/

	return 0;
}