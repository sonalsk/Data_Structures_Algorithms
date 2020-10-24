#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack <char> chars;
    string name = "sonal";

    for(char c: name) {
        chars.push(c);
    }

    string reverse_name;
    while (!chars.empty()) {
        reverse_name += chars.top();
        chars.pop();
    }

    cout << reverse_name << endl;
    return 0;
}