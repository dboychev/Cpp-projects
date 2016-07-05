#ifndef OPEL_H
#define OPEL
#include "Family.h"

class Opel : public Family
{
public:
	Opel(char* name = "Opel", int hp = 160, int maxSped = 240);
};

#endif