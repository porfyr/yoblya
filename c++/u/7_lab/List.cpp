#include <stdio.h>
#include "List.h"


List::List()
{
    size = 0;
    head = nullptr;
}
List::~List()
{
    ;
}
int &List::operator[](const int index)
{
    printf("Прийнято %d\n", index);
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        printf("Ітерація циклу %d\n", counter);
        if (counter == index)
        {
            return current->data;
            break;
        }
        current = current->pNext;
        counter++;
    }
}

void List::push_back(int data)
{
    printf("Додаємо %d\n", data);
    if (head == nullptr)
        head = new Node(data, nullptr);
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->data = data;
        current->pNext = nullptr;
    }
    size++;
    printf("Ніби додали %d\n", data);
}
void List::print()
{
    Node *cur = head->pNext;
    printf("%d %p->%p\n", cur, cur->pNext);
    cur = cur->pNext;
    printf("%d %p->%p\n", cur, cur->pNext);
    cur = cur->pNext;
    printf("%d %p->%p\n", cur, cur->pNext);
}