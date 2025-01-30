package com.anurag.demo;

import java.util.Scanner;

public class main {

		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int choice;
			do {
				Book_management_system.display();
				System.out.print("Enter your choice: ");
				choice = sc.nextInt();
				switch(choice) {
				      case 1: 
				    	  Book_management_system.hardcoded_books();
				    	  break;
				      case 2: 
				    	  Book_management_system.add_newBook();
				    	  break;
				      case 3: 
				    	  Book_management_system.remove_book();
				      case 4: 
				    	  Book_management_system.update_book();
				          break;
				      case 5: 
				    	  Book_management_system.search_book();
				    	  break;
				      case 6: 
				    	  Book_management_system.dispaly_allbooks();
				    	  break;
				      case 7: 
				    	  Book_management_system.sorted_books();
				    	  break;
				      default : 
				    	  System.out.println("Invalid choice! please enter valid choice.");
				    	  
				}

		}while(choice<=7);

		

	}
}