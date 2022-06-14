#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int compare(char *str1, char *str2)
{
    while(*str1) {
        if(*str1 != *str2) 
            return 0;
        
        str1++;
        str2++;
    }

    if(*str2 == '\0') 
        return 1;
    
    return 0;
}

int register_books(struct Books *books, int *total_books)
{
    if(*total_books >= 101) {
        printf("도서가 가득 찼습니다.\n");
        exit(0);
    }

    printf("\n");
    printf("도서의 제목 입력 >> ");
    scanf("%s", books[*total_books].title_name);

    printf("저자 이름 입력 >> ");
    scanf("%s", books[*total_books].auth_name);

    printf("출판사 입력 >> ");
    scanf("%s", books[*total_books].public_name);

    books[*total_books].borrowed = 0;
    (*total_books)++;

    printf("도서가 등록되었습니다.\n");

    return 0;
}

int search_books(struct Books *books)
{
    char search[30];
    int i, idx;
    int book = 0;

    printf("\n");
    printf("검색할 도서의 제목, 저자, 출판사 중 하나를 선택 하세요.\n");
    printf("1. 제목\n");
    printf("2. 저자\n");
    printf("3. 출판사\n");
    printf(">> ");
    scanf("%d", &idx);

    if(idx == 1) {
        printf("\n검색할 책의 제목을 입력하세요 >> ");
        scanf("%s", search);
        
        for(i = 1; i < 101; i++) {
            if(compare(books[i].title_name, search)) {
                printf("%d 번째\n", i);
                printf("제목 : %s\n저자 : %s\n출판사 : %s\n", books[i].title_name, books[i].auth_name, books[i].public_name);

                if(books[i].borrowed != 0) 
                    printf("%s 도서는 현재 대여가 불가능합니다.\n", books[i].title_name);
                else
                    printf("%s 도서는 현재 대여가 가능합니다.\n", books[i].title_name);
                
                book = 1;
            }
        }

        if(book != 1) {
            printf("검색한 책을 찾지 못하였습니다.\n");
            exit(0);
        }
    }
    
    if(idx == 2) {
        printf("\n검색할 저자의 이름을 입력하세요 >> ");
        scanf("%s", search);

        for(i = 1; i < 101; i++) {
            if(compare(books[i].auth_name, search)) {
                printf("%d 번째\n", i);
                printf("제목 : %s\n저자 : %s\n출판사 : %s\n", books[i].title_name, books[i].auth_name, books[i].public_name);

                if(books[i].borrowed != 0) 
                    printf("%s 도서는 현재 대여가 불가능합니다.\n", books[i].title_name);
                else
                    printf("%s 도서는 현재 대여가 가능합니다.\n", books[i].title_name);
                
                book = 1;
            }
        }

        if(book != 1) {
            printf("검색한 저자를 찾지 못하였습니다.\n");
            exit(0);
        }
    }

    if(idx == 3) {
        printf("\n검색할 출판사 이름을 입력하세요 >> ");
        scanf("%s", search);

        for(i = 1; i < 101; i++) {
            if(compare(books[i].public_name, search)) {
                printf("%d 번째\n", i);
                printf("제목 : %s\n저자 : %s\n출판사 : %s\n", books[i].title_name, books[i].auth_name, books[i].public_name);

                if(books[i].borrowed != 0) 
                    printf("%s 도서는 현재 대여가 불가능합니다.\n", books[i].title_name);
                else
                    printf("%s 도서는 현재 대여가 가능합니다.\n", books[i].title_name);
                
                book = 1;
            }
        }

        if(book != 1) {
            printf("검색한 출판사를 찾지 못하였습니다.\n");
            exit(0);
        }
    }

    return 0;
}

int borrow_books(struct Books *books)
{
    int choice, idx;

    printf("대여 하시겠습니까?\n");
    printf("1. 도서 대여\n");
    printf("2. 도서 대여 취소\n");
    printf(">> ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("대여할 도서 번호를 입력 해주세요 >> ");
        scanf("%d", &idx);

        if(books[idx].borrowed == 0) {
            printf("%d번\n", idx);
            printf("제목 : %s\n저자 : %s\n출판사 : %s\n", books[idx].title_name, books[idx].auth_name, books[idx].public_name);
            printf("대여 되었습니다.\n");
            printf("대여 기간은 7일 입니다.\n");
            
            books[idx].borrowed = 1;
        }
        else {
            printf("%d번 째 %s 책은 현재 대여가 불가능합니다.\n", idx, books[idx].title_name);
        }
    }

    if(choice == 2) {
        printf("대여가 취소 되었습니다.\n");
    }

    return 0;
}

int return_books(struct Books *books)
{
    int choice, idx;

    printf("반납 하시겠습니까?\n");
    printf("1. 도서 반납\n");
    printf("2. 도서 반납 취소\n");
    printf(">> ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("반납할 도서 번호를 입력해주세요 >> ");
        scanf("%d", &idx);

        if(books[idx].borrowed == 1) {
            printf("%d번 %s 도서가 반납 되었습니다.\n", idx, books[idx].title_name);
            books[idx].borrowed = 0;
        }
        else {
            printf("%d번 %s 도서는 대여가 가능한 상태입니다.\n", idx, books[idx].title_name);
        }
    }

    if(choice == 2) {
        printf("도서 반납이 취소 되었습니다.\n");
    }

    return 0;
}