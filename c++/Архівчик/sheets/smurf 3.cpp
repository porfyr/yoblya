#include <iostream>
using namespace std;

enum type_gender {
    male, famale
};

char Gender[][7] = {"male", "famale"};

struct date {
    int year;
    int month;
    int day;
};

struct Student{
    char name[50];
    int course;
    int absent;
    type_gender gender;
    date birthday;
};

void Print(const Student &stu) {
    cout << "Name: " << stu.name << endl;
    cout << "Course: " << stu.course << endl;
    cout << "Absent: " << stu.absent << endl;
    cout << "Gender: " << Gender[stu.gender] << endl;
    cout << "Birthday: " << stu.birthday.year << " " << stu.birthday.month << " " << stu.birthday.day << endl;
    cout << endl;
}

void Enter(Student &stu){
    cout << "Name: ";
    cin.getline(stu.name, 50);
    cout << "Course: ";
    cin >> stu.course;
    cout << "Absent: " ;
    cin >> stu.absent;
    cout << "Gender (male/famale) : " ;
    char g[7];
    cin >> g;
    if (strcmp(g, "male") == 0){
        stu.gender = male;
    } else {
        stu.gender = famale;
    }
    cout << "Birthday (year, month, day) : ";
    cin >> stu.birthday.year >> stu.birthday.month >> stu.birthday.day;
    cin.get();
}

int main(){
    Student stu;
    strcpy(stu.name, "John");
    stu.course = 1;
    stu.absent = 5;
    stu.gender = male;
    stu.birthday = {2004, 1, 13};
    
    Student all[3];
    all[0] = stu;
    Enter(all[1]);
    Enter(all[2]);
    
    for (int i = 0; i < 3; i++) {
        Print(all[i]);
    }
    
    return 0;
}