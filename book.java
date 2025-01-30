package com.anurag.demo;
//   class book
public class book {
	private int bookID;
    private String bookName;
    private String authorName;
    private String category;
    private double price;
    private double rating;
    
//   default constructor 
    public book() {
    	
    }
    
//    setters and getters
    public int getBookID() {
		return bookID;
	}
	public void setBookID(int bookID) {
		this.bookID = bookID;
	}
	public String getBookName() {
		return bookName;
	}
	public void setBookName(String bookName) {
		this.bookName = bookName;
	}
	public String getAuthorName() {
		return authorName;
	}
	public void setAuthorName(String authorName) {
		this.authorName = authorName;
	}
	public String getCategory() {
		return category;
	}
	public void setCategory(String category) {
		this.category = category;
	}
	public double getPrice() {
		return price;
	}
	public void setPrice(double price) {
		this.price = price;
	}
	public double getRating() {
		return rating;
	}
	public void setRating(double rating) {
		this.rating = rating;
	}
	
//	parameterized constructor
	public book(int bookId,String bookName,String authorName,String catrgory,double price,double rating) {
		this.bookID = bookId;
    	this.bookName = bookName;
    	this.authorName = authorName;
    	this.category = category;
    	this.price = price;
    	this.rating = rating;
	}
    
//	display function
	
	public void display() {
		System.out.println("Book id: "+bookID);
		System.out.println("Book Name: "+bookName);
		System.out.println("Book AuthorName: "+authorName);
		System.out.println("Book Category: "+category);
		System.out.println("Book Price: "+price);
		System.out.println("Book Rating: "+rating);
	}
//	to string function

	@Override
	public String toString() {
		return "bookID= " + bookID + "\nbookName= " + bookName + "\nauthorName= " + authorName + "\ncategory ="
				+ category + "\nprice= " + price + "\nrating= " + rating+"\n";
	}

	
	
	
    
}
