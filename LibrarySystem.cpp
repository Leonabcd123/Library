#include <iostream>
#include <fstream>
#include <limits>
#include <vector>

class Book{
  public:

    void setupBooks(){

      std::ifstream fileIn("books.txt");

      if (!fileIn.is_open()){

        std::ofstream fileOut("books.txt");
        fileOut.close();
      }

      fileIn.close();
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
      std::ofstream fileOut("books.txt", std::ios::app);

      if (!fileOut.is_open()) {
          std::cerr << "File Could Not Be Opened\n";
          return;
      }

      std::string name, author;
      int year;

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
    std::ifstream fileIn("books.txt");
    if (!fileIn.is_open()) {
        std::cerr << "File Could Not Be Opened\n";
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

    std::string line;
    bool found = false;

    while (std::getline(fileIn, line)) {
        if (line == detail) {
            found = true;
            std::getline(fileIn, line);
            std::getline(fileIn, line);
            continue;
        }
        fileOut << line << '\n';
    }

    fileIn.close();
    fileOut.close();

    if (found) {
        std::remove("books.txt");
        std::rename("temp.txt", "books.txt");
        std::cout << "Book deleted successfully.\n";
    } else {
        std::remove("temp.txt");
        std::cout << "We Couldn't Find This Book!\n";
    }
}



    void searchBook(){

      std::ifstream inFile("books.txt");

      if (!inFile.is_open()){
        std::cerr << "File Could Not Be Opened\n";
          return;
      }

      std::string detail;
      std::string name;
      std::string author;
      std::string year;
      std::string line;
      std::vector<std::string> books;
      bool found = false;

      std::cout << "Enter The Book's Name, Author Or Publication Date: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, detail);

        

        while (std::getline(inFile, line)){

          if (line == detail){
            found = true;
          }

          if (line.empty()){

            if (!found)
            {

              books.clear();
              continue;
            }

            else
            {

              break;

            }

          }

          books.push_back(line);
        }

        if (!found)
        {

          std::cout << "Your Book Wasn't Found!\n";
          return;

        }

        name = books[0];
        author = books[1];
        year = books[2];

        std::cout << "*******************************\n";
        std::cout << "Book Name: " << name << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Year: " << year << '\n';
        std::cout << "*******************************\n";

        }




};

int main(){

  Book book;
  int choice;
  bool running = true;

  book.setupBooks();

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
        book.showBooks();
        break;
      case 2:
        book.addBook();
        break;
      case 3:
        book.deleteBook();
        break;
      case 4:
        book.searchBook();
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
