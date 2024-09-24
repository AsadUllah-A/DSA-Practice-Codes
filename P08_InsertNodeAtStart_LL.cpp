//Insert Node At The Biginning
#include<iostream>
using namespace std;
struct Node
{
    int data;    //Data to store
    Node* next;  // Pointer to the next node
};
void insertAtBiginning (Node** head, int newData)
{
    //Allocate memory for new node
    Node* newNode = new Node();
    //Assign data to the new node
    newNode->data = newData;
    //Make next of new node point to the current node
    newNode->next = *head;
    //Move the head to point to the new node
    *head = newNode;
}
void printList (Node* node)
{
    while (node != nullptr)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    //Initialize the head as Null 
    Node* head = nullptr;
    int value,num;
    cout<<"How many values do you want to insert in the list : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Value "<<i+1<<" : ";
        cin>>value;
        //Insert nodes at the beginning
        insertAtBiginning(&head,value);
    }

    //Print the linked list
    cout<<"Linked List: ";
    printList(head);
    return 0;
}