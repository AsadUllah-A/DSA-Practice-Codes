#include <iostream>
using namespace std;

// Define the structure of a node for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to insert a node at the End of the doubly linked list
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value to the new node
    newNode->next = nullptr;    // Set the next pointer to null

    if (head == nullptr)
    {
        newNode->prev = nullptr; // If list is empty, make newNode the head
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add the new node at the end
        newNode->prev = temp; // Set the previous pointer of the new node
    }
}

// Function to reverse the linked list
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

int main()
{
    Node *head = nullptr;
    // Inserting nodes at the start of the linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    
    cout << "Initial Linked List:" << endl;
    display(head);
    
    // Reverse the linked list
    cout << "\nReversed linked list: " << endl;
    ReverseDisplay(head);
}
