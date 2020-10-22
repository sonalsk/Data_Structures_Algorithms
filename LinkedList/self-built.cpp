#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node * next;
};

class LinkedList {
    private:
        Node * head;
        Node * tail;
        int size = 0;
    
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void print() {
            Node * node = head;
            while (node != nullptr) {
                cout << node->data << "->";
                node = node->next;
            }
            cout << "null" << endl;
        }

        void addFirst(int);
        void addLast(int);
        void deleteFirst();
        void deleteLast();
        bool contains(int);
        int indexOf(int);
        int getSize();
        Node * getPrevious(Node *);
        void reverse();
        int getKthFromEnd(int);
};

int LinkedList::getSize() {
    return size;
}

void LinkedList::addFirst(int element) {
    Node * node = new Node();
    node->data = element;

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
    size++;
}

void LinkedList::addLast(int element) {
    Node * node = new Node();
    node->data = element;

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    size++;
}

void LinkedList::deleteFirst() {
    Node * node = head;
    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = node->next;
        node->next = nullptr;
        delete node;
    }
    size--;
}

Node * LinkedList::getPrevious(Node * node) {
    Node * current = head;
    while (current != nullptr) {
        if (current->next == node) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::deleteLast() {
    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node * node = head;
        while (node->next->next != nullptr) {
            node = node->next;
        }
        node->next = nullptr;
        tail = node;
    }
    size--;
}

bool LinkedList::contains(int element) {
    Node * node = head;

    while (node != nullptr) {
        if (node->data == element) {
            return true;
        }
        node = node->next;
    }
    return false;
}

int LinkedList::indexOf(int element) {
    Node * node = head;
    int index = -1;

    while (node != nullptr) {
        index++;
        if (node->data == element) {
            return index;
        }
        node = node->next;
    }
    return -1;
}

void LinkedList::reverse() {
    Node * curr = head;
    Node * prev = nullptr;
    Node * next = nullptr;
    tail = head;
    
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    tail->next = nullptr;
}

int LinkedList::getKthFromEnd(int k) {
    Node * start = head;
    Node * end = head;

    if (start == nullptr) {
        return -1;
    }

    for (int i = 0; i < k - 1; i++) {
        end = end->next;
        if (end == nullptr) {
            return -1;
        }
    }

    while (end != tail) {
        start = start->next;
        end = end->next;
    }
    return start->data;
}

int main() {
    LinkedList myList;

    for (int i = 1; i <= 5; i++) {
        myList.addLast(i);
    }
    myList.print();

    myList.deleteFirst();
    myList.print();

    myList.deleteLast();
    myList.print();

    cout << myList.contains(8) << endl;

    cout << myList.indexOf(8) << endl;

    cout << myList.getSize() << endl;

    cout << "Reverse" << endl;
    myList.print();
    myList.reverse();
    myList.print();

    cout << myList.getKthFromEnd(-2) << endl;
    return 0;
}