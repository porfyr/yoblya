#include <stdio.h>
#include <fstream>

class List
{
    private:
        struct Node                         // Вузлова структура
        {
            int data;
            Node *pNext, *pPrev;
            Node(int data = 0, Node *pNext = nullptr, Node *pPrev = nullptr)
            {
                this->data = data;
                this->pNext = pNext;
                this->pPrev = pPrev;
            }
        };
        Node *head;
        int size;
    public:
        List();                             // Дефолтний конструктор
        List(char *filename);               // Конструктор з файлу
        ~List();                            // Деструктор рекурсивний
        int &operator[](const int index);   // Оператор []

        int  getSize() { return size; }
        void printSize() { printf("Розмір листа: %d\n", this->size); }

        void push_head(int data);           // Додати елемент з початку
        void push_back(int data);           // Додати елем в кінець
        void rm_head();                     // Усунути елем на початку
        void rm_back();                     // Усунути елем в кінці
        void print();                       // Друк масиву
        void rm_negatives();                // Усуває всі від'ємні елементи
        void mv_min();                      // Переміщає найменші в кінець
};


List::List()                            // Дефолтний конструктор
{
    this->size = 0;
    this->head = nullptr;
}
List::List(char *filename)              // Конструктор з файлу
{
    size = 0;
    head = nullptr;
    printf("Зчитуємо з файлу %s\n", filename);
    std::ifstream fin(filename);
    int val;
    while (fin >> val)
    {
        //printf("Зчитав %d\n", val);
        List::push_back(val);
    }
    fin.close();
}
List::~List()                           // Деструктор рекурсивний
{
    printf("Деструктор List\n");
    Node *current = this->head, *buffer;
    while (current != nullptr)
    {
        buffer = current->pNext;
        delete[] current;
        current = buffer;
    }
}
int &List::operator[](const int index)  // Оператор []
{
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
            break;
        }
        current = current->pNext;
        counter++;
    }
}


void List::push_head(int data)          // Додати елемент з початку
{
    if (head == nullptr)
        head = new Node(data);
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
        {
            std::swap(data, current->data);
            current = current->pNext;
        }
        std::swap(data, current->data);
        current->pNext = new Node(data);
    }
    size++;
    //printf("Запушив: %d\n", data);
}

void List::push_back(int data)          // Додати елем в кінець
{
    //printf("Пушимо в кінець %d\n", data);
    if (head == nullptr)
        head = new Node(data);
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = new Node(data, nullptr, nullptr);
    }
    size++;
}

void List::rm_head()                    // Усунути елем на початку
{
    if (head == nullptr)
        printf("Нема що вилучати\n");
    else
    {
        Node *current = this->head;
        while (current->pNext->pNext != nullptr)
        {
            std::swap(current->data, current->pNext->data);
            current = current->pNext;
        }
        std::swap(current->data, current->pNext->data);
        printf("Ремувнем %d\n", current->pNext->data);
        delete[] current->pNext;
        current->pNext = nullptr;
        size--;
    }
}

void List::rm_back()                    // Усунути елем в кінці
{
    if (head == nullptr)
        printf("Нема що вилучати\n");
    else
    {
        Node *current = this->head;
        while (current->pNext->pNext != nullptr)
        {
            current = current->pNext;
        }
        printf("Ремувнем %d\n", current->pNext->data);
        delete[] current->pNext;
        current->pNext = nullptr;
        size--;
    }
}

void List::print()                      // Друк масиву
{
    Node *current = this->head;
    while (current != nullptr)
    {
        printf("%d ", current->data);
        current = current->pNext;
    }
    printf("\n");
}




















// Зайве


void List::mv_min()                     // Переміщає найменші в кінець
{
    int min = 10500;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->data <= min)
            min = current->data;
        current = current->pNext;
    }
    printf("Мінімальний елемент %d\n", min);
    for (int i = 0; i < 10; i++) // На випадок якщо
    {                           // мінімумів 10 шт))
        current = this->head;
        while (current->pNext->pNext != nullptr)
        {
            if (current->data == min)
            {
                Node *cur = current;
                while (cur->pNext != nullptr)
                {
                    std::swap(cur->data, cur->pNext->data);
                    cur = cur->pNext;
                }
            }
            current = current->pNext;
        }
    }
    if (current->pNext->pNext == nullptr)
    {
        if (current->data == min)
        {
            std::swap(current->data, current->pNext->data);
        }
    }
}

void List::rm_negatives()               // Усуває всі від'ємні елементи
{
    if (head == nullptr)
        printf("Нема що вилучати\n");
    else
    {
        Node *current = this->head;
        while (current->pNext != nullptr)
        {
            if (current->data > -1)
                current = current->pNext;
            else
            {
                Node *cur_temp = current;
                while (cur_temp->pNext->pNext != nullptr)
                {
                    //printf("<> %d %d | ", cur_temp->data, cur_temp->pNext->data);
                    std::swap(cur_temp->data, cur_temp->pNext->data);
                    cur_temp = cur_temp->pNext;
                }
                //printf("<> %d %d ", cur_temp->data, cur_temp->pNext->data);
                std::swap(cur_temp->data, cur_temp->pNext->data);
                //printf(" # %d\n", cur_temp->pNext->data);
                delete[] cur_temp->pNext;
                cur_temp->pNext = nullptr;
                size--;
            }
        }
        if (current->data < 0)
        {
            printf("# %d\n", current->data);
            int temp = current->data;
            Node *cur = this->head;
            while (cur->pNext->data > -1)
                cur = cur->pNext;
            delete[] cur->pNext;
            cur->pNext = nullptr;
            size--;
        }
    }
}