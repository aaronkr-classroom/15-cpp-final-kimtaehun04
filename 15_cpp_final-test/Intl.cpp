#include <algorithm>
#include <vector>

#include "Intl.h"

istream& read_hw(istream& in, vector<double>& hw);

istream& Intl::read(istream& in) {
	Core::read_common(in);
	read_hw(in, homework);
	return in;
}
