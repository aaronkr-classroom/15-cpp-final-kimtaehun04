// Intl.h

#ifndef GUARD_Intl_h
#define GUARD_Intl_h

#include <iostream>

#include "Core.h"

using namespace std;

class Intl : public Core {
public:
	Intl() {};
	Intl(istream& is) { read(is); };
	istream& read(istream&);

private:
	Intl* clone() const { return new Intl(*this); }
};

#endif
