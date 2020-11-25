#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int> g) { 
    while (!g.empty()) { 
        cout << g.top() << " "; 
        g.pop(); 
    } 
    cout << endl; 
} 

void showpq(priority_queue <int, vector<int>, greater<int>> g) {
    while (!g.empty()) { 
        cout << g.top() << " "; 
        g.pop(); 
    } 
    cout << endl; 
}

int main() {
    priority_queue <int> queue;
    queue.push(20);
    queue.push(30);
    queue.push(10);
    queue.push(40);

    showpq(queue);

    queue.pop();
    showpq(queue);

    priority_queue <int, vector<int>, greater<int>> gquiz; 
    gquiz.push(20); 
    gquiz.push(30); 
    gquiz.push(10); 
    gquiz.push(40);

    showpq(gquiz);

    gquiz.pop();
    showpq(gquiz);
    return 0;
}