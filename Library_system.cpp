#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to represent a book
struct Book {
    char title[100];
    char author[100];
    int year;
};

// Function to add a book to the library
void addBook(struct Book library[], int *numBooks) {
    if (*numBooks >= MAX_BOOKS) {
        printf("The library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    scanf(" %[^\n]", library[*numBooks].title);

    printf("Enter book author: ");
    scanf(" %[^\n]", library[*numBooks].author);

    printf("Enter publication year: ");
    scanf("%d", &library[*numBooks].year);

    (*numBooks)++;
    printf("Book added successfully.\n");
}

// Function to display all books in the library
void displayBooks(struct Book library[], int numBooks) {
    if (numBooks == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Books in the library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (Published in %d)\n", i + 1, library[i].title, library[i].author, library[i].year);
    }
}

// Function to search for a book by title
void searchBook(struct Book library[], int numBooks) {
    char searchTitle[100];
    int found = 0;

    if (numBooks == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Enter the title to search: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\nAuthor: %s\nPublication Year: %d\n", library[i].title, library[i].author, library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                searchBook(library, numBooks);
                break;
            case 4:
                printf("Exiting the library management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
