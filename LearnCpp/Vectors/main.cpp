#include <vector>
#include <iostream>
#include "Book.h"

using namespace std;




void PrintVector(const vector<Book>& vectorBooks) {
	//const auto&  avoid copy
	for (const auto& element : vectorBooks) {
		std::cout << element.m_title << endl;
	}
}

int main() {

	Book book1;
	Book book2;
	Book book3;
	Book book4;
	Book book5;
	
	//book1.m_title = "Lord of The Rings";
	//book2.m_title = "The Night Angel";
	//book3.m_title = "The Black Prisim";
	//book4.m_title = "The Night Lord";
	//book5.m_title = "The Count of Monte Cristo";

	std::vector<Book> libraryOfBooks = { Book{"The Night Angel"}, Book{"The Black Prisim"}, Book{"The Night Lord"} };

	PrintVector(libraryOfBooks);
	
	


	



	
	std::cout << book1.m_title << endl;




	return 0;



}

