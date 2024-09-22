#include<iostream>
using namespace std;
int main ()
{
    int choice=0;
    char *pStudent[] = {"M Ahsan","Kamran","Asad Khan","Noor Khan","Ahmed Ali","Saif Khan"};
    char *pStr="Your Favorite student is : ";
    cout<<endl<<"Enter a number between 1 ad 6 : ";
    cin>>choice;
    if(choice>=1 && choice<=6)
    {
        cout<<pStr<<" : "<<pStudent[choice -1]<<endl;
    }
    return 0;
}