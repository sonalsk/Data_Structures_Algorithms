#include<iostream>
using namespace std; 
  
// Node Class
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
  
  
//prints a linked list in reverse manner 
void reverse(Node* head) {
    if (head == nullptr) {
        return;
    }
    reverse(head->next);
    cout << head->data << " ";
}  
  
  
//push a new node
void insertAtHead(Node** head, int new_data)  
{  
    //make a new node
    Node* new_node = new Node(); 
      
    //insert data in the node
    new_node->data = new_data;  
      
   //make the new_node->next points to head
    new_node->next = (*head);  
      
    //head points at new node
    (*head) = new_node;  
}  
  
//Driver Function
int main()  
{  
    //emty list
    Node* head = NULL;  
      
    //insert Data in the list
    insertAtHead(&head, 5);  
    insertAtHead(&head, 4);  
    insertAtHead(&head, 3);  
    insertAtHead(&head, 2);  
    insertAtHead(&head, 1);  
      
    cout<<"List 1->2->3->4->5 \nReverse List:";  
    reverse(head);  
    cout << endl;
  
    return 0;  
}  
  