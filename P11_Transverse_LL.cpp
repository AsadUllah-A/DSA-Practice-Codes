//Insert Node At The END
#include<iostream>
using namespace std;
struct Node
{
    int data;    //Data to store
    Node* next;  // Pointer to the next node
};
//Insert node at the end of the list
void insertAtEnd (Node** head, int newData)
{
    //Allocate memory for new node
    Node* newNode = new Node;
    //Assign data to the new node
    newNode->data = newData;
    //Make next of new node NULL
    newNode->next = NULL;
    //If the list is empty, the new node becomes the head
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    //Otherwise, find the last node
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
void printList(Node* node)
{
    cout<<"Linked List Elements: ";
    while(node != NULL)
    {
        cout<<node->data<<" -> ";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    //Initialize the head as Null 
    Node* head = NULL;
    int value,num;
    cout<<"How many values do you want to insert in the list : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Value "<<i+1<<" : ";
        cin>>value;
        //Insert nodes at the End
        insertAtEnd(&head,value);
    }

    //Print the linked list
    cout<<"Linked List: ";
    printList(head);
    return 0;
}
