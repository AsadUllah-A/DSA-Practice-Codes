#include<iostream>
using namespace std;
int main()
{
    cout<<"\n*** DSA Code#3 Find Odd & Even Elements In Array **\n*"<<endl;

    int size, even=0 , odd=0;
    cout<<"Size of Array is : ";
    cin>>size;
    int array[size];
    cout<<"\nEnter Values for Array :- "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"Vale#"<<i+1<<" : ";
        cin>>array[i];
    }

    //Finding Odd & Even Numbers
    for(int i=0; i<size; i++)
    {
        if(array[i] % 2 == 0)
        {
            even++;
        }
        else //(array[i] % 2 != 2)
        {
            odd++;
        }
    }
    cout<<"\nTotal Even Values Are : "<<even<<endl;
    cout<<"Total Odd Values Are : "<<odd<<endl;
}