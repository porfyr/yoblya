#pragma once
#include <stdio.h>

class List
{
    private:
        struct Node                         // Вузлова структура
        {
            int data;
            Node *pNext;
            Node(int data = 0, Node *pNext = nullptr)
            {
                this->data = data;
                this->pNext = pNext;
            }
        };
        Node *head;
        int size;
    public:
        List();                             // Дефолтний конструктор
        List(char *filename);               // Конструктор з файлу
        ~List();                            // Деструктор рекурсивний
        int &operator[](const int index);   // Оператор []

        int getSize() { return size; }

        void push_head(int data);           // Додати елемент з початку
        void push_back(int data);           // Додати елем в кінець
        void rm_head();                     // Усунути елем на початку
        void rm_back();                     // Усунути елем в кінці
        void rm_negatives();                // Усуває всі від'ємні елементи
        void mv_min();                      // Переміщає найменші в кінець
        void print();                       // Друк масиву
};
