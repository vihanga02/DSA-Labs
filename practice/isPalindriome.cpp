#include <iostream>
#include <string>
#include "gnuplot-iostream.h"
using namespace std;

bool isPalindrome(string str, int start, int end) {
    if (start == end){
        return true;
    }
    else if (str[start] != str[end]){
        return false;
    }
    else{
        return isPalindrome(str, start+1, end-1);
    }
}

int main() {
    string str ; 
    cin >> str;
    bool isPal = isPalindrome(str, 0, str.length() - 1);
    if (isPal) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }
    return 0;
}
