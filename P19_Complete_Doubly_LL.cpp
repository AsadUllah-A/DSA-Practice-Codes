#include <iostream>
using namespace std;

// Structure defining a node in the doubly linked list
struct Node
{
    int data;   // Data to store in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node (used for bidirectional traversal)
};

// Insert a new node at the beginning of the list
void insertAtStart(Node *&head, int value)
{
    Node *newNode = new Node; // Create a new node
    newNode->data = value;    // Assign value to the new node
    newNode->next = head;     // The new node points to the current head
    newNode->prev = nullptr;  // New node's prev is null, since it's the new head

    if (head != nullptr) // If the list is not empty
    {
        head->prev = newNode; // Set the current head's prev to the new node
    }
    head = newNode; // Update the head to the new node
}

// Insert a new node at the end of the list
void insertAtEnd(Node **head, int newData)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = newData;    // Assign data to the new node
    newNode->next = nullptr;    // The new node will point to null as it's the last node
    newNode->prev = nullptr;    // New node's prev initialized to null

    if (*head == nullptr) // Check if the list is empty
    {
        *head = newNode; // If empty, new node becomes the head
        return;
    }

    Node *temp = *head; // Start from the head node
    while (temp->next != nullptr)
    {
        temp = temp->next; // Traverse to the last node
    }

    temp->next = newNode; // Link the last node to the new node
    newNode->prev = temp; // Set the new node's prev to the last node
}

// Insert a new node at a specific position
void insertAtPosition(Node *&head, int value, int position)
{
    if (position == 1) // Special case: inserting at the head
    {
        insertAtStart(head, value); // Use the insertAtStart function
        return;
    }

    Node *newNode = new Node(); // Create a new node
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) // Traverse to the node just before the position
    {
        temp = temp->next;
    }

    if (temp == nullptr) // Check if position is out of range
    {
        cout << "Position out of range." << endl;
        delete newNode; // Delete the newly created node to avoid memory leak
        return;
    }

    newNode->next = temp->next; // Point the new node's next to the next node in the list
    newNode->prev = temp;       // Point the new node's prev to the current node

    if (temp->next != nullptr) // If not inserting at the end
    {
        temp->next->prev = newNode; // Set the next node's prev to the new node
    }
    temp->next = newNode; // Insert the new node in the correct position
}

// Delete a node by value
void deleteByValue(Node **head, int key)
{
    Node *temp = *head;

    if (temp != nullptr && temp->data == key) // Special case: the head holds the value to delete
    {
        *head = temp->next; // Move the head to the next node

        if (*head != nullptr)
        {
            (*head)->prev = nullptr; // Set the new head's prev to null
        }

        delete temp; // Free memory of the old head
        return;
    }

    while (temp != nullptr && temp->data != key) // Traverse the list to find the key
    {
        temp = temp->next;
    }

    if (temp == nullptr) // If value is not found in the list
    {
        cout << "Value not found in the list" << endl;
        return;
    }

    if (temp->next != nullptr) // If the node to delete is not the last one
    {
        temp->next->prev = temp->prev; // Adjust the next node's prev pointer
    }

    if (temp->prev != nullptr) // If the node to delete is not the first one
    {
        temp->prev->next = temp->next; // Adjust the previous node's next pointer
    }

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

    if (head != nullptr) // If list is not empty after deletion
    {
        head->prev = nullptr; // Set the new head's prev to null
    }

    delete temp; // Free memory of the old head
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
        head = nullptr; // Set head to null, as the list is now empty
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node
        }

        temp->prev->next = nullptr; // Disconnect the last node from the list
        delete temp;                // Free memory of the last node
    }
}

// Delete a node at a specific position
void deleteFromPosition(Node *&head, int position)
{
    if (head == nullptr) // Check if the list is empty
    {
        cout << "List is already empty.\n";
        return;
    }

    if (position == 1) // Special case: deleting the head
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position && temp != nullptr; i++) // Traverse to the target position
    {
        temp = temp->next;
    }

    if (temp == nullptr) // Check if position is out of range
    {
        cout << "Position out of range." << endl;
        return;
    }

    if (temp->next != nullptr) // If not the last node
    {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) // If not the first node
    {
        temp->prev->next = temp->next;
    }

    delete temp; // Free memory of the deleted node
}

// Reverse the doubly linked list
void reverse(Node *&head)
{
    Node *next = nullptr;
    Node *current = head;

    while (current != nullptr) // Traverse the list and swap next and prev for each node
    {
        next = current->prev;          // Temporarily store the prev node
        current->prev = current->next; // Swap the prev and next pointers
        current->next = next;
        current = current->prev; // Move to the next node (which is now previous)
    }

    if (next != nullptr) // After reversing, temp will point to the new head
    {
        head = next->prev; // Set the new head of the reversed list
    }
}

// Find and print the middle element of the list
void findMiddle(Node *head)
{
    if (head == nullptr) // Special case: the list is empty
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
    Node *temp=head;
    while (temp != nullptr) // Traverse through the list
    {
        cout << temp->data << " <-> "; // Print each node's data
        temp = temp->next;
    }
    cout << "NULL" << endl; // End of the list
}

// Main function to test the doubly linked list operations
int main()
{
    cout << "\nDoubly Linked List Complete Code" << endl;
    Node *head = nullptr; // Initialize the head of the list as null
    int num, value, deleteValue, position;

    cout << "How many values do you want to insert in the list: ";
    cin >> num;

    for (int i = 0; i < num; i++) // Insert multiple values at the end
    {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(&head, value);
    }

    cout << "Doubly Linked List is: " << endl;
    printList(head); // Print the initial list

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
        cout << "8. Reverse Linked List\n";
        cout << "9. Middle of Linked List\n";
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
            deleteFromBeginning(head); // Delete from the beginning
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
            reverse(head); // Reverse the list
            cout << "\nReversed Doubly Linked List: " << endl;
            printList(head);
            break;
        case 9:
            findMiddle(head); // Find and print the middle element
            break;
        default:
            cout << "\nInvalid choice!\n";
            break;
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // Repeat operations until user exits

    // Final display of the list
    cout << "Final Doubly Linked List: " << endl;
    printList(head);
    return 0;
}
