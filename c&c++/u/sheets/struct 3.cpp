#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

struct date {
    int d,m,y;
};

struct subject{
    char s[100];
    int p;
};

struct passed {
    int n;
    subject *ps;
};


struct student{
    char name[20];
    char surname[20];
    char group[10];
    date b;
    char phone[30];
    int sk;
    passed g;
};

void menu(student*& arr, int &n);
// void enterStudentFromFile(student& st, const char *filename);
// void enterArrOfStudents(student*& arr, int n, const char *filename);


void printSudentIntoConsole(student& st);
void printArrOfStudentsIntoCosnsole(student*& arr, int n);
void printSudentIntoFile(student& st, const char *filename );
void printArrOfStudentsIntoFile(student*& arr, int n, const char *filename);

void enterStudentFromFile(student& st, const  char *filename, int &n, int &q);
void enterArrOfStudents(student*& arr, int &n, const char *filename);
void enterStudentIntoFile(student*& st, int& n, const  char *filename);
//sort
void quickSort(student *arr, int bottom, int top, int type, bool lh = 1);
int partition(student *arr, int bottom, int top, int type, bool lh);
bool compareDate(date a1, date a2);
double findavg(subject *arr, int n);
//zavd 5

student* zavd5_1(student* arr, int propusk, int n, int &i);
student* zavd5_2(student* arr, int year, int n, int &i);
student* zavd5_3(student* arr, int year, int n, int &i);
student* zavd5_4(student* arr, char propusk[1000], int n, int &i);
student* zavd5_5(student* arr, int qu, int n, int &i);
student* zavd5_6(student* arr, char propusk[1000] , int n, int &i);
student* zavd5_7(student* arr, int qu, int n, int &i);
// zavd 6
void zavd6_1(student*& arr, int &n, int sk);
void zavd6_2(student*& arr, int &n, char group[100]);
void deleteStudent(student*& arr, int i, int &n);
//zavd 7
void zavd7_1 (student *arr, char newop[100], int &n);
bool checkIfAllA(student& st);
void zavd7_2 (student *arr, int &n);
bool checkIfGood(student& st);
//
int main()
{
    student *arr =  new student[1000];
    int n = 1; 
    menu(arr,n);
    // int n = 8;
    // student Oleksandr;
    // enterArrOfStudents(arr,n, "1.txt");
    // printArrOfStudentsIntoCosnsole(arr,n);
    // quickSort(arr,0,n-1,4);
    // printArrOfStudentsIntoFile(arr,n,"2.txt");
    // arr[0] = Oleksandr;
    // printArrOfStudentsIntoCosnsole(arr, n);
    // enterStudentIntoFile(arr ,n, "2.txt");
    delete[] arr;
    return 0;
}

