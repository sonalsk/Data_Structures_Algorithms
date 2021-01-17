#include <iostream>
#include <map>

using namespace std;

int main() {
    map <int, string> employees;
    map <int, string>::iterator itr;

    // insert
    employees[2] = "ram";
    employees[3] = "shaam";
    employees[2] = "ramu";
    employees.insert(pair<int, string>(1, "mohan"));

    // employees = {{2, "ram"}, {3, "shaam"}};

    // employees.erase(1);

    // display
    for (itr = employees.begin(); itr != employees.end(); ++itr) { 
        cout << itr->first << '\t' << itr->second << '\n'; 
    } 
    cout << endl;

    cout << employees.at(2) << endl;
    cout << employees.count(2) << endl;

    return 0;
}