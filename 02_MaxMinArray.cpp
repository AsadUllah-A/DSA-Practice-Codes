#include<iostream>
using namespace std;
int main ()
{
    cout<<"\n*** DSA Code#2 Find Maximum & Minimum Elements In Array ***\n"<<endl;

    //Array Declaration & initialization
    int array[]={10,45,37,54,35};
    
    //Find Size Of Array
    int array_size = sizeof(array)/sizeof(array[0]);
    cout<<"Size Of Array Is : "<<array_size<<endl;
    
    //Finding Maximum Number In Array
    int max_num = array[0];
    for(int i=1; i<5; i++)
    {
        if(max_num<array[i])
        {
            max_num = array[i];
        }
    }

    //Displaying Maximum Number
    cout<<"Maximum Number In Array Is : "<<max_num<<endl;

    //Finding Minimum Number In Array
    int min_num = array[0];
    for(int i=1; i<5; i++)
    {
        if(min_num>array[i])
        {
            min_num = array[i];
        }
    }

    //Displaying Minimum Number
    cout<<"Minimum Number In Array Is : "<<min_num<<endl; 
}