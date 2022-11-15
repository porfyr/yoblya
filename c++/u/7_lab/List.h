#pragma once
#include <stdio.h>

class List
{
    private:
        struct Node
        {
            int data;
            Node *pNext;
            Node(int data = 0, Node *pNext = nullptr)
            {
                this->data = data;
                this->pNext = pNext;
                printf("Задефолчений конструктор Node\n");
            }
        };
        Node *head;
        int size;
    public:
        List();
        ~List();
        int &operator[](const int index);

        int getSize() { return size; }

        void push_back(int data);
        void print();
};
