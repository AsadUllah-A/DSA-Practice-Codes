#include<iostream>
using namespace std;
int main()
{
    cout<<"\n*** DSA Code#5 Add Row & Column Elements In Array ***\n"<<endl;

    int row,col;
    cout<<"Enter Size of Row and Column : "<<endl;
    cin>>row>>col;
    
    //2D Array
    int array[row][col];
    cout<<"\nEnter Values for Row and Column :- "<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>array[i][j];
        }
        cout<<endl;
    }
    
    //Display Array
    cout<<"Values for Row and Column Are :- \n"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    //Add Row Elements 
    for(int i=0; i<row; i++)
    {
        int row_sum=0;
        for(int j=0; j<col; j++)
        {
            row_sum += array[i][j];
        }  
        cout<<"Addition of Row "<<i+1<<" : "<<row_sum<<endl;
    }
    
    cout<<endl;

    //Add Colmun Elements 
    for(int j=0; j<col; j++)
    {
        int col_sum=0;
        for(int i=0; i<row; i++)
        {
            col_sum += array[i][j];
        }  
        cout<<"Addition of Column "<<j+1<<" : "<<col_sum<<endl;
    }
    return 0;
}