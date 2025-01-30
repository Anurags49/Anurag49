#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

struct Book {
    int bookID;
    char bookName[50];
    char authorName[50];
    char category[30];
    float price;
    float rating;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void add_newBook();
void dispaly_hardcoded_books();
void remove_Book();
void update_Book();
void search_Book();
void display_AllBooks();
void display_Menu();
void display_sortedbooks();

int main() {
    int choice;

    do {
        display_Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_newBook();
        }else if (choice == 2) {
            dispaly_hardcoded_books();
        } else if (choice == 3) {
            remove_Book();
        } else if (choice == 4) {
            update_Book();
        } else if (choice == 5) {
            search_Book();
        } else if (choice == 6) {
            display_AllBooks();
        } else if (choice == 7) {
            display_sortedbooks();
        } else if (choice == 8) {
            printf("Exit from the system.\n");
            break;
        } else {
            printf("Invalid choice! Please enter valid choice..\n");
        }
    }while(choice!= 0);
      
    return 0;
}

void display_Menu() {
    printf("\n--- Welcome to Book Management System ---\n");
    printf("1. Add a Book\n");
    printf("2. Hardcoded books\n");
    printf("3. Remove a Book\n");
    printf("4. Update Book Details\n");
    printf("5. Search for a Book\n");
    printf("6. Display All Books\n");
    printf("7. Display Sorted Books\n");
    printf("8. Exit\n");
}

void dispaly_hardcoded_books(){
	
	if (bookCount >= MAX_BOOKS) {
		printf("Library is full! Cannot add more books.\n");
		return;
    }
    
    //hardcoded inputs
    if(bookCount==0){
    	
	    // first book
	    struct Book newBook1;
		newBook1.bookID = 101; 
		strcpy(newBook1.bookName, "C Programming");
		strcpy(newBook1.authorName, "Dennis Ritchie");
		strcpy(newBook1.category, "Programming");
		newBook1.price = 299.99;
		newBook1.rating = 4.5;
		library[bookCount++] = newBook1;
	
		// Second book
		struct Book newBook2;
		newBook2.bookID = 102; 
		strcpy(newBook2.bookName, "Clean Code");
		strcpy(newBook2.authorName, "Robert C. Martin");
		strcpy(newBook2.category, "Software Development");
		newBook2.price = 399.99;
		newBook2.rating = 4.8;
		library[bookCount++] = newBook2;
		
		// third book
		struct Book newBook3;
		newBook3.bookID = 103; 
		strcpy(newBook3.bookName, "Rich Dad Poor Dad");
		strcpy(newBook3.authorName, "Robert T. Kiyosaki");
		strcpy(newBook3.category, "Personal Finance");
		newBook3.price = 499.99;
		newBook3.rating = 4.7;
		library[bookCount++] = newBook3;
		
		// fourth book
		struct Book newBook4;
		newBook4.bookID = 104; 
		strcpy(newBook4.bookName, "The 7 Habits of Highly Effective People");
		strcpy(newBook4.authorName, "Stephen R. Covey");
		strcpy(newBook4.category, "Self-Help");
		newBook4.price = 599.99;
		newBook4.rating = 4.8;
		library[bookCount++] = newBook4;
		
		// fifth book
		struct Book newBook5;
		newBook5.bookID = 105; 
		strcpy(newBook5.bookName, "Think and Grow Rich");
		strcpy(newBook5.authorName, "Napoleon Hill");
		strcpy(newBook5.category, "Motivational");
		newBook5.price = 399.50;
		newBook5.rating = 4.6;
		library[bookCount++] = newBook5;
		
		// sixth book
		struct Book newBook6;
		newBook6.bookID = 106; 
		strcpy(newBook6.bookName, "Atomic Habits");
		strcpy(newBook6.authorName, "James Clear");
		strcpy(newBook6.category, "Self-Improvement");
		newBook6.price = 459.75;
		newBook6.rating = 4.9;
		library[bookCount++] = newBook6;
		
		// seventh book
		struct Book newBook7{107,"The Art of Computer Programming","Knuth","Computer Science",499.99,4.8};
		library[bookCount++] = newBook7;
		printf("\n7 hardcoded books are added successfully. Total books: %d\n", bookCount);

    }
} 

