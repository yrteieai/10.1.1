#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { ME, MF, FI, IN, KN };

union Marks {
    int mark_cs;       
    int mark_physics;  
    int mark_math;     
};

struct Student {
    string prizv;          
    Kurs kurs;             
    Spec spec;             
    Marks marks;           
    int mark_physics;      
    int mark_math;         
};

void input_students(Student* students, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter student details #" << (i + 1) << endl;
        cout << "Surname: ";
        cin >> students[i].prizv;

        int kurs, spec;
        cout << "Course (1-6): ";
        cin >> kurs;
        students[i].kurs = static_cast<Kurs>(kurs);

        cout << "Speciality (0-ME, 1-MF, 2-FI, 3-IN, 4-KN): ";
        cin >> spec;
        students[i].spec = static_cast<Spec>(spec);

        cout << "Physics: ";
        cin >> students[i].marks.mark_physics;

        cout << "Math: ";
        cin >> students[i].mark_math;

        cout << "Computer Science: ";
        cin >> students[i].marks.mark_cs;
    }
}

void table(const Student* students, int n) {
    cout << "-------------------------------------------------------------------" << endl;
    cout << "| ¹  |   Surname   | Course |   Spec.  | Physics | Math | CompSci |" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; ++i) {
        cout << "| " << setw(2) << (i + 1) << " | "
            << setw(10) << students[i].prizv << " | "
            << setw(6) << students[i].kurs << " | "
            << setw(8) << students[i].spec << " | "
            << setw(7) << students[i].marks.mark_physics << " | "
            << setw(4) << students[i].mark_math << " | "
            << setw(8) << students[i].marks.mark_cs << " |" << endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
}

int find_students_with_mark_5(const Student* students, int n) {
    int count5 = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i].marks.mark_cs == 5) {
            count5++;
        }
    }
    return count5;
}

int find_students_with_mark_4(const Student* students, int n) {
    int count4 = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i].marks.mark_cs == 4) {
            count4++;
        }
    }
    return count4;
}

int find_students_with_mark_3(const Student* students, int n) {
    int count3 = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i].marks.mark_cs == 3) {
            count3++;
        }
    }
    return count3;
}

double percent_excellent(const Student* students, const int n) {
    int k = 0;
    int total = 0; 

    for (int i = 0; i < n; ++i) {
        total++;

        if (students[i].marks.mark_physics >= 4 || students[i].mark_math >= 4) {
            k++;
        }
    }

    return (total == 0) ? 0.0 : 100.0 * k / total;
}


int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    input_students(students, n);
    table(students, n);

    int count5 = find_students_with_mark_5(students, n);
    int count4 = find_students_with_mark_4(students, n);
    int count3 = find_students_with_mark_3(students, n);

    cout << "\nNumber of '5' grades in computer science: " << count5 << endl;
    cout << "Number of '4' grades in computer science: " << count4 << endl;
    cout << "Number of '3' grades in computer science: " << count3 << endl;

    double procent = percent_excellent(students, n);
    cout << "Percentage of students with grades '4' or '5' in physics and mathematics: "
        << fixed << setprecision(2) << procent << "%" << endl;

    delete[] students;

    return 0;
}
