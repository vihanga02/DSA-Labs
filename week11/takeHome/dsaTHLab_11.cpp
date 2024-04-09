#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    stringstream ss;
    if (year == 1918){
        return "25.09.1918";
    }
    else if (year % 100 == 0 && year > 1918){
        if (year % 400 == 0){
            ss << "12.09." << year;
        }
        else{
            ss << "13.09." << year;
        }
    }
    else{
        if (year % 4 == 0){
            ss << "12.09." << year;
        }
        else{
            ss << "13.09." << year;
        }
    }
    return ss.str();
}

int main()
{
    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
