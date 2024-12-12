#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

class Book{
  public:

    std::string name, author, year;

    Book() = default;
    Book(const std::string& n, const std::string& a, const std::string& y) : name(n), author(a), year(y) {}
};


class Library{
  public:
    void setupBooks(){

      std::ifstream fileIn("books.txt");

      if (!fileIn.is_open()){

        std::ofstream fileOut("books.txt");
        fileOut.close();
      }

      fileIn.close();
    }

    std::vector<Book> getBooks() {
      std::vector<Book> books;
      std::ifstream fileIn("books.txt");

      if (!fileIn.is_open()) {
          std::cerr << "File Could Not Be Opened\n";
          return books;
      }

      std::string line;
      int lineNumber = 0;
      Book currentBook;

      while (std::getline(fileIn, line)) {
          if (line.empty()) {
              continue;
          }

          if (lineNumber == 0) {
              currentBook.name = line;
          } else if (lineNumber == 1) {
              currentBook.author = line;
          } else if (lineNumber == 2) {
              currentBook.year = line;
          }

          lineNumber++;

          if (lineNumber > 2) {
              books.push_back(currentBook);
              lineNumber = 0;
          }
      }

      fileIn.close();
      return books;
  }



    void showBooks(){

      std::ifstream fileIn("books.txt");

      if (!fileIn.is_open()){
        std::cerr << "File Could Not Be Opened\n";
        return;
      }

      std::string line;
      int lineNumber = 0;

      while (std::getline(fileIn, line)){

        if (line.empty()){
          lineNumber = 0;
          std::cout << "*************************\n";
          continue;
        }

        if (lineNumber == 0){
          std::cout << "Book Name: " << line << '\n';
        }

        if (lineNumber == 1){
          std::cout << "Author: " << line << '\n';
        }

        if (lineNumber == 2){
          std::cout << "Year: " << line << '\n';
        }

          lineNumber++;
      }

      fileIn.close();
    }

    void addBook() {
      std::string name, author, year;
      std::ofstream fileOut("books.txt", std::ios::app);

      if (!fileOut.is_open()) {
          std::cerr << "File Could Not Be Opened\n";
          return;
      }

      std::cout << "Enter The Book Name: \n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, name);

      std::cout << "Enter The Book Author: \n";
      std::getline(std::cin, author);

      std::cout << "Enter The Book Publish Date: \n";
      std::cin >> year;

      fileOut << name << '\n' << author << '\n' << year << "\n\n";

      fileOut.close();
    }

    void deleteBook() {
      std::vector<Book> books = getBooks();
      if (books.empty()) {
          std::cout << "No Books To Delete.\n";
          return;
      }

      std::ofstream fileOut("temp.txt");
      if (!fileOut.is_open()) {
          std::cerr << "Temporary File Could Not Be Created\n";
          return;
      }

      std::string detail;
      std::cout << "Enter The Book's Name: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, detail);

      bool found = false;

      for (const auto& book : books) {
          if (book.name != detail) {
              fileOut << book.name << '\n';
              fileOut << book.author << '\n';
              fileOut << book.year << '\n';
              fileOut << '\n';
          }
          else
          {
            found = true;
          }
      }

      fileOut.close();

      if (found) {
          std::remove("books.txt");
          std::rename("temp.txt", "books.txt");
          std::cout << "Book Deleted Successfully.\n";
      } else {
          std::remove("temp.txt");
          std::cout << "We Couldn't Find This Book!\n";
      }
}


    void searchBook() {
    std::ifstream inFile("books.txt");

    if (!inFile.is_open()) {
        std::cerr << "File Could Not Be Opened\n";
        return;
    }

    std::string detail;
    std::vector<Book> books = getBooks();
    bool found = false;

    std::cout << "Enter The Book's Name, Author, Or Publication Date: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, detail);

    for (const auto& book : books) {
        if (book.name == detail || book.author == detail || book.year == detail) {
            std::cout << "*******************************\n";
            std::cout << "Book Name: " << book.name << '\n';
            std::cout << "Author: " << book.author << '\n';
            std::cout << "Year: " << book.year << '\n';
            std::cout << "*******************************\n";
            found = true;
        }
    }

    if (!found) {

      std::cout << "Your Book Wasn't Found!\n";

    }
}





};

int main(){

  Library library;
  int choice;
  bool running = true;

  library.setupBooks();


  while (running){

    std::cout << "Enter Your Choice: \n";
    std::cout << "1. Show Books\n";
    std::cout << "2. Add A Book\n";
    std::cout << "3. Delete A Book\n";
    std::cout << "4. Search For A Book\n";
    std::cout << "5. Quit\n";
    std::cin >> choice;

    switch (choice){

      case 1:
        library.showBooks();
        break;
      case 2:
        library.addBook();
        break;
      case 3:
        library.deleteBook();
        break;
      case 4:
        library.searchBook();
        break;
      case 5:
        running = false;
        break;
      default:
        std::cout << "Please Enter A Valid Number\n";
    }
  }

  

  return 0;
}
