#include <stdio.h>


class Book {
    private:
        Book();
        ~Book();
        char name[10];
        int cost;

    public:
        void setName()
        {
            printf("Як книга сі зве: ");
            scanf("%s", &name);
            //printf("\n");
        }
        void setCost()
        {
            printf("Скільки коштує: ");
            scanf("%d", &cost);
            //printf("\n");
        }
        char * getNamePtr()
        {
            return name;
        }
        int getCost()
        {
            return cost;
        }
};

int main()
{
    Book my_book;
    my_book.setName();
    my_book.setCost();
    
    printf("Назва: %s\n", my_book.getNamePtr());
    printf("Ціна: %d\n", my_book.getCost());

    delete my_book;

    //printf("Робе\n");
    return 0;
}