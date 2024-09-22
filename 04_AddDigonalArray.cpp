#include<iostream>
using namespace std;
int main()
{
    cout<<"\n*** DSA Code#4 Add Digonal Elements In 2D Array ***\n"<<endl;

    int row,col,add=0;
    cout<<"Enter Size of Row and Column : "<<endl;
    cin>>row>>col;
    
    //2D Array
    int array[row][col];
    cout<<"\nEnter Values for Row and Colmun :- "<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>array[i][j];
        }
        cout<<endl;
    }
    
    //Display Array
    cout<<"Values for Row and Colmun Are :- "<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }

    //Add Digonal Elements 
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i==j)
            {
                add += array[i][j];
            }
        }
    }

    //Diplay Result
    cout<<"\nAddition of Digonal Elements Are : "<<add<<endl;
    return 0;
}