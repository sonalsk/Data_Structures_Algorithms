#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

void showstack(stack <char> s) { 
    while (!s.empty()) { 
        cout << s.top() << endl; 
        s.pop();  
    }
}

string balanced_paran(string exp) {
    stack <char> brackets;
    string open_types = "({[<";
    string closed_types = ")}]>";
    map <char,char> types = {{')', '('}, {'}', '{'}, {']', '['}, {'>', '<'}};

    for (char c: exp) {
        if (open_types.find(c) != exp.npos) {
            brackets.push(c);
        }
        else if (closed_types.find(c) != exp.npos) {
            if (brackets.empty()) {
                return "NO";
            }
            else {
                if (types[c] == brackets.top()) {
                    brackets.pop();
                }
                else {
                    return "NO";
                }
            }
        }
    }

    if (brackets.empty()) {
        return "YES";
    }
    else {
        return "NO";
    }
}

int main() {
    int t;
    scanf("%d", &t);
    string exp;
    getline(cin, exp);
    while (t > 0) {
        getline(cin, exp);
        cout << balanced_paran(exp) << endl;
        t--;
    }
    
    return 0;
}