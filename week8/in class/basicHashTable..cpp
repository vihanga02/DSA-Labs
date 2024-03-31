#include <cstring>
#include <string>
#include <iostream>
using namespace std;

// Defining a structure for the hash table
struct HashTable{
    int MAX_LENGTH = 4; // Maximum length of the hash table
    string * password = new string[MAX_LENGTH]; // Array to store passwords

    // Function to initialize the hash table
    void intialize_hashtable(){
        for (int i = 0; i < 4; i++){
            password[i].clear(); // Clearing all passwords
        }
    }

    // Function to check if the hash table is full
    bool isFull(){
        bool full = true; // Assuming the table is full initially
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].empty()){
                full = false; // If any slot is empty, the table is not full
            }
        }
        return full;
    }

    // Function to calculate hash value for a given user name
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(size_t i = 0; i < user_name.length(); i++)
        {
            sum += user_name[i]; // Summing up ASCII values of characters in user name
        }
        hash = sum % MAX_LENGTH; // Modulo operation to fit hash value within table size
        return hash;
    }

    // Function to check if a slot in the table is empty
    bool is_slot_empty(int hash){
        bool empty = password[hash].empty(); // Checking if the slot is empty
        return empty;
    }

    // Function to insert a new user and password into the hash table
    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Calculating hash value for the user name
        empty = is_slot_empty(hash); // Checking if the corresponding slot is empty
        if(empty)
        {
            // If slot is empty, add the user and password
            password[hash] = user_password;
            cout << "User added" << endl;
        }
        else 
        {
            // If slot is not empty, user already exists
            cout << "User already exist" << endl;
        }
    }

    // Function to lookup password for a given user name
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Calculating hash value for the user name
        empty = is_slot_empty(hash); // Checking if the corresponding slot is empty
        if(empty)
        {
            // If slot is empty, user doesn't exist
            cout << "User doesn't exist " << endl;
        }
        else
        {
            // If slot is not empty, print the password
            cout << "User password is " << password[hash] << endl;
        }
    }

    // Function to delete a user from the hash table
    void delete_item(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Calculating hash value for the user name
        empty = is_slot_empty(hash); // Checking if the corresponding slot is empty
        if(empty){
            // If slot is empty, user doesn't exist
            cout<<"No item found\n";
        }
        else{
            // If slot is not empty, delete the user
            password[hash].clear();
            cout<<"User deleted\n";
        }
    }

    // Function to print the contents of the hash table
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->"<<password[i]<<"\n"; // Printing each slot and its content
        }
    }
};

// Main function
int main(){
    HashTable * hashtbl = new HashTable; // Creating a hash table object
    hashtbl->intialize_hashtable(); // Initializing the hash table

    cout<< hashtbl->isFull()<<"\n"; // Checking if the hash table is full

    int command = 0;
    string user_name;
    string password;
    while (command!=-1){
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            // Inserting a new user
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            // Deleting a user
            cout << "Enter item to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            // Looking up password for a user
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            // Printing the hash table
            hashtbl->print_hashtable();
            break;
        case -1:
            // Exiting the program
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