void add_newBook() {
    
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Can not add more books.\n");
        return;
    }
    
    struct Book newBook;
    int isUnique;
    do{
		isUnique = 1; 
        printf("\nEnter Book ID: ");
        scanf("%d", &newBook.bookID);
        
        for (int i = 0; i < bookCount; i++) {
            if (library[i].bookID == newBook.bookID) {
                printf("Book ID %d already exists. Please enter a unique Book ID.\n", newBook.bookID);
                isUnique = 0; 
                break;
            }
        }
    } while (!isUnique);
    
    printf("Enter Book Name: ");
    scanf(" %s", newBook.bookName);
    printf("Enter Author Name: ");
    scanf(" %s", newBook.authorName);
    printf("Enter Category: ");
    scanf(" %s", newBook.category);
    printf("Enter Price: ");
    scanf("%f", &newBook.price);
    do{
    	
		printf("Enter Rating between (0 to 5): ");
		scanf("%f", &newBook.rating);
		
		if(newBook.rating<0||newBook.rating>5){
			printf("Invalid rating! please enter the valid rating..");
			printf("Book is not added! Total books: %d\n", bookCount);
	    return;
	    }
//	    printf("Book is not added! Total books: %d\n", bookCount);
//	    return;
	}while(newBook.rating<0||newBook.rating>5);

    library[bookCount++] = newBook;
    printf("Book added successfully! Total books: %d\n", bookCount);
    
}

void remove_Book() {
    int id, found = 0, choice;
    char author_name[50];

    printf("\nPress 1 for removing a book by using author name.\n");
    printf("Press 2 for removing a book by using book ID.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter part or full Author Name to remove book: ");
        scanf(" %[^\n]s", author_name);

        for (int i = 0; i < bookCount; i++) {
            if (strstr(library[i].authorName, author_name) != NULL) {
                printf("Book by '%s' is found. Removing...\n", library[i].authorName);
                for (int j = i; j < bookCount - 1; j++) {
                    library[j] = library[j + 1];
                }
                bookCount--;
                found = 1;
                printf("Book removed successfully!\n");
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Book ID to remove: ");
        scanf("%d", &id);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].bookID == id) {
                printf("Book with ID %d found. Removing...\n", library[i].bookID);
                for (int j = i; j < bookCount - 1; j++) {
                    library[j] = library[j + 1];
                }
                bookCount--;
                found = 1;
                printf("Book removed successfully!\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

void update_Book() {
    int id, found = 0,choice;
	
    printf("\npress 1 for updating price and ratings of book.\n");
    printf("press 2 for updating all book details.\n");
    
    printf("Enter the choice: ");
    scanf("%d",&choice);
    
    if(choice == 1){
    	printf("Enter Book ID to update: ");
        scanf("%d", &id);
        
    	for (int i = 0; i < bookCount; i++) {
            if (library[i].bookID == id) {
            	
                printf("Enter New Price: ");
                scanf("%f", &library[i].price);
                do{
                	
					printf("Enter New Rating: ");
		            scanf("%f", &library[i].rating);
		            
		            if(library[i].rating<1||library[i].rating>5){
		            	printf("Invalid rating! please enter the valid rating..");
					}
					break;
				}while(library[i].price>1||library[i].price<5);

                found = 1;
                printf("Book updated successfully!\n");
                break;
            }
        }	
	}
    else if(choice==2){
    	printf("Enter Book ID to update: ");
        scanf("%d", &id);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].bookID == id) {
                printf("Enter New Book Name: ");
                scanf(" %[^\n]s", library[i].bookName);

                printf("Enter New Author Name: ");
                scanf(" %[^\n]s", library[i].authorName);

                printf("Enter New Category: ");
                scanf(" %[^\n]s", library[i].category);

                printf("Enter New Price: ");
                scanf("%f", &library[i].price);

                do{
                	
					printf("Enter New Rating between: ");
		            scanf("%f", &library[i].rating);
		            if(library[i].rating<1||library[i].rating>5){
		            	printf("Invalid rating! please enter the valid rating..");
					}
					break;
				}while(library[i].price>1||library[i].price<5);

                found = 1;
                printf("Book updated successfully!\n");
                
            }
        }
        if (!found) {
        printf("Book not found!\n");
    }
	}
}


