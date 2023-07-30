
#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* next;

    Contact(const string& name, const string& phone) : name(name), phone(phone), next(NULL) {}
};

class Phonebook {
private:
    Contact* head;

public:
    Phonebook() 
	{
	head= NULL;
	}

    void addContact(const string& name, const string& phone) {
        Contact* newContact = new Contact(name, phone);
        if (head == NULL) {
            head = newContact;
        } else {
            Contact* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newContact;
        }
        cout << "Contact added: " << name << " - " << phone << endl;
    }

    void displayContacts() {
        if (head == NULL) {
            cout << "Phonebook is empty." << endl;
        } else {
            Contact* current = head;
            cout << "Phonebook contacts:" << endl;
            while (current != NULL) {
                cout << current->name << " - " << current->phone << endl;
                current = current->next;
            }
        }
    }

    bool searchContact(const string& name) {
        Contact* current = head;
        while (current != NULL) {
            if (current->name == name) {
                cout << "Contact found: " << current->name << " - " << current->phone << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Contact not found." << endl;
        return false;
    }

    void deleteContact(const string& name) {
        if (head == NULL) {
            cout << "Phonebook is empty. Cannot delete." << endl;
            return;
        }
        if (head->name == name) {
            Contact* temp = head;
            head = head->next;
            delete temp;
            cout << "Contact deleted: " << name << endl;
            return;
        }
        Contact* prev = head;
        Contact* current = head->next;
        while (current != NULL) {
            if (current->name == name) {
                prev->next = current->next;
                delete current;
                cout << "Contact deleted: " << name << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Contact not found. Cannot delete." << endl;
    }

    ~Phonebook() {
        Contact* current = head;
        while (current != NULL) {
            Contact* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Phonebook phonebook;

    phonebook.addContact("John Doe", "123-456-7890");
    phonebook.addContact("Jane Smith", "987-654-3210");
    phonebook.displayContacts();

    phonebook.searchContact("John Doe");
    phonebook.searchContact("Bob Johnson");

    phonebook.deleteContact("Jane Smith");
    phonebook.displayContacts();

    return 0;
}
