#include <iostream>

using namespace std;

class Array {

    private:
        int count;
        int items[];

    public:
        Array(int length) {
            items[length];
        }

        void print() {
            for (int i = 0; i < count; i++) {
                cout << items[i] << " ";
            }
            cout << endl;
        }

        void insert(int item) {
            items[count++] = item;
        }

        void remove(int index) {
            for (int i = index; i < count; i++) {
                items[i] = items[i + 1];
            }
            count--;
        }

        int indexOf(int item) {
            // If we find, return index
            for (int i = 0;i < count; i++) {
                if (items[i] == item) {
                    return i;
                }
            }
            return -1;
        }
};

int main() {

    Array * numbers = new Array(3);
    
    numbers->insert(10);
    numbers->insert(20);
    numbers->insert(30);
    
    numbers->remove(0);
    
    numbers->print();
    cout << numbers->indexOf(20) << endl;

    return 0;
}