//Delete Node By Value
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
    Node* newNode = new Node();
    //Assign data to the new node
    newNode->data = newData;
    //Make next of new node point to the current node
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
//Function to delete a node by value
void deleteNode(Node** head, int key)
{
    Node* temp =*head;
    Node* prev = NULL;
    //If the head node holds the key to be deleted
    if(temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return; 
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    //The key is not present in the list
    if (temp== NULL)
    {
        cout<<"Value not found  int the list"<<endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void printList(Node* node)
{
    while (node !=NULL)
    {
        cout<< node->data<<"->";
        node= node->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head = NULL;
    int num, value,deleteValue;
    cout<<"How many values do you want to insert in the list : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Value "<<i+1<<" : ";
        cin>>value;
        insertAtEnd (&head, value);
    }
    cout<<"Linked List is: "<<endl;
    printList(head);
    cout<<"Enter the value of the node to be delete : ";
    cin>>deleteValue;
    deleteNode(&head, deleteValue);
    cout<<"Linked List After Deletion is: "<<endl;
    printList(head);
    return 0;
}