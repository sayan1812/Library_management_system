
//  Sure, here's a sample implementation of a library management system in C:


# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[50];
    char author[50];
    int id;
    int is_available;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};

void add_book(struct Library *lib) {
    if (lib->num_books >= MAX_BOOKS) {
        printf("Error: library is full.\n");
        return;
    }

    struct Book new_book;
    printf("Enter book title: ");
    fgets(new_book.title, 50, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // remove newline character
    printf("Enter book author: ");
    fgets(new_book.author, 50, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // remove newline character
    printf("Enter book ID: ");
    scanf("%d", &new_book.id);
    new_book.is_available = 1;

    lib->books[lib->num_books] = new_book;
    lib->num_books++;

    printf("Book added successfully.\n");
}

void display_books(struct Library *lib) {
    printf("Library inventory:\n");
    scanf("ID\tTitle\t\tAuthor\t\tAvailability\n");
     for (int i = 0; i < lib->num_books; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", lib->books[i].id, lib->books[i].title, lib->books[i].author, lib->books[i].is_available ? "Available" : "Not available");
    }
}
void borrow_book(struct Library *lib) {
    int book_id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &book_id);

    for (int i = 0; i < lib->num_books; i++) {
        if (lib->books[i].id == book_id) {
            if (lib->books[i].is_available) {
                lib->books[i].is_available = 0;
                printf("Book borrowed successfully.\n");
            } else {
                printf("Error: book is not available.\n");
            }
            return;
        }
    }

    printf("Error: book not found.\n");
}

void return_book(struct Library *lib) {
    int book_id;
    printf("Enter book ID to return: ");
    scanf("%d", &book_id);

    for (int i = 0; i < lib->num_books; i++) {
        if (lib->books[i].id == book_id) {
            if (!lib->books[i].is_available) {
                lib->books[i].is_available = 1;
                printf("Book returned successfully.\n");
            } else {
                printf("Error: book is already available.\n");
            }
            return;
        }
    }
  printf("Error: book not found.\n");
}

int main() {
    struct Library lib = {0};

    int choice;
    do {
        printf("\nLibrary management system\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Borrow book\n");
        printf("4. Return book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 switch (choice) {
            case 1:
                add_book(&lib);
                break;
            case 2:
                display_books(&lib);
                break;
            case 3:
                borrow_book(&lib);
                break;
            case 4:
                return_book(&lib);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

