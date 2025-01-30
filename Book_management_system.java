package com.anurag.demo;

import java.util.Scanner;

public class Book_management_system {
	
	static book[] newBook = new book [50];
	static int bookCount = 0;
	static Scanner sc = new Scanner(System.in);
	static Book_management_system ref = new Book_management_system();
	
	public static void display() {
		System.out.println("--- Welcome to Book Management System ---");
		System.out.println("1. Hardcoded books");
		System.out.println("2. Add a Book");
		System.out.println("3. Remove a Book");
		System.out.println("4. Update Book Details");
		System.out.println("5. Search for a Book");
		System.out.println("6. Display All Books");
		System.out.println("7. Display Sorted Books");
		System.out.println("8. Exit");	
	}
	
//	Adding hard coded books in the system.
	
	public static void hardcoded_books() {
		
		if(bookCount ==0) {
		    book newBook1 = new book(101,"C Programming","Dennis Ritchie","programming",299.99,4.5);
	        ref.newBook[bookCount++] = newBook1;
			
			book newBook2 = new book(102,"Clean Code","Robert C. Martin","Software Development",399.99,4.8);
			ref.newBook[bookCount++] = newBook2;
			
			book newBook3 = new book(103,"Rich Dad Poor Dad","Robert T. Kiyosaki","Personal Finance",499.99,4.7);
			ref.newBook[bookCount++] = newBook3;
			
			book newBook4 = new book(104,"The 7 Habits of Highly Effective People","Stephen R. Covey","Self-Help",599.99,4.8);		
			ref.newBook[bookCount++] = newBook4;
			
			book newBook5 = new book(105,"Think and Grow Rich","Napoleon Hill","Motivational",399.50,4.6);			
			ref.newBook[bookCount++] = newBook5;
			
			book newBook6 = new book(106,"Atomic Habits","James Clear","Self-Improvement",459.75,4.9);		
			ref.newBook[bookCount++] = newBook6;
			
			book newBook7 = new book(107,"The Art of Computer Programming","Knuth","Computer Science",499.99,4.8);		
			ref.newBook[bookCount++] = newBook7;
			
			
			System.out.println("hardcoded books are added successfully. Total books: "+bookCount);
		}
		
		if(bookCount>=newBook.length) {
			System.out.println("Library is full! Can not add more books.");
			return;
		}
		
	}
	
	public static void add_newBook() {
		if(bookCount>=newBook.length) {
			System.out.println("Library is full! Can not add more books.");
			return;
		}
		
		book tempBook = new book();
		boolean isunique;
		int bookID;
		int i;
		do {
			isunique = true;
			System.out.print("Enter the Book id: ");
			bookID = sc.nextInt();
			sc.nextLine();
			for(i=0; i < bookCount;i++) {
				if(newBook[i].getBookID() == bookID) {
					System.out.println("Book ID "+ bookID+" already exists. Please enter a unique Book ID");
					isunique = false;
					break;
				}
			}
		}while(!isunique);
		tempBook.setBookID(bookID);
		
		System.out.print("Enter the Book Name: ");
		String bookName = sc.nextLine();
		tempBook.setBookName(bookName);
		
		System.out.print("Enter the Author Name: ");
		String authorName = sc.nextLine();
		tempBook.setAuthorName(authorName);
		
		System.out.print("Enter the Category: ");
		String category = sc.nextLine();
		tempBook.setCategory(category);
		
		System.out.print("Enter the Book price: ");
		int Price = sc.nextInt();
		tempBook.setPrice(Price);
		
		System.out.print("Enter the Book rating: ");
		double rating = sc.nextDouble();
		do {
			if(rating <0 || rating>5) {
				System.out.println("Invalid rating! please enter valid rating between 0 to 5.");
			}
		}while(rating <0 || rating>5);
		tempBook.setRating(rating);
		
	    ref.newBook[bookCount++] = tempBook;
	    System.out.println("book is added successfully. Total books: "+bookCount);
		
		
	}
	
