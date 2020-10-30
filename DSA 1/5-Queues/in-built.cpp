#include <iostream>
#include <queue>

using namespace std;

void showq(queue <int> g) {
    while (!g.empty()) {
        cout << g.front() << " ";
        g.pop();
    }
    cout << endl;
}

int main() {
    queue <int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.pop();
    showq(myQueue);
    myQueue.push(30);
    myQueue.push(40);
    showq(myQueue);
    cout << myQueue.back() << endl;
    cout << myQueue.size() << endl;
    
    return 0;
}