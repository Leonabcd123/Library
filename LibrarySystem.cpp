#include <iostream>
#include <fstream>
#include <limits>

class Book{
  public:
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

    std::string name;
    std::cout << "Enter The Book's Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::string line;
    bool found = false;
    bool aFound = false;

    while (std::getline(fileIn, line)) {
        if (line == name) {
            found = true;
            continue;

        }

        if (found){
          aFound = true;
          continue;
        }

        if (aFound){
          continue;
        }

        fileOut << line << '\n';
    }

    fileIn.close();
    fileOut.close();

    if (aFound) {
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

      std::string name;

      if (!inFile.is_open()){
        std::cerr << "File Could Not Be Opened\n";
        return;
      }

      std::cout << "Enter The Book's Name: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, name);

      std::string line;
      std::string author;
      std::string year;
      bool found = false;
      bool aFound = false;

      while (std::getline(inFile, line)){

        if (line == name){
          found = true;
          continue;
        }

        if (found){
          found = false;
          aFound = true;
          author = line;
          continue;
        }

        if (aFound){
          year = line;
          break;
        }




      }

      if (!aFound){
        std::cout << "Your Book Wasn't Found!\n";
      }

      else{
        std::cout << "*******************************\n";
        std::cout << "Book Name: " << name << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Year: " << year << '\n';
        std::cout << "*******************************\n";
      }

    }




};

int main(){

  Book book;
  int choice;
  bool running = true;

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