#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[64];
    char author[64];
    struct Book *next;
} Book;

int idCount = 0;
Book *head = NULL;

void add_book();
int update_book();
int remove_book();
void insert_book();
void print_books();
void free_books();

void list_menu() 
{
    int choice;
    char title[64];
    char author[64];

    while (1) {
        printf("\n___  LINKED LIST MENU  ___\n");
        printf("1. Add Book.\n");
        printf("2. Print Books.\n");
        printf("3. Update Book.\n");
        printf("4. Insert Book.\n");
        printf("5. Delete Book.\n");
        printf("6. Exit.\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            add_book(NULL, NULL); 
        } else if (choice == 2){
            print_books();
        } else if (choice == 3){
            int id;
            printf("Enter id to delete: ");
            scanf("%d", &id);
            update_book(id);
        } else if (choice == 4){
            int idx;
            printf("Enter index to insert: ");
            scanf("%d", &idx);
            getchar();
            insert_book(idx);
        } else if (choice == 5) {
            printf("Title: \n");
            fgets(title, 63, stdin);
            title[strcspn(title, "\n")] = 0;
            remove_book(title);
 
        } else if (choice == 6) {
            exit(0);
        }
    }
}


Book *create_book(const char* title, const char* author) 
{

    Book *new_book = malloc(sizeof *new_book);
    if (!new_book) {
        printf("Failed to alloc Node");
        exit(EXIT_FAILURE);
    }
    // notice in strncpy how size is accessed, for safety and precision
    new_book->id = idCount++;
    strncpy(new_book->title, title, sizeof new_book->title - 1);
    strncpy(new_book->author, author, sizeof new_book->author - 1);
    new_book->title[sizeof new_book->title - 1] = 0; 
    new_book->author[sizeof new_book->author - 1] = 0; 
    new_book->next = NULL;
    return new_book;
}

Book *create_book_wrapper(const char* title, const char* author)
{
    char temp_title[64];
    char temp_author[64];
    if (!title || strlen(title) == 0) {
        printf("Title: \n");
        fgets(temp_title, sizeof(temp_title) - 1, stdin);
        // bug detected: i used strcspn(title, "\n"), 
        // title = NULL = 0, reading mem at addr=0 (protected addr) -> segflt.
        // fix: change to temp_title.
        temp_title[strcspn(temp_title, "\n")] = 0; 
        title = temp_title;
    }
    if (!author || strlen(author) == 0) {
        printf("Author: \n");
        fgets(temp_author, sizeof(temp_author) - 1, stdin);
        temp_author[strcspn(temp_author, "\n")] = 0;
        author = temp_author;
    }

    return create_book(title, author);
}

void add_book(const char* title, const char* author) 
{
    Book *node = create_book_wrapper(title, author);
    if (!head) {
        head = node;
    } else {
        Book *p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = node;
    }
}

int update_book(int id)
{
    char title[64];
    char author[64];
    
    Book *p = head;

    while (p) {
        if (p->id == id) {
            printf("Enter new Title: ");
            fgets(title, sizeof(title) - 1, stdin);
            title[strcspn(title, "\n")] = 0;
            strncpy(p->title, title, sizeof p->title - 1);
            p->title[sizeof p->title - 1] = '\0';
            printf("Enter new Author: ");
            fgets(author, sizeof(author) - 1, stdin);
            author[strcspn(author, "\n")] = 0;
            strncpy(p->author, author, sizeof p->author - 1);
            p->title[sizeof p->author - 1] = '\0';
        
            return 0;        
        }
        p = p->next;
    }
    return -1;
}

// Remove the first book matching the given title
// Returns 1 if removed, 0 if not found
int remove_book(const char* title) 
{
    Book *p = head;
    Book *prev = NULL;
    while (p) {
        if (strcmp(p->title, title) == 0) {
            if (prev) prev->next = p->next;
            else head = p->next;
            free(p);
            return 1;
        }
        prev = p;
        p = p->next;
    }
    return 0;
}

void insert_book(int index)
{
 
    Book *new_book = create_book_wrapper(NULL, NULL);
    Book *p = head;
    int i = 1;
    if ((index <= 0) || (head == NULL)) {
        new_book->next = head;
        head = new_book;
        return;
    }
    
    while ((i < index) && p->next) {
        p = p->next;
        i++;
    }

    new_book->next = p->next;
    p->next = new_book;
}

void print_books(void) 
{
    Book *p = head;
    while (p) {
        //left align title within 20 char space.
        printf("ID:  %-5d  TITLE: %-30s AUTHOR: %s\n", p->id, p->title, p->author);
        p = p->next;
    }
}

void free_books(void) {
    Book *p = head;
    while (p) {
        Book *tmp = p;
        p = p->next;
        free(tmp);
    }
    head = NULL;
}

int main() 
{
    char title[64];
    char author[64];
    int number = 3;
    /*
    for (int i = 0; i < 5; i++) {
        printf("Title: \n");
        fgets(title, 63, stdin);
        title[strcspn(title, "\n")] = 0;
        printf("Author: \n");
        fgets(author, 63, stdin);
        author[strcspn(author, "\n")] = 0;
        add_book(title, author);
    }
    */
    add_book("Harry Potter", "JK Rowling");
    add_book("Art Of War", "Sun Tzu");
    add_book("The Republic", "Plato");
    add_book("Tao Te Ching", "Lao Tse");
    add_book("Calculus", "Sullivan");   
    print_books();
    printf("\n");
    remove_book("Calculus");
    print_books();
    printf("\n");
    update_book(number);
    print_books();
    list_menu();
    free_books();

    return 0;
}
