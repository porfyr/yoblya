#pragma once
#include <stdio.h>
#include <string>

template <typename T>
class Student
{
	protected:
		int number;
		std::string name;
		T* rating = new T[10];
	public:
		Student() { printf("Деструктор Student\n"); }
		~Student() { printf("Деструктор Student\n"); }
		Student(int, std::string);
		T getRating(int n);
		int getNumber();
		std::string getName() { return name; }
		void setRating(T n);
};

template<typename T>
Student<T>::Student(int number, std::string name)
{
	this->number = number;
	this->name = name;
	for (int i = 0; i < 10; i++)
	{
		rating[i] = rand() % 5 + 1;
	}
}

template<typename T>
T Student<T>::getRating(int n)
{
	if (n > 5)
	{
		printf("Направильний ввід\n");
		return 0;
	}
	return rating[n - 1];
}

template<typename T>
int Student<T>::getNumber()
{
	return number;
}

template<typename T>
void Student<T>::setRating(T n)
{
	this->rating = n;
}