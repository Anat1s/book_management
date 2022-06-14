struct Books
{
    char title_name[30];
    char auth_name[30];
    char public_name[30];
    int borrowed;
};

int compare(char *str1, char *str2);
int register_books(struct Books *books, int *total_books);
int search_books(struct Books *books);
int borrow_books(struct Books *books);
int return_books(struct Books *books);