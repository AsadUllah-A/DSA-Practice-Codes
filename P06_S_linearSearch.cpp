#include<iostream>
using namespace std;

int linearsearch(string arr[], int size, string target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string arr[10];
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the array element at index["<<i<<"] : ";
        cin>>arr[i];
    }
    size = sizeof(arr)/sizeof(arr[0]);
    string target;
    cout<<"Enter the search value : ";
    cin>>target;
    int result = linearsearch(arr,size,target);
    if(result !=-1)
    {
        cout<<"Serach Found at index["<<result<<"]"<<endl;
    }
    else
    {
        cout<<"Search Not Found"<<endl;
    }
    return 0;
}