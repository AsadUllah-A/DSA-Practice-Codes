#include<iostream>
using namespace std;
int main ()
{
    cout<<"\n*** DSA Code#1 Array Insertion ***\n"<<endl;

    //Entering Array Size & Data
    int num;
    string names[10];
    cout<<"Enter Size Of Array : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        cout<<"Name "<<i+1<<" : ";
        cin>>names[i];
    }

    //Diplaying Array 
    cout<<"\nEntered Names Are : \n";
    for(int i=0; i<num; i++)
    {
        cout<<"Name "<<i+1<<" : "<<names[i]<<endl;
    }
    
    //Insertion In Array
    int pos;
    string x;
    cout<<"\nEnter the location of Insertion : ";
    cin>>pos;
    cout<<"\nEnter the Name of Insertion : ";
    cin>>x;
    for(int i=num-1; i>=pos-1; i--)
    {
        names[i+1]=names[i];
    }
    names[pos-1]=x;
    num++;

    //Diplaying Array After Insertion
    cout<<"\nArray After Insertion : \n";
    for(int i=0; i<num; i++)
    {
        cout<<"Name "<<i+1<<" : "<<names[i]<<endl;
    }
    return 0;
}