void search_Book() {
    int id, found = 0,choice;
    char authorname[50];
    
    printf("\nchoice 1 for seraching book by book id.");
    printf("\nchoice 2 for seraching book by author name.\n");
    printf("enter the choice: ");
    scanf("%d",&choice);
    
    if(choice == 1){
    	printf("Enter Book ID to search: ");
        scanf("%d", &id);

        for (int i = 0; i < bookCount; i++) {
            if (library[i].bookID == id) {
                printf("\n--- Book Details ---\n");
                printf("Book ID: %d\n", library[i].bookID);
                printf("Name: %s\n", library[i].bookName);
                printf("Author: %s\n", library[i].authorName);
                printf("Category: %s\n", library[i].category);
                printf("Price: %.2f\n", library[i].price);
                printf("Rating: %.1f\n", library[i].rating);
                found = 1;
                break;
            }
        }
	}else if(choice == 2){
		printf("Enter Author name to search: ");
        scanf(" %[^\n]s", authorname);
        
        for (int i = 0; i < bookCount; i++) {
            if(strstr(library[i].authorName, authorname) != NULL) {
                printf("\n--- Book Details ---\n");
                printf("Book ID: %d\n", library[i].bookID);
                printf("Name: %s\n", library[i].bookName);
                printf("Author: %s\n", library[i].authorName);
                printf("Category: %s\n", library[i].category);
                printf("Price: %.2f\n", library[i].price);
                printf("Rating: %.1f\n", library[i].rating);
                found = 1;
                break;
            }
        }
	}

    if (!found) {
        printf("Book not found!\n");
    }
}

void display_AllBooks() {
	
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- All Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", library[i].bookID);
        printf("Name: %s\n", library[i].bookName);
        printf("Author: %s\n", library[i].authorName);
        printf("Category: %s\n", library[i].category);
        printf("Price: %.2f\n", library[i].price);
        printf("Rating: %.1f\n", library[i].rating);
        printf("\n");
    }
}

void display_sortedbooks() {
	
	int choice;
    if (bookCount == 0) {
        printf("No books available in library.\n");
        return;
    }

    struct Book sortedLibrary[MAX_BOOKS];
    for (int i = 0; i < bookCount; i++) {
        sortedLibrary[i] = library[i];
    }

    printf("\nChoice 1: Display all books sorted by Rating.");
    printf("\nChoice 2: Display top 3 books sorted by Rating.");
    printf("\nChoice 3: Display top 3 books sorted by Price.");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        // Sort by rating (high to low)
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (sortedLibrary[j].rating < sortedLibrary[j + 1].rating) {
                    struct Book temp = sortedLibrary[j];
                    sortedLibrary[j] = sortedLibrary[j + 1];
                    sortedLibrary[j + 1] = temp;
                }
            }
        }

        if (choice == 1) {
            printf("\n--- All Books Sorted by Rating ---\n");
            for (int i = 0; i < bookCount; i++) {
                printf("Book ID: %d\n", sortedLibrary[i].bookID);
                printf("Name: %s\n", sortedLibrary[i].bookName);
                printf("Price: %.2f\n", sortedLibrary[i].price);
                printf("Rating: %.1f\n", sortedLibrary[i].rating);
                printf("\n");
            }
        } else if (choice == 2) {
            printf("\n--- Top 3 Books by Rating ---\n");
            for (int i = 0; i < 3 && i < bookCount; i++) {
                printf("Book ID: %d\n", sortedLibrary[i].bookID);
                printf("Name: %s\n", sortedLibrary[i].bookName);
                printf("Price: %.2f\n", sortedLibrary[i].price);
                printf("Rating: %.1f\n", sortedLibrary[i].rating);
                printf("\n");
            }
        }
    } else if (choice == 3) {
        // Sort by price (high to low)
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (sortedLibrary[j].price < sortedLibrary[j + 1].price) {
                    struct Book temp = sortedLibrary[j];
                    sortedLibrary[j] = sortedLibrary[j + 1];
                    sortedLibrary[j + 1] = temp;
                }
            }
        }

        printf("\n--- Top 3 Books by Price ---\n");
        for (int i = 0; i < 3 && i < bookCount; i++) {
            printf("Book ID: %d\n", sortedLibrary[i].bookID);
            printf("Name: %s\n", sortedLibrary[i].bookName);
            printf("Price: %.2f\n", sortedLibrary[i].price);
            printf("Rating: %.1f\n", sortedLibrary[i].rating);
            printf("\n");
        }
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}