void menu(student*& arr, int &n)
{
    student *answ = NULL;
    int a = 1;
    char filename[100] = "1.txt";
    char filename1[100] = "2.txt";
    int zavd;
    int q;
    int r;
    char str2[1000];
    char str[1000];
    while (a != 0)
    {
        cout << "1 read from file \n2 print into a console \n3 add new student\n4 sort \n5 form array \n6 delete students \n7 change something \n8 print into a file\n0 exit\n";
        cin >> a;
        switch (a)
        {
        case 1:
            enterArrOfStudents(arr,n, "1.txt");
            break;
        case 2:
            printArrOfStudentsIntoCosnsole(arr,n);
            cout << "save into a file? (0,1)\n ";
            cin >> r;
            if (r) printArrOfStudentsIntoFile(arr,n,filename1);
            break;
        case 3:
            enterStudentIntoFile(arr,n,filename);
            break;
        case 4:
            cout << "sort by skips  - 1\nsort by birthday - 2\nsort by name - 3\nsort by avg - 4\n";
            // sort
            quickSort(arr,0,n-1,1);
            break;
        case 5:
            cout << "\n1 - < skips\n2 - year \n3 - > skips\n4 - group\n5 - date\n6 - number \n7 -  date2\n";
            cin >> zavd;
            r = 0;
            switch (zavd)
            {
            case 1:
                r = 0;
                q = 0;
                cout << "max skips\n";
                cin >> q;
                // answ = new student[100];
                answ = zavd5_1(arr,q, n, r);
                printArrOfStudentsIntoCosnsole( answ,r);
                delete[] answ;
                break;
            case 2:
                r = 0;
                q = 0;
                cout << "year: " << endl;
                cin >> q;
                answ = zavd5_2(arr,q, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
            case 3:
                r = 0;
                cout << "skips: " << endl;
                cin >> q;
                answ = zavd5_3(arr,q, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
            case 4:
                r = 0;
                cout << "group: " << endl;
                strcpy(str2, "");
                cin >> str2;
                answ = zavd5_4(arr,str2, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
            case 5:
                r = 0;
                cout << "quantity of the youngest: " << endl;
                cin >> q;
                answ = zavd5_5(arr,q, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
            case 6:
                r = 0;
                cout << "3 digits: " << endl;
                strcpy(str2, "38");
                do
                {
                    cin >> str;
                } while (strlen(str) !=3);
                strcat(str2,str);
                answ = zavd5_6(arr,str2, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
            case 7:
                r = 0;
                cout << "quantity of the eldest: " << endl;
                cin >> q;
                answ = zavd5_7(arr, q, n, r);
                printArrOfStudentsIntoCosnsole(answ,r);
                break;
                r = 0;
                break;
            }
            break;
        case 6:
            cout << "zavd1 - 1\nzavd2 -2\n";
            cin >> zavd;
            switch (zavd)
            {
                case 1:
                    cout << "skips " << endl;
                    cin >> q;
                    zavd6_1(arr,n,q);
                    break;
                
                case 2:
                    cout << "group " << endl;
                    cin >> str2;
                    zavd6_2(arr,n,str2);
                    break;
            }
            break;
        case 7:
            cout << "zavd1 - 1\nzavd2 -2\n";
            cin >> zavd;
            switch (zavd)
            {
                case 1:
                    cout << "new operator " << endl;
                    cin >> str2;
                    zavd7_1(arr,str2,n);
                    break;
                
                case 2:
                    zavd7_2(arr,n);
                    break;
            }
            break;
        case 8:
            cout << "filename: " << endl;
            cin >> filename1;
            printArrOfStudentsIntoFile(arr,n,filename1);  
        }
    }
}
// sorting
void quickSort(student *arr, int bottom, int top, int type, bool lh)
{
    if (bottom < top) 
    {
        int p = partition(arr, bottom, top, type, lh);
        quickSort(arr, bottom, p-1, type, lh);
        quickSort(arr, p+1, top, type, lh);
    }
}
//
int partition(student *arr, int bottom, int top, int type, bool lh) 
{   
    char *pivot;
    char *pivot2;
    double pivotavg;
    pivot = arr[top].surname;
    pivot2 = arr[top].name;
    int integerPivot;
    date pivotDate;
    if (type == 1)
    {
        integerPivot = arr[top].sk;
        cout << integerPivot << endl; 
    }  else if (type == 2)
    {
        pivotDate = arr[top].b;
    } else if (type == 4)
    {
        pivotavg = findavg(arr[top].g.ps, arr[top].g.n);
    }
    int i = bottom - 1;
    if (lh) {
        for (int j = bottom; j <= top - 1; j++)
        {
            if (type == 3) {

                if (strcmp(pivot,arr[j].surname) > 0) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                } else if (strcmp(pivot,arr[j].surname) == 0)
                {
                    if (strcmp(pivot2,arr[j].name) > 0 )
                    {
                        i++;
                        swap(arr[j], arr[i]);
                    }
                }
            } else if (type == 1)
            {
                if (integerPivot > arr[j].sk) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            } else if ( type == 4)
            {
                if (pivotavg > findavg(arr[j].g.ps, arr[j].g.n)) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            } else if (type == 2)
            {
                if (compareDate(pivotDate, arr[j].b)) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            }
        }
    } else {
        for (int j = bottom; j <= top - 1; j++)
        {
            if (type == 3) {

                if (strcmp(pivot,arr[j].surname) < 0) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                } else if (strcmp(pivot,arr[j].surname) == 0)
                {
                    if (strcmp(pivot2,arr[j].name) < 0 )
                    {
                        i++;
                        swap(arr[j], arr[i]);
                    }
                }
            } else if (type == 1)
            {
                if (integerPivot < arr[j].sk) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            } else if ( type == 4)
            {
                if (pivotavg < findavg(arr[j].g.ps, arr[j].g.n)) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            } else if (type == 2)
            {
                if (!compareDate(pivotDate, arr[j].b)) 
                {
                    i++;
                    swap(arr[j], arr[i]);
                }  
            }
        }

    }
    swap(arr[i+1], arr[top]);
    //  else swap(arr[i+1], arr[bottom]);
    return(i+1); 
}
//
bool compareDate(date a1, date a2)
{
    if (a1.y > a2.y) 
    {
        return 1;
    } else if (a1.y < a2.y)
    {
        return 0;
    } else if (a1.m > a2.m)
    {
        return 1;
    } else if (a1.m < a2.m)
    {
        return 0;
    } else if (a1.d > a2.d)
    {
        return 1;
    } else 
    {
        return 0;
    }
}
//
double findavg(subject *arr, int n)
{
    int sum = 0;
    double avg;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i].p;
    }
    avg = double(sum)/n;
    return avg;
}

// print fuctions
void printSudentIntoConsole(student& st) 
{
    cout << "Name: "  << st.name << " " << st.surname  << endl;
    cout << "Group: " << st.group << endl;
    cout << "Birthday: " << st.b.d << '.' << st.b.m << '.'<< st.b.y << endl;
    cout <<  "Phone: " << st.phone << endl;
    cout <<  "Skips: " << st.sk << endl;
    cout <<  "Subjects passed: " << st.g.n << endl;
    for (int i = 0; i < st.g.n; i++)
    {
       cout  << st.g.ps[i].s << ": "  << st.g.ps[i].p << endl;
    }
}

void printArrOfStudentsIntoCosnsole(student*& arr, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i+1 << endl;;
        printSudentIntoConsole(arr[i]);
    }
}



