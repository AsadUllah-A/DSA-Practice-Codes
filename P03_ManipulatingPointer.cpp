#include<iostream>
using namespace std;
int main()
{
    int array1[5]={5,6,3,2,8};
    int* ipoint=&array1[0];
    for(int i=0; i<100; i++)
    {
        *ipoint =i;
        cout<<ipoint<<endl;
        ipoint=ipoint+1;
    }
    cout<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<array1[i];
    }
    return 0;
}