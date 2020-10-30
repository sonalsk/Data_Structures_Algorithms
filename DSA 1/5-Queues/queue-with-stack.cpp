#include <iostream>
#include <stack>

using namespace std;

class QueueWithTwoStacks {
    private:
        stack <int> stack_1;
        stack <int> stack_2;
    public:
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        int peek();
};

void QueueWithTwoStacks::enqueue(int element) {
    stack_1.push(element);
}

int QueueWithTwoStacks::dequeue() {
    if (stack_1.empty() && stack_2.empty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    if (stack_2.empty()) {
        while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
    }
    int rm = stack_2.top();
    stack_2.pop();
    return rm;
}

int QueueWithTwoStacks::peek() {
    if (stack_1.empty() && stack_2.empty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    if (stack_2.empty()) {
        while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
    }
    return stack_2.top();
}

bool QueueWithTwoStacks::isEmpty() {
    if (stack_1.empty() && stack_2.empty()) {
        cout << "Stack is Empty" << endl;
        return true;
    }
    return false;
}

int main() {
    QueueWithTwoStacks queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.isEmpty();

    int rm = queue.dequeue();
    cout << rm << endl;




    return 0;
}