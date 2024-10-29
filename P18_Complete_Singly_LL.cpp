#include <iostream>
using namespace std;

// Structure defining a node in the linked list
struct Node
{
    int data;   // Data to store in the node
    Node *next; // Pointer to the next node in the list
};

// Function to insert a node at the beginning of the list
void insertAtStart(Node *&head, int value)
{
    Node *newNode = new Node; // Create a new node
    newNode->data = value;    // Assign value to the new node
    newNode->next = head;     // Point the new node's next to the current head
    head = newNode;           // Update the head to the new node
}

// Insert a new node at the end of the linked list
void insertAtEnd(Node **head, int newData)
{
    // Allocate memory for the new node
    Node *newNode = new Node();
    // Assign data to the new node
    newNode->data = newData;
    // Make the next of the new node point to NULL (end of the list)
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Otherwise, find the last node
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Set the next of the last node to the new node (inserting at the end)
    temp->next = newNode;
}

// Insert a node at a specific position in the list
void insertAtPosition(Node *&head, int value, int position)
{
    // Special case: inserting at the head
    if (position == 1)
    {
        Node *newNode = new Node(); // Create a new node
        newNode->data = value;
        newNode->next = head; // Set the new node's next to current head
        head = newNode;       // Update head to point to the new node
        return;
    }

    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next; // Traverse to the node before the target position
    }

    // Check if the position is out of range
    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        delete newNode; // Clean up newly created node
        return;
    }

    // Insert new node in the correct position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by value
void deleteByValue(Node **head, int key)
{
    Node *temp = *head;
    Node *prev = NULL;

    // Special case: if the head holds the value to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next; // Move head to the next node
        delete temp;        // Free memory of old head
        return;
    }

    // Traverse the list to find the node with the key
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found in the list
    if (temp == NULL)
    {
        cout << "Value not found in the list" << endl;
        return;
    }

    // Delete the node by adjusting the previous node's next pointer
    prev->next = temp->next;
    delete temp; // Free memory of the deleted node
}

// Delete the first node in the list
void deleteFromBeginning(Node *&head)
{
    if (head == nullptr) // Check if the list is empty
    {
        cout << "List is already empty.\n";
        return;
    }

    Node *temp = head; // Store the current head
    head = temp->next; // Move head to the next node
    delete temp;       // Free memory of the old head
}

// Delete the last node in the list
void deleteFromEnd(Node *&head)
{
    if (head == nullptr) // Check if the list is empty
    {
        cout << "List is already empty.\n";
        return;
    }

    if (head->next == nullptr) // Special case: only one node in the list
    {
        delete head;    // Free the only node
        head = nullptr; // Update head to nullptr (list is now empty)
    }
    else
    {
        Node *temp = head;
        // Traverse to the second last node
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // temp now points to the second last node
        Node *lastNode = temp->next; // Store the last node
        temp->next = nullptr;        // Disconnect the last node
        delete lastNode;             // Free memory of the last node
    }
}

// Delete a node from a specific position
void deleteFromPosition(Node *&head, int position)
{
    if (head == nullptr) // Check if the list is empty
    {
        cout << "List is already empty.\n";
        return;
    }

    if (position == 1) // Special case: deleting the head
    {
        Node *temp = head;
        head = temp->next; // Move head to the next node
        delete temp;       // Free memory of the old head
        return;
    }

    Node *temp = head;
    Node *prev = nullptr; // Track the previous node
    for (int i = 1; i < position && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next; // Traverse to the target position
    }

    // If the position is out of range
    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    prev->next = temp->next; // Update the previous node's next pointer
    delete temp;             // Free memory of the deleted node
}

// Reverse the linked list
void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to current
        current = next;       // Move to the next node
    }

    head = prev; // Update head to point to the new first node
}

// Find and print the middle element of the list
void findMiddle(Node *head)
{
    if (head == nullptr) // Special case: list is empty
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *slow = head;
    Node *fast = head;

    // Move fast by two nodes and slow by one node at a time
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Slow pointer moves one step
        fast = fast->next->next; // Fast pointer moves two steps
    }

    // When fast pointer reaches the end, slow pointer is at the middle
    cout << "\nThe middle element is: " << slow->data << endl;
}

// Print the entire list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl; // End of the list
}

// Main function to test the linked list operations
int main()
{
    cout << "\nSingly Linked List Complete Code" << endl;
    Node *head = NULL; // Initialize the head of the list
    int num, value, deleteValue, position;

    // Input: Number of values to insert
    cout << "\nHow many values do you want to insert in the list : ";
    cin >> num;

    // Insert values at the end of the list
    for (int i = 0; i < num; i++)
    {
        cout << "Value " << i + 1 << " : ";
        cin >> value;
        insertAtStart(head, value); // Insert each value at the end
    }

    // Display the list after insertion
    cout << "Linked List is: " << endl;
    printList(head);

    char choice;
    do
    {
        cout << "\nWhat would you like to do next?\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Delete by Value\n";
        cout << "8. Middle of Linked List\n";
        cout << "9. Reverse Linked List\n";
        cout << "Enter your choice (1-9): ";
        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\nEnter the value to insert: ";
            cin >> value;
            insertAtStart(head, value); // Insert at the beginning
            printList(head);
            break;
        case 2:
            cout << "\nEnter the value to insert: ";
            cin >> value;
            insertAtEnd(&head, value); // Insert at the end
            printList(head);
            break;
        case 3:
            cout << "\nEnter the value to insert: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> position;
            insertAtPosition(head, value, position); // Insert at a specific position
            printList(head);
            break;
        case 4:
            deleteFromBeginning(head); // Delete from the start
            printList(head);
            break;
        case 5:
            deleteFromEnd(head); // Delete from the end
            printList(head);
            break;
        case 6:
            cout << "\nEnter the position to delete: ";
            cin >> position;
            deleteFromPosition(head, position); // Delete from a specific position
            printList(head);
            break;
        case 7:
            cout << "\nEnter the value to delete: ";
            cin >> deleteValue;
            deleteByValue(&head, deleteValue); // Delete by value
            printList(head);
            break;
        case 8:
            findMiddle(head); // Find the middle of the list
            break;
        case 9:
            reverse(head); // Reverse the linked list
            cout << "\nReversed linked list: " << endl;
            printList(head);
            break;
        default:
            cout << "\nInvalid choice!\n";
            break;
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Final display of the linked list
    cout << "Final Linked List: " << endl;
    printList(head);

    return 0;
}
