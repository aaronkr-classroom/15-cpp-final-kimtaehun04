// Core.h

#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Core {
public:
	Core() : midterm(0), final(0) {};
	Core(istream& is) { read(is); };
	string getName() const;

	virtual double grade() const;
	virtual istream& read(istream&);

	virtual ~Core() {}; // 소멸자

	// public으로 변경
	virtual Core* clone() const { return new Core(*this); }

protected:
	istream& read_common(istream&);
	double midterm, final;
	vector<double> homework; // 나중에 Vec 클래스를 시도할게

private:
	string name;
	friend class Student_info;
};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif
