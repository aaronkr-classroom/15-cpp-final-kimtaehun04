// main.cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"
#include "Vec.h"
#include "Student_info.h"
#include "median.h"
#include "Handle.h" // NEW
// #include "Ref_handle.h" // NEW 

using namespace std;

bool compare_Core_handles(
    const Handle<Core>& lhs, // 수정
    const Handle<Core>& rhs  // 수정
) {
    return compare(*lhs, *rhs);
}

int main() {
    vector< Handle<Core> > students; // 객체가 아닌 포인터를 저장
    Handle<Core> record;
    char ch;
    string::size_type maxlen = 0;

    cout << "Enter student data in the format: "
        << "U/G/I name midterm final (thesis) [homework]" << endl << endl
        << "  - U/G (select one) is U for Undergraduate (학부생) or G for Graduate (대학원생)" << endl
        << "  - (thesis) is only applicable for G (대학원생)" << endl
        << "  - [homework] is a list of int grades without []" << endl << endl
        << "Press CTRL+Z and ENTER twice to process." << endl << endl;

    // 데이터 읽고 저장하기
    while (cin >> ch) {
        if (cin.eof()) break;  // Check for end of input

        // Handle unexpected empty lines or malformed input
        if (ch != 'U' && ch != 'G' && ch != 'I') {
            // If the input is not a valid student type, skip it
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (ch == 'U')
            record = new Core; // Core 객체 할당
        else if (ch == 'G')
            record = new Grad; // Grad 객체 할당
        else
            record = new Intl; // Intl 객체 할당

        // Handle<T>::-> 연산자 함수 호출 후 가상 함수 호출하기
        record->read(cin);

        maxlen = max(maxlen, record->getName().size()); // 역참조
        students.push_back(record);
    }

    // 포인터로 동작하는 compare 함수를 전달
    sort(students.begin(), students.end(), compare_Core_handles);
    // sort(students.begin(), students.end(), compare_grades);

    // 이름과 점수를 출력하기
    for (vector< Handle<Core> >::size_type i = 0;
        i != students.size(); i++) {

        // 함수를 호출하려고 포인터인 students[i]를 역참조
        cout << students[i]->getName()
            << string(maxlen + 1
                - students[i]->getName().size(), ' ');

        try {
            double final_grade = students[i]->grade(); // 역촘조
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what() << endl; // 예외 출력
        }
    }

    return 0;
}