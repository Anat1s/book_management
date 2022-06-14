#include <stdio.h>
#include "library.h"

void init()
{
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
}

void menu()
{
    printf("1. Register Books\n");
    printf("2. Search Books\n");
    printf("3. Borrow Books\n");
    printf("4. Return Books\n");
    printf("5. Exit\n");
    printf(">> ");
}

int main()
{
    struct Books books[101];
    int borrowed[101], total_books = 1;
    int idx;

    init();

    while(1) {
        menu();
        scanf("%d", &idx);

        switch(idx) {
            case 1:
                register_books(books, &total_books);
                break;
            
            case 2:
                search_books(books);
                break;
            
            case 3:
                borrow_books(books);
                break;
            
            case 4:
                return_books(books);
                break;

            case 5:
                return 0;

            default:
                break;
        }
        printf("\n");
    }

    return 0;
}