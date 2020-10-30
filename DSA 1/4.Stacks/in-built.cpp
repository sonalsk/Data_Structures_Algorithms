#include <iostream>
#include <stack>

using namespace std;

void showstack(stack <int> s) { 
    while (!s.empty()) { 
        cout << s.top() << endl; 
        s.pop(); 
    }
}

int main() {
    stack <int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    showstack(myStack);
    myStack.pop();
    cout << "--------" << endl;
    showstack(myStack);

    return 0;
}