#include <iostream>

using namespace std;

class Stack {
    private:
        int items[5];
        int count;
        
    public:
        Stack() {
            count = 0;
        }
        
        void push(int element) {
            if (count == sizeof(items)/sizeof(items[0])) {
                return;
            }
            items[count++] = element;
        }

        int pop() {
            if (count == 0) {
                return -1;
            }
            count--;
            return items[count];
        }

        int peek() {
            if (count == 0) {
                return -1;
            }
            return items[count - 1];
        }

        bool isEmpty() {
            return count == 0;
        }
};

int main() {
    return 0;
}