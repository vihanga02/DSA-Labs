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
    array_stack(int size){
        this->stack_size = size;
        this->arr[size];
        this->top = -1;
    }
    
    void push(int newData){
        this->top++;
        if (top > stack_size){
            throw overflow_error("Stack is full");
        }
        else{
            arr[top] = newData;
        }
    }
    
    int pop(){
        if (top == -1){
            throw overflow_error("Stack is empty");
        }
        else{
            int previousTop =  arr[top];
            top--;
            return previousTop;
        }
    }
    bool isEmpty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if (top + 1 == stack_size){
            return true;
        }
        else{
            return false;
        }
    }
    void display(){
        if (top == -1){
            cout << "stack is empty" << endl;
        }
        else{
            for (int i = 0; i < stack_size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
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
        stack.display();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.display();
        stack.push(4);
        stack.push(30);
        stack.push(3);
        stack.push(1);
        stack.display();
        auto endingTime = chrono::high_resolution_clock::now();
        double totale_time = chrono::duration_cast<chrono::microseconds>(endingTime - startingTime).count();
        cout << totale_time << endl;
    }
    catch (exception& e){
        cerr << endl <<  "Exception: " << e.what() << endl;
    }
}
