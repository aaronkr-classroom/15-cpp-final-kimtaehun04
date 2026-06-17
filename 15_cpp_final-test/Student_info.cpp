#include <iostream>

#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Intl.h"
#include "grade.h"

using namespace std;

// 생성자!
// 빈 생성자
Student_info::Student_info(const Student_info& s) : cp(0) {
    if (s.cp) cp = s.cp->clone();
}

istream& Student_info::read(istream& is) {
    char ch;
    is >> ch;    // record 타입 입력

    // record 타입 확인
    if (ch == 'U') {
        cp = new Core(is);
    }
    else if (ch == 'G') {
        cp = new Grad(is);
    }
    else if (ch == 'I') {
        cp = new Intl(is);
    }

    return is;
}

Student_info& Student_info::operator=(const Student_info& s) {
    if (&s != this) {

        if (s.cp)
            cp = s.cp->clone();
        else
            cp = 0;
    }
    return *this;
}

// cin을 일어 Student_info를 초기화
// Student_info::Student_info(istream& is) { read(is); }
/*
bool compare(const Student_info& x, const Student_info& y) {
    return x.get_name() < y.get_name(); // A < Z일 때 참 반환, Z < A일 때 거짓 반환
}

double Student_info::grade() const {
    return ::grade(get_midterm(), get_final(), get_hw());
}
*/
