#include <iostream>
#include <stdexcept>
#include <chrono>
 
using namespace std;

class Node {
private:
    int nodeData;

public:
    Node *next;

    // Constructor to initialize Node with data
    Node(int data) {
        this->nodeData = data;
        this->next = nullptr;
    }
    
    // Method to get data of Node
    int data() {
        return nodeData;
    }
};

class LinkedStack {
private:
    int length;

public:
    Node *top;

    // Constructor to initialize LinkedStack
    LinkedStack() {
        top = nullptr;
        this->length = 0;
    }

    // Method to push data onto the stack
    void push(int data) {
        Node *newNode = new Node(data);
        if (isEmpty()) {
            // If the stack is empty, set the new node as top
            top = newNode;
        } else {
            // Otherwise, insert the new node at the top and update top pointer
            newNode->next = top;
            top = newNode; 
        }
        // Increment the length of the stack
        length++;
    }

    // Method to pop data from the stack
    int pop() {
        if (isEmpty()) {
            // If the stack is empty, throw underflow error
            throw underflow_error("Stack is Empty");
        } else {
            // Otherwise, remove the top node and update top pointer
            Node *currentNode = top;
            top = top->next;
            // Decrement the length of the stack
            length--;
            // Return the data of the removed node
            return currentNode->data();
        }
    }

    // Method to check if stack is empty
    bool isEmpty() {
        // Check if top pointer is null
        return top == nullptr;
    }

    // Method to get the top element of the stack
    int stackTop() {
        if (isEmpty()) {
            // If the stack is empty, throw underflow error
            throw underflow_error("Stack is Empty");
        } else {
            // Otherwise, return the data of the top node
            return this->top->data();
        }
    }

    // Method to display the stack elements
    void display() {
        Node *currentNode = this->top;
        while (currentNode != nullptr) {
            // Iterate through the stack and print data of each node
            cout << currentNode->data() << " ";
            currentNode = currentNode->next;
        }
        // Print newline character after displaying all elements
        cout << endl;
    }
};

int main() {
    try {
        LinkedStack stack;
        auto startingTime = chrono::high_resolution_clock::now();
        
        // Pushing elements onto the stack
        stack.push(8);
        stack.push(10);
        stack.push(10);
        stack.push(5);
        stack.push(11);
        stack.push(15);
        stack.push(23);
        stack.push(6);
        stack.push(18);
        stack.push(20);
        stack.push(17);
        
        // Displaying the stack
        stack.display();
        
        // Popping elements from the stack
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        
        // Displaying the stack after popping
        stack.display();
        
        // Pushing more elements onto the stack
        stack.push(4);
        stack.push(30);
        stack.push(3);
        stack.push(1);
        
        // Displaying the stack after pushing
        stack.display();
        
        auto endingTime = chrono::high_resolution_clock::now();
        double total_time = chrono::duration_cast<chrono::microseconds>(endingTime - startingTime).count();
        
        // Printing the total execution time
        cout << "Total execution time: " << total_time << " microseconds" << endl;
    }
    catch (exception& e) {
        // Handling exceptions and printing error messages
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
