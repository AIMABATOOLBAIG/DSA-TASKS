#include <iostream>
#include <string>
using namespace std;

/* =========================
   CSLL - SIMPLE PLAYLIST
   ========================= */

struct CSLLNode {
    int id;
    string name, artist;
    float duration;
    CSLLNode* next;
};

class CSLL {
private:
    CSLLNode* head;

public:
    CSLL() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtBeginning(int id, string name, string artist, float duration) {
        CSLLNode* newNode = new CSLLNode{id, name, artist, duration, NULL};

        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        CSLLNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int id, string name, string artist, float duration) {
        CSLLNode* newNode = new CSLLNode{id, name, artist, duration, NULL};

        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        CSLLNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at Position
    void insertAtPosition(int pos, int id, string name, string artist, float duration) {
        if (pos == 1) {
            insertAtBeginning(id, name, artist, duration);
            return;
        }

        CSLLNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        CSLLNode* newNode = new CSLLNode{id, name, artist, duration, temp->next};
        temp->next = newNode;
    }

    // Delete First Track
    void deleteFirst() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        CSLLNode* temp = head;
        while (temp->next != head)
            temp = temp->next;

        CSLLNode* del = head;
        head = head->next;
        temp->next = head;
        delete del;
    }

    // Delete Last Track
    void deleteLast() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        CSLLNode* prev = NULL;
        CSLLNode* temp = head;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    // Delete by Track ID
    void deleteByID(int id) {
        if (!head) return;

        CSLLNode* curr = head;
        CSLLNode* prev = NULL;

        do {
            if (curr->id == id) {
                if (curr == head)
                    deleteFirst();
                else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    // Display Playlist
    void display() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        CSLLNode* temp = head;
        do {
            cout << "ID: " << temp->id
                 << ", Song: " << temp->name
                 << ", Artist: " << temp->artist
                 << ", Duration: " << temp->duration << " mins\n";
            temp = temp->next;
        } while (temp != head);
    }
};

/* =========================
   CDLL - PREMIUM PLAYLIST
   ========================= */

struct CDLLNode {
    int id;
    string title, artist, album;
    float duration;
    CDLLNode* next;
    CDLLNode* prev;
};

class CDLL {
private:
    CDLLNode* head;
    CDLLNode* current;

public:
    CDLL() {
        head = current = NULL;
    }

    // Insert at Beginning
    void insertAtBeginning(int id, string title, string artist, string album, float duration) {
        CDLLNode* newNode = new CDLLNode{id, title, artist, album, duration};

        if (!head) {
            head = current = newNode;
            head->next = head->prev = head;
            return;
        }

        CDLLNode* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at End
    void insertAtEnd(int id, string title, string artist, string album, float duration) {
        if (!head) {
            insertAtBeginning(id, title, artist, album, duration);
            return;
        }

        CDLLNode* tail = head->prev;
        CDLLNode* newNode = new CDLLNode{id, title, artist, album, duration};

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }

    // Play Next
    void playNext() {
        if (!current) return;
        current = current->next;
        showCurrent();
    }

    // Play Previous
    void playPrevious() {
        if (!current) return;
        current = current->prev;
        showCurrent();
    }

    void showCurrent() {
        cout << "\nNow Playing: "
             << current->title << " by "
             << current->artist << endl;
    }

    // Display Forward
    void displayForward() {
        if (!head) return;

        CDLLNode* temp = head;
        do {
            cout << temp->title << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Loop)\n";
    }

    // Display Reverse
    void displayReverse() {
        if (!head) return;

        CDLLNode* temp = head->prev;
        CDLLNode* tail = temp;

        do {
            cout << temp->title << " -> ";
            temp = temp->prev;
        } while (temp != tail);
        cout << "(Loop)\n";
    }
};

/* =========================
   MAIN FUNCTION
   ========================= */

int main() {
    CSLL simplePlaylist;
    CDLL premiumPlaylist;

    cout << "\nMusic Playlist Manager Initialized Successfully!\n";
    return 0;
}