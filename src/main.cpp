#include <iostream>
#include <string>
using namespace std;

// --- Data Structure: Singly Linked List Node ---
struct Passenger {
    int ticketID;
    string name;
    string trainName;
    Passenger* next;
};

Passenger* head = nullptr;
int idCounter = 1001;

// --- Feature 1: Add Passenger (Queue-like insertion at end) ---
void addPassenger() {
    string n, t;
    cout << "Enter Name: "; cin >> n;
    cout << "Enter Train: "; cin >> t;

    Passenger* newP = new Passenger{idCounter++, n, t, nullptr};

    if (!head) {
        head = newP;
    } else {
        Passenger* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newP;
    }
    cout << ">> Ticket Booked! ID: " << newP->ticketID << endl;
}

// --- Feature 2: Cancel Ticket (Delete by Value) ---
void cancelTicket() {
    if (!head) { cout << ">> No passengers to cancel.\n"; return; }
    int targetID;
    cout << "Enter Ticket ID to cancel: "; cin >> targetID;

    Passenger *temp = head, *prev = nullptr;

    if (temp != nullptr && temp->ticketID == targetID) {
        head = temp->next;
        delete temp;
        cout << ">> Ticket " << targetID << " Cancelled.\n";
        return;
    }

    while (temp != nullptr && temp->ticketID != targetID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) { cout << ">> Ticket ID not found.\n"; return; }

    prev->next = temp->next;
    delete temp;
    cout << ">> Ticket " << targetID << " Cancelled.\n";
}

// --- Feature 3: Search Passenger (Linear Search) ---
void searchPassenger() {
    if (!head) { cout << ">> List is empty.\n"; return; }
    int targetID;
    cout << "Enter Ticket ID to search: "; cin >> targetID;

    Passenger* temp = head;
    while (temp) {
        if (temp->ticketID == targetID) {
            cout << ">> FOUND: " << temp->name << " on " << temp->trainName << endl;
            return;
        }
        temp = temp->next;
    }
    cout << ">> Passenger not found.\n";
}

// --- Feature 4: Display All (Traversal) ---
void displayAll() {
    if (!head) { cout << ">> List is empty.\n"; return; }
    Passenger* temp = head;
    cout << "\n--- Manifest ---\n";
    while (temp) {
        cout << "[" << temp->ticketID << "] " << temp->name << " (" << temp->trainName << ")\n";
        temp = temp->next;
    }
    cout << "----------------\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Book Ticket\n2. Cancel Ticket\n3. Search\n4. View All\n5. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: addPassenger(); break;
            case 2: cancelTicket(); break;
            case 3: searchPassenger(); break;
            case 4: displayAll(); break;
            case 5: cout << "Exiting RailVerse...\n"; break;
            default: cout << "Invalid.\n";
        }
    } while (choice != 5);
    return 0;
}