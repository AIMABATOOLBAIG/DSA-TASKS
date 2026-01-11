#include <iostream>
#include <string>
using namespace std;

#define MAX 10   // Maximum number of tickets

/* =========================
   Ticket Structure
   ========================= */
struct Ticket {
    int ticketID;
    string customerName;
    string issue;
};

/* =========================
   Queue Class
   ========================= */
class TicketQueue {
private:
    Ticket queue[MAX];
    int front, rear;

public:
    // Constructor
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return rear == MAX - 1;
    }

    // Enqueue: Add new ticket
    void enqueue(int id, string name, string issue) {
        if (isFull()) {
            cout << "? Queue is full. Cannot add new ticket.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = {id, name, issue};

        cout << "? Ticket added successfully.\n";
    }

    // Dequeue: Process next ticket
    void dequeue() {
        if (isEmpty()) {
            cout << "? No tickets to process.\n";
            return;
        }

        cout << "?? Processing Ticket:\n";
        cout << "ID: " << queue[front].ticketID
             << ", Customer: " << queue[front].customerName
             << ", Issue: " << queue[front].issue << endl;

        front++;
    }

    // Display all pending tickets
    void display() {
        if (isEmpty()) {
            cout << "?? No pending tickets.\n";
            return;
        }

        cout << "\n?? Pending Tickets (FIFO Order):\n";
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << queue[i].ticketID
                 << ", Customer: " << queue[i].customerName
                 << ", Issue: " << queue[i].issue << endl;
        }
    }

    // Cancel ticket by ID (Advanced Feature)
    void cancelTicket(int id) {
        if (isEmpty()) {
            cout << "? No tickets to cancel.\n";
            return;
        }

        int pos = -1;
        for (int i = front; i <= rear; i++) {
            if (queue[i].ticketID == id) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "? Ticket ID not found.\n";
            return;
        }

        for (int i = pos; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        rear--;
        cout << "?? Ticket canceled successfully.\n";
    }
};

/* =========================
   Main Function (Menu)
   ========================= */
int main() {
    TicketQueue supportQueue;
    int choice, id;
    string name, issue;

    do {
        cout << "\n===== Customer Service Ticket System =====\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display Pending Tickets\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Cancel a Ticket (Advanced)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Ticket ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Customer Name: ";
            getline(cin, name);
            cout << "Enter Issue Description: ";
            getline(cin, issue);
            supportQueue.enqueue(id, name, issue);
            break;

        case 2:
            supportQueue.dequeue();
            break;

        case 3:
            supportQueue.display();
            break;

        case 4:
            if (supportQueue.isEmpty())
                cout << "?? Queue is empty.\n";
            else
                cout << "?? Queue has pending tickets.\n";
            break;

        case 5:
            if (supportQueue.isFull())
                cout << "? Queue is full.\n";
            else
                cout << "? Queue is not full.\n";
            break;

        case 6:
            cout << "Enter Ticket ID to cancel: ";
            cin >> id;
            supportQueue.cancelTicket(id);
            break;

        case 0:
            cout << "?? Exiting system.\n";
            break;

        default:
            cout << "? Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}