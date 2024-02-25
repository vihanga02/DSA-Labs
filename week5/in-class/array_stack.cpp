#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

class array_stack
{
private:
    int top;
    int stack_size;
    int arr[];

public:
    // Constructor to initialize array_stack with specified size
    array_stack(int size){
        this->stack_size = size;
        // Allocate memory for array based on size
        this->arr[size];
        this->top = -1;
    }
    
    // Method to push data onto the stack
    void push(int newData){
        this->top++;
        if (top > stack_size){
            // Throw overflow error if stack is full
            throw overflow_error("Stack is full");
        }
        else{
            // Insert new data into array at top index
            arr[top] = newData;
        }
    }
    
    // Method to pop data from the stack
    int pop(){
        if (top == -1){
            // Throw overflow error if stack is empty
            throw overflow_error("Stack is empty");
        }
        else{
            // Remove and return data from top of the stack
            int previousTop =  arr[top];
            top--;
            return previousTop;
        }
    }

    // Method to check if stack is empty
    bool isEmpty(){
        return top == -1;
    }

    // Method to check if stack is full
    bool isFull(){
        return top + 1 == stack_size;
    }

    // Method to display the stack elements
    void display(){
        if (top == -1){
            // Print message if stack is empty
            cout << "stack is empty" << endl;
        }
        else{
            // Print all elements of the stack
            for (int i = 0; i < stack_size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    // Method to get the top element of the stack
    int StackTop(){
        return arr[top];
    }
};

int main(){
    int stack_size;
    cout << "Enter the size of stack : ";
    cin >> stack_size;

    try
    {
        array_stack stack(stack_size);
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
        // Display total execution time
        auto endingTime = chrono::high_resolution_clock::now();
        double total_time = chrono::duration_cast<chrono::microseconds>(endingTime - startingTime).count();
        cout << "Total execution time: " << total_time << " microseconds" << endl;
    }
    catch (exception& e){
        // Handle exceptions
        cerr << endl <<  "Exception: " << e.what() << endl;
    }
}
