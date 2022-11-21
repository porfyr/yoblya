#include "Bachelor.h"
#include <string>
#include <stdio.h>
#include "Student.h"
#include <list>
#include <iostream>

int main()
{
	std::list<Bachelor<int>> students;
	Bachelor<std::string> st(2, "Вася", "норм");
	printf("%s\n", st.getName().c_str());
	printf("%s\n", st.getRatingOfWork().c_str());
	//students.push_back(st);


	// for (int i = 0; i < n; i++)
	// {
	// 	cout << "Student: " << i+1 << (*students[i]).sumOfRating() << endl;
	// }
}