void printSudentIntoFile(student& st, const char *filename ) 
{
    fstream f;
    f.open(filename, ios::app);
    f << "Name: "  << st.name << " " << st.surname  << endl;
    f << "Group: " << st.group << endl;
    f << "Birthday: " << st.b.d << '.' << st.b.m << '.'<< st.b.y << endl;
    f <<  "Phone: " << st.phone << endl;
    f <<  "Skips: " << st.sk << endl;
    f <<  "Subjects passed: " << st.g.n << endl;
    for (int i = 0; i < st.g.n; i++)
    {
       f  << st.g.ps[i].s << ": "  << st.g.ps[i].p << endl;
    }
    f << endl;
    f.close();
}



void printArrOfStudentsIntoFile(student*& arr, int n, const char *filename)
{
    fstream f;
    f.open(filename, ios::out);
    f.close();
    for (int i = 0; i < n; i++)
    {
        f.open(filename, ios::app);
        f << "Student " << i+1 <<endl;
        f.close();
        printSudentIntoFile(arr[i], filename);
    }
}

// enter functions
void enterArrOfStudents(student*& arr, int &n, const char *filename)
{
    fstream f;
    f.open(filename);
    f.close();
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        enterStudentFromFile(arr[i], filename,r,n);
        if(strlen(arr[i].name) > 2) n++; else n--;
    }
}

void enterStudentIntoFile(student*& st, int& n, const  char *filename)
{
    fstream f;
    student temp;
    n++;
    cin >> temp.name;
    cin >> temp.surname;
    cin >> temp.group;
    cin >> temp.b.y >> temp.b.m >> temp.b.d;
    cin >> temp.phone;
    cin >> temp.sk;
    cin >> temp.g.n;
    temp.g.ps = new subject[temp.g.n];
    for (int i = 0; i < temp.g.n; i++)
    {
        cout <<"name: ";
        cin.get();
        cin.getline(temp.g.ps[i].s,100);
        cout <<" point: ";
        cin >> temp.g.ps[i].p;
    }
    st[n-1] = temp;
    f.open(filename, ios::app);
    f << "Person " << n << endl;
    f.close();
    printSudentIntoFile(st[n-1],filename);
}
void enterStudentFromFile(student& st, const  char *filename, int &n, int &q)
{
    ifstream f;
    char str[100];
    f.open(filename);
    // f.getline(str,100);
    for (int i = 0; i < n; i ++) f.getline(str,100);
    f.getline(str,100);
    n++;
    f >> st.name; f >> st.name;
    f >> st.surname;
    n++;
    f >> st.group;  f >> st.group;
    n++;
    f >> str; f.getline(str, 5,  '.');//; >> st.b.y >> st.b.m >> st.b.d;
    // cout << "aa" << endl;
    st.b.d = strtol (str, NULL ,10);
    f.getline(str, 5,  '.');
    st.b.m = strtol (str, NULL ,10);
    f.getline(str, 5);
    st.b.y = strtol (str, NULL ,10);
    n++;
    f >> str; f >> st.phone;
    n++;
    f >> str;  f >> st.sk;
    n++;
    f >> str; f >> str; f >> st.g.n;
    n++;
    st.g.ps = new subject[st.g.n+1];
    for (int i = 0; i < st.g.n; i++)
    {
        // f >> st.g.ps[i].s;
        strcpy(st.g.ps[i].s , "");
        while (true)
        {
            f >> str;
            strcat(st.g.ps[i].s, str);
            if (str[strlen(str)-1] == ':') break;
            strcat(st.g.ps[i].s, " ");
        }
        strcpy(&st.g.ps[i].s[strlen(st.g.ps[i].s)-1], "");
        // f.getline(st.g.ps[i].s, 100, ':');
        f >> st.g.ps[i].p;
        n++;
    }
    n++;
        // f.getline(str,100);          
    // cout << "n = " << n << endl;

    f.close();
}

