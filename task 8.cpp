#include <iostream>
#include <string>
using namespace std;

#define MAX 10   // Maximum stack size

/* =========================
   Book Structure
   ========================= */
struct Book {
    int id;
    string title;
    string author;
};

/* =========================
   Stack Class (Array Based)
   ========================= */
class BookStack {
private:
    Book stack[MAX];
    int top;

public:
    // Constructor
    BookStack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Push a book onto stack
    void pushBook(int id, string title, string author) {
        if (isFull()) {
            cout << "? Stack Overflow! Cannot add more books.\n";
            return;
        }
        top++;
        stack[top] = {id, title, author};
        cout << "? Book added successfully.\n";
    }

    // Pop a book from stack
    void popBook() {
        if (isEmpty()) {
            cout << "? Stack Underflow! No books to remove.\n";
            return;
        }
        cout << "?? Removed Book:\n";
        cout << "ID: " << stack[top].id
             << ", Title: " << stack[top].title
             << ", Author: " << stack[top].author << endl;
        top--;
    }

    // Peek top book
    void peekBook() {
        if (isEmpty()) {
            cout << "?? Stack is empty. No book to view.\n";
            return;
        }
        cout << "?? Top Book:\n";
        cout << "ID: " << stack[top].id
             << ", Title: " << stack[top].title
             << ", Author: " << stack[top].author << endl;
    }

    // Display all books
    void displayBooks() {
        if (isEmpty()) {
            cout << "?? No books in the stack.\n";
            return;
        }
        cout << "\n?? Books in Stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "ID: " << stack[i].id
                 << ", Title: " << stack[i].title
                 << ", Author: " << stack[i].author << endl;
        }
    }
};

/* =========================
   Main Function (Menu)
   ========================= */
int main() {
    BookStack library;
    int choice, id;
    string title, author;

    do {
        cout << "\n===== Library Undo Stack Menu =====\n";
        cout << "1. Add Book (Push)\n";
        cout << "2. Remove Book (Pop / Undo)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            library.pushBook(id, title, author);
            break;

        case 2:
            library.popBook();
            break;

        case 3:
            library.peekBook();
            break;

        case 4:
            library.displayBooks();
            break;

        case 5:
            if (library.isEmpty())
                cout << "?? Stack is empty.\n";
            else
                cout << "?? Stack is not empty.\n";
            break;

        case 0:
            cout << "?? Exiting program.\n";
            break;

        default:
            cout << "? Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}