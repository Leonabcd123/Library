# Book Management System

This C++ program is a simple yet functional book management system that allows users to manage their personal library. It supports adding, deleting, searching, and viewing books. All data is persistently stored in a text file (`books.txt`), with each book record including the name, author, and publication year.

## Features

- **View Books**: Lists all the books stored in the `books.txt` file, displaying their details.
- **Add a Book**: Enables the user to add a new book by providing its name, author, and publication year.
- **Delete a Book**: Allows the user to remove a book by specifying its name.
- **Search for a Book**: Searches for a book by name and displays its details if found.
- **File-based Storage**: All book data is saved to and retrieved from a text file, ensuring persistence across sessions.

## Getting Started

Follow the steps below to set up and run the program:

### Prerequisites

- A C++ compiler such as GCC, Clang, or Visual Studio.

### Installation and Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/BookManagement.git
   ```
   2. Navigate to the project directory:
   
   ```bash
   cd BookManagement
   ```
   3. Compile the code:
   
   ``` bash
   g++ BookManagement.cpp -o bookmanagement
   ```
   
   4. Run the program:
   
      On Windows:
         ```bash
         .\bookmanagement
         ```
      On Linux/macOS:
         ```bash
         ./bookmanagement
         ```
### Usage
When you run the program, you will see a menu with the following options:

1. **View Books**: Displays all books stored in books.txt along with their details.
2. **Add a Book**: Prompts you to enter the book's name, author, and year of publication, and saves the book to (`books.txt`).
3. **Delete a Book**: Asks for the name of the book to delete and removes it from the file.
4. **Search for a Book**: Requests the book's name and displays its details if it exists.
5. **Quit**: Closes the program.

### Example
Here’s an example of how a session might look:

   ```plaintext
   Enter Your Choice: 
   1. Show Books
   2. Add A Book
   3. Delete A Book
   4. Search For A Book
   5. Quit
   > 2
   Enter The Book Name: 
   Pride and Prejudice
   Enter The Book Author: 
   Jane Austen
   Enter The Book Publish Date: 
   1813
   Book added successfully!
   ```

### License
This project is intended for educational and personal use. Feel free to modify and enhance it as you see fit!
