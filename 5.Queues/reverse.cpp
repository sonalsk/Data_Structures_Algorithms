#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void showq(queue <int> g) {
    while (!g.empty()) {
        cout << g.front() << " ";
        g.pop();
    }
    cout << endl;
}

void reverse(queue <int> q) {
    stack <int> reverse;

    int size = q.size();

    while (!q.empty()) {
        reverse.push(q.front());
        q.pop();
    }

    while (!reverse.empty()) {
        q.push(reverse.top());
        reverse.pop();
    }
    showq(q);
}

int main() {
    queue <int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    showq(myQueue);

    reverse(myQueue);
    showq(myQueue);
    return 0;
}