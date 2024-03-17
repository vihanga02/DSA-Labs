#include <iostream>
#include "linkedlist.cpp" // Including the linked list implementation
using namespace std;

// Defining a structure for the hash table
struct HashTable{
    int MAX_LENGTH = 4; // Maximum length of the hash table
    int MAX_CHAIN_LENGTH = 2; // Maximum length of each chain in the hash table
    LinkedList * password = new LinkedList[MAX_LENGTH]; // Array of linked lists to store passwords

    // Function to check if the hash table is full
    bool isFull(){
        bool full = true; // Assuming the table is full initially
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].head == NULL){
                full = false; // If any slot is empty, the table is not full
            }
        }
        return full;
    }

    // Function to calculate hash value for a given user name
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]); // Summing up ASCII values of characters in user name
        }
        hash = sum % MAX_LENGTH; // Modulo operation to fit hash value within table size
        return hash;
    }

    // Function to check if a slot in the table is empty
    bool is_slot_empty(int hash){
        bool empty;
        if(password[hash].head == NULL){
            empty = true; // If the head of the linked list at this slot is NULL, it's empty
        }
        else{
            empty = false;
        }
        return empty;
    }

    // Function to insert a new user and password into the hash table
    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Calculating hash value for the user name
        empty = is_slot_empty(hash); // Checking if the corresponding slot is empty
        if(password[hash].length < MAX_CHAIN_LENGTH){
            password[hash].insert(user_name.data(), user_password.data()); // Inserting into the linked list
        }
        else{
            cout<<"Linked List reached MAX CAP!\n"; // Maximum chain length reached, cannot insert
        }
    }

    // Function to print the contents of the hash table
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list(); // Printing each slot and its content
        }
    }

    // Function to look up password for a given user name
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Calculating hash value for the user name
        empty = is_slot_empty(hash); // Checking if the corresponding slot is empty
        if(empty)
        {
            // If slot is empty, user doesn't exist
            cout << "User does not exist" << endl;
        }
        else
        {
            // If slot is not empty, search for the username in the linked list
            password[hash].search(user_name);
        }
    }
};

// Main function
int main(){
    HashTable * hashtbl = new HashTable; // Creating a hash table object
    cout<< hashtbl->isFull()<<"\n"; // Checking if the hash table is full

    int command=0;
    string user_name;
    string password;
    while (command != -1){
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            // Inserting a new user
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name, password);
            break;
        case 2:
            // Looking up password for a user
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 3:
            // Printing the hash table
            hashtbl->print_hashtable();
            break;
        case -1:
            // Exiting the program
            hashtbl->print_hashtable();
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
