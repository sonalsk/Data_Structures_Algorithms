#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list <int> myList;

    for (int i = 1; i <= 5; i++) {
        myList.push_front(i);
        myList.push_front(i);
    }

    myList.push_front(5);

    myList.insert_after(myList.before_begin(), 0);
    myList.remove(4);

    for (int x: myList) {
        cout << x << " ";
    }
    cout << endl;

    myList.unique();
    myList.sort();
    myList.reverse();

    for (int x: myList) {
        cout << x << " ";
    }
    cout << endl;
    
    
    
    return 0;
}