	public static void update_book() {
		int bookid,i,choice = 0;
		boolean found = false;
		System.out.println("choice 1 for updating  all book details.");
		System.out.println("choice 2 for updating price and ratings of book.");
		System.out.print("Enter your choice: ");
		choice  = sc.nextInt();
		
		switch(choice) {
		case 1: System.out.print("Enter bookid to update book details: ");
		bookid = sc.nextInt();
		
		for(i=0;i<bookCount;i++) {
			if(newBook[i].getBookID() == bookid) {
				System.out.print("Enter new author name: ");
				String authorname = sc.next();
				newBook[i].setAuthorName(authorname);
				System.out.print("Enter new book name: ");
				sc.nextLine();
				String bookname = sc.next();
				newBook[i].setBookName(bookname);
				System.out.print("Enter new category of book: ");
				String category =sc.next();
				newBook[i].setCategory(category);
				System.out.print("Enter new price: ");
				double price = sc.nextDouble();
				newBook[i].setPrice(price);
				System.out.print("Enter new rating: ");
				System.out.print("Enter the Book rating: ");
				double rating = sc.nextDouble();
				do {
					if(rating <0 || rating>5) {
						System.out.println("Invalid rating! please enter valid rating between 0 to 5.");
					}
				}while(rating <0 || rating>5);
				newBook[i].setRating(rating);
				found = true;
				System.out.println("Book details are updated successfully.");
			}
		}
		return;
		
		case 2: System.out.print("Enter bookid to update book details: ");
		bookid = sc.nextInt();
		
		for(i=0;i<bookCount;i++) {
			if(newBook[i].getBookID() == bookid) {
				System.out.print("Enter new price: ");
				double price = sc.nextDouble();
				newBook[i].setPrice(price);
				System.out.print("Enter new rating: ");
				double rating = sc.nextDouble();
				newBook[i].setRating(rating);
				found = true;
				System.out.println("Book details are updated successfully.");
			}
		}
		return;
		
		default : System.out.println("Invalid choice! please enter valid choice..");
		break;
		}while(choice<=2);
		
		if(!true) {
			System.out.println("Book not found / not present in the system.");
		}
		
	}
	
	public static void search_book() {
		int bookid,i,choice;
		String authorname;
		boolean found = false;
		
		System.out.println("choice 1 for searching book by Book id.");
		System.out.println("choice 2 for searching book by Author name.");
		System.out.print("Enter your choice: ");
		choice = sc.nextInt();
		switch(choice) {
		case 1: System.out.println("Enter Book id to search book.");
		bookid = sc.nextInt();
		
		for(i=0;i<bookCount;i++) {
			if(newBook[i].getBookID() == bookid) {
				System.out.println(newBook[i]);
				found = true;
			}
		}
		return;
		
		case 2: System.out.println("Enter Author name to search book.");
		sc.nextLine();
	    authorname= sc.nextLine();
	    
	    for(i=0;i<bookCount;i++) {
	    	if(newBook[i].getAuthorName().equals(authorname)) {
	    	   System.out.println(newBook[i]);
	    		found = true;
	    	}
	    }
	    return;
	    
	    default : System.out.println("Invalid choice! please enter valid choice..");
		break;
		}while(choice<=2);
		
		if(!true) {
			System.out.println("Book not found / not present in the system.");
		}
	}
	
	public static void dispaly_allbooks() {
		
		for(int i=0;i<bookCount;i++) {
			System.out.println(newBook[i]);
		}
	}
	
	public static void sorted_books() {
		int choice,i,j;
		
		System.out.println("choice 1 for sorting all books in the system by rating.");
		System.out.println("choice 2 for top 3 books in the system by rating.");
		System.out.println("choice 3 for sorting all books in the system by price.");
		System.out.println("choice 4 for top 3 books in the system by price.");
		System.out.print("Enter your choice: ");
		choice = sc.nextInt();
		
		if(choice == 1 || choice == 2) {
			for(i=0;i<bookCount;i++) {
				for(j=i+1;j<bookCount;j++) {
					if(newBook[i].getRating()<newBook[j].getRating()) {
					book temp = newBook[i];
					newBook[i] = newBook[j];
					newBook[j]=temp;
					}
				}
			}
			
			if(choice == 1) {
				for(i=0;i<bookCount;i++) {
					System.out.println(newBook[i]);
				}
			}else if(choice ==2) {
				for(i=0;i<3&&i<bookCount;i++) {
					System.out.println(newBook[i]);
				}
			}
		}else {
			if(choice == 3|| choice == 4) {
				for(i=0;i<bookCount;i++) {
					for(j=i+1;j<bookCount;j++) {
						if(newBook[i].getPrice()<newBook[j].getPrice()) {
							book temp = newBook[i];
							newBook[i] = newBook[j];
							newBook[j]=temp;
							}
					}
				}	
			}
			
			if(choice == 3) {
				for(i=0;i<bookCount;i++) {
					System.out.println(newBook[i]);
				}
			}else if(choice == 4) {
				for(i=0;i<3&&i<bookCount;i++) {
					System.out.println(newBook[i]);
				}
			}
		}
	
	}

	public static void remove_book() {
		
		
	}
}
