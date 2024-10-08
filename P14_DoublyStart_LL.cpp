#include <iostream>
using namespace std;

// Define the structure of a node for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to insert a node at the beginning of the doubly linked list
void insertAtStart(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value to the new node
    newNode->next = head;       // Point the new node's next to the current head
    newNode->prev = nullptr;    // The previous of the new node is null

    if (head != nullptr)
    {
        head->prev = newNode; // Update the previous head's prev pointer
    }
    head = newNode; // Update head to point to the new node
}

// Function to display the doubly linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void ReverseDisplay(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node *head = nullptr;
    // Inserting nodes at the End of the linked list
    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);
    
    cout <<"Initial Linked List:" << endl;
    display(head);

    cout<<"\nReversed Linked List:"<<endl;
    ReverseDisplay(head);
    
}
