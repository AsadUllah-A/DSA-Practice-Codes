#include<iostream>
using namespace std;

int main()
{
    int searchValues;
    cout << "Enter Search Value: ";
    cin >> searchValues;
    bool found = false;
    int numbers[5] = {12, 34, 23, 34, 78};
    for (int i = 0; i < 5; i++)
    {
        if (numbers[i] == searchValues)
        {
            found = true;
            cout << "*** Search Found ***" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "*** Search Not Found ***" << endl;
    }
    return 0;
}
