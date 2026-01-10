#include<iostream>
using namespace std;

class node {
public:
    int patientid;
    node* prev;
    node* next;

    node(int id) {
        patientid = id;
        prev = NULL;
        next = NULL;
    }
};

class doublylinkedlist {
private:
    node* head;

public:
    doublylinkedlist() {   // Corrected constructor
        head = NULL;
    }

    void insertatend(int id) {
        node* newnode = new node(id);

        if (head == NULL) {
            head = newnode;
            return;
        }

        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    void insertatbeginning(int id) {
        node* newnode = new node(id);

        if (head == NULL) {
            head = newnode;
            return;
        }

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }

    void display() {
        if (head == NULL) {
            cout << "No patients in the list\n";
            return;
        }

        node* temp = head;
        cout << "Patient List: ";

        while (temp != NULL) {
            cout << temp->patientid << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    doublylinkedlist d1;
    int choice, id;

    while (true) {
        cout << "\nPatient Management System\n";
        cout << "1. Insert patient at end\n";
        cout << "2. Insert patient at beginning\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;
                d1.insertatend(id);
                break;

            case 2:
                cout << "Enter patient ID: ";
                cin >> id;
                d1.insertatbeginning(id);
                break;

            case 3:
                d1.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}