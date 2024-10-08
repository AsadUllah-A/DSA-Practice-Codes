#include <iostream>
using namespace std;

// Define the structure of a node for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to insert a node at the start of the doubly linked list
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

// Function to delete a node from the Start
void deleteFromStart(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is already empty.\n";
        return;
    }
    Node *temp = head;
    head = head->next; // Move head to the next node

    if (head != nullptr)
    {
        head->prev = nullptr; // Set the new head's previous to null
    }
    delete temp; // Free memory of the deleted node
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
    char choice;
    // Inserting nodes at the start of the linked list
    insertAtStart(head, 10);
    insertAtStart(head, 20);
    insertAtStart(head, 30);
    
    cout << "Initial Linked List:" << endl;
    display(head);
    
    do
    {
        cout << "\nDo you want to delete a node from the Start? (y/n): ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Deletion From Start:" << endl;
            deleteFromStart(head);
            cout << "Linked List After Deletion:" << endl;
            display(head);
        }
    } while (choice == 'y');
    return 0;
}