//5 zavdannya 



student* zavd5_1(student* arr, int propusk, int n, int &i)
{
    student *ans = new student[100];
    int q = 0;
    for (int k = 0; k < n; k++)
    {
        if (arr[k].sk < propusk) {
            ans[q] = arr[k];
            q++;
            i++;
        }
    } 
    return ans;
}

student* zavd5_2(student* arr, int year, int n, int &i)
{
    student *ans = new student[100];
    int q = 0;
    for (int k = 0; k < n; k++)
    {
        if (arr[k].b.y == year) {
            ans[q] = arr[k];
            q++;
            i++;
        }
    } 
    return ans;
}


student* zavd5_3(student* arr, int propusk, int n, int &i)
{
    student *ans = new student[100];
    int q = 0;
    for (int k = 0; k < n; k++)
    {
        if (arr[k].sk > propusk) {
            ans[q] = arr[k];
            q++;
            i++;
        }
    } 
    return ans;
}


student* zavd5_4(student* arr, char propusk[1000], int n, int &i)
{
    student *ans = new student[100];
    int q = 0;
    for (int k = 0; k < n; k++)
    {
        if (strcmp(arr[k].group, propusk) == 0) {
            ans[q] = arr[k];
            q++;
            i++;
        }
    } 
    return ans;
}


student* zavd5_5(student* arr, int qu, int n, int &i)
{
    student *ans = new student[100];

    for (int k = 0; k < n; k++)
    {
        ans[k] = arr[k];
    }
    quickSort(ans,0,n-1,2,0);
    i = qu;
    return ans;
}


student* zavd5_6(student* arr, char propusk[1000] , int n, int &i)
{
    student *ans = new student[100];
    char check[6];
    int q = 0;
    for (int k = 0; k < n; k++)
    {
        strncpy(check, arr[k].phone, 5);
        // cout << check << endl;
        // cout << propusk << endl;
        if (strcmp(check, propusk) == 0)
            {
                ans[q] = arr[k];
                q++;
                i++;
            }
    }
    return ans;
}


student* zavd5_7(student* arr, int qu, int n, int &i)
{
    student *ans = new student[100];

    for (int k = 0; k < n; k++)
    {
        ans[k] = arr[k];
    }
    quickSort(ans,0,n-1,2);
    i = qu;
    return ans;
}
// zavd 6

void zavd6_1(student*& arr, int &n, int sk)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].sk > sk)
        {
            deleteStudent(arr, i, n);
            i--;
        }
    }
}

void zavd6_2(student*& arr, int &n, char group[100])
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(arr[i].group, group))
        {
            deleteStudent(arr, i, n);
            i--;
        }
    }
}


void deleteStudent(student*& arr, int i, int &n)
{
    for (int j = i; j < n-1; j++)
    {
        arr[j] = arr[j+1];
    }
        n--;
}

//zavd 7
void zavd7_1 (student *arr, char newop[100], int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (checkIfAllA(arr[i]))
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i].phone[j+2] = newop[j];
            }

        }
    }
}


void zavd7_2 (student *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (checkIfGood(arr[i]))
        {
            int w = strlen(arr[i].group);
            arr[i].group[w-2] = arr[i].group[w-2] + 1;
        }
    }
}


bool checkIfGood(student& st)
{
    for (int i = 0; i < st.g.n; i++){
        if (st.g.ps[i].p < 81) return 0;
    }
    return 1;
}

bool checkIfAllA(student& st)
{
    for (int i = 0; i < st.g.n; i++)
    {
        if (st.g.ps[i].p < 90) return 0;
    }
    return 1;
}


    // for (int k = 0;k < n; k++)
    // {
    //     if (arr[k].sk < n) {
    //         ans[q] = arr[k];
    //         q++;
    //     }
    // } 
    // cout << i << endl;
    // }
// void enterArrOfStudents(student*& arr, int n, const char *filename)
// {
//     fstream f;
//     f.open(filename);
//     f.close();
//     for (int i = 0; i < n; i++)
//     {
//         enterStudentFromFile(arr[i], filename);
//     }