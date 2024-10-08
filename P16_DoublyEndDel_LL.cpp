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
// Function to delete a node from the end
void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is already empty.\n";
        return;
    }

    Node *temp = head;
    if (head->next == nullptr)
    {
        // If there's only one node
        head = nullptr;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node
        }
        temp->prev->next = nullptr; // Set the second last node's next to null
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
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    
    cout << "Initial Linked List:" << endl;
    display(head);
    
    do
    {
        cout << "\nDo you want to delete a node from the end? (y/n): ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Deletion From End:" << endl;
            deleteFromEnd(head);
            cout << "Linked List After Deletion:" << endl;
            display(head);
        }
    } while (choice == 'y');
    return 0;
}
