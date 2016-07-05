#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "TRACK.h"
#include "Car.h"
#include "Family.h"
#include "Sports.h"
#include "Luxury.h"
#include "Subaru.h"
#include "Lexus.h"
#include "Ford.h"
#include "Opel.h"
#include "Mercedes.h"

int main()
{
	Ford A("Gosho", 250, 300);
	Lexus B("Ivan", 220, 280);

	Track C("Burgas", 1500, 15);

	C.RACE(A, B);

	return 0;
}