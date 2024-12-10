# Book Management System

This C++ program provides a simple book management system that allows users to add, delete, search, and view books. It stores the books in a text file (`books.txt`), and each book contains the name, author, and publication year.

## Features

- **Show Books**: Displays all the books stored in the `books.txt` file.
- **Add Book**: Allows the user to add a new book to the file.
- **Delete Book**: Allows the user to delete a book by its name.
- **Search Book**: Allows the user to search for a book by name and display its details.
- **File Handling**: Books are stored in a text file, and operations like add, delete, and search are performed by reading and modifying the file.

## Getting Started

To compile and run the program, follow the steps below:

### Prerequisites

- C++ compiler (e.g., GCC, Clang, Visual Studio)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/BookManagement.git
   
   2. Compile the code:
   
     ```bash
     g++ BookManagement.cpp -o bookmanagement
      ```

      3. Run the program:
         On Windows:
           ```bash
           .\bookmanagement
            ```

         On Linux or macOS:
           ```bash
           ./bookmanagement
            ```
     
### Usage
After running the program, the user will be presented with a menu to choose an operation:

Show Books: Displays all books stored in books.txt.
Add A Book: Prompts the user to enter a book's name, author, and year to add it to the file.
Delete A Book: Prompts the user to enter a book's name to remove it from the file.
Search For A Book: Prompts the user to enter a book's name and displays the details if found.
Quit: Exits the program.

### License
This project is for personal use and learning. Feel free to modify and expand it!
