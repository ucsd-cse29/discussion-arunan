#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100  // Maximum number of books in the library

// Book Struct
typedef struct {
    char title[100];
    char author[50];
    int year;
    int available;
} Book;

// Library of Books
Book* library[MAX_BOOKS];
int book_count = 0;  // Count of books in library

int available_count = 0; //Books not checked out

// Function to create a new Book and add it to library
void add_book(const char *title, const char *author, int year) {
    if (book_count >= MAX_BOOKS){
        printf("Library is full!!!");
        return;
    }
    Book *new_book = malloc(sizeof(Book));

    if (new_book == NULL) { //ALWAYS check if malloc is unsuccessful
        printf("Malloc error");
        return;
    }
    new_book->year = year;
    (*new_book).available = 1;
    strncpy(new_book->title, title, 100);
    strncpy(new_book->author, author, 50);
    // new_book->author = author; Works if author is char* BUT points to local variable 

    library[book_count] = new_book;
    book_count++;
    available_count++;
    return;
};

void book_taken(int id) {
    if (id > book_count) {
        printf("book does not exist");
        return;
    }
    Book *book = library[id]; 
    book->available *= -1; //Flip sign of available 1: in library / -1: not in library
    available_count--;
    return;
}

void print_library() {
    printf("Library contains %d book(s):\n\n", available_count);
    for(int i = 0; i < book_count; i++){
        //
        // Book *book = library[i]; Boring way of indexing
        Book *book = *(library + i); //library + i * sizeof(Book) Cool way of indexing 😎
        //
        printf("Book %d\n", i + 1);
        printf("  Title: %s\n", book->title);
        printf("  Author: %s\n", book->author);
        printf("  Year: %d\n", book->year);
        printf(book->available> 0 ? "  Available: Yes\n": "  Available: No\n"); //Ternary operator - Basically 1 line if statement
        printf("\n");
    }
}

void delete_library() {
    for (int i = 0; i < book_count; i++){
        if (!library[i]) {
            printf("invalid address");
            continue;
        }
        free(library[i]);
    }
    book_count = 0;
    available_count = 0;
}

int main() {
    // Add books to the library
    add_book("1984", "George Orwell", 1949);
    add_book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    add_book("Moneyball", "Michael Lewis", 2003);

    // Display all books in the library
    print_library();

    //Oakland A's fan checks out Moneyball
    book_taken(2);

    //Change 1989 to Animal Farm (George Orwell)
    strncpy((char*)*(library+1), "Animal Farm", 100);
    (*library[1]).year = 1945;
    print_library();


    delete_library();

    return 0;
}

