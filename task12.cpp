#include <iostream>
#include <string>

class Book 
{
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn) 
	: title(title), author(author), isbn(isbn) {}
    void settitle(const std::string& newtitle) 
	{
        title = newtitle;
    }
    void setauthor(const std::string& newauthor) 
	{
        author = newauthor;
    }
    void setisbn(const std::string& newisbn) 
	{
        isbn = newisbn;
    }
    std::string gettitle() const 
	{
        return title;
    }
    std::string getauthor() const 
	{
        return author;
    }
    std::string getisbn() const 
	{
        return isbn;
    }
};

int main() 
{
    Book myBook("Animal Farm", "George Orwell", "95454");
    std::cout << "Book information:" << std::endl;
    std::cout << "Title: " << myBook.gettitle() << std::endl;
    std::cout << "Author: " << myBook.getauthor() << std::endl;
    std::cout << "ISBN: " << myBook.getisbn() << std::endl;
    myBook.settitle("Alice's Adventures in Wonderland");
    myBook.setauthor("Lewis Carroll");
    myBook.setisbn("978555");
    std::cout << "New book information:" << std::endl;
    std::cout << "Title: " << myBook.gettitle() << std::endl;
    std::cout << "Author: " << myBook.getauthor() << std::endl;
    std::cout << "ISBN: " << myBook.getisbn() << std::endl;
    return 0;
}
